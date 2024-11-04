#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#ifdef STACK_USE_DYNAMIC_ARRAY

struct StackType {
  Item *contents;
  int top;
  int size;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(int size) {
  Stack stack = malloc(sizeof(struct StackType));
  if (stack == NULL) {
    terminate("Error in create: stack could not be created.");
  }

  stack->contents = malloc(size * sizeof(Item));
  if (stack->contents == NULL) {
    free(stack);
    terminate("Error in create: stack could not be created.");
  }
  stack->top = 0;
  stack->size = size;

  return stack;
}

void destroy(Stack stack) {
  free(stack->contents);
  free(stack);
}

void make_empty(Stack stack) {
  stack->top = 0;
}

bool is_empty(Stack stack) {
  return stack->top == 0;
}

bool is_full(Stack stack) {
  return stack->top == stack->size;
}

void push(Stack stack, Item item) {
  if (is_full(stack)) {
    terminate("Error in push: stack is full.");
  }
  stack->contents[(stack->top)++] = item;
}

Item pop(Stack stack) {
  if (is_empty(stack)) {
    terminate("Error in pop: stack is empty.");
  }
  return stack->contents[--(stack->top)];
}

#endif
