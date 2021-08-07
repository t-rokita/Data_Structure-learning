#include "single_list.h"

#include <stdlib.h>
#include <stdio.h>

void push_front(ListElement_type **head, int number)
{ 
    ListElement_type *current;
    current=(ListElement_type *)malloc(sizeof(ListElement_type));
 
    current->data=number;
    current->next=(*head);
    *head=current;
 
}
 
void push_back(ListElement_type **head, int number)
{
	if(*head==NULL)
	{
		*head = (ListElement_type *)malloc(sizeof(ListElement_type));
   		(*head)->data = number;
    	(*head)->next = NULL;
	}else
	{
		ListElement_type *current=*head;
	
	    while (current->next != NULL) {
	        current = current->next;
	    }
	
	    current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
	    current->next->data = number;
	    current->next->next = NULL;	
	}
}
 
void push_by_back(ListElement_type **head, int number, int position)
{
	if(position==0) push_front(head, number);
	else
	{
		if(position==list_size(*head)) push_back(head, number);
		else
		{
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
            current->next->next=tmp;
        }
	}
		
		
}
 
void pop_front(ListElement_type **head)
{
    ListElement_type * tmp=NULL;
 
    if (*head!=NULL) {
   	 tmp=(*head)->next;
   	 free(*head);
   	 *head=tmp;	
	}    
}
 
void pop_back(ListElement_type **head)
{   
	if((*head)->next==NULL)
	{	
		*head=NULL;	
	}else
	{
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
	else
	{
		ListElement_type *current=*head;
	    ListElement_type *tmp;
		
		int i=0;
		while (current->next != NULL && i<position-1) {
	        current=current->next;
			i++;    
			}
			
		tmp = current->next;
	    current->next = tmp->next;
	    free(tmp);	
	}
	
 
}
void show(ListElement_type *head)
{
    printf("\n");
    if(head==NULL) printf("List is empty");
    else
    {
        ListElement_type *current=head;
            do {
            printf("%Lf", current->data);
            printf("\n");
            current = current->next;
            }while (current != NULL);
 
    }
}
 
int list_size(ListElement_type *head)
{
    int counter=0;
    if(head==NULL) return counter;
    else
    {
        ListElement_type *current=head;
            do {
            counter++;
            current = current->next;
            }while (current != NULL);
    }
    return counter;
}