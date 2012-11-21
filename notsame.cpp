#include <stdio.h>

#include <string>
#include <map>

using namespace std;

string find_largest_not_same(string input){
	string::iterator it;
	map<char,int> last_seen_pos;
	int *result = new int[input.size()];
	int  i = 0;
	int max = 0;	
	int max_pos = 0;
	for(it = input.begin(); it < input.end();++it){
		char c = *it;	

	
		if(i==0){
			result[i] = 1;
		}
		else{
			int last_seen = -1;

			if (last_seen_pos.find(c)!=last_seen_pos.end()){
				last_seen = last_seen_pos[c];
			}

			if( (i-1 - (result[i-1] - 1)) >last_seen){
				result[i] = result[i-1]+1;	
			}
			else{
				result[i] = i - 1 - (last_seen +1)  + 1;
			}
		}

		last_seen_pos[c] = i;
		
		
		if (result[i] > max){
			max = result[i];
			max_pos = i;
		}
		++i;

	}

	return input.substr(max_pos-(max-1),max);
	
}

int main(int argc,char *argv[]){
	printf("%s\n",find_largest_not_same("ababc").c_str());
	return 0;
}
