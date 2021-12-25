#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Person owns the string through its pointer
// if you are working with STL containers, STL containers requires there contain need to be copy constructable and copy assignable 
class Person {
public:
	Person(string name) { pName_ = new string(name); }

	/**********below two line for solution 1*********/
	//Person(const Person& rhs) { pName_ = new string(*(rhs.get_name()));}
	//Person& operator=(const Person& rhs); // Deep Copying
	/************************************************/
	
	//Person* clone() { return (new Person(*(pName_)));}// for solution 2
	void printName() { cout<< *pName_<< endl; }

	string* get_name() const {  return pName_;}
	~Person() { delete pName_; }
private:
	/***********below two line for solution 2*******/
        //Person(const Person& rhs);
        //Person& operator=(const Person& rhs);
	/**********************************************/
	string* pName_;
};

int main() {
	/*******************************************Wrong Code**************************/
	vector<Person> persons;
	persons.push_back(Person("George"));// what happened with this line code
	// above line code actally involves three operations step
	// 1. "George" is constructed
	// 2. A copy of "George" is saved in the vector persons(shallow copy)
	// 3. "George" is detsroyed
        persons.back().printName();/// when we can run this line code, program is crashed
	/********************************************************************************/
		
	// how can do solution this problem? there are two solution for this problem
	/*********** Solution 1: Define copy constructor and and copy assigment operator for deep copying*****/
	/*vector<Person> persons;
          persons.push_back(Person("George"));
	  persons.back().printName();
	*/
	/********************************************************************************/
	
	/******** Solution 2: Solution 1: Delete copy constructor and and copy assigment operator (we can copy constructor and copy assigmnet operator private), and define clone function**/
	/* vector<Person*> persons;
         persons.push_back(new Person("George"));
         persons.back()->printName();
	 */
	/*******************************************************************************************************************************************************/
	cout<< "Goodbye..."<<endl;
	return 0;
}
