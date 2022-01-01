/******** Multiple Inherıtance ***********/
/* C++ standard says before compiler sees accessibility of a function it 
 * must decide which function is the best match for the function call
 */

#include <iostream>
#include <string>

using namespace std;

/**** Example 1: input output file ****/

class InputFile {
	public:
		void read();
		//void open() {cout<<"file is open for read"<<endl;}//state 1
	private:
		void open() {cout<<"file is open for read"<<endl;}//state 2
};

class OutputFile {
	public:
		void write();
		void open() {cout<<"file is open for write"<<endl;} //state 1
};

class IOFile : public InputFile, public OutputFile {

};

/******** Example 2******
 * input File and Output File have open function so when we call open function, compiler give "request for member ‘open’ is ambiguous" error. for solve thsi error we can define a common base class.*/
					//        File
      	                                //        / \
                                        //       /   \
                                        //InputFile OutputFile
                                        //      \    /
                                        //       \  /
                                        //      IOFile
// below code have ıssue still, because when we use File class for inheritance Input and output file have open function. this is a known diamond shape problem. we can use virtual inheritance for solution this problem. virtual inhertance is provided one instance name and one instance open fuction during the inheritance process
class File {
	public:
		string name_;
		void open() {cout<<"file is open "<<endl;}
};

class InputFile1 : virtual  public File {
        public:
                void read();
};

class OutputFile1 :virtual  public File {
        public:
                void write();
};

// Diamond shape of hierarchy
class IOFile1 : public InputFile1, public OutputFile1 {

};

/** Q :why do we have to use it multiple inheritance?
    A: Interface Segregation principle
    * split large interfaces into smaller and more specific ones so that clients only need to know about the methods taht are of interset to them
*/
int main() {
	cout<<"example 1 : "<<endl;
	IOFile f;
	//f.open(); 
	// when we compile this code, this code give error
	// because compiler don't know which open function want to call
	// state 1 : two open function is public member function
	// state 2 : one open function is private other function still public
	// for two above state compiler give "request for member ‘open’ is ambiguous" error	   // solution
	f.OutputFile::open();
      	
	cout<<"example 2 :" <<endl;
	IOFile1 f1;
	f1.open();	
	return 0;
}
