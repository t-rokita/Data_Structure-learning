#include <iostream>
#include "dynamic_array.hpp"
#include <boost/array.hpp>

int main(void) {
    darr::Dynamic_Array<int> array;
    for(int i = 0; i < 10; i++) {
        array.append(i);
    }
    std::cout << array << std::endl;
 
    return 0;
}