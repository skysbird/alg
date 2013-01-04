#include <stdio.h>
using namespace std;

void swap(int i,int j,int *arr){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void sum(int *arr,int s,int n,int length,int *result){
	int j = length - 1;
	if(n==0 && s==0){
		//find it
		for(int ri=0;ri<5;++ri){
			if(result[ri]){
				//printf("%d ",result[ri]);
				printf("%d ",arr[ri]);
			}
		}
		printf("fuck\n");
		return;
	}
	else if(s==0){
		return ;
	}
	while(j>=0){
		if(arr[j] > s || result[j]){
			--j;
			continue;
		}
		else{
			result[j] = 1;
			sum(arr,s-arr[j],n-1,j+1,result); //select j ele
			//sum(arr,s,n,length-1); //not select j ele
			result[j] = 0;


		}
		--j;
	}	
}
#include <string.h>

int main(int argc,char *argv[]){
	int arr[] = {1,2,3,4,5};
	int result[5];
	memset(result,0,sizeof(int)*5);
	sum(arr,6,3,5,result);
	return 0;
}
