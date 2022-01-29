/*##################################################3
 *
 * Koening Lookup
 */
#include <iostream>

using namespace std;

/*################ Example 1 ###################*/
namespace A {
	struct X {int a;};
	void g(X) { cout<< "calling A::g() \n";}
}

/* when we call below fucntion, this code printout: "calling A::g()"*/
void state1() {
	cout<< "******** Example 1 - state 1******\n";
	A::X x1;
	A::g(x1);
}

/* if we remove A:: before g function and only calling g function what happen?
 * we may expect thah the compiler will error out saying cannot find a function 
 * called g, because function g is only defined inside the namespace A. however
 * this code not only compile it will still callic print out "calling A::g()"
 * it turns out when the compiler see the function g it will not only search 
 * the function g in the current scope and global scope. it will also search the
 * function in the scope where its parameter type is defined. parameter type
 * defined in ths case the type of it's parameter is X and X is defined in 
 * namespace A. so the compiler will search the g function in the namespace A
 * this is a called Koenig Lookup or Argument dependent Lookup
 */
void state2() {
	cout<< "******** Example 1 - state 2******\n";
	A::X x1;
	g(x1);
}

/*################ Example 2 ###################*/
class C {
	public:
		struct Y {};
		static void h(Y) { cout<< "calling C::h() \n"; }
};

/* when we call below fucntion, this code printout: "calling C::h()"*/
void state3() {
	cout<< "******** Example 2 - state 1******\n";
	C::Y y;
	C::h(y);
}

/* what will happen? since we have koenig lookup when the compiler see the H, it 
 * it was searched the function in the scope where the type of its parameted is 
 * defined. so it was searched inside C and find h right? !!! no, actually the
 * koenig lookup only aplies to namespace. it cannot reach into a class. so below
 * code give error.*/
void state4() {
	cout<< "******** Example 2 - state 2******\n";
        C::Y y;
        //h(y); // Error
}

/*################ Example 3 ###################*/
namespace B {
	struct X { };
	void g( X ) { cout<< "calling B::g() \n"; }
}

namespace D {
	void g( B::X ) {cout<< "calling D::g() \n"; }
	void j() {
		B::X x;
		//g(x); // error
	}
}

/* what will happen ? this code will not compile. whwn thw compiler try to resolve
 * the function call of g, it definitely can see D::g function. however, because 
 * of the koenig lookup it can also see B::g function. so the compiler doesn't know 
 * which one to call. it is an anbiguus code to function g. if I change D from a 
 * namespace to a class. */
void state5() {
	cout<< "******** Example 3 - state 1******\n";
        //D::j(); // error: call of overloaded ‘g(B::X&)’ is ambiguous
}

class E { // namespace D change to class E
	public:
        	void g( B::X ) {cout<< "calling D::g() \n"; }
        	void j() {
        	        B::X x;
        	        g(x);
       		 }
};

/* what will happen? this code will compile and print out "calling D::g()". why ?
 * because when the compiler tries to find function g, it will first search it inside 
 * class E and fuction g is found it will stop searching. only when the G is not find
 * inside of the class E the compiler will look at the global scope and use the koeing 
 * lookup. if we not define function g inside of class E. this code will still compile but 
 * print out calling "calling B::g()"
*/
void state6() {
        cout<< "******** Example 3 - state 2******\n";
        E e;
	e.j();
}

/* ############### Name hiding: namespace example */

namespace name1 {
	void g( int ) { cout<<"calling name1::g()\n";}
	namespace name2 {
		void g() { cout<<"calling name2::g()\n";}
		void j() {
			using name1::g; //for overcome name hiding
			g(8);
		}
	}
}

/* whwn we invoke J function code is not compile. you may expect when the compiler
 * g(8) it should invoke the g(int) function because they are all under the umbrella 
 * od namespace name1 so h function should be visible inside namespace name2 but actually
 * it is not. this code not compile because g(int) function is shadowed by g() function.
 * even though they have different parameter signature. this is name hiding. 
 * we can "using declaration" for overcome name hiding.
*/
 void namespace_hiding() {

	cout<<"********namespace hiding ******\n";
	name1::name2::j();
}

int main() {
	state1();
	state2();
	state3();
	//state5(); //code not compile
	state6();
	namespace_hiding();
	return 0;
}

