#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct ListElement {
    long double data;
    struct ListElement * next;
} ListElement_type;

void show(ListElement_type *head);
void push_front(ListElement_type **head, int number);
void push_back(ListElement_type **head, int number);
void push_by_index(ListElement_type **head, int number, int position);
void pop_front(ListElement_type **head);
void pop_back(ListElement_type **head);
void pop_by_index(ListElement_type **head, int position);

int list_size(ListElement_type *head);

#endif