/*
JTSK-320112
stack.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

typedef struct Stack
{
    unsigned int count;
    int array[12]; // Container
} stack;

/*@brief isEmpty checks if stack is empty
@param stack *p ptr to stack structure
@return returns 0 if empty, -1 else*/
int isEmpty(stack *p);


/*@brief print_arr prints elements in stack
@param stack *p ptr to stack
@return void */
void print_arr(stack *p);


/*@brief push adds element to top of stack
@param stack *p ptr to stack structure
@param x integer to be added
*/
void push(stack *p, int x);



/* @brief pop removes first element of stack
@param stack *p ptr to stack structure
@return 0 if empty, and removed element if popping was successful */
int pop(stack *p);


/*@brief empty empties the stack
@param stack *p ptr to stack structure
@return nothing */
void empty(stack *p);
