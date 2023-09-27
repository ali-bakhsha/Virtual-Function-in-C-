// Topic Virtual Destructor

//Note
// 1. if we deletre child class object through a pointer of parrent class then it is undefined behavior
//    if parent class does not have virtual destructor.
// 2. if we fail to declare destructor as virtual in parent class then we endup having memory leak
#include <iostream>
using namespace std;

				// esample 1 -> output is 
				//Base constructor
				//Derived constructor
				//Base destructor
				//and it has memory leak
/*class Base{
	public:
		Base(){cout << "Base constructor" << endl;}
		~Base(){cout << "Base destructor" << endl;}
};

class Derived : public Base{
	public:
		Derived(){cout << "Derived constructor" << endl;}
		~Derived(){cout << "Derived destructor" << endl;}
};*/


class Base{
	public:
		virtual void function1() = 0;
		Base(){cout << "Base constructor" << endl;}
		virtual ~Base(){cout << "Base destructor" << endl;}
		void test(){cout << "Test" << endl;}
};

class Derived : public Base{
	public:
		Derived(){cout << "Derived constructor" << endl;}
		~Derived(){cout << "Derived destructor" << endl;}
		void function1() {}

};





int main()
{
	Base* b = new Derived();
	delete b;
	
	cout << endl<< endl;
	// second way without adding virtual destructor
	Derived* b1 = new Derived();
	delete b1;
	
	cout << endl<< endl;
	Derived c;
	
	
	return 0;
}