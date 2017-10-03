/////////////////////////////////////////////////////////////////////////////
//
// COMS30121 - HSVtoRGB.cpp
//
// University of Bristol
//
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <opencv/cv.h>        //you may need to
#include <opencv/highgui.h>   //adjust import locations
#include <opencv/cxcore.h>    //depending on your machine setup

using namespace cv;


int main() {

  // Read image from file
  Mat image = imread("mandrill3.jpg", 1);


  uchar pixelBlue,pixelRed,pixelGreen;
  for (int y=0; y<image.rows;y++){
    for(int x=0; x<image.cols;x++){
      pixelBlue = image.at<Vec3b>(y,x)[0];
      pixelGreen = image.at<Vec3b>(y,x)[1];
      pixelRed = image.at<Vec3b>(y,x)[2];

    }
  }

 // CONVERT TO RGB from HSV AND SAVE THE IMAGE
 cvtColor( image, image, CV_HSV2BGR);
 imwrite( "man3.jpg", image );

 return 0;
}
