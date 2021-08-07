#pragma once
#include <cstdlib>
#include <vector>
namespace lst {
    class Node {
    public:
        long double data;
        Node * next;
    };

    void initialize_head(lst::Node ** head);
    void append(lst::Node ** head, long double value);
    void add_to_top(lst::Node ** head, long double value); 
    void show(lst::Node * head);
    void push_by_index(lst::Node ** head, long double number, size_t index);
    size_t list_size(lst::Node * head);
}
