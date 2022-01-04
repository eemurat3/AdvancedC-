/*#####################################################################
 *  C++ keyword: Using : using keyword can be used in two ways
 */

#include <iostream>

/***** Way 1 ****
 *
 * Using directive: to bring all namespace members into current scope 
 *  Example:
 */

/***** Way 2 ****
 *
 * Using declaration
 *  1. Bring one specific namespace member to current scope.
 *  2. bring a member from base class to current class's scope 
 */

/************* Example 1 ***************/
using namespace std; // for way 1, global scope
using std::cout; // for way 2.1, global scope

class B {
	public:
		void f(int a) {
			cout<<"From B: \n";
		}
};

class D : private B {
	public:
		void g() {
			using namespace std; // way1, local scope
			cout<<"From D:\n";
		}
		void h() {
			using std::cout; // way 2.1, local scope
			cout<<"From D: \n";
		}
		using B::f; // way 2.2, class scope
		//if we not declare above line and whwn we call D.f compiler give error
		
		/* using std::cout; // in class scope, illegal
		 * using namespace std; // in class scope, illegal*/
};

//using B::f; //illegal

/************* Example 2 ***************/
class B2 {
	public:
		void f(int a) {}
};

class D2 : public B2 {
	public:
		using B2::f; // solution for "trying()" function error
		void f() {}
};

// when we call below function code is not compiling because f(int ) 
// funtion is shadowed by f(); this is called name hiding.
// if we want to overcome name hiding we could use "using declaration" : 
//

void trying() {
	D2 d;
	d.f(8);
}

/* 
 * Anonymous Namespace
 */
namespace {
	void h() {
		std::cout<<"anonymous namespace\n";
	}
}

int main() {
	D d;
	d.f(5);
	d.g();
	d.h();

	h(); // anonymous namespace
	return 0;
}
