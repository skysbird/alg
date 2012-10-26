#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
	struct Link *prev;
	struct Link *next;
	int value;
} Link;


void insert(Link **head,int value){
	Link *p = *head;
	Link *node = malloc(sizeof(Link));
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	if(!p){
		*head = node;	
	}	
	else{
		Link *q;
		while(p){
			q = p;
			p = p->next;
		}

		q->next = node;
		node->prev = q;
	}
}


void reverse(Link **head){
	Link *q = *head;
	if (!q||!q->next) return;
	Link *p = q->next;
	
	q->next = NULL;
	while(p){
		Link *r = p->next;
		p->next = q;
		q->prev = p;

		q = p;
		p = r;
	}

	q->prev = NULL;
	*head = q;
	
}
void print_link(Link *head){
	Link *p = head;
	while(p){
		printf("value = %d\n",p->value);
		if (p->prev)
			printf("prev value = %d\n",p->prev->value);
		printf("\n");
		p = p->next;

	}
}
int main(int argc,char *argv[]){
	Link *head = NULL;
	insert(&head,3);
	insert(&head,13);
	insert(&head,23);
	insert(&head,33);
	insert(&head,43);
	insert(&head,53);
	print_link(head);

	reverse(&head);
	print_link(head);
	return 0;
}
