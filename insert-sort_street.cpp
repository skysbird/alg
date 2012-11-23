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

int insert_sort(int *data,int length){
	int i = 0;
	int sum = 0;
	for (i = 1; i< length; ++i){
		int j = i - 1;	
		int v = data[i];
		while( j>=0 && v < data[j]){
			data[j+1] = data[j];
			--j;
			++sum;
		}
		data[j+1] = v;
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
		outputs.push_back(insert_sort(arr,n));

	}
	
	for( it = cases.begin() ; it<cases.end(); ++it){
	}

	vector<int>::iterator oit;
	for ( oit = outputs.begin(); oit < outputs.end(); ++oit){
		cout << *oit <<endl;
	}
	return 0;
}
