#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;

class BSTree{
	public:
		char value;
		struct BSTree *left;
		struct BSTree *right;
		BSTree(){
			this->left = NULL;
			this->right = NULL;
			this->value = 0;
		}

		void add_child(BSTree *node){
			if(this->left==NULL){
				this->left = node;
			}
			else if(this->right == NULL){
				this->right = node;
			}
		}
} ;

void create_tree(string input,BSTree **head){
	stack<BSTree *> stack;

	string::iterator it ;
	BSTree *last = NULL;
	//int k = 0;

	for(it = input.begin(); it<input.end();++it){
		switch(*it){
			case '(':
				//k = 1;
				if(last){
					stack.push(last);
				}
				break;
			case ')':
				stack.pop();
				if(!stack.empty()){
					last = stack.top();
				}
				//k = 2;
				break;
			default:
				BSTree *node = new BSTree();
				node->value = *it;
				if(last){
					stack.top()->add_child(node);
					last = node;
				}
				else{
					last = node;
					*head = last;
				}
				//k = 0;
				break;
		}
	}
	
}

void print_tree(BSTree *T,int level){
	if(T){
		print_tree(T->right,level+1);	
		int i = 0;
		for(i = 0;i<level; ++i){
			printf("  ");
		}
		printf("%c\n",T->value);
		print_tree(T->left,level+1);
	}
}


int main(int argc,char *argv[]){
	BSTree *t = NULL;

	create_tree("a(b(cd)e)",&t);
	
	print_tree(t,0);		
	return 0;
}
