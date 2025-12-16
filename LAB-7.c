#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->prev = n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }
    struct node *t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;
}

void insert_left(int key, int x) {
    struct node *t = head;
    while (t != NULL && t->data != key)
        t = t->next;

    if (t == NULL) return;

    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = t;
    n->prev = t->prev;

    if (t->prev != NULL)
        t->prev->next = n;
    else
        head = n;

    t->prev = n;
}

void del(int key) {
    struct node *t = head;
    while (t != NULL && t->data != key)
        t = t->next;

    if (t == NULL) return;

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);
}

void display() {
    struct node *t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    create(1);
    create(2);
    create(3);

    insert_left(2, 5);
    del(3);

    display();
    return 0;
}
