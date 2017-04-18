#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
	
struct Node* head;
void print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d",temp->data);
		temp = temp->next;
	}
	printf("\n)");
}
void insert(int data){
	head = NULL;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}
int main(){
	insert(2);
	insert(3);
	print();
}