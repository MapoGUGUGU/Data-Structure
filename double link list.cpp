#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	int number;
	char name[100];
	struct Data *next;
	struct Data *prev;
}*head, *tail;

void print(){
	if(head != NULL){
		struct Data *curr = head;
		printf("Current Data: ");
		while(curr != NULL){
			printf("%d-%s ", curr->number, curr->name);
			curr = curr->next;
		}
		printf("\n");
	}
	else{
		printf("No Data \n");
	}
}

void pushHead(int num, char n[100]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node ->number = num;
	strcpy(node->name, n);
	node->next = NULL;
	node->prev = NULL;
	
	if(head == NULL){
		head = tail = node;
	}
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(int num, char n[100]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node ->number =num;
	strcpy(node->name, n);
	node->next = NULL;
	node->prev = NULL;
	
	if(head==NULL){
		head = tail = node;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void pushMid(int num, char n[100]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->number = num;
	strcpy(node->name, n);
	node->next=NULL;
	node->prev = NULL;
	
	if(head==NULL){
		head = tail = node;
	}
	else {
		if(num < head->number){
			pushHead(num, n);
		}
		else if(num > tail->number){
			pushTail(num, n);
		}
		else{
			struct Data *curr = head;
			while(curr->number < num){
				curr = curr->next;
			}
			node->prev = curr->prev;
			curr->prev->next = node;
			node->next=curr;
			curr->prev = node;
		}
	}
}

void popHead(){
	if(head != NULL){
		if(head==tail){
			free(head);
			head = tail = NULL;
		}
		else{
			head = head->next;
			free(head->prev);
			head->prev = NULL;
		}
	}
	else{
		printf("Data is already empty ");
	}
}

void popTail(){
	if(head!=NULL){
		if(head==tail){
			free(tail);
			tail = head = NULL;
		}
		else{
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
	}
	else{
		printf("Data is already empty ");
	}
}

void popMid(int num){
	if(head!=NULL){
		if(head==tail){
			if(num == head->number){
				free(head);
				head = tail = NULL;	
			}
			else{
				printf("no data");
			}	
		}
		
		else{
			if(head->number==num){
				popHead();
			}
			else if(tail->number==num){
				popTail();
			}
			else{
				struct Data *curr = head;
				while (curr->number < num && curr->next != tail){
					curr = curr->next;
				}
				if(curr->number==num){
					curr->next->prev = curr->prev;
					curr->prev->next = curr->next;
					free(curr);
					curr = NULL;
				}
				else{
					printf("No data to be deleted! \n");
				}
			}
		}
	}
}

int main(){
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	
	pushHead(19, "Sugma");
	pushHead(12, "coxx");
	pushHead(22, "Andi");
	printf("push head: ");
	print();
	
	pushTail(67, "Mike");
	pushTail(39, "sukandi");
	pushTail(27, "trolo");
	printf("push tail: ");
	print();
	
	pushMid(25, "sungkono");
	pushMid(45, "Joko");
	pushMid(32, "widono");
	
	printf("push mid: ");
	print();
	
	
	popHead();
	print();
	
	popTail();
	print();
	
	popMid(24);
	print();
	return 0;
}	
