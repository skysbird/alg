#include <stdio.h>
#include <string.h>

char **split(const char *str,char split,int &size){
	
	char c;
	int length = strlen(str);
	char *temp = new char[length];
	int  temp_start = 0;
	int i = 0;

	size = 0;
	char **result = new char *[length];
	while(c = str[i++]){
		if(c!=split){
			temp[temp_start++] = c;				
		}
		if(c==split || i==length){
			//find a word
			if(i-2>=0 && str[i-2]!=split){
				temp[temp_start] = '\0';
				//add to result
				result[size] = new char[temp_start+1];
				strcpy(result[size],temp);
				++size;
				temp_start = 0;
			}
			
		}
	}	
	return result;
}

char **split2(const char *str,char split,int &size){
	
	char c;
	int length = strlen(str);
	char *temp = new char[length];
	int  temp_start = 0;
	int i = 0;

	size = 0;
	char **result = new char *[length];
	while(c = str[i]){
		if(c!=split){
			temp_start = 0;
			while(c && c!=split){
				temp[temp_start++] = c;				
				c = str[++i];
			}
			temp[temp_start] = '\0';
			result[size] = new char[temp_start+1];
			strcpy(result[size],temp);
			++size;
		}
		else{
			++i;
		}
	}	
	return result;
}
int main(int argc,char *argv[]){
	int size = 0;
	char **result = split2("  new     and delete cannot resize, because they allocate just enough memory to hold an object of the given type. The size of a given type will never change. There are new[] and delete[] but there's hardly ever a reason to use them.   ",' ',size);

	printf("%d\n",size);

	int i = 0;
	for(i=0; i<size;++i){
		printf("%s\n",result[i]);
	}

}
