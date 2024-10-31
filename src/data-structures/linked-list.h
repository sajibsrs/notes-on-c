#ifndef LINKED_LIST
#define LINKED_LIST

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

#endif
