#include <iostream>

/*#########################################################
 * Demystifying Oerator new/delete
 * Why do we wany to customize new/delete
 * 1. Usage error detection:
 *  - Memory leak detection/garbage collection
 *  - array index overrun/underrun
 * 2. Improve Efficiency
 *  - clustering related objects to reduce page fault
 *  - fixed size allocation(good for aplication with many small object)
 *  - align similar size objects to same places to reduce fragmentation.
 * 3. Perform additional tasks:
 *  - fill the deallocated memorywith 0's - security
 *  - Collect Usage statistics
 */

class dog {
	public:
	    dog() {
	        std::cout<<"dog is created\n";
	    }

	    ~dog() {
	        std::cout<<"dog is destroyed\n";
	    }
};

/************ 	Example 1 *********************************
 * what happens when following code is executed?
 */

void example1() {
	std::cout<<"************* example1 ***************\n";
    dog* pd = new dog();
    /*
     * step 1: operator new is called to allocate memory
     * step 2: dog'S constructor is called to create dog
     * step 3: if step 2 throws an exception, call operator delete to free
     * 	       the memory allocated in step 1
     */

    delete pd;
    /*
     * step 1: dog's destructor is called.
     * step 2: operator delete is called to free memory
     */

}

/***** simplified version of operator new ********************/
/*
 * Note: new handler is a function invoked when operator new failed to allocate memory
 * set_new_handler() installs a bew handler and returns current new handler
 */

void* operator new(std::size_t size) throw(std::bad_alloc) {
    while(true) {
        void* pMem = malloc(size); //allocate memory
	if(pMem)
		return pMem; // return the memory if succesfull
	
	std::new_handler Handler = std::set_new_handler(0); //get the new handler
	std::set_new_handler(Handler);
	
	if(Handler)
	    (*Handler) (); //invoke new handler
	else
            throw std::bad_alloc(); // if new handler is null, throw exception

    }
}

/*
 * sometimes you don't want to overload the global or upload the new. only want to overload 
 * the operator new for your own class
 * Member Operator New/delete
 */

class cat {
    public:
        static void*operator new(std::size_t size) throw(std::bad_alloc) {
	   //customNewForDog(size);
	   
	    /*solution for problem 1
            if(size == sizeof(cat)
		//customNewForDog(size);
	    else
	        ::operator new(size);*/ //for child class
	}

	static void operator delete(void* pMemory) throw() {
	    free(pMemory);
	}

	~cat();
};

class vancat : public cat {
    public:
        static void operator delete(void* pMemory) throw() {
            free(pMemory);
        }

    int age;
};

void example2() {
    vancat* vanc = new vancat();
    /* we create a new vancat on the heap. now do you smell any from this code?
     * the cats operate the new is a public function. that means it will be inherited
     * by its child vancat. so when we create a vancat on the heap actually call the 
     * cats of operator new not the standard operate new. as a result we'll be calling 
     * customer new for dog to allocate memory(problem 1)*/
}

int main() {
    example1();

    return 0;
}
