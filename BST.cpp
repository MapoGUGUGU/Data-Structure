#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *left;
	struct Node *right;
}*root = NULL;


struct Node *newNode(int val){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct Node *insert(struct Node *root, int val){
	if(root == NULL){
		return newNode(val);
	}else if(val< root->val ){
		root->left = insert(root->left, val);
	}else{
		root->right = insert(root->right, val);
	}
	return root;
}

void search(struct Node *root, int val){
	if(root==NULL){
		printf("no data");
		return;
	}
	if(root->val==val){
		printf("root found");
		return;
	}else if(val < root->val){
		search(root->left, val);
	}else {
		search(root->right, val);
	}
}

struct Node *deleteNode(struct Node *root, int val){
	if(root == NULL){
		return NULL;
	}else if(val < root->val){
		root->right = deleteNode(root->right, val);
	}else if(val > root->val){
		root->left = deleteNode(root->left, val);
	}else if(root->val == val){
		//node tidak punya anak
		if(root->right==NULL && root->left==NULL){
			free(root);
			root == NULL;
			
		//1 anak
		//anak kiri
		}else if(root->right==NULL && root->left!=NULL){
			struct Node *temp = root->left;
			*root = *temp;
			free(temp);	
		}
		//anak kanan
		else if(root->right!=NULL && root->left==NULL){
			struct Node *temp = root->right;
			*root = *temp;
			free(temp);
		}
		//2 anak
		else if(root->right!=NULL && root->left!=NULL){
			struct Node *temp;
			temp = root->left;
			while(root->right!=NULL){
				temp = root->right;
			}
			root->val = temp->val;
			root->left = deleteNode(root->left, temp->val);
		}
	}
	return root;
}

int main(){
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 9);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 3);
	
	search(root, 97);
	
	return 0;
}


