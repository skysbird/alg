#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
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

int insert_sort_stat(int *data,int length){
	int i = 0;
	int j = 0 ;
	int sum = 0;
	for (i = 0; i< length; ++i){
		for ( j = i+1;j<length;++j){
			if (data[i] > data[j]) ++sum;
		}
	}
	return sum;
}

void print_array(int *p,int length){
	int i = 0;
	for (i = 0; i < length; ++i){
		printf("%d ",p[i]);
	}
	printf("\n");
}
static int arr[100000];
int main(int argc,char *argv[]){
	string in;
	getline(cin,in);
	int num_of_cases = atoi(in.c_str());
	vector<int> outputs;	
	int n = 0;
	int i = 0;
	while(num_of_cases--){
		scanf("%d",&n) ;
	        for(i = 0;i < n;i++) scanf("%d",&arr[i]) ;
		
		//int k = atoi(inputs[0].c_str());
		//string a = inputs[1];
		//string b = inputs[2];
		outputs.push_back(insert_sort_stat(arr,n));

	}
	

	vector<int>::iterator oit;
	for ( oit = outputs.begin(); oit < outputs.end(); ++oit){
		cout << *oit <<endl;
	}
	return 0;
}
