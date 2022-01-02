/* The Duality of Public Inheritance
 *  - Inheritance of Interface
 *  - Inheritance of Implementation
 *
 *  ********Types  of Inheritance in C++****
 *  1. Pure virtual public function - inherit interface only
 *  2. Non-virtual public function - inherit both interface and implementation
 *  3. Impure virtual public function - inherit interface and default implementation
 *  4. protected function - inherit implementation only
 *
 *  as a software designer, it is very important to seperate the concepts of interface and implementation
 *  
 */

#include <iostream>

/*
 * Interface Inheritance
 *   1. Subtyping
 *   2. Polymorhism
 *	
 *   Pure virtual function which is interface inheritance only should be widely used
 *   when subtyping and polymorhism needed : virtual void doSomething() = 0;
 *
 *  Pitfals
 *   -- be careful of interface bloat
 *   -- Interface do not reveal implementation
 *
 */ 

/*
 * Implementation Inheritance
 *   1. Increase code complexity
 *   2. Not encouraged
 *
 *  Guidelines for Implemenation Inhertitance
 *   1. Do not use inheritance for code reuse, use composition
 *   2. Minimize the implementation in base classes. Base class should be thin.
 *   3. Minimize the level of hierarcihes inimplemntationinheritance
 *
 */

using namespace std;

int main() {
	return 0; 
}
