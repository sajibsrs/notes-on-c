#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

/// @brief Singly linked list node.
typedef struct SinglyLinkedListNode {
  struct SinglyLinkedListNode* next;
  int value;
} SinglyLinkedListNode;

/// @brief Construct a new Node.
/// @param val Value of the new node.
/// @return Pointer to the new node.
static SinglyLinkedListNode* node_construct(int val);

/// @brief Insert a node into the list.
/// @param node Node to be replaced.
/// @param val Value of the new node.
/// @return Pointer to the new node.
SinglyLinkedListNode* list_insert(SinglyLinkedListNode* node, int val);

/// @brief Search a list.
/// @param node Node to start from.
/// @param val Value to be searched.
/// @return Pointer to the node or NULL.
SinglyLinkedListNode* list_search(SinglyLinkedListNode* node, int val);

/// @brief Delete a node from list.
/// @param node Node start seach from.
/// @param val Value to find.
/// @return Returns the new list node.
SinglyLinkedListNode* list_delete(SinglyLinkedListNode* node, int val);

/// @brief Print the list.
/// @param node Node to start.
void list_print(SinglyLinkedListNode* node);

/// @brief Remove a list.
/// @param node First node (head).
void list_destruct(SinglyLinkedListNode** node);

#endif
