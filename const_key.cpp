/// const : A compile time contraint that an objcet can not be modified

/** Why use const
 * a.) Guard against inadvertent write to the variable
 * b.) self documenting
 * c.) enable compiler to do more optimization, making code tighter
 * d.) const means the varibale can be put in the ROM */
#include <iostream>


using namespace std;

int main() {
	/// data is const
	const int i= 9; 
	/// if we  changed the i ,at the compile time compiler gave error becaus i is const
	// i =5 ; //compiler give error
	
	//if we can use const_cast for change value of i compiler not give error but value is not changed
	const_cast<int&>(i) = 6; //   value of i is equal  9,still
	std::cout <<"value of i :"<<i<<std::endl;

	//data is const , pointer is not const
        const int *p = &i; 	
	//*p = 10; //compile give error
	p++; //compile not give error and the value of p is garbage value
	
	//data and pointer are both const
	const int* const p3 = &i;
	//i = 10; //compile give error
	//p++; //cmpile give error
	return 0;
}

