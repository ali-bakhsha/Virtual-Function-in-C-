// Topic Introduction to Virtual Function

//Note
// 1. Whay to use virtual fucntion?
//		a. To achive dynamic polymorphism. which is the ability to call derived class function using base class pointer or refrence

// How to use virtual function?
//		a. by declering function as virtual in base class and overriding that function in derived class.
//		   (function signature should be same in base and derived class)
//		b. declaring a function as virtual in base class in enough, derived class need not to be declared virtual.
//		c. Virtual function should be accessed using pointer(*) or refrence(&) of base class type to achieve run time polymorphism.

// Additional notes
// 1. virtual function can not be static and also can not be a friend function of anothe class.
// 2. a class can have virtual destructor but can not have virtual constructor.
// 3. there are 2 types of virtual function in c++:
//	  a. virtual function
//	  b. pure virtual function
#include <iostream>
using namespace std;

class Base{
	public:
		virtual void fun(){
			cout << "I am Base fun" << endl;
		}
		
		virtual void fun2() = 0;
};

class Derived : public Base{
	public:
		// you can declare without virtual keytford at beginning 
		//void fun() {
		virtual void fun() {
			cout << "I am Derived Class" << endl;
		}
		void fun2(){
			cout << "here is derived fun2" << endl;
		}
};
class Derived1 : public Derived{
	public:
		// you can declare without virtual keytford at beginning 
		//void fun() {
		virtual void fun() {
			cout << "I am Derived1 Class" << endl;
		}
};
int main()
{
	
	
	/*Base* b = new Base();
	b->fun();
	delete b;*/
	
	Base* b1 = new Derived();
	b1->fun();
	delete b1;
	
	Derived d;
	Base& b2 = d;
	
	b2.fun();
	
	
	Base* b3 = new Derived1();
	b3->fun();
	delete b3;
	
	return 0;
}