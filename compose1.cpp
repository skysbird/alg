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
		return ;
	}
	//for (int i =length-1;i>=0;--i){
		result.push_back(arr[length-1]);
		compose(arr,length-1);
		result.pop_back();
		compose(arr,length-1);
	//}
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
		compose1(arr,i);
		result.pop_back();
		//compose1(arr,i);
	}
	compose1(arr,0);
}

int main(int argc,char *argv[]){
	int arr[] = {1,2,3};
	compose1(arr,3);
	return 0;
}
