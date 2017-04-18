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
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}
void removedup(){
	struct Node *p = head, *q = head;
	struct Node* prev;
	q = q->next;
	while(p != NULL){
		while(q != NULL && p->data != q->data ){
			prev = q;
			q = q->next;
		}
		if(q == NULL){
			p = p->next;
			if(p != NULL){ //you need to mention if loop because the loop traverses completely even if it  has removed dup
				q = p->next;
			}
		}
		else if(p->data == q->data){
			struct Node* temp;
			prev->next = q->next;
			temp = q;
			q = q->next;
			free(temp);
		}
	}
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
	removedup();
	printf("\nNo Dup :");
	print();
	
}