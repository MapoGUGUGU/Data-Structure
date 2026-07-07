#include <stdio.h>
#include <stdlib.h>

struct Data{
	int x;
	struct Data *left;
	struct Data *right;
	int height;
} *root = NULL;

int getHeight(struct Data *node){
	if(node==NULL)return 0;
	else return node->height;
}

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

int getBalanceFactor(struct Data *node){
	if(node==NULL){
		return 0;
	}else return getHeight(node->left) - getHeight(node->right);
}

struct Data *rightRotate(struct Data *y){
	struct Data *x = y->left;
	struct Data *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}
 
struct Data *leftRotate(struct Data *y){
	struct Data *x = y->right;
	struct Data *B = x->left;
	
	x->left = y;
	y->right = B;
	
	//jangan dibalik
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

struct Data *push(struct Data *node, int x){
	if(node==NULL){
		node = (struct Data*)malloc(sizeof(struct Data));
		node->left = node->right = NULL;
		node->x =  x;
		node->height = 1;
	}else{
		if(x < node->x){
			node->left = push(node->left, x);
		}else if(x > node->x){
			node->right = push(node->right, x);
		}
	}
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	
	int getBF = getBalanceFactor(node);
	if(getBF > 1 && x < node->left->x){
		return rightRotate(node);
	}else if(getBF < -1 && x > node->right->x){
		return leftRotate(node);
	}else if(getBF > 1 && x > node->left->x){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}else if(getBF < -1 && x < node->right->x){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

//delete
struct Data *findPreds(struct Data *node){
	while(node->right !=NULL){
		node=node->right;
	}
	return node;
}

struct Data *del(struct Data *node, int x){
	if(node==NULL){
		return NULL;
	}
	else{
		if(x < node->x){
			node->left = del(node->left, x);
		}else if(x > node->x){
			node->right = del(node->right, x);
		}else{
			if(node->left == NULL && node->right==NULL){
				free(node);
				node = NULL;
			}else if(node->left == NULL){
				Data *temp = node;
				node = node->right;
				free(temp);
			}else if(node->right == NULL){
				Data *temp = node;
				node = node->left;
				free(temp);
			}else{
				Data *temp = findPreds(node->left);
					node->x = temp->x;
					node->left = del(node->left, temp->x);
				}
			}
		}
	
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	
	int getBF = getBalanceFactor(node);
	if(getBF > 1 && getBalanceFactor(node->left) >= 0){
		return rightRotate(node);
	}else if(getBF < -1 && getBalanceFactor(node->right) <= 0){
		return leftRotate(node);
	}else if(getBF > 1 && getBalanceFactor(node->left) < 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}else if(getBF < -1 && getBalanceFactor(node->right) > 0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

struct Data *freeAll(struct Data *node){
	if(node==NULL)return NULL;
	node->left = freeAll(node->left);
	node->right = freeAll(node->right);
	free(node);
	node = NULL;
}


void preOrder(struct Data *curr){
	if(curr != NULL){
		printf("%d ", curr->x);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(struct Data *curr){
	if(curr != NULL){
		inOrder(curr->left);
		printf("%d ", curr->x);
		inOrder(curr->right);
	}
}

void postOrder(struct Data *curr){
	if(curr != NULL){
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ", curr->x);
	}
}

int main(){
	root = push(root, 55);
	root = push(root, 100);
	root = push(root, 33);
	root = push(root, 70);
	root = push(root, 67);
	root = push(root, 1);
	root = push(root, 121);
	root = push(root, 7);
	
	printf("pre order: ");
	preOrder(root);
	printf("\n");
	printf("post order: ");
	postOrder(root);
	printf("\n");
	printf("in order: ");
	inOrder(root);
	printf("\n");
	
	printf("\n================================================\n");
	//del
	root = del(root,55);
	printf("pre order: ");
	preOrder(root);
	printf("\n");
	
	printf("\n================================================\n");
	root = freeAll(root);
	printf("pre order: ");
	preOrder(root);
	printf("\n");
	return 0;
}
