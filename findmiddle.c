#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node* head;

void insert(int data){
	struct Node* temp =  (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}
}

void findmiddle(){
	struct Node *fast_ptr = head, *slow_ptr = head;
	while(fast_ptr != NULL && fast_ptr->next != NULL){
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	printf("median : %d", slow_ptr->data);
}
int main(){
	head = NULL;
	int middle;
	int data, n, i;
	printf("enter the nuber of elements");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d", &data);
		insert(data);
	}
	print();
	findmiddle();
}