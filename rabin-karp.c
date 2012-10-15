#include "stdio.h"
#include "string.h"
#include <math.h>
/*
* compute string value, length should be small than strlen
*/
int compute_value(char *str,int length,int d,int q){
	int i =0;
	int p0 = 0;
	
	for (i=0;i<length;++i){
		p0 = (d*p0 + (str[i]-'0'))%q;
	}

	return p0;

}
/**
*find the first place of pattern in str
*/
int rk_matcher(char *str,char *pattern,int d, int q){
	int i=0;
	int str_length = strlen(str);
	int pattern_length = strlen(pattern);
	int p0 = 0;	
	int ts[str_length];
	p0 = compute_value(pattern,pattern_length,d,q);
	for(i=0; i<str_length; ++i){
		if (i==0){
			ts[i] = compute_value(str,pattern_length,d,q);
		}
		else{
			ts[i] = (ts[i-1]*d - ((str[i-1]-'0')*(int)pow(d,pattern_length)))%q + (str[i+pattern_length-1]-'0')%q;
		}
		if(i+pattern_length>=str_length){//boring boundage condition check
			break;
		}
	}
	
	int j = 0;
	for(i = 0 ; i<=str_length - pattern_length;++i){
		//printf("%d\n",ts[i]);
		if (ts[i] == p0){
			for (j=0 ; j<pattern_length;++j){
				if (pattern[j] != str[i+j]){
					break;
				}
				else if(j==pattern_length-1){
					return i;
				}
			}
		}
	}

	return -1;
	
		
}
int main(int argc,char *argv[]){
	int pos = rk_matcher("1234567","345",10,500000);
	printf("%d",pos) ;
	return 0;
}



