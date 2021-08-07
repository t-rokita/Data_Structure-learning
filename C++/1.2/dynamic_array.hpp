#pragma once 

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <memory>

namespace darr {
    template <typename array_type> class Dynamic_Array {
    private:
        std::shared_ptr<array_type*> arr;
        unsigned int length_;
        unsigned int capacity_;
    public:
        Dynamic_Array() : length_(0), capacity_(0) { }
        unsigned int capacity(void) { return capacity_; }
        unsigned int length(void) { return length_; }
        void clear() {
            for(int i = 0;i < this->capacity_;i++) {
                this->arr[this->capacity_] = nullptr;
            }
            this->length_ = 0;   
        }
        void at(array_type value, size_t index) {
             if(index < 0 || index > this->capacity_) {
                std::cerr << "Index has to be more than zero and less then capacity" << std::endl;
            }
            else {
                this->arr[index] = value;
            }
        }
        bool is_Empty() { return length_ == 0;}
        void append(array_type value){
            if(this->capacity_ == 0) {
                this->arr = (array_type *) malloc(sizeof(array_type) * 2);
                this->capacity_ = 2;
            }
            else {
                if(this->length_ + 1 >= this->capacity_) {
                    this->capacity_ *= 2;
                    this->arr = (array_type *) realloc(this->arr, sizeof(array_type) * this->capacity_);
                }
            }
            this->arr[this->length_] = value;
            this->length_++;
            
        }
        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const Dynamic_Array<U> arr);
    };

    template<typename array_type>
    void sort(Dynamic_Array<array_type>& array, unsigned int low_bounder, unsigned int upper_bounder) {
        if(low_bounder < 0 || upper_bounder > array.length() ) {
            return;
        }
        unsigned int half_of_table = array.length() / 2;
        
        fix_sort(array, low_bounder, half_of_table - 1);
        fix_sort(array, half_of_table + 1, upper_bounder);


    }

    using index_t = unsigned int;

    // template<typename array_type>
    // index_t search(Dynamic_Array<array_type>& array, array_type element) {

    // }

    template<typename array_type>
    std::ostream& operator<<(std::ostream& out, const Dynamic_Array<array_type> array) {
        for(unsigned int i = 0; i < array.length_;i++) {
            out << array.arr[i] << std::endl;
        }
        return out;
    }
}