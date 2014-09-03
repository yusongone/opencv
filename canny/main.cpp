#include <iostream>
#include "unistd.h"
#include <sys/time.h>

#include <stdio.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc,char** argv){

	VideoCapture cap(-1);
	if(!cap.isOpened()){
		cout << "can't open camera!" << endl;
		return -1;
	}
	Mat frame;
	namedWindow("show",1);
	
	Mat element=getStructuringElement(MORPH_CROSS,Size(3,3),Point(2,2));
	Mat m(8,8,CV_8UC(1),Scalar(0,0,0));
	while(1){
		cap >> frame;
	//	blur(frame,frame,Size(30,30));	
		//cvtColor(frame,frame,CV_BGR2GRAY);
		//equalizeHist(frame,frame);
		//Canny(frame,frame,60,100,3);

		
		//erode(frame,frame,element);
		dilate(frame,frame,m);
		


		imshow("show",frame);
		waitKey(30);
	}

    return 0;
};



