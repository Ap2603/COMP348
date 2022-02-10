//header files
#include<stdio.h>
#include<stdlib.h>

//Making a Node structure
struct Node {
	char data;
	struct Node *next; //pointer to next node
	struct Node *subList; //pointer to subList, if any
};

//function to print the List. we are using the same function to implement CDR function, so we are taking isCDR as integer input. 0 indicates CDR is not to be printed. 1 indicates CDR is to be printed.
void printList(struct Node *head, int isCDR) {
	struct Node *temp=head; //make a temporary variable pointing to head node
	printf("("); //initial brackets
	while(temp!=NULL) { //till the end is reached
		if(temp->subList!=NULL) { //if a subList is there
			struct Node *temp2 = temp->subList; //store the address of the subList in temp2
			printf("("); //initial brackets
			while(temp2!=NULL) { //till the end is reached
				printf("%c", temp2->data); //print the data
				temp2 = temp2->next; //move to next node
			}
			printf(")"); //closing brackets
		} else { //if subList is not there
			if(temp==head && isCDR) {} //if CDR is to be printed, skip the first node data
			else printf("%c", temp->data); //else print the data
		}
		temp = temp->next; //move to the next node
	}
	printf(")");//closing brackets
}

//function to print CAR of the linked list
void car(struct Node *head) {
	printf("\n%c\n",head->data); //print the data of the head node
}
//function to print CDR of the linked list
void cdr(struct Node *head) {
	printList(head, 1); //call printList function with isCDR equals to 1
}

//function to free up the space of the Linked List
void freeList(struct Node *head) {
	struct Node *temp=head; //store head node
	while(temp!=NULL) { //till the end is reached
		if(temp->subList!=NULL) { //if subList is there
			struct Node *temp2 = temp->subList; //store the subList node
			while(temp2!=NULL) { //till the end is reached
				struct Node *t1=temp2; //store the address in a new variable
				temp2 = temp2->next; //move to next node
				free(t1); //free the current node
			}
		}
		struct Node *t2 = temp; //store the address in a new variable
		temp = temp->next; //move to next node
		free(t2); //free the current node
	}
}

//main function
int main() {
	//Making a LinkedList as per the question. Here we are using malloc to dynamically allocate space for the Nodes.
	struct Node *head = new Node();
	head->data = 'a';
	struct Node *link = new Node();
	head->next = link;
	link->subList = new Node();
	link->subList->data = 'b';
	link->subList->next = new Node();
	link->subList->next->data = 'c';
	link->next = new Node();
	link->next->data = 'd';
	link->next->next = new Node();
	link->next->next->data = 'e';

	//Print List
	printList(head, 0);
	//Print CAR
	//car(head);
	//Print CDR
	//cdr(head);
	//Free up the space
	freeList(head);
}