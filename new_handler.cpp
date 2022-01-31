#include <iostream>
#include <memory>

/***** simplified version of operator new ********************/                  
/*                                                                             
* Note: new handler is a function invoked when operator new failed to allocate 
* memory. It's purpose is to help memory allocation to succed
* set_new_handler() installs a bew handler and returns current new handle     
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
 * So the new handler must do one of following things
 * 1. Make more mempry available
 * 2. Install a different new-handler
 * 3. Uninstall the new-handler(passing a null pointer)
 * 4. Throw an exception bad_alloc or its descendent
 * 5. Terminate the program
*/

/*********************Example1**************************/
//basic handler
void NoMoreMem() {
    std::cerr << "Unable to Allocate memory" << std::endl;
    abort();
}


/** Class specific new handler */
class dog {
    public:
        static void NoMemForDog() {
            std::cerr << "No more memory for doggy" << std::endl;
            std::set_new_handler(origHandler); // Restore old handler
            throw std::bad_alloc();
        }

        void* operator new(std::size_t size) throw (std::bad_alloc) {
            origHandler = std::set_new_handler(NoMemForDog);
            void* pV = ::operator new(size); // call global operator new
            std::set_new_handler(origHandler);
            return pV;
        }
    private:
        int hair[10000000000000L];
        static std::new_handler origHandler;
};

std::new_handler dog::origHandler;

int main() {
    /*int *pGiant = new int[10000000000000L];
    delete[] pGiant;
    
    //output  for above two line
    //terminate called after throwing an instance of 'std::bad_alloc'
    // what():  std::bad_alloc*/
    
    /** for Example1 ***/
    /*std::set_new_handler(NoMoreMem);
    int *pGiant = new int[10000000000000L];
    delete[] pGiant;
    
    // output for above three line
    // Unable to Allocate memory
    */

    /** For class handler **/
    std::shared_ptr<dog> pd(new dog());
    
    //output for above line
    //No more memory for doggy
    //terminate called after throwing an instance of 'std::bad_alloc'
    //what():  std::bad_alloc
    
    return 0;
}
