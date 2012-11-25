#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

class Node{
	public:
		int v;
		int done;
		int pos;
		Node(){
			this->v = 0;
			this->pos = 0;
			this->done = 0;
		}
		Node(int v){
			this->v = v;
			this->pos = 0;
			this->done = 0;
		}
};
void print_array_tree(Node *arr,int length){
	int i =0;
	for ( i=0; i<length;++i){

		printf("%d ",arr[i].v);
	}
	printf("\n");
}

void print_array(int *arr,int length){
	int i =0;
	for ( i=0; i<length;++i){

		printf("%d ",arr[i]);
	}
	printf("\n");
}

void adjust(Node *tree,int tree_index){
	//adjust index in the tree
	//find the sibling node index
	int left = tree_index;
	int right = tree_index + 1;
	if (tree_index%2==0){
		left = tree_index - 1;
		right = tree_index;
	}

	//调整锦标赛树
	int i = right;//保证i是比较节点中的右边的那个
	while(i>0){
		Node n1 = tree[i-1];
		Node n2 = tree[i];		
		int par = (i-2)/2;
		if(n1.done && n2.done){
			Node n = Node(0);
			n.done = 1;
			tree[par] = n;
		}
		else if(n1.done){
			Node n = Node(n2.v);
			n.pos = n2.pos;
			tree[par] = n;
		}
		else if(n2.done){
			Node n = Node(n1.v);
			n.pos = n1.pos;
			tree[par] = n;
		}
		else{
			if(n1.v < n2.v){
				Node n = Node(n1.v);
				n.pos = n1.pos;
				tree[par] = n;
			}
			else{
				Node n = Node(n2.v);
				n.pos = n2.pos;
				tree[par] = n;
			}
		}

		if(par%2==0){//只调整相关分支上的节点
			i = par;
		}else{
			i = par+1;
		}
		
	}
			
}
void tour(int *arr,int length){
	int tree_node_length = int(ceil(log(length)/log(2)));
	tree_node_length = pow(2,tree_node_length);
	int tree_length = 2*tree_node_length - 1;
	int tree_node_start = tree_length - tree_node_length ;
	
	Node *tree = new Node[tree_length];
	int i =0;
	int j =0;
	//初始化叶子
	for ( i = tree_node_start,j=0; i<tree_length && j<length;++i,++j){
		Node n = Node(arr[j]);
		n.pos = i;
		tree[i] = n;
	}
	while(i<tree_length){
		Node n = Node(0);
		n.done = 1;
		n.pos = i;
		tree[i] = n;
		++i;
	}

	//第一次构造锦标赛树
	
	i = tree_length-1;		
	while(i>0){
		Node n1 = tree[i-1];
		Node n2 = tree[i];		
		int par = (i-2)/2;
		if(n1.done && n2.done){
			Node n = Node(0);
			n.done = 1;
			tree[par] = n;
		}
		else if(n1.done){
			Node n = Node(n2.v);
			n.pos = n2.pos;
			tree[par] = n;
		}
		else if(n2.done){
			Node n = Node(n1.v);
			n.pos = n1.pos;
			tree[par] = n;
		}
		else{
			if(n1.v < n2.v){
				Node n = Node(n1.v);
				n.pos = n1.pos;
				tree[par] = n;
			}
			else{
				Node n = Node(n2.v);
				n.pos = n2.pos;
				tree[par] = n;
			}
		}
		i -= 2;
	}
	
	while(!tree[0].done){	
		printf("%d\n",tree[0].v);
		//printf("%d\n",tree[0].pos);
		tree[tree[0].pos].done = 1;
		adjust(tree,tree[0].pos);
	}
	//print_array_tree(tree,tree_length);

	
}

int main(int argc,char *argv[]){
	int arr[7] = {5,2,1,23,3,1,354};
	tour(arr,7);
	return 0;
}
