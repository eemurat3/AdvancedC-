/**
 * sometimes you want to a virtual constructor. this can be implemented with clone() function.
 */

#include <iostream>

class Dog {
public:
	//solution, define clone function
	virtual Dog* clone() { return (new Dog(*this));} //co-variant return type
	virtual void printClass() { std::cout<< "Dog Class"<<std::endl;}
};

class YellowDog : public Dog {
	virtual YellowDog* clone() { return (new YellowDog(*this));}
	virtual void printClass() { std::cout<< "YellowDog Class"<<std::endl;}
};

//problem
void foo(Dog* d) { // d is a yellowdog
	Dog* c = new Dog(*d); // c is a dog for solve this problem we can define clone function
	c->printClass();
}

//solution
void foo1(Dog* d) { // d is a yellowdog
	Dog* c = d->clone();
	c->printClass();
}


int main() {
	YellowDog d;
	foo(&d); // output this : Dog Class
	foo1(&d);// output this : YellowDog Class
	return 0;
}
