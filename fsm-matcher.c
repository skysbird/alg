#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
*Finite Machine Matcher Preprocess
*/

//character set is a-z
//character mapping function
int charvalue(char c){
	return c-'a';
}

//check a is b suffix
int is_suffix(char *a, char *b,int length_a,int length_b){
	if (length_a > length_b){
		return 0;
	}
	int i = length_a-1;
	int j = length_b-1;
	
	while(i>=0 && a[i] == b[j]){
		--i;
		--j;	
	}

	return i<0;
	
}
//transform result array
int *transform;

void print_arrayv(int *transform,int x,int y);

//preprocess the transform function
void preprocess(char *p, char *charset){	
	int m = strlen(p)+1;
	int e = strlen(charset);	
	transform = (int *)malloc(sizeof(int)*m*e);
	
	int q = 0;
	int length = 0;
	char pqa[m];
	int i = 0;
	for (q = 0; q < m; ++q){
		length = q+1;
		memcpy(pqa,p,q);
		for( i = 0; i < e; ++i){
			pqa[length-1]=charset[i];
			int k = length;
			while(k>0 && !is_suffix(p,pqa,k,length)){
				--k;	
			}
			*(transform+q*e+charvalue(charset[i])) = k ;
		}
		
	}

	print_arrayv(transform,m,e);
}

/*fsm-matcher
* find p in t first place
*/
int fsm_matcher(char *t, char *p,char *charset){
	preprocess(p,charset);
	int m = strlen(p) + 1;
	int e = strlen(charset);
	int length_t = strlen(t);	
	int i = 0;
	int q = 0;
	for ( i=0 ; i<length_t; ++i){
		q = transform[q*e+charvalue(t[i])];	
		if (q==m-1){
			return i - m +2;
		}
	}
	return -1;

}
void print_arrayv(int *transform,int x,int y){
	int i = 0;
	int j = 0;
	for(i=0; i < x ; ++i){
		for(j=0; j<y; ++j){
			printf("%d ",*(transform+i*y+j));
		}
		printf("\n");
	}
	
}

int main(int argc,char *argv[]){
	char *charset="abcdefghijklmnopqrstuvwxyz";
	int pos = fsm_matcher("asdfaabcdeabcdefg","abcde",charset);
	printf("result is %d\n",pos);
	return 0;
}
