#include <stdio.h>
#include <stdlib.h>

typedef struct BSTree{
	int value;
	struct BSTree *left;
	struct BSTree *right;
	struct BSTree *parent;
} BSTree;


BSTree* search(BSTree *T,int v){
	BSTree *p = T;
	while(p){
		if(v<p->value){
			p = p->left;
		}
		else if(v>p->value){
			p = p->right;
		}
		else{
			return p;
		}
	}	
	return NULL;
}
BSTree * min(BSTree *T){
	BSTree *p = T;
	BSTree *q=NULL;
	while(p){
		q = p;
		p = p->left;
	}
	return q;
}

BSTree* successor(BSTree *p){
	if(p->right){
		return min(p->right);
	}else{
		while(p->parent && p!=p->parent->left){
			p = p->parent;
		}
		if(p->parent){
			return p->parent;
		}
		else{
			return p;
		}
	}
	
}
//insert node into T
void insert(BSTree **T,int v){
	BSTree *node = (BSTree *)malloc(sizeof(BSTree));
	node->value = v;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	if(*T==NULL){
		*T = node;
		
	}
	else{
		BSTree *head = *T;	
		BSTree *p = head;
		BSTree *q = NULL;
		while(p){
			if(node->value < p->value){
				q = p;
				p = p->left;
			} 	
			else{
				q = p;
				p = p->right;		
			}
		}

		if(node->value<q->value){
			q->left = node;
			node->parent = q;	
		}
		else{
			q->right = node;
			node->parent = q;
		}
	}
}

void del(BSTree **T,BSTree *node){
	if (*T==node){
		*T = NULL;
	}
	else{
		BSTree *p = node->parent;
		if (!node->left && !node->right){
			if (p->left == node){
				p->left = NULL;
			}
			else{
				p->right = NULL;
			}	
		}
		else if(!node->right){//no right child, just delete node
			if (p->left == node){
				p->left = node->left;
			}
			else{
				p->right = node->left;
			}	
		}
		else if(!node->left){//no left child just delete node
			if (p->left == node){
				p->left = node->right;
			}
			else{
				p->right = node->right;
			}	
		
		}
		else{//have left and right child
			//find successor
			BSTree *s = successor(node);	
			//copy sattlite data
			node->value = s->value;
			//delete successor,must not have two child
			delete(T,s);	
		}
	}
}

void print_tree(BSTree *T,int level){
	if(T){
		print_tree(T->right,level+1);	
		int i = 0;
		for(i = 0;i<level; ++i){
			printf("  ");
		}
		printf("%d\n",T->value);
		print_tree(T->left,level+1);
	}
}

#include <stack>
#include <map>
using namespace std;

stack<BSTree *> s;
map<BSTree *,int> flag;

void in_order(BSTree *T){
	while (!s.empty()){
		s.pop();
	}
	BSTree *p = T;
	if (!p) return;
	
	while(p || !s.empty()){
		while(p){
			s.push(p);
			p = p->left;
		}		
		p = s.top();
		s.pop();
		printf("%d ",p->value);
		p=p->right;
	}
	printf("\n");
}

void pre_order(BSTree *T){
	while (!s.empty()){
		s.pop();
	}
	BSTree *p = T;
	if (!p) return;
	
	while(p || !s.empty()){
		while(p){
			printf("%d ",p->value);
			s.push(p);
			p = p->left;
		}		
		p = s.top();
		s.pop();
		p=p->right;
	}

	printf("\n");
}

void last_order(BSTree *T){
	while (!s.empty()){
		s.pop();
	}
	BSTree *p = T;
	if (!p) return;

	while(p){
	
		s.push(p);
		p = p->left;
	}	
	while(!s.empty()){
		p = s.top();
		if(flag[p]){
			printf("%d ",p->value);	
			s.pop();
		}
		else{
			flag[p] = 1;
			p = p->right;
			while(p){
				s.push(p);
				p = p->left;	
			}	
		}
	}
	
	printf("\n");
}

int max_height(BSTree *node,int &max_l,int &max_r){
	if(node==NULL){
		max_l = 0;
		max_r = 0;
		return 0;
	}
	int max_l1 = 0;
	int max_r1 = 0;

	if(node->left && node->right){
		int max_height_r = max_height(node->right,max_l1,max_r1);
		max_r = max_l1 > max_r1? max_l1:max_r1;
		max_r = max_r + 1;

		int max_height_l = max_height(node->left,max_l1,max_r1);
		max_l = max_l1 > max_r1? max_l1:max_r1;
		max_l = max_l + 1;

		int result = max_l + max_r;
		if(result < max_height_r){
			result = max_height_r;
		}

		if(result < max_height_l){
			result = max_height_l;
		}
		return result;
	}
	else{
		if(!node->left && !node->right){
			max_l = 0;
			max_r = 0;
			return 0;
		}

		if(node->left){
			int max_height_l = max_height(node->left,max_l1,max_r1);
			max_l = max_l1 > max_r1? max_l1:max_r1;
			max_l = max_l + 1;
			max_r = 0;
			int result = max_l + max_r;

			if(result < max_height_l){
				result = max_height_l;
			}
			return result;
			
		}

		if(node->right){
			int max_height_r = max_height(node->right,max_l1,max_r1);
			max_r = max_l1 > max_r1? max_l1:max_r1;
			max_r = max_r + 1;

			max_l = 0;
			int result = max_l + max_r;
			if(result < max_height_r){
				result = max_height_r;
			}

			return result;

		}
	}
}
int main(int argc,char *argv[]){
	BSTree *t = NULL;
	insert(&t,15);
	insert(&t,5);
	insert(&t,16);
	insert(&t,20);
	insert(&t,3);
	insert(&t,12);
	insert(&t,18);
	insert(&t,23);
	insert(&t,10);
	insert(&t,13);
	insert(&t,6);
	insert(&t,7);
	
	print_tree(t,0);	
	int max_l = 0;
	int max_r = 0;	
	int r = max_height(t,max_l,max_r);
	printf("max_height = %d\n,max_l = %d\nmax_r=%d\n",r,max_l,max_r);
	return 0;
}
