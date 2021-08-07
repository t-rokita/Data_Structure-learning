#include <bits/stdc++.h>
#include <iostream>
#include "single_list.h"
#include <fstream>
#include <vector>

const char * path = "../../numbers.txt";
const unsigned int max_size = 10e6;

bool load_file (std::vector<long double>& out) {
    std::fstream file;
    long double number;   
    file.open(path, std::ios::in);
    if(file.good() == false) {
        std::cerr << "Cannot open the file " << std::endl;
        return false;
    }
    else {
        unsigned int i = 0;
        while(i < max_size) {
            file >> number; 
            out.push_back(number);
            i++;
        }
        return true;
    }

}

int main(void) {
    std::vector<long double> out;
    if(!load_file(out)) {
        std::cerr << "Cannot open file " << std::endl;
        fflush(stderr);
        return 1;
    }
    lst::Node* head;
    lst::initialize_head(&head);
    lst::append(&head, 4.5);
    lst::append(&head, 5.5);
    // for(auto x : out) {
    //     lst::append(&head, x);
    // }
    lst::show(head);
    char c = getchar();
    return 0;
}
