#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

static Node* node_construct(int val) {
  Node* node = malloc(sizeof(Node));
  node->value = val;
  node->next = NULL;

  return node;
}

Node* list_insert(Node* node, int val) {
  printf("insert %d\n", val);

  Node* ptr = node_construct(val);
  ptr->next = node;

  return ptr;
}

Node* list_search(Node* node, int val) {
  printf("Searching for value: %d\n", val);

  Node* ptr = node;

  while (ptr != NULL) {
    if ((ptr->value) == val) {
      return ptr;
    }
    ptr = ptr->next;
  }
  return ptr;
}
