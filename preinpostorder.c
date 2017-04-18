#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* getnode(char data){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}	
struct Node* root;
struct Node* insert(struct Node* root, int data){
		if(root == NULL){
			root = getnode(data);
		}
		else if(data <= root->data){
			root->left = insert(root->left, data);
		}
		else{
			root->right = insert(root->right, data);
		}
		return root;
}

struct Node* inorder(struct Node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	printf(" %i", root->data);
	inorder(root->right);

}

struct Node* preorder(struct Node* root){
	if(root ==NULL) {
		return;
	}
	printf(" %i", root->data);
	preorder(root->left);
	preorder(root->right);
}

struct Node* postorder(struct Node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf(" %i", root->data);
}

int main(){
	root = NULL;
	int i, n;
    int data;
	printf("enter the number of elements");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%i", &data);
		root = insert(root, data);
	}
	preorder(root); /*you need to pass root becuase a local root 
	 variable is taken in and that pointer is used to traverse in the tree 
	  as a recursive variable */
	inorder(root);
	postorder(root);
}