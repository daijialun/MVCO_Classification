
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()  {

    Mat src = imread("2.png",0);
	namedWindow("Origin");
	imshow("Origin", src);


    /*Mat kernel = (Mat_<float>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);
    Mat shapen;
    filter2D(src, shapen, src.depth(), kernel);
    imshow("Shapen", shapen);*/

    int BilateralFilterValue=10;
    Mat filter;
    bilateralFilter ( shapen, filter, BilateralFilterValue, BilateralFilterValue*2, BilateralFilterValue/2 );
    imshow("BilateralFilter", filter);

    Mat scharrGX, scharrGY;
   Mat scharrAGX, scharrAGY;
   Mat scharrDst;
   Scharr(filter, scharrGX, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT );
   convertScaleAbs(scharrGX, scharrAGX);
   Scharr(filter, scharrGY, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
   convertScaleAbs(scharrGY, scharrAGY);
   addWeighted(scharrAGX, 0.5, scharrAGY, 0.5, 0, scharrDst);
    imshow("Scharr", scharrDst);
    waitKey();
    return 0;
}

