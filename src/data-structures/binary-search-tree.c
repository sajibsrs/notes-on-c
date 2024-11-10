#include <stdlib.h>

#include "binary-search-tree.h"

/// @brief Allocates and initializes a tree node.
/// @param value New node value.
/// @return Pointer to the newly created node, NULL on failure.
static BSTNode *node_construct(int value){
    BSTNode *node;

    node = malloc(sizeof(BSTNode));
    if (node == NULL) {
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

BSTNode *bst_insert(BSTNode *root, int value) {
    if (root == NULL) {
        return node_construct(value);
    }

    if (value < root->value) {
        root->left = bst_insert(root->left, value);
    } else {
        root->right = bst_insert(root->right, value);
    }

    return root;
}

BSTNode *bst_search(BSTNode *root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value == root->value) {
        return root;
    } else if(value < root->value) {
        return bst_search(root->left, value);
    }

    return bst_search(root->right, value);
}

BSTNode *bst_delete(BSTNode *root, int value) {}
void bst_print(BSTNode *root) {}
void bst_destroy(BSTNode *root) {}

// TODO: update comment style
