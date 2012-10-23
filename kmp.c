#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *pi,int size);

void compute_pi(int *pi,char *p){
	int k = 0;
	pi[1] = 0;
	int q = 2;
	int m = strlen(p);
	for(q = 2; q <= m; ++q){
		while( k > 0 && p[k] != p[q-1]){
			k = pi[k+1];	
		}

		if (p[k] == p[q-1]){
			k = k + 1;
		}

		pi[q] = k;
		
	}
	print_array(pi,m);
}

void kmp(char *t,char *p){
	int *pi;
	int m = strlen(p);
	pi = (int *)malloc(m*sizeof(int));	
	compute_pi(pi,p);
	
	int i = 0;
	int q = pi[1];
	int length_t = strlen(t);
	int length_p = m;
	
	for (i=0; i < length_t; ++i){
		while ( q > 0 && t[i] != p[q]){
			q = pi[q];
		}	
		if (t[i] == p[q]){
			q = q + 1;
		}
		if (q == length_p){
			printf("result is %d\n",(i-(length_p-1)));
			q = pi[q];
		}
	}
}
void print_array(int *pi,int size){
	int i = 0;
	for (i=1;i<=size;++i){
		printf("%d ",pi[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[]){
	kmp("abcdabg","ab");
	return 1;
}
