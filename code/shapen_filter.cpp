#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main( int argc, char** argv )
{
    // global setting
    Mat kernel = (Mat_<float>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);
   int BilateralFilterValue=10;
   int CannyParam=15;
    int sobelKernelSize=1;

	Mat src = imread("1.png",0);
	namedWindow("Origin");
	imshow("Origin", src);
    waitKey();

     // ******************** Shapen ************************//
    Mat dst_aug=src.clone();
    filter2D(src, dst_aug, src.depth(), kernel);

    // ********************  BilateralFilter *******************//
    Mat dst_fil=dst_aug.clone();
    bilateralFilter ( dst_aug, dst_fil, BilateralFilterValue, BilateralFilterValue*2, BilateralFilterValue/2 );

    // *********************   Canny   ********************//
    namedWindow( "Canny", WINDOW_AUTOSIZE );
    Mat CannyEdge;
    blur( dst_fil, CannyEdge, Size(3,3) );
    Canny( CannyEdge, CannyEdge, CannyParam, CannyParam*3, 3 );
    Mat dstCanny(dst_fil.size(), dst_fil.type());
    dstCanny= Scalar::all(0);
    src.copyTo( dstCanny, CannyEdge);
    imshow("Canny", dstCanny);
    waitKey();

    // *********************   Sobel   ********************//
    Mat sobelGX, sobelGY;
    Mat sobelAGX, sobelAGY;
    Mat dstSobel;
	Sobel( dst_fil, sobelGX, CV_16S, 1, 0, (2*sobelKernelSize+1), 1, 1, BORDER_DEFAULT );
	convertScaleAbs( sobelGX, sobelAGX );
	Sobel( dst_fil, sobelGY, CV_16S, 0, 1, (2*sobelKernelSize+1), 1, 1, BORDER_DEFAULT );
	convertScaleAbs( sobelGY, sobelAGY );
	addWeighted( sobelAGX, 0.5, sobelAGY, 0.5, 0, dstSobel );
	namedWindow( "Sobel", WINDOW_AUTOSIZE );
	imshow("Sobel", dstSobel);
   waitKey();


	return 0;
}

