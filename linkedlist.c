#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list(struct node * head) {
    if (head == NULL) printf("EMPTY");
    while ( head != NULL) {
        printf("%d -> ", head->i);
        head = head->next;
    }
    printf("\n");
}


struct node * insert_front(struct node * head, int data) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->i = data;
    new->next = head;
    return new;
} 

struct node * insert_order(struct node * head, int data) {
    
    struct node *current = head;
    if (! current) return insert_front(NULL, data); //if head is null, insert in front
    if (data < current->i) return insert_front(head, data); //if head is greater than value, insert in front
    
    while (current->next) {
        if (current->next->i >= data) {
            current->next = insert_front(current->next, data); //if the data has a place between two nodes
            return head;
        }
        current = current->next;
    }
    
    current->next = insert_front(current->next, data);
    return head;
    // if current doesn't have a next but it hasn't beeen sorted
}

struct node * free_list(struct node * head) {
    struct node * nxt;
    struct node * frst;
    while ( head != NULL) {
        nxt = head->next;
        free(head);
        head = nxt;
    }
    frst = NULL;
    return frst;
}

/*int main() {
    struct node * q = insert_front(NULL, 2);
    q = insert_order(q, -2);
    q = insert_order(q, 8);
    q = insert_order(q, 5);
    q = insert_order(q, 3);
    q = insert_order(q, 52);
    q = insert_order(q, 6);
    q = insert_order(q, -5);
    q = insert_order(q, 6);
    q = insert_order(q, -54);
    q = insert_order(q, -54);
    q = insert_order(q, 52);
    print_list(q);
} */
