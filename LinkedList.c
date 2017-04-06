#include <stdio.h>
#include <stdlib.h>
//Declares
void add(int data);
void removeAt(int pos);
void view();


struct Node {
	int data;
	struct Node *next;
};

//Top pointer
struct Node *head = NULL;


void add(int num){
	//Allocate memory (returns pointer)
	struct Node *temp = malloc( sizeof(struct Node) ); 
	temp->data = num;
	temp->next = head;
	head = temp;
}

void view(){
	//Loop through all elements and print them
	struct Node *toggle = head;
	while(toggle != NULL){
		printf("Element %d\n",toggle->data);
		toggle=toggle->next;
	}	
}


void removeAt(int pos){
	//Set pointer to top
	struct Node *index = head;
	int i;
	
	//If position to remove is the 1st
	if (pos == 1){
		
		//Point top to 2nd element
		head = index->next;
		free(index);
	} else {
		//Loop through till posiion - 2
		for( i = 0; i < pos-2; i++)
			index = index->next;
		
		//Create links
		struct Node *temp = index->next;
		index->next = temp->next;
		free(temp);
	}
}


int main() {
	
	add(5);
	add(3);
	add(4);
	add(10);
	view();
	removeAt(2);
	printf("\n");
	view();
	
	
	return 0;
}
