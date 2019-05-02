/*
JTSK-320112
stack.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

/*struct stack */
typedef struct stack
{
    unsigned int count; //no of words in a sentence
    char word[20][100]; // max 20 words in this array
} stack ;

stack q; //global struct so that local changes reflected everywhere


/* @brief isEmpty checks if the stack is empty
@param stack *p ptr to stack
@return 0 if empty, -1 if not */
int isEmpty(stack *p);


/* @brief print_arr prints words in stack
@param stack *p ptr to stack
@return void */
void print_arr(stack *p);


/*@brief push puts words at top of stack
@param stack *p ptr to stack
@param char* my_words word to be added to stack */
void push(stack *p, char* my_words, int x);

/* @brief reverse stores words in another stack in reverse order
@param stack *p ptr to stack of actual order
@return ptr to global stack q (which is not reverse stack) */
stack* reverse(stack *p);

/* @brief pop removes top element of stack
@param stack *p ptr to stack
@return ptr to char
*/
char* pop(stack *p);

/*@brief empty empties the stack
@param stack *p ptr to stack */
void empty(stack *p);






