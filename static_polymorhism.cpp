/************ Static POlymorhism *****************/
#include <iostream>

/*******Dynamic polymorhism ******/
/*
* Polymorhism is not for free, it becomes with a small price to pay. 
* the price is number one the memory cost of the virtual table and number
* two the runtime cost of the dynamic binding. basically the code that creates
* and uses the virtual table. what if my profiler tells me that is a critical 
* part of my algorithm and and it needs tu run as fast and I don't want to give up
* on the benefit of polymorhism. What can I do? 
*/

struct TreeNode { 
	TreeNode* left;
	TreeNode* right;};

class Generic_Parser {
	public:
		void parse_preoder( TreeNode* node) {
			if(node) {
				process_node(node);
				parse_preoder(node->left);
				parse_preoder(node->right);
			}
		}
	private:
		virtual void process_node(TreeNode* node){}
};

class EmployeeChart_Parser : public Generic_Parser {
	private:
		void process_node(TreeNode* node) {
			std::cout<<"Customized process_node() for EmployeeChart. \n";
		}
};

/***** Static Polymorhism ******/
/*basic simulation
 * 1. is-a relationship between base class and derived class
 * 2. base class defines a generic algorithm that's used by derived class
 * 3. the generic algorithm is customized by the derived class
*/
template <typename T>
class Generic_Parser1 {
        public:
                void parse_preoder( TreeNode* node) {
                        if(node) {
                                process_node(node);
                                parse_preoder(node->left);
                                parse_preoder(node->right);
                        }
                }
	void process_node(TreeNode* node){
		static_cast<T*>(this)->process_node(node);
	}

};

class EmployeeChart_Parser1 : public Generic_Parser1<EmployeeChart_Parser1> {
        public:
                void process_node(TreeNode* node) {
                        std::cout<<"Customized process_node() for EmployeeChart. \n";
                }
};


int main() {
	//dynamic polymorhism
	/*std::cout<<"\n dynamic polymorhism\n";
	TreeNode root;
	EmployeeChart_Parser ep;
	ep.parse_preoder(&root);*/
	
	//static polymorhism
	std::cout<<"\n static polymorhism\n";
	TreeNode root1;
        EmployeeChart_Parser1 ep1;
        ep1.parse_preoder(&root1);
	return 0;
}
