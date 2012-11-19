#include <stdio.h>

int result[100];
int finded = 0;
int c[100];
const int MAX = 10000;
int find_min_coins(int d,int coins[],int length,int level){
	//int c[d+1];
	int i = 0;
	c[0] = 0;
	for ( i =1;i<=d; ++i){
		int j =0;
		int sum = MAX;
		for(j=0; j<length;++j){
			if(i<coins[j]) continue;
			if(sum > c[i-coins[j]] + 1)
			{
				sum = c[i-coins[j]]+1;
				c[i] = sum;
				result[i] = coins[j];
			}
		}
	}

	return c[d];
}

//a is the decrease order of coin value
void coin(int d, int coins[],int length,int level){
	if(d==0){
		int i =0;
		for(i = 0;i<level;++i){
			printf("%d ",result[i]);
		}
		printf("\n");
		finded = 1;
		return;
	}

	if(d < coins[length-1]){
		return;
	}

	
	int i = 0;
	while(!finded && i < length ){ 
		result[level] = coins[i];
		coin(d-coins[i],coins,length,level+1);
		++i;
	}

	
	
}

int main(int argc,char *argv[]){
	int a[] = {25,21,5,2,1};
	//coin(63,a,5,0);
	int target = 50;
	int level = find_min_coins(50,a,5,0);
	printf("%d\n",level);
	int i = 50;
	while(i>=1){
		printf("%d ",result[i]);
		i -= result[i];
	}
	return 0;
}


