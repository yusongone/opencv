#include "iostream"

using namespace std;

class Test{
	public:
		void go(){
			cout << "gogo" <<endl;
		};
	private:
		int a;
};

class B{
	public:
		void callback(){
		};
	private:
		int c;
};

void testA(int* Callback(int a,int b)){
	Callback(1,2);
};


int* bba(int a,int b){
	cout << a+b << endl;
};


int main(){
	int (*fefe)(int a,int b)=bba;
	Test t;
	t.go();
	testA(bba);
	return -1;
};


