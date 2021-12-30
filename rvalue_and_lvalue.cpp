/**
 * Understanding Rvalue and Lvalue
 *
 * why do I care?
 *  1. Understanding C++ construct and decypher compiler errors or warning
 *  2. C++ 11 introduced rvalue reference
 *
 * Simplified Definition
 * lvalue - An object that occupies some identifiable location in memory
 * rvalue - any objcet that is not a lvalue
 *
 */

#include <iostream>

// Lvalue Examples

class dog {
};

void lvalue() {
	int i; // i is a lvalue
	int* p = &i; //i's adress is identifiable
	i = 2; //memory content is modified

	dog d1; // lvalue of user defined type (class)
		// most variables in C++ code are lvalues
}

// Rvalue examples

int sum(int x, int y) { return x+y;}
void rvalue() {
	int i = 5; // 5 is an rvalue
	int x = (i+2); // (i+2) is an rvalue
	
	/*
	int* p = &(i + 2) // Error
	i+2 = 4; // Error
	2 = i; // Error
	*/

	int s = sum(3,4); // sum(3,4) is rvalue

}

// Reference ( or lvalue reference)

int square(int& x) {return x*x;}


void lvalue1() {
	int i;
	int& r = i;

	int& r = 5; //Error
	
	//Exception : Constant lvalue refence can be assign a rvalue
	const int& r = 5;

	square(i); //Ok
	square(40); // Error 
	// workaround for above two code line
	// int square(const int& x) {return x*x;} // square(i) and square(40) work
}

/*
 * lvalue can be used to create an rvalue
 * example :
 * int i = 1;
 * int x = i+2;
 * int x = i;
 *
 * Note : lvalue can be implicitly transformed into rvalue
 *
 * rvalue can be used to create an lvalue
 * example :
 * int v[3];
 * *(v+v) = 4;
 *
 * Misconception 1: function or operator always yields rvalues
 * int x = i+3;
 * int y = sum(3,4);
 * int myglobal;
 * int& foo() { return myglobal; }// function return lvalue
 *
 * foo() = 50;
 *
 * A more common example
 * array[3] = 50; // operator [] almost always generates lvalue
 *
 * Misconception 2: lvalues are mofiable
 * C language: lvalue means "valuesuitable for left-hand-side of assigment"
 *
 * const int c = 1; // c is a lvalue
 * c = 2; // Error, c is not modifiable 
 *
 * Misconception 3: rvalues are not modifiable
 * i + 3 =6; // error
 * sum(3,4) = 7; //Error
 *
 * it is not true for user defined type(class)
 * class d;
 * dog().doSomething();// .doSomething() may change the state of the dog object
 *
 */ 

/********** Summary ********
 * 1. every C++ expression yield either an ravlue or a lvalue
 * 2. if the expression has an identifiable memory address, it's lvalue; otherwise, rvalue
int main() {
	lvalue();
	rvalue();
	return 0;
}
