/** 
 * Const used with function
 */
#include <iostream>
#include <string>

class Dog {
private:
	int age;
	std::string name;
public:
	Dog(){ age = 3; name = "dummy"; }
	//constant reference parameter
	void setAge(const int& a) { age = a;}
	void setAge(int& a) { age = a;}
	//if we use pass by value  instaed of pass by refernce , at the this point const using not very useful because  value change only in the funtion 

	//const return value
	const std::string& getName() {return name;}

	//const Function : the means of const function can not changing any member variable of this clas
	//a const function can call  only another const function in the own body
	void printDogName() const { std::cout<<"const name :" <<name<<std::endl; }
	// the Dog object defined with const  ,when we call prinDogName function above function is called , else below function is called
	void printDogName() { std::cout<<"non-cost name :" <<name<<std::endl; }	
};

int main() {
	
	Dog d;
	const Dog d1;
	int i=9;
	d.setAge(i);
	
	d.printDogName();
	d1.printDogName();

	return 0;
}
