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
