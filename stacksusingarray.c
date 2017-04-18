#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1; /*always top will be pointing to -1th location if there is no elements in the stack */
void push(int n){
	top++;
	A[top] = n;
}
void pop(){
	top--;
}
void print(){
	int i;
	printf("stack: ");
	for(i=0;i<top;i++){ 
/*as we have declared top globally whatever modifiaction
we do on it, it will be updated in all the functions, 
so top will take the value of its current position */
		printf(" %d",A[i]);
	}
	printf("\n");
}
int main(){
	push(1);print();
	push(2);print();
	push(4);print();
	push(6);print();
	push(7);print();
	pop();print();
	pop();print();
}