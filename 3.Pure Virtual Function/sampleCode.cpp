// Topic Pure Virtual Destructor

//Syntax     virtual return type function name(parameters , , , ) = 0;


//Note
// 1. if some class can have only signature of function but not the body, we use pure virtual function.
// 2. sometimes in Base class we know the function name but not the definition of the function, so we want derived classess to provide the function
// 3. we can actualy give body of pure virtual function 
// 4. if you have pure virtual function in your class, it means that class is an abstract class and you cant create an object of that class. (But pointers and refrences can be created)

//Use case
// 			it  used to create abstract class which helps in interface (API)
#include <iostream>
using namespace std;
class Animal{
public:
	virtual void move() = 0;
	virtual ~Animal(){cout << "Animal des" << endl;}
	void test(){cout <<"Test" << endl;}
};

void Animal::move(){ // can have a body
	cout << "I am animal and I want to go, here is my body" << endl;
}
class Cow : public Animal{
public:
	void move() override{
			cout << "I am walk and run" << endl;
	}
	~Cow(){cout << "Cow des" << endl;}
	
};
class Snake : public Animal{
public:
	void move() override{
		
		Animal::move(); // call the body of animal move
			cout << "I am scrooooling" << endl;
	}
	~Snake(){
		Animal::move(); // anywhere in derived class can call pure function body of base and anu other functions
		Animal::test(); // we can call some functions of base class without having an object, object is ban because of abstract class
		cout << "Snake des" << endl;}
};

int main(){
	Animal* a = new Cow();
	Animal* b = new Snake();
	
	a->move();
	cout << endl;
	b->move();
	cout << endl;
	delete a;
	cout << endl<< endl; 
	delete b;
	
	
	// you can not create object of abstract class but yu can use it by refrence and pointer
	//Animal an; 		// error declare variable 'an' to be of abstract type 'Animal'
	
	cout << "1********************" << endl;
	Cow c;
	Animal &an = c;
	an.move();
	an.test();
	
	cout << "2********************" << endl;
	Snake *sn = new Snake();
	Animal* ani = sn;
	ani->test();
	ani->move();
	
	delete ani;
	
	
	
	
	
}