#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;
int split(const string& str, vector<string>& ret_, string sep = ",")
{
    if (str.empty())
    {
        return 0;
    }

    string tmp;
    string::size_type pos_begin = str.find_first_not_of(sep);
    string::size_type comma_pos = 0;

    while (pos_begin != string::npos)
    {
        comma_pos = str.find(sep, pos_begin);
        if (comma_pos != string::npos)
        {
            tmp = str.substr(pos_begin, comma_pos - pos_begin);
            pos_begin = comma_pos + sep.length();
        }
        else
        {
            tmp = str.substr(pos_begin);
            pos_begin = comma_pos;
        }

        if (!tmp.empty())
        {
            ret_.push_back(tmp);
            tmp.clear();
        }
    }
    return 0;
}


int merge_sort(int *data,int p,int q){
	int result = 0;
	if( p < q){

	int r = (p+q)/2;
	int l_length = merge_sort(data,p,r);
	int r_length = merge_sort(data,r+1,q);

	int i = 0;
	int j = 0;	
	
	int merge_length = 0;
	int *larray = new int[r-p+1];
	int *rarray = new int[q-r];
	memcpy(larray,data+p,sizeof(int)*(r-p+1));
	memcpy(rarray,data+r+1,sizeof(int)*(q-r));
	
	int k = p;
	while(1){
		if(larray[i] >rarray[j]){
			data[k] = rarray[j];
			merge_length += r-p+1 - i;
			++j;
			
		}
		else{
			data[k] = larray[i];
			++i;
		}
		++k;
		if(i>=r-p+1) break;
		if(j>=q-r) break;

	}
	
	while(i<r-p+1){
		data[k++] = larray[i];
		++i;
	}

	while(j<q-r){
		data[k++] = rarray[j];
		++j;
	}

	result = l_length + r_length + merge_length;

	delete []larray;
	delete []rarray;
	}

	return result;
	
}

int merge(int *a, int low, int mid, int high)  
{  
    int n1 = mid-low+1;  
    int n2 = high-mid;  
    int *tmp1 = new int[n1];
    int *tmp2 = new int[n2];
    int i, j, k;  
    for(i=0; i<n1; i++)  
        tmp1[i] = a[low+i];  
    for(i=0; i<n2; i++)  
        tmp2[i] = a[mid+i+1];  
    k = low;  
    int cross_inversion = 0;  
    for(i=0, j=0; i<n1 && j<n2;)  
    {  
        if(tmp1[i]<=tmp2[j])  
            a[k++] = tmp1[i++];  
        else  
        {  
            //从i到n1-1，所以是n1-1-i+1 = n1-i个逆序对  
            a[k++] = tmp2[j++];  
            cross_inversion += (n1-i);  
        }  
    }  
    while(i<n1)  
        a[k++] = tmp1[i++];  
    while(j<n2)  
        a[k++] = tmp2[j++];  
    delete tmp1;  
    delete tmp2;  
    return cross_inversion;  
}  
int count_inversions(int *a, int low, int high)  
{  
    int inversions = 0;  
    if(low < high)  
    {  
        int mid = (low+high)/2;  
        inversions += count_inversions(a, low, mid);  
        inversions += count_inversions(a, mid+1, high);  
        inversions += merge(a, low, mid, high);  
    }  
    return inversions;  
} 


int insert_sort(int *data,int length){
	return merge_sort(data,0,length-1);
}

void print_array(int *p,int length){
	int i = 0;
	for (i = 0; i < length; ++i){
		printf("%d ",p[i]);
	}
	printf("\n");
}
int main(int argc,char *argv[]){
	string in;
	getline(cin,in);
	int num_of_cases = atoi(in.c_str());
	vector<string> cases;
	vector<string>::iterator it;
	vector<int> outputs;	
	while(num_of_cases--){
		getline(cin,in);
		int n = atoi(in.c_str());
		getline(cin,in);
		vector<string> inputs ;
		split(in,inputs," ");
		
		int *arr = new int[n];
		int i = 0;
		for(i = 0 ; i<n; ++i){
			arr[i] = atoi(inputs[i].c_str());
		}
		//int k = atoi(inputs[0].c_str());
		//string a = inputs[1];
		//string b = inputs[2];
		//outputs.push_back(insert_sort(arr,n));
		outputs.push_back(count_inversions(arr,0,n-1));

	}
	
	for( it = cases.begin() ; it<cases.end(); ++it){
	}

	vector<int>::iterator oit;
	for ( oit = outputs.begin(); oit < outputs.end(); ++oit){
		cout << *oit <<endl;
	}
	return 0;
}
