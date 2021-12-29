//******************* Public Inheritance *************** 
/*
 * public inheritance => "is-a" relation
 * A derived class should be able to do everything the base class can do.
 */

#include <iostream>
#include <string>

using namespace std;

/***** Example 1 *******/
class Dog {
	public:
		void bark() {cout << "I am just a dog" << endl;}
};

class YellowDog : public Dog {
	public:
		void bark() { cout << "I am a yellow dog" << endl;}
};

void example1() {
	// below dogs are same and calling function are same  but result is different,
	// this is not a good thing
	cout<<"**example1 : 2 object the same but result is different, not use virtual function**\n";
	YellowDog* py = new YellowDog();
        py->bark();

        Dog* pd = py;
        pd->bark();
}

/***** Example 2 *******/
class Dog2 {
        public:
		//above function not seem in the yellow dog function.
		//when we call this function with yellowdog2 code is not compiled
		//for this we must add this line in the yellow dog class using Dog1::bark;
		void bark(int age) {cout<< "I am "<<age<<" yaers old"<<endl;}
                virtual void bark(string msg="just a") {
			cout << "I am "<<msg<<" dog" << endl;
		}
};

class YellowDog2 : public Dog2 {
        public:
		using Dog2::bark;
		virtual void bark(string msg="a yellow") {
                        cout << "I am "<<msg<<" dog" << endl;
                }
};

void example2() {
	cout<<"**example1 : 2 object the same but result is different, use virtual function**\n";
	
	YellowDog2* py = new YellowDog2();
        py->bark(5);

        Dog2* pd = py;
        pd->bark();
}

int main() {
	example1();
	example2();
	return 0;
}

/************ Summary ***************/
/*
 * 1. Precise definition of classes
 * 2. Don't override non virtual functions.
 * 3. Don't override default parameter values for virtual functions
 * 4. Force inheritance of shadowed functions
 */
