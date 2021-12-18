/** use virtual destructor in polymorphic base classes 
 * Note: All classes in STL have no virtual destructor, so be careful 
 * inheriting from them*/
#include <iostream>
#include <memory>

using namespace std;

class Dog {
public:
	~Dog() {cout << "Dog Destroyed" << endl ;}
	/***For Solution 1****/
	//virtual ~Dog() {cout << "Dog Destroyed" << endl ;}
};


class YellowDog : public Dog {
public: 
	~YellowDog() {cout << "Yellow dog destroyed" << endl;}
};

//factory pattern
class DogFactory {
public:
	static Dog* createYellowDog() { return (new YellowDog()); }
	/***For Solution 2****/
	/*static shared_ptr<Dog> createYellowDog() { 
		return shared_ptr<YellowDog>(new YellowDog());
       	}*/
};


int main() {
	//if we when run this two code line YellowDog destructor is  not invoke
	//this program output : Dog Destroyed
	
	Dog* pd = DogFactory::createYellowDog();
	delete pd;
	
	/*-----Solution 1------*/
	//if we put virtual keyword before the Dog destructor, this problem is solutes.
	
	/*----Solution 2------*/
	//use the shared_ptr
	//shared_ptr<Dog> pd1 = DogFactory::createYellowDog();
	return 0;
}
