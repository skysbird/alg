#include <stdio.h>
#include <string>
#include <stack>
#include <stdlib.h>

using namespace std;

int compute(int a,int b,char c){
	switch(c){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}

int suffix_to_value(string input){
	stack<int> s;	
	string::iterator it;
	int v = 0;
	int a = 0;
	int b = 0;
	for(it = input.begin(); it < input.end(); ++it){
		switch(*it){
			case '+':
			case '-':
			case '*':
			case '/':
				b = s.top();s.pop();
				a = s.top();s.pop();
				v = compute(a,b,*it);
				s.push(v);
				break;
			default:
				s.push(*it-'0');
				break;
		}
	}
	return s.top();

}
string infix_to_suffix(string input){
	string output;
	stack<char> s;	
	string::iterator it;
	for(it = input.begin(); it < input.end(); ++it){
		switch(*it){
			case '+':
			case '-':
				while(!s.empty()){
					char c = s.top();
					if(c=='('){
						break;
					}
					if(c!='('){
						output.append(1,c);
					}
					s.pop();
				}
				s.push(*it);
				break;
			case '*':
			case '/':
				if(!s.empty()){
					char c = s.top();
					if(c!='(' && c!='+' && c!='-'){//优先级低于当前操作符不处理
						output.append(1,c);
						s.pop();
					}
				}
			case '(':
				s.push(*it);		
				break;
			case ')':
				while(!s.empty()){
					char c = s.top();
					s.pop();

					if(c=='('){
						break;
					}
					output.append(1,c);
				}	
				break;
			default:
				output.append(1,*it);
				break;
		}	
	}
	while(!s.empty()){
		output.append(1,s.top());
		s.pop();
	}
	return output;
	
		
}
int main(int argc,char *argv[]){
	string a = infix_to_suffix("3+(2-5)*6/3");
	printf("%s\n",a.c_str());
	printf("%d\n",suffix_to_value(a));

	return 0;
}
