#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Queue node type.
 */
typedef struct QueueNode {
  QueueNode *next;
  int value;
} QueueNode;

/**
 * @brief Allocate and initialize queue node.
 * @param value Node value.
 * @return Pointer to the newly created node.
 */
static QueueNode *queue_node_construct(int value);

/**
 * @brief Insert into the queue.
 * @param node Starting node (head).
 * @param value Queue node value.
 * @return Starting node.
 */
QueueNode *queue_insert(QueueNode *node, int value);

#endif
