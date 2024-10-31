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
  Node* ptr = node_construct(val);
  ptr->next = node;

  return ptr;
}

Node* list_search(Node* node, int val) {
  Node* ptr = node;

  while (ptr != NULL) {
    if ((ptr->value) == val) {
      return ptr;
    }
    ptr = ptr->next;
  }
  return ptr;
}

Node* list_delete(Node* node, int val) {
  if (node == NULL) {
    return NULL;
  }

  if (node->value == val) {
    Node* tmp = node;
    node = node->next;
    free(tmp);

    return node;
  }

  Node* prev = node;
  Node* curr = node->next;

  while (curr != NULL && curr->value != val) {
    prev = curr;
    curr = curr->next;
  }

  if (curr != NULL) {
    prev->next = curr->next;
    free(curr);
  }
  return node;
}

void list_print(Node* node) {
  if (node == NULL) {
    printf("NULL\n");
    return;
  }

  while (node != NULL) {
    printf("%d -> ", node->value);
    node = node->next;
  }
  printf("NULL\n");
}

void list_destruct(Node** node) {
  if (node == NULL) {
    return;
  }

  Node* current = *node;

  while (current != NULL) {
    Node* tmp = current;
    current = current->next;
    printf("removing: %d\n", tmp->value);
    free(tmp);
  }
  *node = NULL;
}
