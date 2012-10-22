#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *a,int p,int q,int r){	
	int *left = (int *)malloc((q-p+1)*sizeof(int));
	int *right = (int *)malloc((r-q)*sizeof(int));
	int length = r - p + 1;
	memcpy(left,a+p,(q-p+1)*sizeof(int));
	memcpy(right,a+q+1,(r-q)*sizeof(int));

	int i = 0;
	int j = 0;
	int k = 0;

	for ( k =0; k< length; ++k){
		if (left[i] < right[j]){
			a[p+k] = left[i];
			++i;
		}
		else{
			a[p+k] = right[j];
			++j;
		}

		if (i>=q-p+1){
			while(j<r-q){
				a[++k+p] = right[j++];
			}
		}
		if (j>=r-q){
			while(i<q-p+1){
				a[++k+p] = left[i++];
			}
			
		}
	}	

}

void print_array(int *a,int size);

void merge_sort(int *a,int p,int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}	
}
void print_array(int *a,int size){
	int i =0;
	for ( i =0; i<size; ++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[]){

	int a[8] = {6,42,1,4,1,2,3,5};
	//print_array(a,8);
	merge_sort(a,0,7);
	//merge(a,2,2,3);
	print_array(a,8);	
	return 0;
}




