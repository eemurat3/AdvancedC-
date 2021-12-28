/********** Pubic, Private and Protected Inheritance ************/
#include <iostream>

using namespace std;

class B {
};

class D_priv : private B { };
class D_prot : protected B { };
class D_pub : public B { };

/*
 * They specifies different acces control from the derived class to the base class
 *
 * Access Control:
 *  1. None of the derived classes can access anything that is private in B
 *  2. D_pub inherits public members of B as public and protected members of B as public
 *  3. D_priv inherit the public and protected members of B as private
 *  4. D_prot inherits the public and protected members of B as protected
 *
 * Casting
 *  1. Anyone ca cast a D_pub* to B*. D_pub is a special kinf of B.
 *  2. D_priv's members and friends can cast a D_priv* to B*.
 *  3. D_prot members,friends and children can cast a D_prot* to B*.
 */

/*############### Detailed Example #Derived_priv's#################*/
class Base {
	 public:
		 void f_pub() { cout<<"f_pub is called"<<endl;}
 	protected:
		 void f_prot() { cout<<"f_prot is called"<<endl;}
	 private:
		 void f_priv() { cout<<"f_priv is called"<<endl;}
};

class Derived_pub : public Base {
	public:
		void f() {
			f_pub();  //OK, Derived_pub's public function
			f_prot(); //OK, Derived_pub's protected function 
			f_priv(); //Error, Base's private function
		}
};

class Derived_prot : protected Base {
        public:
		//using Base::f_pub();
                void f() {
                        f_pub();  //OK, Derived_prot's protected function
                        f_prot(); //OK, Derived_prot's protected function
                        f_priv(); //Error, Base's  private function
                }
};

class Derived_priv : private Base {
        public:
                void f() {
                        f_pub();  //OK, Derived_priv's private function
                        f_prot(); //OK, Derived_priv's private function
                        f_priv(); //Error, Base's private function
                }
};

/**
 * public inheritance: is-a relation, eg. Derived_pub is-a kinf of a Base
 *
 * private inheritance: similar to has-a relation
*/

class Ring {
	public:
		void tinkle() { cout<<"tinkle"<<endl; }
};

/** Composition **/
class Dog {
	Ring ring_;
	public:
		void tinkle() { ring_.tinkle();}// call forwarding
};

/** private inheritance **/
class dog : private Ring {
	public:
		using::Ring::tinkle;
};


int main() {
	Derived_pub d1;
	d1.f_pub(); // Ok, f_pub() id Derived_pub's public function

	Derived_prot d2;
	d2.f_pub(); // Error, f_pub() id Derived_prot's protected function
	//if we add "using Base::f_pub" in Derived_prot class, this line code not give error

	B* pB = &d1; // ok
	pb = &d2; //Error
	return 0;
}



