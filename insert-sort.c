#include <stdio.h>


void insert_sort(int *p,int length ){
	int j = 1;
	int v = 0;
	for( j = 1; j< length; ++j){
		v = p[j];
		while(j>0 && v < p[j-1]){
			p[j] = p[j-1];
			--j;
		}
		p[j] = v;
	}
}

void print_array(int *p,int length){
	int i = 0;
	for (i = 0; i < length; ++i){
		printf("%d ",p[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[]){
	int p[6] = {5,2,4,6,1,2};
	print_array(p,6);
	insert_sort(p,6);
	print_array(p,6);
	return 0;
}
