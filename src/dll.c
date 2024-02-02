#include "dll.h"

/* Public Function Implementation to create and return
 * new empty doubly linked list*/
dll_t* dll_new() {
    dll_t *dll = (dll_t *)calloc(1, sizeof(dll_t));

    if (!dll) {
        exit(EXIT_FAILURE);
    }

    dll->front = NULL;
    dll->back = NULL;
    return dll;
}

void dll_free(dll_t *dll) {
    while(dll_empty(dll) != 0) {
        dll_remove_back(dll);
    }
}

/* Add to DLL*/
int dll_add_data_front(dll_t *dll, void *app_data) {
    if (!dll || !app_data)
        return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->previous = NULL;
    dll_new_node->next = NULL;
    dll_new_node->data = app_data;

    // If is empty, add this to the front
    if(dll_empty(dll) == 0) {
        dll->front = dll->back = dll_new_node;
    }
    else {
        dll->front->previous = dll_new_node;
        dll_new_node->next = dll->front;
        dll->front = dll_new_node;
    }
    return 0;
}

/* Add to DLL*/
int dll_add_data_back(dll_t *dll, void *app_data) {
    if (!dll || !app_data)
        return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->previous = NULL;
    dll_new_node->next = NULL;
    dll_new_node->data = app_data;

    if(dll_empty(dll) == 0) {
        dll->front = dll->back = dll_new_node;
    }
    else {
        dll->back->next = dll_new_node;
        dll_new_node->previous = dll->back;
        dll->back = dll_new_node;
    }
    return 0;
}

int  dll_remove_front(dll_t *dll) {
    dll_node_t *to_remove = NULL;
    
    if ((dll == NULL) || (dll_empty(dll) == 0)) {
        return -1;
    }
    to_remove = dll->front;
    if (dll->front == dll->back) {
        dll->front = dll->back = NULL;
    }
    else {
        dll->front = dll->front->next;
        dll->front->previous = NULL;
    }
    free(to_remove->data);
    free(to_remove);
    return 0;
}

int  dll_remove_back(dll_t *dll) {
    dll_node_t *to_remove = NULL;
    
    if ((dll == NULL) || (dll_empty(dll) == 0)) {
        return -1;
    }
    to_remove = dll->back;
    if (dll->front == dll->back) {
        dll->front = dll->back = NULL;
    }
    else {
        dll->back = dll->back->previous;
        dll->back->next = NULL;
    }
    free(to_remove->data);
    free(to_remove);
    return 0;
}

/* return 0 if empty, -1 if not empty
 */
int dll_empty(dll_t *dll) {
    if((dll->front == NULL) && (dll->back == NULL)) {
        return 0;
    }
    return -1;
}
