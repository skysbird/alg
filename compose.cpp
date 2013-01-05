#include <stdio.h>
#include <vector>

using namespace std;

vector<int> result;
void compose(int *arr,int length){
	if(length==0){
		for(int i=0;i<result.size();++i){
			printf("%d ",result[i]);
		}
		printf("\n");
		return;
	}
	for (int i =length-1;i>=0;--i){
		result.push_back(arr[i]);
		compose(arr,i);
		result.pop_back();
		//compose(arr,i);
	}
}

void compose1(int *arr,int length){
	if(length==0){
		for(int i=0;i<result.size();++i){
			printf("%d ",result[i]);
		}
		printf("\n");
		return ;
	}
	for (int i =length-1;i>=0;--i){
		result.push_back(arr[i]);
		compose(arr,i);
		result.pop_back();
		//compose(arr,i);
	}
}

int main(int argc,char *argv[]){
	int arr[] = {1,2,3};
	compose(arr,3);
	return 0;
}
