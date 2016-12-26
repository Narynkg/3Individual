#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
IplImage* image = 0;
IplImage* dst = 0;
int main(int argc, char* argv[]) {
    const char *filename = argc == 2 ? argv[1] : "/home/azamat/a/len.png";
    image = cvLoadImage(filename, 1);
    printf("[i] image: %s\n", filename);
    assert(image != 0);
    dst = cvCloneImage(image);
    cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Filter2D", CV_WINDOW_AUTOSIZE);

    float kernel[9];
    kernel[0] = 3;
    kernel[1] = 0;
    kernel[2] = -1;

    kernel[3] = 2;
    kernel[4] = 2;
    kernel[5] = 0;

    kernel[6] = 1;
    kernel[7] = 1;
    kernel[8] = 1;
    CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
    cvFilter2D(image, dst, &kernel_matrix, cvPoint(-1, -1));
    cvShowImage("original", image);
    cvShowImage("resultat", dst);
    cvWaitKey(0);
    cvReleaseImage(&image);
    cvReleaseImage(&dst);
    cvDestroyAllWindows();
    return 0;
}