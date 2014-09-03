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


	//CvCapture *cap=cvCaptureFromCAM(0);
	VideoCapture cap(0);
	namedWindow("video",CV_WINDOW_AUTOSIZE);
	namedWindow("video2",CV_WINDOW_AUTOSIZE);

	Mat frame,result,result2,finalyResult;
	int a=0;
	int b=256;
	int c=0;

	while(1){
	//	frame=cvQueryFrame(cap);
		cap.read(frame);
		flip(frame,frame,1);
		cvtColor(frame,frame,CV_BGR2HSV);
		//blur(frame,frame,Size(3,3));
 		vector<Vec3f> circles;
		Scalar min=Scalar(0,110,170);
		Scalar max=Scalar(20,230,256);
		Scalar min2=Scalar(150,50,150,0);
		Scalar max2=Scalar(256,180,256,0);
	//	inRange(frame, min , max, result);
		inRange(frame, min , max, finalyResult);
		//inRange(frame, min2 , max2, result2);
		//bitwise_or(result,result2,finalyResult);
  		HoughCircles( finalyResult, circles, CV_HOUGH_GRADIENT, 2, finalyResult.rows/4, 50, 50, 20, 200 );
/*
      	Point center(0, 100);
      	circle( frame, center, 30, Scalar(0,50,170,0), 3, 8, 0 );
*/


for( size_t i = 0; i < circles.size(); i++ ) {
	cout << circles.size() << endl;
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      //circle( frame, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( frame, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }


		imshow("video",finalyResult);
		imshow("video2",frame);
		//cvShowImage("video",frame);
		//imshow("video2",frame);
		int k=waitKey(30);
		if(k==113){
			a=a+10;
			cout << a << endl;
		}else if(k==119){
			b=b-10;
			cout << b << endl;
		}else if(k==101){
			c=c+10;
		}
};
    return 0;
};



