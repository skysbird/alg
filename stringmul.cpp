#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

string add(string a,string b){
	int i = a.size()-1;
	int j = b.size()-1;
	string result ;
	int m = 0;//进位
	while ( i>=0 && j >=0){
		int t = a[i]-'0' + b[j]-'0' + m;
		m = t / 10;
		t = abs(t % 10);
		char c = (char )t+'0';
		result.insert(0,1,c);
		--i;--j;
	}

	while(i>=0){
		int t = a[i] - '0' + m;
		m = t / 10;
		t = abs(t % 10);
		char c = (char )t+'0';
		result.insert(0,1,c);
		--i;
	}
	while(j>=0){
		int t = b[j] - '0' + m;
		m = t / 10;
		t = abs(t % 10);
		char c = (char )t+'0';
		result.insert(0,1,c);
		--j;
	}

	while(m>0){//剩下的进位处理
		int t = abs(m%10);
		m = m/10;
		char c = (char )t+'0';
		result.insert(0,1,c);
		
	}
	return result;

}

string mul(string a,string b){
	string big = a;
	string small = b;
	if(a.size() < b.size()){
		big = b;
		small = a;	
	}

	int i = big.size()-1;
	int j = small.size()-1;
	
	int m = 0;
	string added0 = "";
	string result = "0";
	while(j>=0){

		int op2 = small[j]-'0';
		
		i = big.size()-1;
		string temp_result = "";
		while(i>=0){
			int op1 = big[i] - '0';
			int t = op1 * op2 + m;
			m = t / 10;
			t = abs(t%10);
			temp_result.insert(0,1,t+'0');
			--i;
		}

		while(m>0){//剩下的进位处理
			int t = abs(m%10);
			m = m/10;
			char c = (char )t+'0';
			temp_result.insert(0,1,c);
			
		}

		temp_result.append(added0);//追加0
		result = add(result,temp_result);
		added0.append("0");
		--j;
	}

	return result;
	
}
int main(int argc,char *argv[]){
	printf("%s\n",add("12345","90005").c_str());
	printf("%s\n",mul("123452","125").c_str());
	return 0;
}
