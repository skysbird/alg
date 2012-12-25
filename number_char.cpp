#include <stdio.h>
#include <string.h>

const char *dict[10] = {
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

const int length[10] = {
	0,0,3,3,3,3,3,4,3,4
};

char result[100];

void words(const char *number,int start){
	int num_length = strlen(number);
	if(start>num_length-1) {
		int i = 0;
		for(i=0;i<start;++i){
			printf("%c",result[i]);
		}
		printf("\n");
		return;
	}
	int i = start;
	int pos = 0;
	for(pos=0;pos< length[number[i]-'0'];++pos){
		result[start] = dict[number[i]-'0'][pos];
		words(number,i+1);
	}
}
int main(int argc,char *argv[]){
	words("26678837",0);
	return 0;
}
