#include <stdio.h>

void swap(int a[],int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//permutation
void permutation(int result[],int a[],int length,int j,int cut_length){
	
	if (cut_length==j){
		int i = 0;
		for(i =0;i<cut_length;++i){
			printf("%d ",result[i]);
		}
		printf("\n");
		return;
	}

	if (length==0){
		int i = 0;
		for(i =0;i<j;++i){
			printf("%d ",result[i]);
		}
		printf("\n");
		return;
	}
	int i = 0;
	for(i =0;i<length;++i){
		swap(a,0,i);
		permutation(result,a+1,length-1,j+1,cut_length);
		swap(a,0,i);

	}
}


//permutation with character count
void start_permutation(int result[],int total_length){
	int i =0;
	for(i=0; i<=total_length;++i){
		permutation(result,result,total_length,0,i);
	}
}


/*void permutation(int result[],int a[],int length,int j){
	if (length==0){
		int i = 0;
		for(i =0;i<j;++i){
			printf("%d ",result[i]);
		}
		printf("\n");
		return;
	}
	int i = 0;
	for(i =0;i<length;++i){
		swap(a,0,i);
		permutation(result,a+1,length-1,j+1);
		swap(a,0,i);

	}
}*/


//permutation2 with character count
/*void permutation2(int result[],int a[],int length,int j,int total_length){
	int i = 0;
	int q = 0;
	
	for (q = 1;q<=total_length; ++q){

	}
}*/


int main(){
	int a[] = {1,2,3};
	start_permutation(a,3);	
	//permutation2(a,a,3,0,3);
}
