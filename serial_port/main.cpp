#include <SerialStream.h>
#include <iostream>
#include <cv.h>
#include <string>


using namespace LibSerial; 
using namespace std;

int main(int argv,char** avgc){
	SerialStream serial_port;
	serial_port.Open("/dev/ttyACM0");
	serial_port.SetBaudRate(SerialStreamBuf::BAUD_9600);
	serial_port.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
	serial_port.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
	serial_port.SetParity(SerialStreamBuf::PARITY_NONE);
	serial_port.SetNumOfStopBits(1);
	serial_port.SetVMin(10);
	cout << serial_port.good() << endl;
	//cout << serial_port.get(next_char) << endl;
	//serial_port.Close();
		char command[]="abc";
		serial_port.write(command,3);
	while(1){
		char next_char;
		serial_port.get(next_char);
		cout << next_char << endl;
	}
	if(!serial_port.good()){

	cout << "a" << endl;

	};
	cout << "b" << endl;
	serial_port.Close();
return 0;

}
