#include <SerialStream.h>
#include <iostream>
#include <cv.h>
#include <string>
#include <pthread.h>

using namespace LibSerial; 
using namespace std;

void* function(void *param){
	while(1){
		cout << "abc" << endl;
	}
	return ((void*)0);
}

void test(void* callback(void *param)){
	pthread_t nid;
	int err=pthread_create(&nid,NULL,callback,NULL);
	cout << err << endl;
	
}

int main(int argv,char** avgc){
test(function);
	while(1){
		cout << "bcd" << endl;
	}
return 0;
}

