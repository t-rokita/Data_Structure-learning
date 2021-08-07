#include <iostream>
#include <cstdlib>
#include <ctime>
#include "static_array.hpp"

int main(void) {
    srand(time(NULL));
    starr::static_array<int, 32> array;
    for(int i = 0; i < 20; i++) {
        // array.append(rand() % 100000 + 1);
        array.append(i);
    }
    
    std::cout << array.getSize() << std::endl;
    std::cout << array.getLength() << std::endl;
    starr::quicksort(array);
    std::cout << array << '\n';
    if( starr::binary_search(array, 32) == true) {
        std::cout << "This element exist in array\n";
    }
    else {
        std::cout << "This element doesn't exist in array\n";
    }

    
    return 0;
}