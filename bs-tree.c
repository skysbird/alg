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
	BSTree *node = malloc(sizeof(BSTree));
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

void delete(BSTree **T,BSTree *node){
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
	
	BSTree *n = search(t,5);
	//printf("%d\n",n->value);
	//BSTree *d = successor(n);
	//printf("%d\n",d->value);
	delete(&t,n);
	print_tree(t,0);
	return 0;
}
