#include <stdio.h>

long count_times(long num){
	long k = 1;
	long sum = 0;
	while(num/k){
		long c = (num/k) % 10;
		long high = num/(k*10) ;
		long low = num - (num/k)* k;

		switch (c){
			case 0:
				sum += high * k;
				break;
			case 1:
				sum += high *k + low +1;
				break;
			default:
				sum += (high+1) * k; 	
		}
	
		k *= 10;	
	}	
	return sum;
}
int main(int argc,char *argv[]){
	printf("%d\n",count_times(99));
	printf("%d\n",count_times(1111111110));

	long N = 99999999999;
	while(N){
		//printf("tring %ld\n",N);
		if(count_times(N) == N) break;
		N--;
	}

	printf("%d\n",N);
	return 0;
}
