#ifndef LINKED_LIST
#define LINKED_LIST

/// @brief Singly linked list node.
typedef struct list_node {
  struct list_node* next;
  int value;
} Node;

/// @brief Construct a new Node.
/// @param val Value of the new node.
/// @return Pointer to the new node.
static Node* node_construct(int val);

/// @brief Insert a node into the list.
/// @param node Node to be replaced.
/// @param val Value of the new node.
/// @return Pointer to the new node.
Node* list_insert(Node* node, int val);

/// @brief Search a list.
/// @param node Node to start from.
/// @param val Value to be searched.
/// @return Pointer to the node or NULL.
Node* list_search(Node* node, int val);

/// @brief Delete a node from list.
/// @param node Node start seach from.
/// @param val Value to find.
/// @return Returns the new list node.
Node* list_delete(Node* node, int val);

/// @brief Print the list.
/// @param node Node to start.
void list_print(Node* node);

#endif
