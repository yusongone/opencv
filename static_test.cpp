#include "iostream"
#include <stdio.h>


const int AGE=1;
using namespace std;

class A{
	public:
	void go(){
		AGE=3;
		cout << AGE << endl;
	};
	void setD(){
	};
	private:
		static string d;
};

class B{
	public:
	void go(){
		cout << "b" << endl;
	};
};

int main(){
	A a;	
	A b;
	a.setD();
	b.setD();
	a.go();
	b.go();

	
return -1;
};
