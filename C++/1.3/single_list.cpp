#include "single_list.h"
#include <iostream>

void lst::initialize_head(lst::Node ** head) {
    *head = new lst::Node[1];
    (*head)->data = 0;
    (*head)->next = nullptr;
}

void lst::add_to_top(lst::Node ** head, long double value) {
    lst::Node* next;
    next = new lst::Node[1];
    next->data = value;
    next->next = *head;
    *head = next;
}


void lst::append(lst::Node ** head, long double value) {
    if((*head)->next == nullptr) {
        (*head)->data = value;
        (*head)->next = nullptr;
    }
    else {
        lst::Node *current = *head;
        while(current->next != nullptr) {
            current = current->next;
        }

        current->next = new lst::Node[1];
        current->next->data = value;
        current->next->next = nullptr;
    }
    
}
void lst::show(lst::Node * head) {
    if(head->next == nullptr && head->data == 0) {
        std::cout << "No elements" << std::endl;
    }
    else {
        lst::Node* current = head;
        int i = 0;
        do {
            std::cout << " Wartość " << current->data << " elemntu " << i << std::endl; 
            current = current->next;
            i++;
        }while(current->next != nullptr);
    }
}
size_t lst::list_size(lst::Node * head) {
    
    if(head->next == nullptr) {
        return 0;
    }
    else {    
        lst::Node * current = head;
        size_t length = 0;
        do {
            current = current->next;
            length++;
        }while(current->next != nullptr);
        return length;
    }
}