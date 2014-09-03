#include <iostream>
#include "unistd.h"
#include <sys/time.h>

#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>


#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <math.h>

using namespace std;
using namespace cv;

bool status=true;


int main(int argc,char** argv){
	VideoCapture cap(0);
	if(!cap.isOpened()){return -1;}

	Mat frame,resultFrame;
	while(1){
		cap >> frame;
		imshow("video",frame);
		waitKey(30);
};
	while(0){
		cap >> frame;
		//flip(frame,frame,1);
		cvtColor(frame,resultFrame,CV_BGR2GRAY);
		GaussianBlur(resultFrame,resultFrame,Size(7,7),10,10);

 vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
  HoughCircles( resultFrame, circles, CV_HOUGH_GRADIENT, 2, resultFrame.rows/4, 100, 100, 0, 0 );
for( size_t i = 0; i < circles.size(); i++ ) {
	cout << circles.size() << endl;
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      //circle( frame, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( frame, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }
		imshow("video",frame);
		//imshow("video",frame);
		waitKey(30);
	}
    return 0;
};



