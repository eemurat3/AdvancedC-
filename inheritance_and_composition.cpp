/*************************************
 * 
 * Code Reuse: Inheritance Vs. Composition
 */

#include <iostream>

using namespace std;

/*****code reuse with inheritance******/

class Dog {

	//common activities
};

class BullDog : public Dog {

	// call the common activities to perform more tasks
	
};

class ShepherDog : public Dog {
	
	//call the common activities to perform more tasks
};

/****Code Reuse With Composition*********/
class ActivityManager {
	// common Activities
};

class dog {

};

class bullDog : public dog {
	ActivityManager* pActMngr;
	// call the common activities through pActMngr
};

class shepherDog : public dog {
        ActivityManager* pActMngr;
        // call the common activities through pActMngr
};

/*
 * Code Reuse: composition is better than inheritance
 *  1. Less code coupling between reused code and reuse of the code
 *   a. Child class automatically inherits ALL parent class's public members.
 *   b. Child class can acces parent's protected members.
 *    - Inheritance breaks ancapsulation
 *
 *    Note : there are two big the enemy of encapsulation in c++. number one is Friend and number two inheritance.
 *
 *  2. Dynamic binding
 *   a. Inheritance is bound at compile time
 *   b. Composition can be bound either at compile time or at run time
 * 	
 *

int main() {

	return 0;
}
