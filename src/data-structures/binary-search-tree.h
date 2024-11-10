#ifndef BST_H
#define BST_H

/// @brief Binary seach tree node
typedef struct BSTNode {
    BSTNode *left;
    BSTNode *right;
    int value;
} BSTNode;

/// @brief Insert a node to the binary tree.
/// @param root Root node of the tree.
/// @param value Node value.
/// @return Pointer to the new root.
BSTNode *bst_insert(BSTNode *root, int value);

/// @brief Search for a value in the tree.
/// @param root Root node of the tree.
/// @param value Value to search for.
/// @return Returns the node containing the value or NULL.
BSTNode *bst_search(BSTNode *root, int value);

/// @brief Delete a node from the tree.
/// @param root Root node of the tree.
/// @param value Value to delete.
/// @return Root of the tree or NULL.
BSTNode *bst_delete(BSTNode *root, int value);

/// @brief Print the tree.
/// @param root Root of the tree.
void bst_print(BSTNode *root);

/// @brief Delete the whole tree.
/// @param root Root node of the tree.
void bst_destroy(BSTNode *root);

#endif
