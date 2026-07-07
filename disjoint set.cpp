#include <stdio.h>

int parent[105];

void makeSet(int n){
	for (int i = 1; i<=n; i++){
		parent[i]=i;
	}
}

int findParent(int x){
	if(parent[x]==x) return x;
	return parent[x]= findParent(parent[x]);
}

void merge(int a, int b){
	parent[findParent(a)]= findParent(b);
}

int isSameSet(int a, int b){
	return findParent(a) == findParent(b);
}

int main(){
	makeSet(10);
	merge(1,2);
	merge(2,3);
	
	printf("Find Parent(2): %d\n", findParent(2));
	
	printf("is same set(1,3): %d\n", isSameSet(1,3));
	merge(7,8);
	merge(8,9);
	printf("is same set(2,8): %d\n", isSameSet(2,8));
	return 0;
}
