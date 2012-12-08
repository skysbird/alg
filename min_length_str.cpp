#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

set<string> dict;
vector<string> word_list;
queue<int> last_pos ; 
map<string,int> dict_word_count;

string next_word(string content,int &start_pos){
	if(start_pos == content.size()){
		return "";
	}
	int i = start_pos;
	while(content[start_pos]==' ') ++start_pos;

	for(i = start_pos; i<content.size();++i){
		if(content[i] == ' '){
			break;
		}
	}
	
	return content.substr(start_pos,i-start_pos);
}
int main(int argc,char *argv[]){
	string content = "a a a a a b c d";
	int *c = new int[content.size()];

	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	dict.insert("d");


	int start_word_pos = 0;
	int i = 0;
	int start_pos = 0;
	int processed_pos = 0;
	int found_in_dict = 0;

	string  word=next_word(content,processed_pos);
	while(word!=""){
		processed_pos = processed_pos + word.size();
		if(dict.count(word)) break;
		word = next_word(content,processed_pos);
	}

	word_list.push_back(word);

	last_pos.push(word_list.size()-1);
	dict_word_count[word] = 1;
	found_in_dict++;

	c[i] = word_list[start_word_pos].size();
	++i;	
	word=next_word(content,processed_pos);
	int min = content.size();
	int last_t = 0;//上一轮计算的是后更改了start_pos,last_t表示更改了start_pos后，需要补偿的差值
	while(word!=""){
		if(dict.count(word)){
			word_list.push_back(word);
			last_pos.push(word_list.size()-1);

			if(word != word_list[start_word_pos]){
				c[i] = c[i-1] + word.size();
			}
			else{
				//update start_word_pos
				int deleted_pos = last_pos.front();
				last_pos.pop();
				int front_pos_index = last_pos.front();
				while(dict_word_count[word_list[front_pos_index]] > 1){
					last_pos.pop();
					dict_word_count[word_list[front_pos_index]]--;
					front_pos_index = last_pos.front();
				}
				start_word_pos = front_pos_index;

				c[i] = c[i-1] - (c[start_word_pos-1]) + word.size() + last_t;
				//c[start_word_pos] = word_list[start_word_pos].size();
				last_t = c[start_word_pos] - word_list[start_word_pos].size();

				dict_word_count[word_list[deleted_pos]]--;
				found_in_dict--;

				
			}

			if(!dict_word_count.count(word)||dict_word_count[word]==0){
				dict_word_count[word] = 1;
				found_in_dict++;
			}
			else{
				dict_word_count[word]++;
			}
		}
		else{
			c[i] = c[i-1] + word.size();
			word_list.push_back(word);

		}

		if(found_in_dict==dict.size()){
			if(c[i] < min){
				min = c[i];
			}
			
			int deleted_pos = last_pos.front();
			last_pos.pop();
			int front_pos_index = last_pos.front();
			while(dict_word_count[word_list[front_pos_index]] > 1){
				last_pos.pop();
				dict_word_count[word_list[front_pos_index]]--;
				front_pos_index = last_pos.front();
			}


			start_word_pos = front_pos_index;

			c[i] = c[i-1] - (c[start_word_pos-1]) + word.size()+last_t;
			//c[start_word_pos] = word_list[start_word_pos].size();
			last_t = c[start_pos] - word_list[start_pos].size();

			dict_word_count[word_list[deleted_pos]]--;
			found_in_dict--;
		
		}

		++i;
		processed_pos = processed_pos + word.size();
		word = next_word(content,processed_pos);

	}

	printf("%d\n",min);
	return 0;
}
