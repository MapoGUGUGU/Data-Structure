#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct data{
	int n;
	struct data *next;
	struct data *prev;
}*head, *tail;

//LIFO
void pushTail(int n){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node -> n = n;
	node->next = NULL;
	node->prev = NULL;
	
	if(head == NULL){
		head = tail = node;
	}
	else{
		tail->next =node;
		node->prev = tail;
		tail = node;
	}
}

int popTail(){
	if(head != NULL){
		int temp;
		if(head == tail){
			temp = head->n;
			free(head);
			head = tail = NULL;
		}
		else{
			temp = tail->n;
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
		return temp;
	}
	else{
		printf("Data empty");
	}
	return -1;
}

void print(){
	if(head != NULL){
		struct data *curr = head;
		while(curr != NULL){
			printf("%d ", curr->n);
			curr = curr->next;
		}
		printf("\n");
	}
	else{
		printf("empty\n");
	}
}

int main(){
	char postfix[] = "4652-*3/+";
	for(int i = 0; i < strlen(postfix); i++){
		if(isdigit(postfix[i])==1){
			pushTail(postfix[i]-'0');
		}
		else{
			int varA = popTail();
			int varB = popTail();
			
			if(postfix[i]=='+'){
				pushTail(varB + varA);
			}
			else if(postfix[i]=='-'){
				pushTail(varB - varA);
			}
			else if(postfix[i]=='*'){
				pushTail(varB * varA);
			}
			else if(postfix[i]=='/'){
				pushTail(varB / varA);
			}
			else if(postfix[i]=='^'){
				pushTail(pow(varB, varA));
			}
		}
	}
	print();
	return 0;
}
