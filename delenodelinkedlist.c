#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
	
struct Node* head;

void del(int n){
	int i;
	struct Node* temp = head;
	if(n==1){
		head = temp->next;
		free(temp);
		return;
	}
	struct Node* temp1 = head;
	for(i=0;i<n-2;i++){
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
}
void insert(int data){
	
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("elements:%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	int n;
	insert(4);
	insert(3);
	insert(5);
	insert(6);
	print();
	printf("enter the node which you neeed to delete\n");
	scanf("%d", &n);
	del(n);
	print();
}