#include <stdio.h>

int search(int a[],int length,int i,int j,int value){
	if(i>j){
		return -1;	
	}
	else{
		int pos = (i+j)/2;
		int low = 0;
		int high = 0;
		if (a[pos] == value){
			return pos;
		}
		else if(a[pos] < value){
			//should be in left but need more check
			low = pos+1;
			high = j;
			if(a[low]<value){
				low = i;
				high = pos - 1;
			}
			}

		else{
			low = i;
			high = pos - 1;
			if(a[low]>value){
				low = pos+1;
				high = j;
			}
		}
		search(a,length,low,high,value);

	}
}
int main(int argc, char*argv[]){

	int a[] = {4,5,6,1,2,3};
	printf("%d",search(a,6,0,5,2));
}
//4，5，6，1，2，3

