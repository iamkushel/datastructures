#include <stdio.h>
#include <stdlib.h>

void print();
void insert(int x, int n);
struct Node {
	
	int data;
	struct Node* next;
};
struct Node* Head;
int main(){
	Head = NULL;
		insert(5,1);
		insert(3,2);//to insert the elements
		insert(2,3);
		insert(8,4);
		insert(9,5);
		insert(1,6);
		insert(7,4);
		print(); //to print value of elements in the node
}

void insert(int x, int n){
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = x;
	temp1->next = NULL;
	if(n == 1){
			temp1->next = Head;
			Head = temp1;
			return;
	}
	struct Node* temp2 = Head;
	int i;
	for(i=0;i<n-2;i++){
/*so n-2 because if want to insert element at nth position the temp2 data should be pointed by nth-1 next address
 that is temp2(nth) = temp2.next(n-1)th also as as array starts from 0th position it is n-2*/
		temp2 = temp2->next;
	}
	temp1->next = temp2->next; 
/*remember temp1 will be pointing to the new node not temp2, 
temp2 wil be poiting to either head or temp2.next of previous node where it should attach*/
	temp2->next = temp1;
}

void print(){
	int array_size = 256;
	int *array = (int)malloc(sizeof(array_size));
	int i=0;
	int j =0;
	struct  Node* temp = Head;
	while (temp != NULL){
		printf("the list now:%d\n", temp->data);
		array[i] = temp->data;
		temp = temp->next;
		i++;
	}
	i++;
	int t,k;
	for(k =0;k<i-1;k++){
		for(j=0;j<i-k-1;j++){
			if(array[j]>array[j+1]){
				t = array[j];
				array[j]=array[j+1];
				array[j+1]= t;
				printf("%d", array[j]);
				j++;
	    	}
    	}	
		k++;
	}
	printf("\n");
	
}