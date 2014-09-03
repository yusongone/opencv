#include <iostream>
#include "unistd.h"
#include <sys/time.h>


#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <math.h>

using namespace std;
using namespace cv;

bool status=true;

class Animate{
	public:
		Animate(){
			struct timeval tv;
			struct timezone tz;	
			gettimeofday(&tv,&tz);
			old=tv.tv_sec*pow(10,6)+tv.tv_usec;
		};
		void loop(void (*callback)(long int time)){
			while(1){
				struct timezone tz;	
				struct timeval tv;
				gettimeofday(&tv,&tz);
				long int now=tv.tv_sec*pow(10,6)+tv.tv_usec;
				callback(now-old);	
				old=now;
				usleep(1000*20);
			}
		};
	private:
		long int old;
};


void callback(long int time){
	std::cout << time << std::endl;	
}


int main(int argc,char** argv){
 VideoCapture cap(0); // open the default camera
    if(!cap.isOpened()){  // check if we succeeded
        return -1;
	};
int i=0;
	while(1){
		Mat atom_image = Mat::zeros( 3, 3, CV_8UC3 );
		namedWindow("edges",1);

		Mat frame;
		cap >> frame; // get a new frame from camera
		Mat ff;
		flip(frame,ff,1);
		Point a;
		a.x=i++;
		a.y=50;

		Point b;
		b.x=500;
		b.y=500;
		line(frame,a,b, Scalar( 250, 0, 0 ),2,2);
		imshow("edges", ff);
		int c=waitKey(30);
	}

	void (*cb)(long int time)=callback;

	Animate A;
	A.loop(cb);

    return 0;
};



