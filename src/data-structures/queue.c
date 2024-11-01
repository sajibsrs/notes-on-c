#include <stdlib.h>

#include "queue.h"

static QueueNode *queue_node_construct(int value) {
  QueueNode *node = malloc(sizeof(QueueNode));

  if (node == NULL) {
    return NULL;
  }

  node->value = value;
  node->next = NULL;

  return node;
}

QueueNode *queue_insert(QueueNode *node, int value) {
  if (node == NULL) {
    return queue_node_construct(value);
  }

  QueueNode *curr = node;

  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = queue_node_construct(value);

  return node;
}
