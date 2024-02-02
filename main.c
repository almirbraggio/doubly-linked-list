#include <stdio.h>
#include "dll.h"

/* Application specific data structures */
typedef struct measure {
    int id;
    float value;    
} measure_t;

static void print_measure_details(measure_t *measure) {
    printf("%d: %.2f\r\n", measure->id, measure->value);
}

static void print_all_measures(dll_t *dll) {
    if (!dll || !dll_empty(dll)) {
        return;
    }

    dll_node_t *ptr = dll->front;
    measure_t *data = NULL;

    while(ptr) {
        data = ptr->data;
        print_measure_details(data);
        ptr = ptr->next;
    }
}

static void print_all_measures_reverse(dll_t *dll) {
    if (!dll || !dll_empty(dll)) {
        return;
    }

    dll_node_t *ptr = dll->back;
    measure_t *data = NULL;

    while(ptr) {
        data = ptr->data;
        print_measure_details(data);
        ptr = ptr->previous; 
    }
}

int main(int argc, char **argv) {
    measure_t *m1 = calloc(1, sizeof(measure_t));
    m1->id = 1;
    m1->value = 25.5;

    measure_t *m2 = calloc(1, sizeof(measure_t));
    m2->id = 2;
    m2->value = 30.1;

    measure_t *m3 = calloc(1, sizeof(measure_t));
    m3->id = 3;
    m3->value = 99.9888;

    dll_t *my_dll = dll_new();
    dll_add_data_front(my_dll, m2);
    dll_add_data_back(my_dll, m3);
    dll_add_data_front(my_dll, m1);

    print_all_measures(my_dll);

    dll_remove_front(my_dll);
    print_all_measures(my_dll);

    dll_remove_back(my_dll);
    print_all_measures(my_dll);

    dll_empty(my_dll) ? printf("DLL is not empty\r\n") : printf("DLL is empty\r\n");

    dll_free(my_dll);
    print_all_measures(my_dll);

    dll_empty(my_dll) ? printf("DLL is not empty\r\n") : printf("DLL is empty\r\n");

    return 0;
}