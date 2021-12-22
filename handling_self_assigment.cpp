/**Assignment operator is frequently being overloaded. 
* Self-assignment is one thing you need to be careful with 
* when you overload an assignment operator. */


#include <iostream>

/// implementing Assigment operator
class collar;

class Dog {
public:
	Dog& operator=(const Dog& rhs) {
		/// there is a problem with below implementation the problem arises when 
		// this dog and rhs dog are the same dog. if that is the case when I delete 
		// pCollar I'm also deleting Pcollar of the right hand side dog. then when I 
		// copy constructor from the right hand side pCollar I'm accesing an object 
		// that is deleted and the result could be disastrous. 
		// what is solution for this problem?
		delete pCollar;
		pCollar = new collar(*rhs.pCollar);
		return *this;

		// simple solution : we can do check if this dog equal to the right hand side dog
		// if(this == &rhs)
		// 	return *this;
		// delete pCollar;
                // pCollar = new collar(*rhs.pCollar);
                // return *this;
		//
		// adding safety for exception : we adding two line above code
		// if(this == &rhs)
                //      return *this;
                // collar* pOrginalCollar = pCollar;
                // pCollar = new collar(*rhs.pCollar);
		// delete pOrginalCollar;
                // return *this;
		

		// solution 2: Delegation 
		// *pCollar = *rhs.pCollar; // member by member copying pf collars or call
					    // collar's operator=
	 	// return *this;
	}
private:
	collar* pCollar;

};

int main() {
	return 0;
}
