/**
 * Resource Acquisition is Iniialization (RAII)
 *
 * Use objects to manage resources 
 * 	memory, hardware device, network handle, etc
 */

#include <iostream>
#include <mutex>
#include <memory>

using namespace std;

mutex mu;

void functionA() {
	mu.lock();
	// Do something
	mu.unlock(); // will this line always be executed?
		     // maybe Do something is  return to functionA or throw an exception
		     // we need to quarantee the mutex be unlock. solution is below
}

/**
 * Solution
 */

class Lock {
private:
	mutex* mu_;
public:
	explicit Lock(mutex* mu) { 
		mu_->lock(); 
		mu_ = mu;
		cout<<"\n mutex locked \n";
	}

	~Lock() { 
		mu_->unlock(); 
		cout<<"\n mutex unlocked \n";
	}
};

void functionB() {
        Lock myLock(&mu);
	// Do something
	// the mutex will always be released when mylock is destroied from stack
}

/** Conclusion:
 * the only code that can be quaranted to be executed after exception is thrown are the destructor of objects residing on the stack

 * Resource management therefore needs to be tied to the lifespan of suitable objects in order to gain automatic deallocaton and reclamation
*/


/** Note 1:
 * Another good Example of RAII: shared_ptr
 */
class Dog {
public:
	Dog() { cout<< "\nDog Created\n"; };
        ~Dog() { cout << "\nDog Destroyed\n" << endl; }
};

int function_A() {
	shared_ptr<Dog> pd(new Dog());
	return 1;
}//the dog is destructed when pd goes out of scope( no more pointer points to pd


/** Note 2:
 * what happens whem resource managament object is copied
 */

Lock l1(&mu);
Lock l2(l1);

/** Solution 1:
 * prohibit copying.
 * Disallow compiler generated function
 */

/** Solution 2:
 * Reference-count the underlying resource by using shared_ptr
 *
class Lock1 {
private:
        shared_ptr<mutex> mu_;
public:
        explicit Lock1(mutex* mu):mu_(mu, mu_->unlock()) {
                mu_->lock();
                cout<<"\n mutex locked \n";
		// the second parameter of shared_ptr constructor is "deleter" function
	}
};*/

int main() {
	functionB();
	function_A();

	return 0;
}

