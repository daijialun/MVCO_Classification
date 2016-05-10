#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int BilateralFilterValue=10;
static void on_BilateralFilter(int, void *);
Mat src, dst_aug, dst_fil;
int main()
{
    src = imread("1.png");
    dst_aug=src.clone();
    dst_fil=src.clone();
    Mat kernel = (Mat_<float>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);
   //filter2D(src,output,src.depth(),kernel);

    filter2D(src, dst_aug, src.depth(), kernel);

    namedWindow("src");
    imshow("src",src);

    namedWindow("dst_aug");
    imshow("dst_aug",dst_aug);

    namedWindow("dst_fil");
    createTrackbar("Value: ", "dst_fil",&BilateralFilterValue, 50,on_BilateralFilter);
    on_BilateralFilter(BilateralFilterValue, 0);
    cvWaitKey(0);
	return 0;
}

static void on_BilateralFilter(int, void *)
{
	bilateralFilter ( dst_aug, dst_fil, BilateralFilterValue, BilateralFilterValue*2, BilateralFilterValue/2 );
	imshow("dst_fil", dst_fil);
}


