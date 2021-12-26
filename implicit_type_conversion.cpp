#include <iostream>
#include <string>

using namespace std;
//************************************************
/* User Defined Implicit Type Conversion
 * 
 * Categories of Type Conversion :
 *                                   Implicit    Explicit
 * Standard Type Conversion 		A	    B
 * User Defined Type Conversion 	C	    D
 *						(casting)
 */

// Category A: Implicit Standard Type Conversion
//
void category_a() {
	char c = 'A';
	int i = c;
	std::cout<< "char c to int i, char c: "<<c<<", int i: "<<i<<std::endl;  
	
	char* pc = 0; //int to Null pointer

}

// Category C: Implicit User Data Defined Type Conversion
/*
 * Defined inside class (user defined type)
 * there are 2 methods to define implicit userdefined type conversion
 *
 * Method 1: use constructor that can accept a single parameter.
 * 	- convert other types of object into your class
 * Method 2: Use the type conversion fuction
 * 	- convert an object of your class into other types
 */

class Dog {
public:
	Dog(string name) {name_ = name;}//no explicit
	// if you only want to define a constructor, and no imlicit type
	// conversion, always put "explicit" before the constructor to avoid inadvertent type conversion
	string get_name() const { return name_;} 
	operator string() { return name_; }//dog to string, type conversion function
private:
	string name_;
};

void category_c(){
	string name = "blabla";
	Dog d1 = name;
	cout<< "Dog name is :"<<d1.get_name()<<endl;
	string dogtostring = d1;
	cout<< "Dog to string  :"<<dogtostring<<endl;
	//printf("\n Dog name is %s",d1);
}
/* PRINCIPLE: make interface easy to use correctly and hard to use incorrectly.
 * How hard is enough? ideally, uncompilable
 *
 * General guideline
 * 	1. avoid definning seemingly unexpected conversion
 * 	2. avoid definning two-way implicit conversion
 */

/*
 * Implicit type conversion is useful when creating numerical types of class, such as a rational class
*/
 class Rational {
public:
	Rational(int numerator = 0, int dennomnator = 1):
		num(numerator),den(dennomnator) { };
	int num;
	int den;
	
	// comment lines code using for (int * rational) operation not use for (rational * int) opration
	// for using two oprtaion we define global multiple function
	/*const Rational operator*(const Rational& rhs ){
		return Rational(num*rhs.num,den*rhs.den);
	}
 	
	operator int() const { return num/den; }*/
 	
	int get_rational() const { return num/den; }//Type conversion function
 };

//global multiple function
const Rational operator*(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.num*rhs.num,lhs.den*rhs.den);
}

void rational() {
	Rational r1 = 23;
	Rational r2 = 2 * r1;
	Rational r3 = r1 * 3;
	cout<<"Ratinal r3 = 3 * r1 :"<<r3.get_rational()<<endl;
}

int main() {
	category_a();
	category_c();
	rational();
	return 0;
}
