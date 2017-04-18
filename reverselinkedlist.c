#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* insert(int data, struct Node* head){
	//head = NULL; if you add head is null in the insert statenment it will not execute because everytime it iscalled head is null so link will not be created
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head =temp;
	return head;
}
struct Node* reverse(struct Node* head){
	struct Node *prev, *current, *next;
	current = head;
	prev = NULL;
	while(current != 0){
		 next = current->next;
		 current->next = prev;
		 prev = current;
		 current = next;
	}
	head = prev;
	return head;
}

void print(struct Node* head){
	struct Node* temp = head;
	while(temp != NULL){
		printf("elements:%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	struct Node* head;
	head = NULL;
	int n;
	head = insert(4, head);
	head = insert(3, head);
	head = insert(5, head);
	head = insert(6, head);
	print(head);
	head = reverse(head);
	print(head);
}