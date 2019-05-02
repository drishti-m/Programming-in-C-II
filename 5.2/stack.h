/*
JTSK-320112
stack.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

typedef struct Stack
{
    unsigned int count;
    int array[32]; // Container
} stack;




/**
 * @brief print_arr Prints elements from stack.
 *
 * @param stack *p The pointer to stack structure
 *
 * @return Returns void
 */
void print_arr(stack *p);




/**
 * @brief push puts element at top of stack
 *
 * @param stack *p The pointer to stack structure
 *
 * @return Returns void
 */
void push(stack *p, int x);


