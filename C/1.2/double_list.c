#include "double_list.h"

#include <stdio.h>
#include <stdlib.h>

void push_front(ListElement_type **head, int number)
{	
    if(*head==NULL) {
    	*head = (ListElement_type *)malloc(sizeof(ListElement_type));
   		(*head)->data = number;
   		(*head)->previous=NULL;
    	(*head)->next = NULL;
	} else {
		ListElement_type *current;
    	        current=(ListElement_type *)malloc(sizeof(ListElement_type));
    	        current->data=number;
    	        current->previous=NULL;
    	        current->next=(*head);
    	        (*head)->previous=current;
    	        *head=current;
	}
}
 
void push_back(ListElement_type **head, int number)
{
	if(*head==NULL) {
		*head = (ListElement_type *)malloc(sizeof(ListElement_type));
   		(*head)->data = number;
   		(*head)->previous = NULL;
    	(*head)->next = NULL;
	}
    else {
		ListElement_type *current=*head;
	
	    while (current->next != NULL) {
	        current = current->next;
	    }
	
	    current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
	    current->next->data = number;
	    current->next->previous=current;
	    current->next->next = NULL;	
	}
}
 
void push_by_index(ListElement_type **head, int number, int position)
{
	if(position==0) push_front(head, number);
	else {
		if(position==list_size(*head)) push_back(head, number);
		else {
			ListElement_type *current=*head;
   			ListElement_type *tmp;
 
			int i=0;
  			while (current->next != NULL && i<position-1) {
            	current = current->next;
      			i++;
    		}	
    		
            tmp=current->next;
            current->next=(ListElement_type *)malloc(sizeof(ListElement_type));
            current->next->data=number;
            current->next->previous=current;
            tmp->previous=current->next;
            current->next->next=tmp;
           
        }
	}	
}
 
void pop_front(ListElement_type **head)
{
 
    if (*head!=NULL) {
    	if((*head)->next==NULL) {
    		*head=NULL;
		} else {
			ListElement_type *tmp;
			tmp=(*head)->next;
   			free(*head);
   			*head=tmp;
   	 		(*head)->previous=NULL;
		}
   	 
	}
    
}
 
void pop_back(ListElement_type **head)
{
    
	if((*head)->next==NULL) {	
		*head=NULL;	
	}
    else {
		ListElement_type *current=*head;
		while (current->next->next!= NULL) {
        current = current->next;
    	}
   		 free(current->next);
   		 current->next=NULL;
	}   
}
 
 
void pop_by_index(ListElement_type **head, int position)
{
	if(position==0) pop_front(head);
	else {
		ListElement_type *current=*head;
	    ListElement_type *tmp;
		
		int i=0;
		while (current->next != NULL && i<position-1) {
	        current=current->next;
			i++;    
		}
			
		tmp = current->next;
	    current->next = tmp->next;
	    current->next->previous=current;
	    free(tmp);	
	}
}
 
void show(ListElement_type *head)
{
    printf("\n");
    if(head==NULL) printf("List is empty");
    else {
        ListElement_type *current=head;
        do {
            printf("%Lf", current->data); 
            printf("\n");
            current = current->next;
        }while (current != NULL);
    }
}
 
void show_reverse(ListElement_type *head)
{
    printf("\n");
    if(head==NULL) printf("List is empty");
    else {
        ListElement_type *current=head;
        while (current->next != NULL) {
            current = current->next; 
        }
        
        do {
        	printf("%Lf ", current->data); 
            printf("\n");
            current = current->previous;
		}while(current!=NULL);
 
    }
}
 
 
int list_size(ListElement_type *head)
{
    int counter=0;
    if(head==NULL) return counter;
    else {
        ListElement_type *current=head;
            do {
            counter++;
            current = current->next;
            }while (current != NULL);
    }
    return counter;
}