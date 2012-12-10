#include<iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void print_arr(int *arr,int n){
	int i = 0;
	for(i = 0; i<n;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int times(int n,int k){
	int *seq = new int[n];
	int i = 0;
	//initial help arr
	for ( i = 0; i<n; ++i){
		seq[i] = i;
	}	

	
	int step = n/k;

	int times = 0;
	while(1){
		int start = n - step;
		i = 0;	
		int *seq2 = new int[n];
		while(start < n){
			int pos = start;
			while(pos>=0){
				seq2[i++] = seq[pos];
				pos -= step;
			}
			start = start + 1;
		}
		++times;
		//print_arr(seq2,n);
		if(seq2[0] == 0) break;
		memcpy(seq,seq2,n*sizeof(int));
	}
	return times;
	
}

#include <vector>
#include <cstdlib>

int main(int argc,char *argv[]){
	string in;
	getline(cin,in);
	int num_of_cases = atoi(in.c_str());
	vector<int> outputs;	
	int n = 0;
	int k = 0;
	while(num_of_cases--){
		scanf("%d %d",&n,&k) ;
		outputs.push_back(times(n,k));

	}
	

	vector<int>::iterator oit;
	for ( oit = outputs.begin(); oit < outputs.end(); ++oit){
		cout << *oit <<endl;
	}
	return 0;
}
