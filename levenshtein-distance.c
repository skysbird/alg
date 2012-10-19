#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//return the smallest a,b,c 
inline int min(int a,int b,int c){
	if (a<b){
		if (a<c){
			return a;
		}
		else{
			return c;
		}
	}

	else{
		if(b<c){
			return b;
		}
		else{
			return c;
		}
	}
}

void print_array(int *c,int x, int y);
/*
* compute t to p disntance, result in c
*/
int compute_distance(char *t,char *p){
	//distiance count array, 2 dimension i,j
	int *c;
	int length_t = strlen(t);
	int length_p = strlen(p);
	c = (int *)malloc((length_t + 1)*(length_p+1)*sizeof(int));
	
	int i,j;
	//initial c status
	for (i=0; i<length_t+1; ++i){
		c[i*(length_p+1)+0] = i;
	}

	for (j=0; j<length_p+1; ++j){
		c[0*(length_p+1)+j] = j;
	}

	int temp = 0;
	for (i=1; i<length_t+1; ++i){
		for(j=1; j<length_p+1; ++j){
			if (t[i-1] == p[j-1]){//FIXME:maybe something wrong here, but haven't found a bad case
				c[i*(length_p+1)+j] = c[(i-1)*(length_p+1)+j-1]+0;
			}
			else{
				c[i*(length_p+1)+j] = min(c[(i-1)*(length_p+1)+j]+1,c[i*(length_p+1)+j-1]+1,c[(i-1)*(length_p+1)+j-1]+1);
			}
		}
	}
	print_array(c,length_t+1,length_p+1);
	return c[length_t*(length_p+1)+length_p];
}

//maybe this one is more correct
int compute_distance2(char *t,char *p){
	//distiance count array, 2 dimension i,j
	int *c;
	int length_t = strlen(t);
	int length_p = strlen(p);
	c = (int *)malloc((length_t + 1)*(length_p+1)*sizeof(int));
	
	int i,j;
	//initial c status
	for (i=0; i<length_t+1; ++i){
		c[i*(length_p+1)+0] = i;
	}

	for (j=0; j<length_p+1; ++j){
		c[0*(length_p+1)+j] = j;
	}

	int temp = 0;
	for (i=1; i<length_t+1; ++i){
		for(j=1; j<length_p+1; ++j){
			temp = t[i-1] == p[j-1]?0:1;
				c[i*(length_p+1)+j] = min(c[(i-1)*(length_p+1)+j]+1,c[i*(length_p+1)+j-1]+1,c[(i-1)*(length_p+1)+j-1]+temp);
		}
	}
	print_array(c,length_t+1,length_p+1);
	return c[length_t*(length_p+1)+length_p];
}

void print_array(int *c,int x,int y){
	int i,j;
	for (i=0;i<x;++i){
		for(j=0;j<y;++j){
			printf("%d ",c[i*y+j]);
		}
		printf("\n");
	}
}

int p;
int main(int argc,char *argv[]){
	char *p = "a";
	char *s = "abc";
	int r = compute_distance(s,p);
	printf("result is %d\n",r);

	int r1 = compute_distance(s,p);
	printf("result is %d\n",r1);

	return 0;
}
