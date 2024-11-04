#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#ifdef STACK_USE_FIXED_ARRAY

#define STACK_SIZE 100

struct StackType {
  Item contents[STACK_SIZE];
  int top;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void) {
  Stack s = malloc(sizeof(struct StackType));
  if (s == NULL) {
    terminate("Error in create: stack could not be created.");
    s->top = 0;

    return s;
  }
}

void destroy(Stack stack) {
  free(stack);
}

void make_empty(Stack stack) {
  stack->top = 0;
}

bool is_empty(Stack stack) {
  return stack->top == 0;
}

bool is_full(Stack stack) {
  return stack->top == STACK_SIZE;
}

void push(Stack stack, Item item) {
  if (is_full(stack)) {
    terminate("Error in push: stack is full.");
  }
  stack->contents[stack->top++] = item;
}

Item pop(Stack stack) {
  if (is_empty(stack)) {
    terminate("Error in pop: stack is empty.");
  }
  return stack->contents[--stack->top];
}

#endif
