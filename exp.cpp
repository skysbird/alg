#include <stdio.h>
#include <string>
#include <stack>

using namespace std;


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
	printf("%s",a.c_str());
	return 0;
}
