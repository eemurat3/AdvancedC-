//***********************************************************************
/* 
 * All castings Considered
 *
 * Type conversion:
 * 	1. Implicit Type Conversion
 * 	2. Explicit TYpe conversion - Casting
 */

#include <iostream>
#include <string>

using namespace std;
class Dog {
	public:
		Dog(string name) : name_(name){}
		string get_name() const {return name_;}
		virtual string get_color() const {return " ";}
	private:
		string name_;
};

class YellowDog : public Dog {
	public:
		YellowDog(string name) : Dog(name) { }
		string get_color() const { return "yellow";}

};

/********** 1. static_cast *******************/
/*
 * Convert Objcect from one type another
 * Type conversion needs to be defined
 */

void static_cast_operation() {
	int i = 9;
	float f = static_cast<float>(i);
	Dog* pd = static_cast<Dog*>(new YellowDog("abc")); //convert pointer/reference from one type to a related type (down/up cast)
	cout<<"static_cast : Dog Color : "<<pd->get_color()<<endl;
} 

/********** 1. dynamic_cast *******************/
/*
 * 1 .It Convert Pointer/reference from one type to  another related type(down cast)
 * 2. Run-time type check. if suceed py == pd; if fail py ==0;(in the dynamic_cast_opeerator)
 * 3.It requires the 2 types to be polymorhic (have virtual function)
 * Type conversion needs to be defined
 */

void dynamic_cast_operator() {
	Dog* pd = new YellowDog("xyz");
	YellowDog* py = dynamic_cast<YellowDog*>(pd);
	cout<<"dynamic casting : Dog Color :"<<py->get_color()<<endl;
}

/********** 1. const_cast *******************/
/*
 * only works on pointer/reference
 * pnly works on same type
 * cast away costness of the object
 */

void const_cast_operator() {
	const char* str = "hello world";
	char* modifiable = const_cast<char*>(str);
	cout<<"const casting : modifiable :"<<modifiable<<endl;
}

/********** 1. reinterpet_cast *******************/
/*
 * re-interpret the bits of the objcet pointed to 
 * The ultimate cast than can cast one pointer to any other type of pointer
 */

void reinterpret_cast_operator() {
	long p = 51110980;
	Dog* d = reinterpret_cast<Dog*>(p);
}

/********** C-Style Casting  *******************/

void c_style_cast() {
	short a = 2000;
	int i = (int)a; //c-like cast notation
	int j = int(i); //fuctional notation
	cout<<"C-style casting: i = (int)a = "<<i<<endl;
}

/**
 * Generally C++ style casts are preferred over the C-style, because:
 *  1. Easier to identify in the code
 *  2. Less usage Error. C++ style provides :
 *   a. Narrowly specified purpose of each cast
 *   b. Run-time type check capability
 */
 
int main() {
	static_cast_operation();
	dynamic_cast_operator();
	const_cast_operator();
	reinterpret_cast_operator();
	c_style_cast();
	return 0;
}
