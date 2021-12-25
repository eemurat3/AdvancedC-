# AdvancedC++
this repository is about of some c++ context
1. Const Key
 * const value
 * const pointer
 * const function

2. Compiler Generated Function
 * ----C++ 03:
 * 1. Default Constructor( only if there is no constructor declared)
 * 2. Copy Constructor(generated only if no 5,6 declared by user) + (c++11 3,4)
 * 3. Copy Assiment operator(generated only if 5,6 not declared by user) + (c++11 2,4)
 * 4. Destructor
 * 
 * ----C++ 11:
 * 5. Move Constructor( only if 2,3,4,6 not declared by user)
 * 6. Move Assigment Operator( generated only 2,3,4,5 not declared by user)

3. Virtual Destructor
 * use virtual destructor in polymorphic base classes                                     
 * Note: All classes in STL have no virtual destructor, so be careful inheriting from them  
 * use shared_ptr for invoked derived class destructor

4. Assignment to Self in Assignment Operator
 * Assignment operator is frequently being overloaded. Self-assignment is one thing you need to be careful with when you overload an assignment operator.

5. Resource Acquisition is Iniialization (RAII)
 * the only code that can be quaranted to be executed after exception is thrown are the destructor of objects residing on the stack
 * Resource management therefore needs to be tied to the lifespan of suitable objects in order to gain automatic deallocaton and reclamation

6. Struct Vs. Class
 * The most big different of class and struct, struct's default access specifier is public and class 's default access specifier is private 

7. Resource Managing Class
 * anytime you have one object owning another object its pointer you have to do two things
 * 1. Define copy constructor and and copy assigment operator for deep copying
 * 2. olution 2: Solution 1: Delete copy constructor and and copy assigment operator (we can copy constructor and copy assigmnet operator private), and define clone function

 *<strong> Note :</strong> if you are working with STL containers, STL containers requires there contain need to be copy constructable and copy assignable 


* you can find this codes and more at the youtube. youtube link https://www.youtube.com/playlist?list=PLE28375D4AC946CC3
