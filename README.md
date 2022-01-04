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
 * anytime you have one object owning another object  pointer you have to do two things
 * 1. Define copy constructor and and copy assigment operator for deep copying
 * 2. Delete copy constructor and and copy assigment operator (we can copy constructor and copy assigmnet operator private), and define clone function
 * <strong> Note :</strong> if you are working with STL containers, STL containers requires there contain need to be copy constructable and copy assignable 

8. Virtual Constructor - Clone() Function
 * Sometimes you want a virtual constructor.This can be implemented with clone() function.

9. Define Implicit Type Conversion
 * Implicit Standard Type Conversion 
 * Implicit User Defined Type Conversion
 * Explicit Standard  Type Conversion
 * Explicit User Defined Type Conversion

10. Casting Operators
 * 1. static_cast operator
 * 2. dynamic_cast operator 
 * 3. const_cast operator
 * 4. reinterpret_cast operator
 * 5. c style cast();

11. Inheritance - Public, Protected, and Private 
 * They specifies different acces control from the derived class to the base class

 a. Access Control:
  *  1. None of the derived classes can access anything that is private in B
  *  2. D_pub inherits public members of B as public and protected members of B as public
  *  3. D_priv inherit the public and protected members of B as private
  *  4. D_prot inherits the public and protected members of B as protected
 
 b. Casting
  *  1. Anyone ca cast a D_pub* to B*. D_pub is a special kinf of B.
  *  2. D_priv's members and friends can cast a D_priv* to B*.
  *  3. D_prot members,friends and children can cast a D_prot* to B*.

12. Maintain is-a Relation for Public Inheritance
 * Public Inheritance indicates is-a relationship between base class and derived class. How to maintain this relationship in software development.

14. Understanding rvalue and lvalue
 * Simplified Definition
   * lvalue - An object that occupies some identifiable location in memory
   * rvalue - any objcet that is not a lvalue

15. Static Polymorphism
 * Polymorhism is not for free, it becomes with a small price to pay. the price is number one the memory cost of the virtual table and number two the runtime cost of the dynamic binding. basically the code that creates and uses the virtual table 

16. Multiple Inheritance
 * if you have two same function in the different two class and u want to use two class together for multiple inheritance; when you instance from derived class and you call one of the same functions compiler  gives error "equest for member ‘function name’ is ambiguous". how can we solve this ambiguous?
 * you can common base class, virtual inheritance or Pure Abstract Class

<strong> Note : C++ standard says before compiler sees accessibility of a function it must decide which function is the best match for the function call </strong>

17. The Duality of Public Inheritance
     - Inheritance of Interface
     - Inheritance of Implementation
 
   Types  of Inheritance in C++
    1. Pure virtual public function - inherit interface only
    2. Non-virtual public function - inherit both interface and implementation
    3. Impure virtual public function - inherit interface and default implementation
    4. protected function - inherit implementation only
 
   *  as a software designer, it is very important to seperate the concepts of interface and implementation (codes will be added soon )

18. Code Reuse: Inheritance Vs. Composition

19. Namespace and Keyword "using"
 * C++ keyword using : using keyword can be used in two ways
  - Using directive: to bring all namespace members into current scope 
  - Using declaration
     1. Bring one specific namespace member to current scope.
     2. bring a member from base class to current class's scope 


you can find this codes and more at the youtube. youtube link https://www.youtube.com/playlist?list=PLE28375D4AC946CC3
