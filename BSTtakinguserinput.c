/*always make sure you ve added typdef bool to add bool,as you are using recursive functio
 you need to send root as a inpt because when you are sending back right or left node 
  * you need to have it specified in the call function even if you have declared root
  * globally*/

#include <stdio.h>
#include <stdlib.h>
typedef bool;
#define true 1
#define false 0

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
bool search(struct Node* root, int key){
	if(root == NULL){
		return false;
	}
	else if(root->data == key){
		return true;
	}
	else if (key <= root->data){
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}


int main(){
	root = NULL;
	int n, i, data;
	int key = 0; 
	printf("enter the elements you wish to add");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &data);
		root = insert(root,data);
	}
	printf("enter the number you wish to search");
	scanf("%d", &key);
	if(search(root,key)== true){
		printf("element exist");
	}
	else{
		printf("does not exist");
	}
}