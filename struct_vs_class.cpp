/**
 * What's the difference between Struct and Class in C++
 * the most big different of class and struct, struct's default access specifier is public and class 's default access specifier is private
 */

#include <iostream>
#include <string>

using namespace std;

/// small passive objcets that carry public data and have no or few basic member functions
/// Data container
struct Person_t {
	/// data member is public
	string name;
	unsigned age;
};

/// Bigger active onjects that carry private data, interfaced through pblic member functions
/// Complex data container
class Person {
	/// data member is private
	string name_;
	unsigned age_;
	/// we cannot access the data member for this we can write public interface
public:
	/// getter or accessor functions
	unsigned get_age() const { return age_; }
	string get_name() const { return name_; }
	/// setter or mutator functions
	void set_age(unsigned age) { age_ = age; }
	void set_name(string name) { name_ = name; }
};

int main() {
	Person_t P;
	P.age = 5;
	cout<<"struct person age :"<<P.age<<endl;

	Person P1;
	P1.set_age(15);
	cout<<"class person age :"<<P1.get_age()<<endl;
	return 0;
}
