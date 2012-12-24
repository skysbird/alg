#include <stdio.h>


int search1(int *arr,int s,int e,int v){
	if(s>=e) return s;
	int m = s+(e-s)/2;
	if(arr[m]==v){
		return m;
	}
	else if(arr[m]<v){
		return search1(arr,m+1,e,v);
	}
	else{
		return search1(arr,s,m-1,v);	
	}
	return -1;	
}


int search2(int *arr,int s,int e,int v){
	if(s>=e) 
	{
		if(arr[s]==v)
			return s;
		else
			return -1;
	}
	int m = s+(e-s)/2;
	if(arr[m]<v){
		return search2(arr,m+1,e,v);
	}
	else{
		return search2(arr,s,m,v);	
	}
	return -1;	
}

int search3(int *arr,int s,int e,int v){
	if(s>=e-1) 
	{
		if(arr[e]==v)
			return e;
		else if(arr[s]==v)
			return s;
		else
			return -1;
	}
	int m = s+(e-s)/2;
	if(arr[m]<=v){
		return search3(arr,m,e,v);
	}
	else{
		return search3(arr,s,m-1,v);	
	}
	return -1;	
}

int search4(int *arr,int s,int e,int v){
	if(s>=e-1) 
	{
		if(arr[e]<v)
			return e;
		else if(arr[s]<v)
			return s;
		else
			return -1;
	}
	int m = s+(e-s)/2;
	if(arr[m]==v){
		return search4(arr,s,m-1,v);
	}
	else if(arr[m]<v){
		return search4(arr,m,e,v);
	}
	else if(arr[m]>v){
		return search4(arr,s,m-1,v);	
	}
	return -1;	
}

int search5(int *arr,int s,int e,int v){
	if(s>=e-1) 
	{
		if(arr[s]>v)
			return s;
		else if(arr[e]>v)
			return e;
		else
			return -1;
	}
	int m = s+(e-s)/2;
	if(arr[m]==v){
		return search5(arr,m+1,e,v);
	}
	else if(arr[m]<v){
		return search5(arr,m+1,e,v);
	}
	else if(arr[m]>v){
		return search5(arr,s,m,v);	
	}
	return -1;	
}

int main(int argc,char *argv[]){
	int arr[] = {1,2,2,3,4,4};
	printf("%d\n",search1(arr,0,5,2));
	printf("%d\n",search2(arr,0,5,2));
	printf("%d\n",search3(arr,0,5,2));
	printf("%d\n",search2(arr,0,5,4));
	printf("%d\n",search3(arr,0,5,4));
	printf("%d\n",search4(arr,0,5,3));
	printf("%d\n",search5(arr,0,5,4));
	return 0;
}
