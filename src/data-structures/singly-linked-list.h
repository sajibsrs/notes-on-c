#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/// @brief Singly linked list node.
typedef struct SinglyLinkedListNode {
  struct SinglyLinkedListNode *next;
  int value;
} SinglyLinkedListNode;

/// @brief Insert a node into the list.
/// @param node Node to be replaced.
/// @param val Value of the new node.
/// @return Pointer to the new node.
SinglyLinkedListNode *list_insert(SinglyLinkedListNode *node, int val);

/// @brief Search a list.
/// @param node Node to start from.
/// @param val Value to be searched.
/// @return Pointer to the node or NULL.
SinglyLinkedListNode *list_search(SinglyLinkedListNode *node, int val);

/// @brief Delete a node from list.
/// @param node Node start seach from.
/// @param val Value to find.
/// @return Returns the new list node.
SinglyLinkedListNode *list_delete(SinglyLinkedListNode *node, int val);

/// @brief Print the list.
/// @param node Node to start.
void list_print(SinglyLinkedListNode *node);

/// @brief Remove a list.
/// @param node First node (head).
void list_destruct(SinglyLinkedListNode **node);

#endif
