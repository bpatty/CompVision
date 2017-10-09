#include <stdio.h>
#include <opencv/cv.h>        //you may need to
#include <opencv/highgui.h>   //adjust import locations
#include <opencv/cxcore.h>    //depending on your machine setup

using namespace cv;           //make available OpenCV namespace

int main() {

  // Read image from file
  Mat image = imread("mandrill1.jpg", 1);
  Mat image1(512, 512, CV_8UC3, Scalar(0));

  for (int y=0; y<image.rows;y++){
    for(int x=0; x<image.cols;x++){
      image1.at<Vec3b>(y,x)[0]=image.at<Vec3b>(y,x)[0];
      image1.at<Vec3b>(y,x)[1]=image.at<Vec3b>(y,x)[1];
    }
  }

  for (int y=30; y<image.rows;y++){
    for(int x=30; x<image.cols;x++){
      image1.at<Vec3b>(y,x)[2]=image.at<Vec3b>(y-30,x-30)[2];
    }
  }

  imwrite("man1.jpg",image1);
  return 0;
  }
