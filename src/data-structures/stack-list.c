#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef STACK_USE_LIST

struct Node {
    Item data;
    struct Node *next;
};

struct StackType {
    struct Node *top;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack stack = malloc(sizeof(struct StackType));
    if (stack == NULL) {
        terminate("Error in create: stack could not be created.");
    }
    stack->top = NULL;
    return stack;
}

void destroy(const Stack stack) {
    make_empty(stack);
    free(stack);
}

void make_empty(const Stack stack) {
    while (!is_empty(stack)) {
        pop(stack);
    }
}

bool is_empty(const Stack stack) {
    return stack->top == NULL;
}

bool is_full(const Stack stack) {
    return false;
}

void push(const Stack stack, const Item i) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
        terminate("Error in push: stack is full.");
    }

    node->data = i;
    node->next = stack->top;
    stack->top = node;
}

Item pop(const Stack stack) {
    if (is_empty(stack)) {
        terminate("Error in pop: stack is empty.");
    }

    struct Node *old_top = stack->top;
    Item item = old_top->data;

    stack->top = old_top->next;
    free(old_top);

    return item;
}

#endif
