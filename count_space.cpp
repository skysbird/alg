#include <stdio.h>
#include <string>

using namespace std;

int count_space(string input){
	int i =0;
	char old = ' ';
	while(input[i]==' ') ++i;
	if (i==input.size()) return 1;	
	
	int result = 0;
	for(i = 0; i<input.size(); ++i){
		if (old==' ' && input[i]!=' ' ){
			++result;
		}
		old = input[i];
	}

	return result;
	
	
}
int main(int argc,char *argv[]){
	printf("%d\n",count_space("what's fuck fuckthing fuck you suck coding "));
	return 0;
}
