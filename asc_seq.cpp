#include <stdio.h>

int binary_search(int *arr,int s,int e,int v){
	if(s >= e-1){
		if(arr[e] <v) return e;
		if(arr[s] <v) return s;
		return -1;		
	}

	int mid = s+(e-s)/2;
	if(arr[mid] > v){
		return binary_search(arr,s,mid-1,v);
	}
	if(arr[mid] == v){
		return binary_search(arr,mid,e,v);
	}
	if(arr[mid]<v){
		return binary_search(arr,mid,e,v);
	}

	return -1;

}
int find_largest_seq_length(int arr[],int length){
	int i = 0;
	int *list = new int[length];
	int *maxv = new int[length+1];

	maxv[1] = arr[0];
	maxv[0] = -1111111111;
	
	for(i=0;i<length;++i){
		list[i] = 1;
	}
	
	int j = 1;
	int nMax = 1;
	for(i = 1; i < length;++i){
		int j = 0;
		//normal force
		/*for(j = nMax; j>=0; --j){
			if(arr[i] > maxv[j]){
				list[i] = j + 1;
				break;
			}
		}*/
		//the third one in Bianchengzhimei is wrong,like below
		/*for(j = list[i-1]; j>=1; --j){
			if(arr[i] > maxv[j]){
				list[i] = j + 1;
				break;
			}
		}*/		

		//but we can use binary search in maxv,because maxv is asc sorted array
		j = binary_search(maxv,0,nMax,arr[i]);
		if(j!=-1){
			list[i] = j+1;
		}
	
		if(list[i] > nMax){
			nMax = list[i];
			maxv[nMax] = arr[i];
		}
		else{
			if(arr[i] > maxv[j] && arr[i] < maxv[j+1]){
				maxv[j+1] = arr[i];
			}
		}
	}

	return nMax;
	
}
int main(int argc,char *argv[]){
	int arr[] = {1,-1,2,-3,4,-5,6,-7};
	//int maxv[] = {1,3};
	//printf("%d\n",binary_search(maxv,0,1,4));
	printf("%d\n",find_largest_seq_length(arr,8));
	return 0;
}
