#include <stdio.h>
#include <opencv/cv.h>        //you may need to
#include <opencv/highgui.h>   //adjust import locations
#include <opencv/cxcore.h>    //depending on your machine setup

#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


int circularFilter(int M, int x){
  if (x<0)
    return x+M;

  if(x >= M)
    return x-M;

  return x;
}

void kernelFilter(Mat input, Mat output, float Kernel[][3]){
  float sum, x1, y1;
  for(int y = 0; y < input.rows; y++){
      for(int x = 0; x < input.cols; x++){
          sum = 0.0;
          for(int k = -1;k <= 1; k++){
              for(int j = -1;j <= 1; j++ ){
                  x1 = circularFilter(input.cols, x - j);
                  y1 = circularFilter(input.rows, y - k);
                  sum = sum + Kernel[j+1][k+1]*input.at<uchar>(y1,x1);
              }
          }
          output.at<uchar>(y,x) = sum;
      }
  }
}

int main(){

  Mat input, output;

  /// Load an image
  input = imread("mandrill.jpg", CV_LOAD_IMAGE_GRAYSCALE);

  if( !input.data )
  { return -1; }

  float Kernel[3][3] = {
                        {1/9.0, 1/9.0, 1/9.0},
                        {1/9.0, 1/9.0, 1/9.0},
                        {1/9.0, 1/9.0, 1/9.0}
                       };

    output = input.clone();
    for(int y = 0; y < input.rows; y++)
        for(int x = 0; x < input.cols; x++)
            output.at<uchar>(y,x) = 0.0;

    kernelFilter(input, output, Kernel);

    namedWindow("final");
    imshow("final", output);

    namedWindow("initial");
    imshow("initial", input);

  waitKey();

  return 0;
}
