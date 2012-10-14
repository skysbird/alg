#include "stdio.h"


void count_lcs(char *a, char *b,int length_a, int length_b,int *count, int *flag){
	int i,j;
	for (i = 0; i< length_a; ++i){
		*(count+i*length_b+0) = 0;
	}
	
	for (j = 0; j< length_b; ++j){
		*(count+0*length_b +j) = 0;
	}
	
	for (i = 0 ; i < length_a ; ++i){
		for (j = 0; j <length_b ; ++j){	
			if (a[i] == b[j]){
				if (i==0 || j == 0){
					*(count+i*length_b+j) = 1;
				}
				else{
					*(count+i*length_b+j) = *(count + (i-1)*length_b + j-1)+1;
				}
				*(flag+i*length_b + j) = 1;
			}
			else{
				if (i == 0 && j == 0  ){
					*(count+i*length_b+j) = 0;	
					*(flag+i*length_b + j) = 2;
				}
				else if (i == 0){
					*(count+i*length_b+j) = *(count+i*length_b+j-1);
					*(flag+i*length_b + j) = 2;
				}
				else if (j == 0){
					*(count+i*length_b+j) = *(count+(i-1)*length_b+j);
					*(flag+i*length_b + j) = 3;
				}
				else if (*(count+i*length_b+j-1) < *(count+(i-1)*length_b+j)){
					*(count+i*length_b+j) = *(count+(i-1)*length_b+j);
					*(flag+i*length_b + j) = 2;
				}
				else{
					*(count+i*length_b+j) = *(count+i*length_b+j-1);
					*(flag+i*length_b + j) = 3;
				}
			}
		}
	}

}

void print_lcs(char *a,char *b,int length_a, int length_b, int *count, int *flag){

}

/**
 * find largest common string in a and b
 * @return the largest common string
 */

char * lcs(char *a,char *b,int length_a,int length_b){
	/*
	 * used for count x[i-1],y[j-1] lcs length
	 * count[1][2] means x[1],y[2] string lcs length
	 */
	int count[length_a][length_b];
	int flag[length_a][length_b];
	count_lcs(a,b,length_a,length_b,(int *)count,(int *)flag);
	int i=0;
	int j=0;
	for (i=0; i <length_a;++i){
		for(j=0;j<length_b;++j){
			printf("%d,",count[i][j]);
		}
		printf("\n");
	}
		
	
}
int main(int argc,char *argv[]){
	char *a = "aaab";
	char *b = "aa";
	lcs(a,b,4,2);
	return 0;
}
