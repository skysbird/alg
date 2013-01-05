#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//函数功能 ： 从一个字符串中选m个元素
//函数参数 ： pStr为字符串， m为选的元素个数， result为选中的
//返回值 ：   无
void Combination_m(char *pStr, int m, vector<char> &result)
{
	if(pStr == NULL || (*pStr == '\0'&& m != 0))
		return;
	if(m == 0) //递归终止条件
	{
		for(unsigned i = 0; i < result.size(); i++)
			cout<<result[i];
		cout<<endl;
		return;
	}
	//选择这个元素
	result.push_back(*pStr);
	Combination_m(pStr + 1, m - 1, result);
	result.pop_back();
	//不选择这个元素
	Combination_m(pStr + 1, m-1, result);
}
//函数功能 ： 求一个字符串的组合
//函数参数 ： pStr为字符串
//返回值 ：   无
void Combination(char *pStr)
{
	if(pStr == NULL || *pStr == '\0')
		return;
	int number = strlen(pStr);
	//for(int i = 1; i <= number; i++)
	{
		vector<char> result;
		Combination_m(pStr, number, result);
	}
}

int main(int argc,char *argv[]){
	Combination("123");
	return 0;
}
