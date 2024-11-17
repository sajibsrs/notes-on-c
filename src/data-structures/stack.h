#ifndef STACK_H
#define STACK_H

#define STACK_USE_LIST
// #define STACK_USE_FIXED_ARRAY
// #define STACK_USE_DYNAMIC_ARRAY

#include <stdbool.h>

// Stack item that'll be stored in stack.
typedef int Item;

// Stack pointer.
typedef struct StackType *Stack;

/**
 * @brief Create new stack.
 * @param void
 * @return Pointer to that stack.
 */
Stack create(void);

/**
 * @brief Destroy the stack and do necessary cleanup.
 * @param stack Pointer to that stack.
 */
void destroy(const Stack stack);

/**
 * @brief Make stack empty.
 * @param stack Pointer to that stack.
 */
void make_empty(const Stack stack);

/**
 * @brief Checks if stack is empty.
 * @param stack
 * @return Boolean
 */
bool is_empty(const Stack stack);

/**
 * @brief Checks if the stack is full.
 * @param stack Pointer to that stack.
 * @return `true` if stack is full `false` otherwise.
 */
bool is_full(const Stack stack);

/**
 * @brief Adds item to the top of the stack.
 * @param stack Pointer to that stack.
 * @param item Stack item.
 */
void push(const Stack stack, const Item item);

/**
 * @brief Removes item from the top of the stack.
 * @param stack Pointer to that stack.
 * @return Removed item.
 */
Item pop(const Stack stack);

#endif
