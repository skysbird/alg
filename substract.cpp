#include <string.h>
#include <stdio.h>
#include <map>
#include <string>
#include <set>

using namespace std;

struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return strcmp(a, b) < 0;
   }
};

char *get_word(const char *str,int length,int &from);

int find_min_substract(const char *str,int length){
	map<char *,int,cmp_str> word_count;
	set<char *,cmp_str> dict;
	dict.insert("la");
	dict.insert("be");
	int word_dict_length = dict.size();

	int window_count = 0;
	int start = 0;
	int prev_pos = start;	
	int window_start = 0;
	int result = length+1;
	while(start<length){
		if(window_count < word_dict_length){
			prev_pos = start;
			char * w = get_word(str,length,start);
			//check word in dict
			set <char *,cmp_str>::iterator s_it = dict.find(w);
			if(s_it != dict.end()){
				//check the word in map
				map <char *,int,cmp_str>::iterator l_it = word_count.find(w);
				if(l_it == word_count.end()){
					word_count[w] = 1;
					window_count++;
				}
				else{
					if(word_count[w]==0){
						window_count++;
					}
					++word_count[w];
				}
			}
		}
		//else{
			int prev_window_start = window_start;
			while(window_count == word_dict_length){
				while(str[window_start]==' ') window_start++;
				int temp = start - window_start;
				if(temp<result){
					result = temp;
				}	

				char *w = get_word(str,length,window_start);	
				window_start++;

				//check the word in map
				map <char *,int,cmp_str>::iterator l_it = word_count.find(w);
				if(l_it != word_count.end()){
					if(word_count[w]>0){
						--word_count[w];
						if(word_count[w]==0){
							window_count--;
						}
					}
				}
			}
		//}
		
	}
	return result;
}
//word iterator, from is the next start pos
char *get_word(const char *str,int length,int &from){
	const char *p = str+from;
	char *temp = new char[length];
	int temp_start = 0;
	while(*p&& *p==' '){ ++p;++from;}
	while(*p && *p!=' '){
		temp[temp_start] = *p;
		++temp_start;
		++from;
		++p;
	}
	temp[temp_start] = '\0';
	//while(*p && *p==' '){ ++p;++from;}
	return temp;
}

void min_substract(const char *str,int length){
	
	const char *p = str;
	char temp[length];
	int temp_start = 0;
	while(*p){
		if(*p!=' '){
			temp[temp_start] = *p;
			++temp_start;
		}		
		else{
			//find a word
			if(temp_start){
				temp[temp_start] = '\0';
				printf("%s\n",temp);
				temp_start = 0;
			}

		}
		++p;
	}
	if(*p!=' '){
		printf("%s\n",temp);
	}
}
int main(int argc,char *argv[]){
	const char *test = "la what la la f be ";
	//min_substract(test,strlen(test));
	int str_len = strlen(test);
	int pos = 0;
	/*while(pos<str_len){
		char * w = get_word(test,str_len,pos);
		printf("%s\n",w);
	}*/
	int r = find_min_substract(test,str_len);
	printf("%d\n",r);
	return 0;
}
