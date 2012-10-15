#include "stdio.h"
#include "string.h"
/**
*naive substring matcher 
*@return the first place of substr in str
*/
int naive_matcher(char *str, char *substr){
	int str_length = strlen(str);
	int substr_length = strlen(substr);
	int i = 0;
	int j = 0;
	for (i = 0 ; i<str_length; ++i){
		for ( j=0; j < substr_length; ++j){
			if (str[i+j]!=substr[j]){
				break;
			}
			else if (j==substr_length-1){
				return i;
			}
		}
	}
	return -1;
}


int main(int argc,char *argv[]){
	int pos = naive_matcher("abcdefg","efg");
	printf("%d",pos);
	return 0;
}
