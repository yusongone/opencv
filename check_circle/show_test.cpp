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
Mat frame,result,result3,result2,finalyResult;
int cb,cg,cr;

static void onMouse(int event,int x,int y,int ,void*){
	if(event==1){//click
		cb = frame.at<Vec3b>(x,y)[0];
		cg = frame.at<Vec3b>(x,y)[1];
		cr = frame.at<Vec3b>(x,y)[2];

		cout << cb <<" "<< cg <<" "<< cr << endl;
		
	
	}
}

int add(int x){
	int temp=10;
	if((x+temp)>255){
		return 256;
	}else{
		return x+temp;
	}
}

int sub(int x){
	int temp=10;
	if((x-temp)<1){
		return 0;
	}else{
		return x-temp;
	}
}

int main(int argc,char** argv){
Scalar min=Scalar(0,110,170);
Scalar max=Scalar(20,230,256);


	//CvCapture *cap=cvCaptureFromCAM(0);
	VideoCapture cap(1);
	namedWindow("video",CV_WINDOW_AUTOSIZE);
	namedWindow("video2",CV_WINDOW_AUTOSIZE);

	int a=0;
	int b=256;
	int c=0;

	setMouseCallback("video2",onMouse,0);

	while(1){
	//	frame=cvQueryFrame(cap);
//		Scalar min=Scalar(sub(cb),sub(cg),sub(cr));
//		Scalar max=Scalar(add(cb),add(cg),add(cr));
		cap.read(result);
		//flip(result,result,1);
		cvtColor(result,frame,CV_BGR2HSV);
 		vector<Vec3f> circles;
		inRange(frame, min , max, finalyResult);
		blur(finalyResult,finalyResult,Size(9,9));
		//bitwise_or(result,result2,finalyResult);
  		HoughCircles( finalyResult, circles, CV_HOUGH_GRADIENT, 2, finalyResult.rows/4, 200, 100, 20, 150 );

for( size_t i = 0; i < circles.size(); i++ ) {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( result, center, 3, min, -1, 8, 0 );
      // circle outline
      circle( result, center, radius,Scalar(250,0,0,0.1), 3, CV_AA, 0 );
   }


		imshow("video",finalyResult);
		imshow("video2",result);
		//cvShowImage("video",frame);
		//imshow("video2",frame);
		int k=waitKey(1);
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



