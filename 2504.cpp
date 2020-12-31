#include <iostream>
#include <string.h>
using namespace std;

const int MAX_LEN = 30;
typedef char Data;

struct Stack
{
    Data items[MAX_LEN];
    int top;
};

// Make stack empty
void InitStack(Stack *pstack);
// Check whether stack is full
bool IsFull(Stack *pstack);
// Check whether stack is empty
bool IsEmpty(Stack *pstack);

// Read the item at the top
Data Peek(Stack *pstack);
// Insert an item at the top
void Push(Stack *pstack, Data item);
// Remove the item at the top   
void Pop(Stack *pstack);

int ParenKind(char paren);
bool IsRight(Stack *pstack, char paren);
int BlockLen(char pParenArr[], int len);
int CalParenVal(char pParenArr[], int len);

int main(void)
{
    char parenArr[MAX_LEN];
    cin >> parenArr;
    cout << CalParenVal(parenArr, strlen(parenArr));
    return 0;
}

void InitStack(Stack *pstack)
{
    pstack->top = -1;
}

bool IsFull(Stack *pstack)
{
    return (pstack->top == MAX_LEN - 1);
}

bool IsEmpty(Stack *pstack)
{
    return (pstack->top == -1);
}

Data Peek(Stack *pstack)
{
    if (IsEmpty(pstack))
        exit(1);
    else
        return (pstack->items[pstack->top]);
}

void Push(Stack *pstack, Data item)
{
    if (IsFull(pstack))
        exit(1);
    else
        pstack->items[++(pstack->top)] = item;
}

void Pop(Stack *pstack)
{
    if (IsEmpty(pstack))
        exit(1);
    else
        pstack->top -= 1;
}

int ParenKind(char paren)
{
    switch(paren)
    {
        case '(':
            return 0;
        case '[':
            return 1;
        case ')':
            return 2;
        case ']':
            return 3;
    }
}

bool IsRight(Stack *pstack, char paren)
{
    return ( ParenKind(pstack->items[pstack->top]) == ParenKind(paren) - 2 );
}

int BlockLen(char pParenArr[], int len)
{
    Stack stack;
    char target = (pParenArr[0] == '(') ? ')' : ']';
    int i;
    InitStack(&stack);
    for (i = 0; i < len; i++)
    {
        if ( pParenArr[i] == pParenArr[0] )
            Push( &stack, pParenArr[i] );
        else if (pParenArr[i] == target)
        {
            Pop(&stack);
            if (stack.top == -1)
                return (i + 1);
        }
    }
    return 0;
}

int CalParenVal(char pParenArr[], int len)
{
    Stack stack;
    int result = 0;
    int i;
    InitStack(&stack);

    for (i = 0; i < len; i++)
    {
        if ( ParenKind(pParenArr[i]) < 2 ) // open paren?
        {
            if ( i == 0 )
                Push(&stack, pParenArr[i]);
            else
            {
                if ( ParenKind(pParenArr[i - 1]) >= 2 ) // close paren?
                {
                    char ppParenArr[MAX_LEN];
                    int blockLen = BlockLen(pParenArr + i, strlen(pParenArr + i));
                    int blockVal;
                    strncpy(ppParenArr, pParenArr + i, blockLen);
                    ppParenArr[blockLen] = 0;
                    blockVal = CalParenVal(ppParenArr, strlen(ppParenArr));
                    if ( blockVal == 0 )
                        return 0;
                    result += blockVal;
                    i += blockLen - 1;
                }
                else
                    Push(&stack, pParenArr[i]);
            }
        }
        else // close paren
        {
            if ( IsEmpty(&stack) )
                return 0;
            else
            {
                if (IsRight(&stack, pParenArr[i]))
                {
                    if (pParenArr[i] == ')')
                    {
                        if (pParenArr[i - 1] == '(')
                            result += 2;
                        else // ) ]
                            result *= 2;
                    }
                    else // ]
                    {
                        if (pParenArr[i - 1] == '[')
                            result += 3;
                        else
                            result *= 3;
                    }
                        Pop(&stack);
                }
                else
                    return 0;
            }
        }
    }
    if (IsEmpty(&stack))
        return result;
    else
        return 0;
}