#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "aggregate.h"
typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode;
typedef struct {
	eltype type;
	union {
		atom a;
		struct _listnode* l;
	};
} element;
typedef struct _listnode {
	element el;
	struct _listnode* next;
} *list;
const element NIL = { .type = LIST, .l = NULL };
element aasel(atom a);
element lasel(list l);
element car(element e);
list cdr(element e);
list cddr(element e);
list cons(element e, list l);
list append(list l1, list l2);
void lfreer(list l);
void print(element e);


int main(void)
{   //testing the aasel method
	atom example= 't';
	element e1 = aasel(example);
	
	printf("the type atom is:%d\n", ATOM);
	printf("the type list is:%d\n", LIST);
	printf("Testing aasel with atom t\n");
	printf("the type for elemenet1 is:%d\n", e1.type);
	printf("the atom for the element1 is:%c\n", e1.a);
	//creating tets data for lasel
	list newList = (struct list*)malloc(sizeof(list));
	e1.a = 'w';
	if (newList == NULL) {
		printf("this is null\n");
	}
	else {
		newList->el = e1;
		//testing lasel method
		element e2 = lasel(newList);
		printf("Testing lasel with list containg atom t\n");
		printf("the type for lasel is:%d\n", e2.type);
		printf("the type for lasel in list is:%d\n", e2.l->el.type);
		printf("the atom for lasel in list is:%c\n", e2.l->el.a); 
		//testing car mehtod will return null with invalid parameters
		element e3 = car(e1);
		printf("testing car while given an atom value\n");
		printf("the type for head is:%d\n", e3.type);
		if (e3.l == NULL) {
			printf("this is null\n");
		}
		//testing car method
		element e4 = car(e2);
		printf("the type for the head in list is:%d\n", e4.type);
		printf("the atom for the head in list is:%c\n", e4.a);
		e1.a = 'r';
		printf("Testing the const list:\n");
		//testing cons method
		list conList = cons(e1, newList);
		printf("the type for the conList in list is:%d\n", conList->el.type);
		printf("the atom for the conList in list is:%c\n", conList->el.a);
		printf("the type for the conList->next in list is:%d\n", conList->next->el.type);
		printf("the atom for the conList->next in list is:%c\n", conList->next->el.a);

		//creatig test data for cdr
		list newListPart3 = (list)malloc(sizeof(struct _listnode));
		element eListPart3 = { .type = ATOM, .a = 'c'};
		newListPart3->el = eListPart3;
		newListPart3->next = NULL;
		list newListPart2 = (list)malloc(sizeof(struct _listnode));
		element eListPart2 = { .type = ATOM, .a = 'b'};
		newListPart2->el = eListPart2;
		newListPart2->next = newListPart3;
		list newListPart1 = (list)malloc(sizeof(struct _listnode));
		element eListPart1 = { .type = ATOM, .a = 'a'};
		newListPart1->el = eListPart1;
		newListPart1->next = newListPart2;
		element fullList= { .type = LIST, .l = newListPart1 };
		//testing cdr method
		list tail=cdr(fullList);
		printf("Testing tail:");
		printf("the type for the tail in list is:%d\n", tail->el.type);
		printf("the atom for the tail in list is:%c\n", tail->el.a);
		//testing cdr method will return null with invalid parameters
		printf("testing crd with invalid parameters:\n");
		list shouldBeNull=cdr(e1);
		if (shouldBeNull == NULL) {
			printf("the type for cdr not list is:this is null\n");
		}
		//creating invalid parameters
		list listWith1=NULL;
		listWith1= (list)malloc(sizeof(struct _listnode));
		listWith1->next = NULL;
		list listWith2=NULL;
		listWith2 = (list)malloc(sizeof(struct _listnode));
		listWith2 ->next = (list)malloc(sizeof(struct _listnode));
		listWith2->next->next = NULL;
		element eNUllChecker0 = { .type = LIST, .l = NULL};
		element eNUllChecker1 = { .type = LIST, .l = listWith1 };
		element eNUllChecker2 = { .type = LIST, .l = listWith2 };
		//testing cdr method will return null with invalid parameters
		shouldBeNull=cdr(eNUllChecker0);
		printf("testing crd with invalid parameters:\n");
		if (shouldBeNull == NULL) {
			printf("the type for cdr 1 list is:this is null\n");
		}
		shouldBeNull =cdr(eNUllChecker1);
		if (shouldBeNull == NULL) {
			printf("the type for cdr 2 list is:this is null\n");
		}
		//testing cddr
		list tailOfTail= cddr(fullList);
		printf("Testing cddr:\n");
		printf("the type for the tailOfTail in list is:%d\n", tailOfTail->el.type);
		printf("the atom for the tailOfTail in list is:%c\n", tailOfTail->el.a);
		//testing cddr method will return null with invalid parameters
		printf("Testing cddr with invalid parametrs:\n");
		shouldBeNull= cddr(e1);
		if (shouldBeNull == NULL) {
			printf("the type for ccdr not list is:this is null\n");
		}
		shouldBeNull= cddr(eNUllChecker0);
		if (shouldBeNull == NULL) {
			printf("the type for ccdr 0 list is:this is null\n");
		}
		shouldBeNull= cddr(eNUllChecker1);
		if (shouldBeNull == NULL) {
			printf("the type for ccdr 1 list is:this is null\n");
		}
		shouldBeNull= cddr(eNUllChecker2);
		if (shouldBeNull == NULL) {
			printf("the type for ccdr 2 list is:this is null\n");
		}
		print(fullList);
		lfreer(newListPart1);


		//creating test data to append print and free
		list newListPart3COMBINE1 = (struct list*)malloc(sizeof(list));
		element eListPart3COMBINE1 = { .type = ATOM, .a = 'z' };
		newListPart3COMBINE1->next = NULL;
		newListPart3COMBINE1->el = eListPart3COMBINE1;
		list newListPart2COMBINE1 = (struct list*)malloc(sizeof(list));
		element eListPart2COMBINE1 = { .type = ATOM, .a = 'y' };
		newListPart2COMBINE1->el = eListPart2COMBINE1;
		newListPart2COMBINE1->next = newListPart3COMBINE1;
		list newListPart1COMBINE1 = (struct list*)malloc(sizeof(list));
		element eListPart1COMBINE1 = { .type = ATOM, .a = 'x' };
		newListPart1COMBINE1->el = eListPart1COMBINE1;
		newListPart1COMBINE1->next = newListPart2COMBINE1;


		list newListPart3COMBINE2 = (struct list*)malloc(sizeof(list));
		element eListPart3COMBINE2 = { .type = ATOM, .a = 'c' };
		newListPart3COMBINE2->next = NULL;
		newListPart3COMBINE2->el = eListPart3COMBINE2;
		list newListPart2COMBINE2 = (struct list*)malloc(sizeof(list));
		element eListPart2COMBINE2 = { .type = ATOM, .a = 'b' };
		newListPart2COMBINE2->el = eListPart2COMBINE2;
		newListPart2COMBINE2->next = newListPart3COMBINE2;
		list newListPart1COMBINE2 = (struct list*)malloc(sizeof(list));
		element eListPart1COMBINE2 = { .type = ATOM, .a = 'a' };
		newListPart1COMBINE2->el = eListPart1COMBINE2;
		newListPart1COMBINE2->next = newListPart2COMBINE2;
		//testing apending, printing andd freeing
		list total=append(newListPart1COMBINE2, newListPart1COMBINE1);
		printf("testing combing list\n");
		printf("the type for the PART1 in list is:%d\n", total->el.type);
		printf("the atom for the PART1 in list is:%c\n", total->el.a);
		printf("the type for the PART2 in list is:%d\n", total->next->el.type);
		printf("the atom for the PART2 in list is:%c\n", total->next->el.a);
		printf("the type for the PART3 in list is:%d\n", total->next->next->el.type);
		printf("the atom for the PART3 in list is:%c\n", total->next->next->el.a);
		printf("the type for the PART4 in list is:%d\n", total->next->next->next->el.type);
		printf("the atom for the PART4 in list is:%c\n", total->next->next->next->el.a);
		printf("the type for the PART5 in list is:%d\n", total->next->next->next->next->el.type);
		printf("the atom for the PART5 in list is:%c\n", total->next->next->next->next->el.a);
		printf("the type for the PART6 in list is:%d\n", total->next->next->next->next->next->el.type);
		printf("the atom for the PART6 in list is:%c\n", total->next->next->next->next->next->el.a);

		element eFullList = {.type=LIST, .l= total };
		printf("testing print list\n");
		print(eFullList);
		printf("testing free list\n");
		lfreer(total);
		//creating test date for appending, printing a freeing with sub lists
		list printListPart6 = (list)malloc(sizeof(struct _listnode));
		element elPrintListPart6 = { .type = ATOM, .a = '6' };
		printListPart6->next = NULL;
		printListPart6->el = elPrintListPart6;

		list printListPart5 = (list)malloc(sizeof(struct _listnode));

			list printListPart5SubPart3 = (list)malloc(sizeof(struct _listnode));
			element elPrintListPart5SubPart3 = { .type = ATOM, .a = 'e' };
			printListPart5SubPart3->next = NULL;
			printListPart5SubPart3->el = elPrintListPart5SubPart3;

			list printListPart5SubPart2 = (list)malloc(sizeof(struct _listnode));
			element elPrintListPart5SubPart2 = { .type = ATOM, .a = 'f' };
			printListPart5SubPart2->next = printListPart5SubPart3;
			printListPart5SubPart2->el = elPrintListPart5SubPart2;

			list printListPart5SubPart1 = (list)malloc(sizeof(struct _listnode));
			element elPrintListPart5SubPart1 = { .type = ATOM, .a = 'd' };
			printListPart5SubPart1->next = printListPart5SubPart2;
			printListPart5SubPart1->el = elPrintListPart5SubPart1;

		element elPrintListPart5 = { .type = LIST, .l = printListPart5SubPart1 };
		printListPart5->el = elPrintListPart5;
		printListPart5->next = printListPart6;

		list printListPart4 = (list)malloc(sizeof(struct _listnode));
		element elPrintListPart4 = { .type = ATOM, .a = '4' };
		printListPart4->el = elPrintListPart4;
		printListPart4->next = printListPart5;


		list printListPart3 = (list)malloc(sizeof(struct _listnode));
		element elPrintListPart3 = { .type = ATOM, .a = '3' };
		printListPart3->el = elPrintListPart3;
		printListPart3->next = printListPart4;

		list printListPart2 = (list)malloc(sizeof(struct _listnode));

			list printListPart2SubPart3 = (list)malloc(sizeof(struct _listnode));
			element elPrintListPart2SubPart3 = { .type = ATOM, .a = 'n' };
			printListPart2SubPart3->next = NULL;
			printListPart2SubPart3->el = elPrintListPart2SubPart3;

			list printListPart2SubPart2 = (list)malloc(sizeof(struct _listnode));
			
				list printListPart2SubSubPart3 = (list)malloc(sizeof(struct _listnode));
				element elPrintListPart2SubSubPart3 = { .type = ATOM, .a = '0' };
				printListPart2SubSubPart3->next = NULL;
				printListPart2SubSubPart3->el = elPrintListPart2SubSubPart3;

				list printListPart2SubSubPart2 = (list)malloc(sizeof(struct _listnode));
				element elPrintListPart2SubSubPart2 = { .type = ATOM, .a = '9' };
				printListPart2SubSubPart2->next = printListPart2SubSubPart3;
				printListPart2SubSubPart2->el = elPrintListPart2SubSubPart2;

				list printListPart2SubSubPart1 = (list)malloc(sizeof(struct _listnode));
				element elPrintListPart2SubSubPart1 = { .type = ATOM, .a = '8' };
				printListPart2SubSubPart1->next = printListPart2SubSubPart2;
				printListPart2SubSubPart1->el = elPrintListPart2SubSubPart1;
			
			element elPrintListPart2SubPart2 = { .type = LIST, .l = printListPart2SubSubPart1 };
			printListPart2SubPart2->next = printListPart2SubPart3;
			printListPart2SubPart2->el = elPrintListPart2SubPart2;

			list printListPart2SubPart1 = (list)malloc(sizeof(struct _listnode));
			element elPrintListPart2SubPart1 = { .type = ATOM, .a = 'l' };
			printListPart2SubPart1->next = printListPart2SubPart2;
			printListPart2SubPart1->el = elPrintListPart2SubPart1;


		element elPrintListPart2 = { .type = LIST, .l = printListPart2SubPart1 };
		printListPart2->el = elPrintListPart2;
		printListPart2->next = printListPart3;

		list printListPart1 = (list)malloc(sizeof(struct _listnode));
		element elPrintListPart1 = { .type = ATOM, .a = '1' };
		printListPart1->el = elPrintListPart1;
		printListPart1->next = printListPart2;
		
		printListPart1->next->next->next = NULL;
		//tests is you can append two list who contain elements that poitn to other lists
		list combined2=append(printListPart1 , printListPart4);
		printf("Testing append function with a list contaning sub list ");
		printf("the type for the PART1 in list is:%d\n", combined2->el.type);
		printf("the atom for the PART1 in list is:%c\n", combined2->el.a);
		printf("the type for the PART2 in list is:%d\n", combined2->next->el.type);
		printf("the type for the PART3 in list is:%d\n", combined2->next->next->el.type);
		printf("the atom for the PART3 in list is:%c\n", combined2->next->next->el.a);
		printf("the type for the PART4 in list is:%d\n", combined2->next->next->next->el.type);
		printf("the atom for the PART4 in list is:%c\n", combined2->next->next->next->el.a);
		printf("the type for the PART5 in list is:%d\n", combined2->next->next->next->next->el.type);
		printf("the type for the PART6 in list is:%d\n", combined2->next->next->next->next->next->el.type);
		printf("the atom for the PART6 in list is:%c\n", combined2->next->next->next->next->next->el.a);
		printListPart1->next->next->next = printListPart4;
		element eTest = { .type = LIST, .l = printListPart1 };
		//test printing and freeing with lists contaiing sub lists
		printf("Testing print function with a list contaning sub list ");
		print(eTest);
		printf("Testing free function with a list contaning sub list ");
		lfreer(printListPart1);
		
	}
	
	return 0;
}
/**
creates an element containing the specificed atom
@param a atom
@return element the created element
**/
element aasel(atom a) {
	element newElement = { .type = ATOM, .a = a };
	return newElement;
}
/**
creates an element containing the specificed list
@param l list
@return element the created element
**/
element lasel(list l){
	element newElement = { .type = LIST, .l = l };
	return newElement;
}
/**
gets the head element of the list
@param e element
@return element the head element
**/
element car(element e) {
	//returns NIL if e is not a list
	if (e.type!= LIST) {
		element NIL = { .type = LIST, .l = NULL };
		return NIL;
	}
	list l = e.l;
	element head = l->el;
	return head;
}
/**
gets the tail element of the list
@param e element
@return list the tail of the tail
**/
list cdr(element e){
	//checking to make sure the tail exists
	if (e.type != LIST || e.l==NULL) {
		list NIL = NULL;
		return NIL;
	}
	list l = e.l;
	list tail = l->next;
	if (tail==NULL) {
		list NIL = NULL;
		return NIL;
	}
	else {
		return tail;
	}
}
/**
gets the second tail element of the list 
@param e element
@return list the tail of the tail
**/
list cddr(element e) {
	//checking that the lement contains a tail of tail
	if (e.type != LIST || e.l == NULL) {
		list NIL = NULL;
		return NIL;
	}
	list l = e.l;
	list tail = l->next;
	if (tail == NULL) {
		list NIL = NULL;
		return NIL;
	}
	list tailOfTail = tail->next;
	if (tailOfTail == NULL) {
		list NIL = NULL;
		return NIL;
	}
	else {
		return tailOfTail;
	}
}
/**
takes and element and a list node and adds thenm to a new list node
@param e element
@param l list
@return list the created list
**/
list cons(element e, list l) {
	struct _listnode *newList = NULL;
	newList = (struct _listnode*)malloc(sizeof(struct _listnode));
	newList->el = e;
	newList->next = l;
	return newList;
}
/**
combines two list into one but only allows their shallow copies
@param l1 list
@param l2 list
@return list the cobined list
**/
list append(list l1, list l2) {
	struct _listnode* combinedList = NULL;
	combinedList = (struct _listnode*)malloc(sizeof(struct _listnode));
	combinedList->next = NULL;
	//copies elements of both lists
	while (l1 != NULL) {
		combinedList->el = l1->el;
		struct _listnode* newList = (struct _listnode*)malloc(sizeof(struct _listnode));
		newList->next = combinedList;
		combinedList = newList;
		l1 = l1->next;
	}
	while (l2!=NULL) {	
		combinedList->el = l2->el;
		struct _listnode* newList = (struct _listnode*)malloc(sizeof(struct _listnode));
		newList->next = combinedList;
		combinedList = newList;
		l2 = l2->next;
	}
	
	combinedList = combinedList->next;
	struct _listnode* preveiousList = NULL;
	struct _listnode* currentList = combinedList;
	struct _listnode* nextList;
	//puts the list back in order (when added oginaly to the nes list the elemnts are put in reverse)
	while (currentList != NULL) {
		nextList = currentList->next;
		currentList->next = preveiousList;
		preveiousList = currentList;
		currentList = nextList;
	}

	combinedList = preveiousList;
	
	return combinedList;
}
/**
*  
  free allocated memory of the list and sublists
  @param l list
**/
void lfreer(list l) {
	
	while (l!=NULL) {
		struct _listnode* temList = l;		
		l = l->next;
		temList->next = NULL;
		if (temList->el.type==ATOM) {
			printf("freeing element:%c\n", temList->el.a);
		}
		//if there is an inner list goes into the next elements to free it
		else if(temList->el.type == LIST&& temList->el.l!=NULL) {
			struct _listnode* elList = temList->el.l;
			lfreer(elList);
		}
		free(temList);
	}
	printf("freeing list\n");
	free(l);
}
/**
	prints items in a given list list and the sublist are indicated by barrakets
	@param e element
**/
void print(element e) {
	if ( e.l == NULL&&e.type==LIST) {
		printf("NIL\n");
	}
	else if (e.type == ATOM) {
		printf(" %c ", e.a);
	}
	else {
		
		printf("( ");
		struct _listnode* nextList = e.l;
		//goes throught all the elements of the list
		while (nextList !=NULL) {
			print(nextList->el);
			nextList = nextList->next;
		}
		printf(" )");
	}
}
