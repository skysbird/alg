#include <stdio.h>

//low effiency
int find_sub(int a[],int length){
	int i = 0;
	int j = 0;
	int c[length][length];
	int max_sum = -10000;
	int result_i = 0;
	int result_j = 0;
	for ( i = 0; i<length; ++i){
		c[i][i] = a[i];
		if (c[i][i] > max_sum ){
			result_i = i;
			result_j = i;
			max_sum = c[i][i];
		}
	}	
	
	for( i = 0; i<length; ++i){
		for (j=i+1;j<length; ++j){
			c[i][j] = c[i][j-1] + a[j];
			if (c[i][j] > max_sum ){
				result_i = i;
				result_j = j;
				max_sum = c[i][j];
			}
		}
	}

	for ( i = result_i; i<=result_j; ++i){
		printf("%d ",a[i]);
	}

	
}

//DP O(n)
find_sub2(int a[],int length){
	int i = 0;
	int max_sum = -10000;
	int result_i = 0;
	int result_j = 0;
	int c[length];
	c[0] = a[i];
	
	for( i = 1; i<length; ++i){
		if (a[i] > c[i-1]+a[i]){
			result_i = i;
			result_j = i;
			max_sum = c[i];
		}
		else{
			max_sum = c[i-1] + a[i];
			result_j = i-1;
		}
	}

	for ( i = result_i; i<=result_j; ++i){
		printf("%d ",a[i]);
	}
	
}
int main(int argc,char *argv[]){
	int a[] = {-2,3,-1,3,-4};
	find_sub2(a,5);
	return 1;
}
