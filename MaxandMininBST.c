/*always make sure you ve added typdef bool to add bool,as you are using recursive functio
you need to send root as a inpt because when you are sending back right or left node 
you need to have it specified in the call function even if you have declared root
globally*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;

struct Node* getnode(data){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

struct Node* insert(struct Node* root, int data){
	if(root == NULL){
		root = getnode(data);
	}
	else if (data <= root->data ){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right, data);
	}
	return root;
}

struct Node* findmin(struct Node* root){
	if(root == NULL){
		return 0;
	}
	else if(root->left == NULL){ /*check root->left not root->data with NULL because
by the time root->data will be NULL root will be NULL so always if statement executes
 If you check root->left with NULL so the last leaf will show null, return type can be pointer or int
 because as you are returning root->data you can send both */ 
		return root->data;
	}
	return findmin(root->left);
}
struct Node* findmax(struct Node* root){
	if(root == NULL){
		return 0;
	}
	else if(root->right == NULL){
		return root->data;
	}
	return findmax(root->right);
}

int main(){
	root = NULL;
	int n, i, data, min, max;
	int key = 0; 
	printf("enter the elements you wish to add");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &data);
		root = insert(root,data);
	}
	min = findmin(root);
	printf("Minimum element: %d", min);
	
	max = findmax(root);
	printf("max element: %d", max);
}