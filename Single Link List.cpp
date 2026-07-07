#include <stdio.h>
#include <stdlib.h>

struct Data{
	int number;
	struct Data *next;
	
}*head, *tail;

void pushHead(int n){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	
	//bisa | pakai -> | atau | (*node). |
	 
	node->number = n;       // (*node).number = n;        
	(*node).next = NULL;    // node -> next = NULL;
	
	if(head==NULL){
		head = tail = node;
	}
	
	else{
		node->next = head;
		head = node; //tidak bisa => node = head
	}
}

void penTail(int n){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->number = n;
	node->next = NULL;
	if(tail==NULL){
		tail = head = node;
	}
	else{
		tail->next=node;
		tail=node;
	}
}

void printAll(){
	if(head != NULL){
		struct Data *current = head;
		while (current != NULL){
			printf("%d ", current ->number);
			current = current -> next;
		}
		printf("\n");
	}
	else{
		printf("data is empty (_)_)====D");
	}
}

void pushMid(int n){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->number = n;
	node->next = NULL;
	
	if(head==NULL){
		head = tail = node;
	}
	
	else{
		if(n < head ->number){
			node->next=head;
			head=node;
		}
		else if(n > tail ->number){
			tail->next=node;
			tail=node;
		}
		else{
			struct Data *current = head;
			while(current->next->number < n){
				current = current -> next;
			}
			node->next = current->next;
			current->next = node;
			
			
		}
	}
}

void popHead(){
	if(head!=NULL){
		if(head==tail){
			free(head);
			head = tail = NULL;
		}
		else{
			struct Data *temp = head;
			head=head->next;
			free(temp);
			temp=NULL;
		}
	}
}

void popTail(){
	if(head!=NULL){
		if(head==tail){
			free(head);
			head = tail = NULL;
		}
		else{
			struct Data *temp = head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			tail=temp;
			free(tail->next);
			tail->next=NULL;
		}
	}
}

void popMid(int n){
	if(head!=NULL){
		if(head==tail){
			//1 data only
			if(head->number==n){
				free(head);
				head = tail = NULL;
			}
			else{
				printf("data is not found (_)_)====D");
			}
		}
		else{
			// 1 < data
			if(head->number==n){
				popHead();
			}
			else if(tail->number==n){
				popTail();
			}
			else{
				struct Data *current = head;
				while(current->next->number != n && current->next != tail){
					current = current -> next;
				}
				if(current->next->number==n){
					struct Data *removeData = current->next;
					current->next=removeData->next;
					free(removeData);
					removeData = NULL;	
				}
				else{
					printf("data is not found (_)_)====D");
				}
			
			}
		}
	}
}

void popAll(){
	while(head!=NULL){
		popHead();
	}
}

int main(){
	pushHead(10);
	pushHead(67);
	pushHead(69);
	pushHead(420);
	pushHead(6767);
	printf("HEAD   ");
	printAll();
	
	penTail(69);
	penTail(67);
	penTail(420);
	penTail(46);
	printf("pentil ");
	printAll();
	
	pushMid(123);
	pushMid(12);
	pushMid(443);
	pushMid(125);
	printf("Pushmid ");
	printAll();
	
	
	popHead();
	printf("hasil pophead ");
	printAll();
	
	popTail();
	printf("hasil poptail ");
	printAll();
	
	
	popMid(67);
	printf("hasil popMid ");
	printAll();
	
	popAll();
	printf("hasil   ");
	printAll();

	return 0;	
}
