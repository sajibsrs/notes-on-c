#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

static SinglyLinkedListNode* node_construct(int val) {
  SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));
  if (node == NULL) {
    return NULL;
  }
  node->value = val;
  node->next = NULL;

  return node;
}

SinglyLinkedListNode* list_insert(SinglyLinkedListNode* node, int val) {
  SinglyLinkedListNode* ptr = node_construct(val);
  ptr->next = node;

  return ptr;
}

SinglyLinkedListNode* list_search(SinglyLinkedListNode* node, int val) {
  SinglyLinkedListNode* ptr = node;

  while (ptr != NULL) {
    if ((ptr->value) == val) {
      return ptr;
    }
    ptr = ptr->next;
  }
  return ptr;
}

SinglyLinkedListNode* list_delete(SinglyLinkedListNode* node, int val) {
  if (node == NULL) {
    return NULL;
  }

  if (node->value == val) {
    SinglyLinkedListNode* tmp = node;
    node = node->next;
    free(tmp);

    return node;
  }

  SinglyLinkedListNode* prev = node;
  SinglyLinkedListNode* curr = node->next;

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

void list_print(SinglyLinkedListNode* node) {
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

void list_destruct(SinglyLinkedListNode** node) {
  if (node == NULL || *node == NULL) {
    return;
  }

  SinglyLinkedListNode* current = *node;

  while (current != NULL) {
    SinglyLinkedListNode* tmp = current;
    current = current->next;
    printf("removing: %d\n", tmp->value);
    free(tmp);
  }
  *node = NULL;
}
