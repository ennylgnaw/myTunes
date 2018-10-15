#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    struct node * linked_list;
    struct node * p = malloc(sizeof(struct node));

    printf("Creating a new linked list... Adding a new node storing the value 2.\n");
    linked_list = insert_order(NULL, 2);
    print_list(linked_list);
    
    printf("Adding a new node storing the value 140.\n");
    linked_list = insert_order(linked_list, 140);
    print_list(linked_list);
    
    printf("Adding a new node storing the value 12.\n");
    linked_list = insert_order(linked_list, 12);
    print_list(linked_list);
    
    printf("Adding a new node storing the value -2.\n");
    linked_list = insert_order(linked_list, -2);
    print_list(linked_list);
}
