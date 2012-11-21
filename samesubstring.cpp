#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//dummy way maybe o(n^2)

int comp(string input,int i,int j){
	int len = 0;
	while(j<input.size() && input[i]==input[j]){
		++i;++j;++len;
	}
	return len;
}

string find_same_substring(string input){
	int i = 0;
	int j =0;
	int max = 0;
	int max_i = 0;
	int max_j = 0;
	for (i=0;i<input.size();++i){
		for(j = i+1; j < input.size(); ++j){
			int r = comp(input,i,j);
			if(max < r){
				max = r;
				max_i = i;
				max_j = j;
			}	
		}
	}
	
	return input.substr(max_i,max);

}


//suffix array
int comp2(string input1,string input2){
	int i = 0;
	int j = 0;
	int len = 0;
	while(i < input1.size() && j < input2.size() && input1[i] == input2[j]){
		++i;++j;++len;
	}
	return len;
}

string find_same_substring2(string input){
	int i =0;
	vector<string> suffix;
	for(i = 0; i<input.size();++i){
		suffix.push_back(input.substr(i));
	}

	sort(suffix.begin(),suffix.end());	
	int max = 0;
	int result = 0;
	for (i=0; i<suffix.size();++i){
		if(i+1<suffix.size()){
			 
			 int r  = comp2(suffix[i],suffix[i+1]);
			 if (max < r){
				max = r;
				result = i;
			}
	
		}
	}

	return suffix[result].substr(0,max);
}
int main(int argc,char *argv[]){

	printf("%s\n", find_same_substring("abcabcaabcde").c_str());
	printf("%s\n", find_same_substring2("abcabcaabcde").c_str());
	return 0;
}
