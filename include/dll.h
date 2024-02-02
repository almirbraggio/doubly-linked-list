#ifndef __DLL__
#define __DLL__

#include <memory.h>
#include <stdlib.h>

/* Header file for Doubly Linked List*/
typedef struct dll_node_ {
    void *data;
    struct dll_node_ *previous;
    struct dll_node_ *next;
} dll_node_t;

typedef struct dll_ {
    dll_node_t *front;
    dll_node_t *back;
} dll_t;

/* Public Function declaration to create and return
 * a new empty doubly linked list*/
dll_t *dll_new();
void dll_free(dll_t *dll);

/* Public Function declaration to add a new application
 * data to DLL*/
/* return 0 on success, -1 on failure*/
int dll_add_data_front(dll_t *dll, void *app_data);
int dll_add_data_back(dll_t *dll, void *app_data);

int  dll_remove_front(dll_t *dll);
int  dll_remove_back(dll_t *dll);

int dll_empty(dll_t *dll);

#endif
