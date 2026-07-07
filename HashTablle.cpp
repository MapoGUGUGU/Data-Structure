#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
	
struct Data{
	int key;
	char name[100];
	struct Data *next;
}*head[97], *tail[97];

int div(char val[]){
	int sumVal=0;
	for(int i = 0; i<strlen(val); i++){
		sumVal += val[i];
	}
	return sumVal%97;
}

void pushTail(int k, char n[]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->key = k;
	strcpy(node->name, n);
	node->next = NULL;
	
	if(head[k]==NULL){
		head[k] = tail[k] = node;
	}
	else{
		tail[k]->next = node;
		tail[k]= node;
	}
}

void viewChainning(){
	for(int i = 0; i<97; i++){
		if(head[i]==NULL){
			printf("%d. -\n", i+1);
		}
		else{
			struct Data *curr = head[i];
			printf("%d. -\n", i+1);
			while(curr!=NULL){
				printf("%s->", curr->name);
				curr= curr->next;
			}
			printf("\n");
		}
	}
}

//linear probing
char arr[97][100] = {};

void linProb(int k, char n[]){
	if(strcmp(arr[k],"")==0){
		strcpy(arr[k], n);
	}
	else{
		for(int i = 0; i<97; i++){
			if(strcmp(arr[i], "")==0){
				strcpy(arr[i], n);
				break;
			}
			if(i == 97)i = -1;
		}
	}
	
}

int main(){
	int loop, a;
	char sigma[97][100];
	
	scanf("%d", &loop);
	for(int i=0; i<loop; i++){
		scanf("%s", sigma[i]);
		pushTail(div(sigma[i]), sigma[i]);
		//linear probing
		linProb(div(sigma[i]), sigma[i]);
	}
	
	printf("choose: (1.View Chain) || (2.LinProb): \n");
	scanf("%d", &a);
	if(a==1){
		viewChainning();
	}
	else if(a==2){
		for(int i = 0; i <97; i++){
			printf("%d. %s\n", i+1, arr[i]);
		}
	}
	
	
	return 0;
}
