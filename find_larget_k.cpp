#include <stdio.h>

//minify the k'th element
void minify(int *heap,int length,int k){
	if(k > length/2 - 1) return;
	int left = 2*k+1;
	int right = 2*k+2;
	int min_index = k;
	if(heap[k] > heap[left]){
		if(right < length && heap[left] > heap[right]){
			min_index = right;
		}
		else{
			min_index = left;
		}
	}
	else if(right<length && heap[k] > heap[right]){
		if(heap[left] > heap[right]){
			min_index = right;
		}
		else{
			min_index = left;
		}
	}

	if( min_index!=k){
		//swap 
		int t = heap[k];
		heap[k] = heap[min_index];
		heap[min_index] = t;

		minify(heap,length,min_index);
	}
}

void init(int *heap,int length){
	int last_inner = length/2 - 1;
	while(last_inner>=0){
		minify(heap,length,last_inner);
		--last_inner;
	}
}
void print_array(int *heap,int length){
	int i = 0;
	for(i=0; i< length;++i){
		printf("%d ",heap[i]);
	}
	printf("\n");
}


int *find_larget(int *arr,int length,int k){
	int *result=new int[k];
	int i = 0;
	for(i=0; i<k;++i){
		result[i] = arr[i];
	}
	init(result,k);

	for(i=k+1;i<length;++i){
		if(arr[i] > result[0]){
			result[0] = arr[i];
			minify(result,k,0);
		}
	}	
	return result;
}
int main(int argc,char *argv[]){
	int heap[5] = {5,4,3,2,1};

	print_array(find_larget(heap,5,4),4);
	return 0;
}
