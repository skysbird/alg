#include <stdio.h>


//maxify heap for node i
void maxify_heap(int *heap,int i,int heapsize){
	int left = i*2+1;
	int right = left + 1;	
	int k = i;
	if (left <  heapsize ){
		if (heap[left] > heap[i]){
			k = left;
		}
		if (right < heapsize && heap[right] > heap[k]){
			k = right;
		}
		
		if ( i!=k){
			int temp = heap[i];
			heap[i] = heap[k];
			heap[k] = temp;
			maxify_heap(heap,k,heapsize);
		}
		
	}
	
}

void maxify_sort(int *heap,int heapsize){
	int inner_i = heapsize / 2 - 1;
	
	while ( inner_i >=0){
		maxify_heap(heap,inner_i--,heapsize);
	}	
	if (heapsize>0){
		//change the max node to n
		int temp = heap[0];
		heap[0] = heap[heapsize-1];
		heap[heapsize-1] = temp;
		maxify_sort(heap,heapsize-1);
	}
}

void print_array(int *heap,int heapsize){
	int i = 0;
	for(i = 0; i < heapsize; ++i){
		printf("%d ",heap[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[]){
	int a[10] = {5,2,3,1,6,7,23,1,2};
	maxify_sort(a,10);
	//maxify_heap(a,1,4);
	print_array(a,10);
	return 0;
}
