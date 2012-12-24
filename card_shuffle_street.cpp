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
	int *seq2 = new int[n];
	while(1){
		int start = n - step;
		i = 0;	
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

#include <set>

set<int> temp_pos;

int times2(int n,int k){
	int step = n/k;
	int times = 0;
	int start = n - step;
	int pos0 = 0;
	
	//temp_pos.insert(pos0);
	int t = 0;	
	int i = 0;
	
	do{
		i = start;
		t = 0;
		//while(1){

			int m = (i - pos0)%step;
			if (m!=0){	
				if(i < pos0){
					t = pos0 - i;
					i = pos0;

				}
				else{
					int need = ((i - pos0)/step +1)*step - (i-pos0);
					t = need;
					i += need;
				}
			}
		//	else{
		//		break;
		//	}
		//}

		pos0 = k*t + (i-pos0)/step;
		//if(temp_pos.count(pos0) && pos0!=0) return -1;
		times++;	
	}while(pos0!=0);

	return times;
	
}
#include <math.h>

int times3(int n,int k){
	int step = n/k;
	int times = 1;
	while(1){
		if(int(pow(k,times)) %(n+1) == 1){
			break;
		}
		times++;
	}

	return times;
	
}

#include <vector>
#include <cstdlib>

int main(int argc,char *argv[]){
	/*int nn = 1000000000;
	int kk = nn;

	while(nn>=2){
		kk = nn;
		while(kk>=2){
			if(nn%kk==0){
				printf("n=%d,k=%d\n",nn,kk);
				printf("%d\n",times2(nn,kk));
			}
			--kk;
		}
		--nn;
	}
	
	return 0;*/
	string in;
	getline(cin,in);
	int num_of_cases = atoi(in.c_str());
	vector<int> outputs;	
	int n = 0;
	int k = 0;
	while(num_of_cases--){
		scanf("%d %d",&n,&k) ;
		outputs.push_back(times3(n,k));

	}
	

	vector<int>::iterator oit;
	for ( oit = outputs.begin(); oit < outputs.end(); ++oit){
		cout << *oit <<endl;
	}
	return 0;
}
