#include <stdio.h>


int result[100];

void print_result(int j){
	int i = 0;
	for(i = 0;i<j;++i){
		printf("%d ",result[i]);
	}
	printf("\n");
}
void compute(int d, int a[],int length,int j){
	if(d==0) {
		print_result(j);
		return;
	}
	if(length && d < a[0]) return;
	int i =0;
	for(i=0;i<length;++i){
		result[j++] = a[i];
		compute(d-a[i],a+i+1,length-1,j);
		j--;
	}
		
}
int main(int argc,char *argv[]){
	int a[] = {1,2,3,4,5,6,7};
	compute(20,a,7,0);
	return 1;
}


