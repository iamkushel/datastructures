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

int print(){
	struct Node* temp = head;
	int count = 0;
	while(temp != NULL){
		printf("%d", temp->data);
		count++;
		temp = temp->next;
	}
	return count;
}
void findkth(int count, int k){
	struct Node* temp1 = head;
	int i;
	for(i=0;i<count - k; i++){
		temp1 = temp1->next;
	}
	printf("%d", temp1->data);
}
int main(){
	head = NULL;
	int data, n, i,count, k;
	printf("enter the number of elements");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d", &data);
		insert(data);
	}
	count = print();
	printf("\nCount : %d\n", count);
	print();
	printf("enter the k value");
	scanf("%d", &k);
	findkth(count, k);
}