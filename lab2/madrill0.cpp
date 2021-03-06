#include <stdio.h>
#include <opencv/cv.h>        //you may need to
#include <opencv/highgui.h>   //adjust import locations
#include <opencv/cxcore.h>    //depending on your machine setup

using namespace cv;           //make available OpenCV namespace




int main() {

  // Read image from file
  Mat image = imread("mandrill0.jpg", 1);


  uchar pixelBlue,pixelRed,pixelGreen;
  for (int y=0; y<image.rows;y++){
    for(int x=0; x<image.cols;x++){
      pixelBlue = image.at<Vec3b>(y,x)[0];
      pixelGreen = image.at<Vec3b>(y,x)[1];
      pixelRed = image.at<Vec3b>(y,x)[2];
      image.at<Vec3b>(y,x)[0]=pixelRed;
      image.at<Vec3b>(y,x)[1]=pixelBlue;
      image.at<Vec3b>(y,x)[2]=pixelGreen;

    }
  }

i

  imwrite("man0.jpg",image);
  return 0;
}
