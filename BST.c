#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
#define MAX(a,b) ((a) > (b) ? a : b)

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;

struct Node* getnode(int x){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = x;
	newnode->right = NULL;
	newnode->left = NULL; 
	return newnode;
}
struct Node* insert(struct Node *root, int x){
	if(root == NULL){
		root = getnode(x);
	}
	else if(x <= root->data){
		root->left = insert(root->left,x);
	}
	else{
		root->right = insert(root->right,x);
	}
	return root;
}

bool search(struct Node* root,int n){
	if(root == NULL){
		return false;
	}
	else if(root->data == n) {
		return true;
	}
	else if(n <= root->data) {
		return search(root->left, n);
	}
	else {
		return search(root->right, n);
	}
}



int findheight(struct Node* root){
	if(root == NULL){
		return 1;
	}
	else{
		
	}
}
int main(){
	root = NULL;
	int n, height;
	root = insert(root,15);
	root = insert(root,20);
	root = insert(root,10);
	root = insert(root,2);
	root = insert(root,12);
	root = insert(root,27);
	root = insert(root,23);
	root = insert(root,18);
	search(root, n);
	height = findheight(root);
	printf("The height is %d", height);
	printf("enter the number you wish to search\n");
	scanf(" %d", &n);
	if(search(root,n)==1) printf("the number exits in the tree\n");
	else if (search(root,n)==0) printf("the number does not exist in the tree\n");
}