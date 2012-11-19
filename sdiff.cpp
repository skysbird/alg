#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
const int max_length = 1500;
static int c[max_length][max_length];
static int flag[max_length][max_length];	

void print_array(int x,int y){
	int i =0;
	int j =0;
	for(i = 0;i<x;++i){
		for(j=0; j<y;++j){
			printf("%d ",c[i][j]);		
		}
		printf("\n");
	}

	for(i = 0;i<x;++i){
		for(j=0; j<y;++j){
			printf("%d ",flag[i][j]);		
		}
		printf("\n");
	}

}

int str_diff(string a,string b,int k){
	int i =0;
	int j =0;
	int a_length = a.size();
	int b_length = b.size();
	//i,j 表示截至到当前位置的a[i],b[j]中，包含<=k个不同字符的最长子串的长度 
	
	
	int max = 0;
	int result_i = 0;
	int result_j = 0;
	memset(flag,-10000,max_length*max_length*sizeof(int));	
	memset(c,-10000,max_length*max_length*sizeof(int));	

	for(i=0;i<a_length;++i){
		c[i][0]= 0;
		flag[i][0] = k;
		if(a[i]==b[0]){
			c[i][0] = 1;
		}
		else{
			if(flag[i][0]){
				c[i][0]= 1;
				--flag[i][0];
			}
		}

		if(max<=c[i][0]){	
			max = c[i][0];
			result_i = i;
			result_j = 0;
		}

	}


	for(j=0;j<b_length;++j){
		c[0][j] = 0;
		flag[0][j] = k;
		if(a[0]==b[j]){
			c[0][j] = 1;
		}
		else{
			if(flag[0][j]){
				c[0][j]= 1;
				--flag[0][j];
			}
		}

		if(max<c[0][j]){	
			max = c[0][j];
			result_i = 0;
			result_j = j;
		}
		


	}

	
	print_array(a_length,b_length);
	//print_array((int*)flag,a_length,b_length);
	for(i=1;i<a_length;++i){
		for(j=1; j<b_length;++j){
			flag[i][j] = flag[i-1][j-1];
			if(a[i]==b[j]){
				c[i][j] = c[i-1][j-1] + 1;
			}
			else{
				if(flag[i][j]){
					c[i][j] = c[i-1][j-1]+1;
					--flag[i][j];
				}
			}

			if(max<c[i][j]){	
				max = c[i][j];
				result_i = i;
				result_j = j;
			}
		}
	}
	print_array(a_length,b_length);
	//print_array((int*)flag,a_length,b_length);

	printf("max = %d,i = %d, j = %d\n", max,result_i-max+1,result_j-max+1);
	return max;


		
}

#include <vector>

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

int main(int argc,char *argv[]){
	
	//int k = 2;
	int k =2;
	//string a = "abcdef";
	//string b = "fedcba";

	string a = "tabriz";
	string b = "torino";
	printf("%d",str_diff(a,b,k));
	return 0;
	string in;
	getline(cin,in);
	int num_of_cases = atoi(in.c_str());
	vector<string> cases;
	while(num_of_cases--){
		getline(cin,in);
		cases.push_back(in);
	}
	
	vector<string>::iterator it;
	vector<int> outputs;	
	for( it = cases.begin() ; it<cases.end(); ++it){
		string input = *it;
		vector<string> inputs ;
		split(input,inputs," ");
		
		int k = atoi(inputs[0].c_str());
		string a = inputs[1];
		string b = inputs[2];
		outputs.push_back(str_diff(a,b,k));
	}

	vector<int>::iterator oit;
	for ( oit = outputs.begin(); oit < outputs.end(); ++oit){
		cout << *oit <<endl;
	}


	return 0;
}
