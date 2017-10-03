/////////////////////////////////////////////////////////////////////////////
//
// COMS30121 - thr.cpp
// TOPIC: RGB explicit thresholding
//
// Getting-Started-File for OpenCV
// University of Bristol
//
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <opencv/cv.h>        //you may need to
#include <opencv/highgui.h>   //adjust import locations
#include <opencv/cxcore.h>    //depending on your machine setup

using namespace cv;

int histofunc(Mat image, string name){

  Mat imagecor = image;

  Mat rgbcor[3];
  split(imagecor,rgbcor);

  int histSize = 256; //from 0 to 255

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ; //the upper boundary is exclusive
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  /// Compute the histograms:
  calcHist( &rgbcor[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &rgbcor[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &rgbcor[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

  // Draw the histograms for R, G and B
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /// Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize;GB i++ )
  {
    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                     Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                     Scalar( 255, 0, 0), 2, 8, 0  );
    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                     Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                     Scalar( 0, 255, 0), 2, 8, 0  );
    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                     Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                     Scalar( 0, 0, 255), 2, 8, 0  );
  }

  namedWindow(name, CV_WINDOW_AUTOSIZE );
  imshow(name, histImage );

  return 0;
}

int main() {

  // Read image from file
  Mat image = imread("mandrill2.jpg", 1);

  // Threshold by looping through all pixels
  for(int y=0; y<image.rows; y++) {
   for(int x=0; x<image.cols; x++) {
     uchar pixelBlue = image.at<Vec3b>(y,x)[0];
     uchar pixelGreen = image.at<Vec3b>(y,x)[1];
     uchar pixelRed = image.at<Vec3b>(y,x)[2];

   }
  }
}

 histofunc(imread("mandrillRGB.jpg", 1),"corrupt0");
 waitKey(0);

 //Save thresholded image
 imwrite("colourthr.jpg", image);
  return 0;
}
