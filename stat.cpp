#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class WordStat{
	public:
		string word;
		int count;
};

vector<string> split(string s,set<char> delimeters){
	int length = s.size();
	char c = ' ';
	int word_start = 0;
	string *temp = new string;
	vector<string> result;
	set<char>::iterator it;
	for(int i = 0;i<length;++i){
		c = s[i];
		//check whether in delimeters
		it = delimeters.find(c);
		if(it == delimeters.end()){
			//not in delimeters
			temp->push_back(c);	
			word_start = 1;
		}
		else{
			if(word_start){
				word_start = 0;
				result.push_back(*temp);
				temp = new string();
			}
		}
	}
	if(word_start){
		result.push_back(*temp);
	}
	return result;	
}

void print_vc(vector<string> r){
	for(int i = 0;i<r.size();++i){
		printf("%s\n",r[i].c_str());
	}

}
set<char> dm;
bool comp(const WordStat a,const WordStat b){
	return a.count > b.count;
}

void stat(){
	string filter_filename = "filter/filter.txt";
	string filterout_filename = "filterout/filterout.txt";
	ifstream filterout_file(filterout_filename.c_str(),ios::in);

	string line;
	vector<string> result ;

	set<string> exclude_words;
	while(getline(filterout_file,line)){
		transform(line.begin(),line.end(),line.begin(),::tolower);
		result = split(line,dm);
		//cout<<line<<endl;
		for(int i = 0;i<result.size();++i){
			exclude_words.insert(result[i]);
		}
	}

	ifstream filter_file(filter_filename.c_str(),ios::in);

	map<string,int> word_count;
	map<string,int>::iterator wit;
	set<char>::iterator it;

	while(getline(filter_file,line)){
		transform(line.begin(),line.end(),line.begin(),::tolower);
		result = split(line,dm);
		//cout<<line<<endl;
		for(int i = 0;i<result.size();++i){
			if(exclude_words.find(result[i])==exclude_words.end()){
				if(word_count.find(result[i])!=word_count.end()){
					word_count[result[i]]++;
				}
				else{
					word_count[result[i]] = 1;
				}
				//printf("%s\n",result[i].c_str());
			}
		}
	}

	printf("%d,%d\n",exclude_words.size(),word_count.size());
	//put into vector to sort
	vector<WordStat> wresult;
	for(wit = word_count.begin();wit!=word_count.end();++wit){
		WordStat ws;
		ws.word = wit->first;
		ws.count = wit->second;
		wresult.push_back(ws);
	}

	sort(wresult.begin(),wresult.end(),comp);
	for(int j = 0 ; j<wresult.size();++j){	
		printf("%s\t%d\n",wresult[j].word.c_str(),wresult[j].count);
	}
	
}


int main(int argc,char *argv[]){
	dm.insert(',');
	dm.insert('.');
	dm.insert('?');
	dm.insert(' ');
	dm.insert('\r');
	dm.insert('\n');
	dm.insert('\t');
	dm.insert(' ');
	dm.insert('"');
	dm.insert(0xffffffe6);
	dm.insert(0xffffffe4);
	dm.insert(0xffffffc2);
	dm.insert('-');
	stat();
//	vector<string> r = split("76. type  77",dm);


//	print_vc(r);
	return 0;
}
