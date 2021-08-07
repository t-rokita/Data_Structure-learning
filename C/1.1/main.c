#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

#include "single_list.h"

#define ARRAY_SIZE 1000002

const char * path = "../../numbers.txt";

long double array[ARRAY_SIZE];

bool load_file(FILE** file_) {
    *file_ = fopen(path, "r");
    if((*file_) == NULL) {
        return false;
    }
    fseek((*file_), 0, 0);
    int i = 0;
    while(fscanf((*file_), "%Lf", &array[i]) == 1) { i++; }
    return true;
}

static void close_file(FILE ** file_) {
    fclose((*file_));
}

int main(void) {
    FILE *file;    
    ListElement_type* list;
    clock_t start, stop;
    list = malloc(sizeof(ListElement_type));
    if(!load_file(&file)) {
        exit(EXIT_FAILURE);
    }
    time(&start);
    push_front(&list, array[0]);
    for(int i = 1;i < 99999;i++) {
        push_back(&list, array[i]);
    }

    time(&stop);

    double result = difftime(stop, start);
    
    printf("Czas alokacji %d elementów wynosi: %lf\n", list_size(list), result);

    close_file(&file);
    return 0;
}