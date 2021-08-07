#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <boost/smart_ptr/make_shared_array.hpp>
#include <boost/smart_ptr/allocate_shared_array.hpp>


// TODO: MAKE GOOD EXEPTION HANDLING

namespace starr
{
    template<typename array_type, const size_t size> class static_array final
    {
    private:
        boost::shared_ptr<array_type[]> array;
        const size_t array_size;
        size_t length;
    public:
        static_array() : array_size(size), length(0) {
            this->array = boost::make_shared<array_type[]>(array_size);
        }

        ~static_array() = default;

        void append(array_type value) {
            try {
                if(this->length == size) {
                    throw std::out_of_range("Out of range");
                }
                this->array[this->length] = value;
                this->length++;
            }
            catch(std::out_of_range &e) {
                std::cerr << "Out of range " << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        bool is_Empty(void) { return this->array_size == 0; }
        constexpr array_type getValue(size_t index) const {
            try {
                if(index < 0 || index > this->array_size) {
                    throw std::out_of_range("Out of array range");
                }
                return array[index];
            }
            catch(std::out_of_range& e) {
                std::cerr << "Cannot access that element: Out of range" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        constexpr size_t getSize(void) const { return this->array_size; }
        constexpr size_t getLength(void) const { return this->length; }
        void at(size_t index, array_type value) {
            try {
                if(index < 0 || index > this->array_size) {
                    throw std::out_of_range("Out of array range");
                }
                this->array[index] = value;
            }
            catch(std::out_of_range& e) {
                std::cerr << "Cannot access that element: Out of band" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        void clear(void) {
            for(size_t i = 0; i < this->array_size; i++) {
                array[i] = 0;
            }
        }

        constexpr array_type& operator[](size_t index) {
            return this->array[index];
        }

        template<typename A, const size_t size2>
        friend std::ostream& operator<<(std::ostream& out, const static_array<A, size2>& arr);

        template<typename A, const size_t size2>
        friend void quicksort(static_array<A, size2>& array);

        template<typename A, const size_t size2>
        friend bool binary_search(const static_array<A, size2>& array, A value_to_search);
    };


    template<typename array_type, const size_t size>
    std::ostream& operator<<(std::ostream& out, const static_array<array_type, size>& arr) {
        for(size_t i = 0; i < arr.getLength(); i++) {
            out << arr.array[i] << std::endl;
        }
        return out;
    }
    template<typename array_type, const size_t size>
    void quicksort(static_array<array_type, size>& array) {
        std::sort(&array.array[0], &array.array[array.length]);
    }
    template<typename array_type, const size_t size>
    bool binary_search(const static_array<array_type, size>& array, array_type value_to_search) {
        return std::binary_search(&array.array[0], &array.array[array.length], value_to_search);
    }


} // namespace starr
