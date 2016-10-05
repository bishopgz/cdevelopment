#include <stdio.h>
#include <stdlib.h>

//Node Structure 
struct node {
	int data;
	struct node *next;
};
void add(int num);
void print();

//Root pointer 
struct node *root = NULL; 

//main function start
int main() {
	
	int num,i,input;
	printf("Choose number of entries->");
	scanf("%i",&num);
	for (i = 1; i <= num; i++){
		printf("\nEnter number->");
		scanf("%i",&input);
		add(input);
		print();
	}
	
	return 0;
}

void add(int num){
	struct node *temp = malloc(sizeof(struct node));
	temp->data = num;
	temp->next = root;
	root = temp;

}

void print(){
	struct node *p = root;

	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}









