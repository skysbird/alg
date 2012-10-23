#include <stdio.h>

//another partition method
int partition2(int *a,int p,int r){
	int v = a[r];
	int i = p-1;
	int j = p;

	while(j<r){
		if (a[j] < v){
			++ i ;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
		++j;
			
	}

	int temp = a[i+1];
	a[i+1] = v;
	a[r] = temp;
	return i+1;
}
//more effiency
int partition1(int *a,int p,int r){
	int v = a[p];
	int i = p + 1;
	int j = r;
	while(1){
		while ( i <= r && a[i] < v)++i;
		while ( j >= p && a[j] >= v)--j;
		if (i>=j) break;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;	
	}
	
	int temp = a[j];
	a[j] = 	v;
	a[p] = temp;
	return j;
}

//not effiency
int partition(int *a,int p, int r){
	if (p>=r) return r;
	int i = p+1;
	int j = r;	
	
	int v = a[p];

	if ( i == j){
		if (a[j] < v){
			int temp = a[j];
			a[j] = a[p];
			a[p] = temp;
		}
		return i-1;
	}	

	while ( i < j ){
		while( i < j && a[i] < v){
			++i;
		}
		if (i<j){
			if (a[i] >= v){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		while(i<j && a[j] > v){
			--j;
		}

		if (i<j){
			if (a[j] < v){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}
	}	

	int pos = 0;
	if (a[i] > v){
		pos = i - 1;
	}	
	else{
		pos = i;
	}
	int temp = a[pos];
	a[pos] = v;
	a[p] = temp;
	return pos;
	
}

void quick_sort(int *a,int p,int r){
	if (p<r){
		int q = partition2(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
void print_array(int *a,int length){
	int i = 0;
	for ( i = 0; i < length ; ++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[]){
	int a[8] = {6,3,2,4,6,8,3,1};
	quick_sort(a,0,7);
	//int b[3] = {6,3,2};
	//int pos = partition2(b,0,2);
	//printf("%d",pos);
	//print_array(b,3);
	print_array(a,8);
	return 1;
}
