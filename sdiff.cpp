#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
const int max_length = 1500;
static int c[max_length][max_length];

#include <queue>

class record{
	public:
		int left_diff;
		queue<int> diff_pos;	
		record(){
			left_diff = 0;
		}
};


void print_array(int x,int y){
	int i =0;
	int j =0;
	for(i = 0;i<x;++i){
		for(j=0; j<y;++j){
			printf("%d ",c[i][j]);		
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
	memset(c,0,max_length*max_length*sizeof(int));	

	/*for(i=0;i<a_length;++i){
		c[i][0]= 0;
		int left_diff = k;
		if(a[i]==b[0]){
			c[i][0] = 1;
		}
		else{
			if(left_diff){
				c[i][0]= 1;
				--left_diff;
			}
			crec[i][0].diff_pos.push(i);
		}
		crec[i][0].left_diff = left_diff;

		if(max<=c[i][0]){	
			max = c[i][0];
			result_i = i;
			result_j = 0;
		}

	}


	for(j=0;j<b_length;++j){
		c[0][j] = 0;
		int left_diff = k;
		if(a[0]==b[j]){
			c[0][j] = 1;
		}
		else{
			if(left_diff){
				c[0][j]= 1;
				--left_diff;
			}
			crec[0][j].diff_pos.push(0);
		}

		crec[0][j].left_diff = left_diff;

		if(max<c[0][j]){	
			max = c[0][j];
			result_i = 0;
			result_j = j;
		}
		


	}

	*/
	//print_array(a_length,b_length);
	//print_array((int*)flag,a_length,b_length);
		
		for(i=0; i<a_length;++i){
			int ii = i;
			int jj = 0; 
			record last;
			last.left_diff = k;
			while(ii<a_length && jj<b_length){

				if(a[ii]==b[jj]){
					if(ii==0||jj==0){
						c[ii][jj] = 1;
					}
					else{
						c[ii][jj] = c[ii-1][jj-1] + 1;
					}
				}
				else{
					if(last.left_diff){
						if(ii==0||jj==0){
							c[ii][jj] = 1;
						}
						else{
							c[ii][jj] = c[ii-1][jj-1] + 1;
						}
						--last.left_diff;
					}
					else{
						if(k>0){
							int first_diff_pos = last.diff_pos.front();
							c[ii][jj] = ii - first_diff_pos;
							last.diff_pos.pop();
						}
					}
					last.diff_pos.push(ii);
				}

				if(max<c[ii][jj]){	
					max = c[ii][jj];
					result_i = ii;
					result_j = jj;
				}
				++ii;
				++jj;
			}
			


		}

		for(j=0; j<b_length;++j){
			int ii = 0;
			int jj = j;
			record last;
			last.left_diff = k;
			while(ii<a_length && jj<b_length){

				if(a[ii]==b[jj]){
					if(ii==0||jj==0){
						c[ii][jj] = 1;
					}
					else{
						c[ii][jj] = c[ii-1][jj-1] + 1;
					}
				}
				else{
					if(last.left_diff){
						if(ii==0||jj==0){
							c[ii][jj] = 1;
						}
						else{
							c[ii][jj] = c[ii-1][jj-1] + 1;
						}
						--last.left_diff;
					}
					else{
						if(k>0){
							int first_diff_pos = last.diff_pos.front();
							c[ii][jj] = ii - first_diff_pos;
							last.diff_pos.pop();
						}
					}
					last.diff_pos.push(ii);

				}

				if(max<c[ii][jj]){	
					max = c[ii][jj];
					result_i = ii;
					result_j = jj;
				}


				++ii;
				++jj;
			}
			


		}
	//print_array(a_length,b_length);
	//print_array((int*)flag,a_length,b_length);

	//printf("max = %d,ii = %d, jj = %d\n", max,result_i,result_j);
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
	//int k =2;
	//string a = "abcdef";
	//string b = "fedcba";

	//string a = "tabriz";
	//string b = "torino";
	//int k = 0;
	//string a = "abacba";
	//string b ="abcaba";
	//printf("%d",str_diff(a,b,k));
	//return 0;
	//int k =1;
	//string a = "abcdef";
	//string b = "fedcba";
	//int k = 1;
	//string a = "atabtt";
	//string b = "btactt";
	//printf("%d\n",sizeof(record));
	//int k =2;
	//string a = "aaaattt";
	//string b = "babbttt";
	
	//printf("%d",str_diff(a,b,k));
	//return 0;
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
