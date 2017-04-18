//logic

int findheight(struct Node* root){
	if(root == NULL) {
		return -1;
	}
	else{
		return MAX(findheight(root->left),findheight(root->right));
	}
}