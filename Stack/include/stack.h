#ifdef ARRAY_BASED_STACK

#define MAXSTACK 100
#define StackEntry int

// create stack datatype
typedef struct stack {
    int top; // indicates the top's index of the stack
    StackEntry entry[MAXSTACK];
} Stack;

void CreateStack(Stack *);

void Push(StackEntry, Stack *);

void Pop(StackEntry *, Stack *);

void StackTop(StackEntry *, Stack *);

int StackFull(Stack *);

int StackEmpty(Stack *);

int StackSize(Stack *);

void ClearStack(Stack *);

void Display(Stack *);

/*******************************************************/
#else

#define StackEntry int

typedef struct stackNode {
    StackEntry entry;
    struct stackNode *next;
} StackNode;

typedef struct stack {
    StackNode *top;
    int size;
} Stack;

void CreateStack(Stack *);

void Push(StackEntry, Stack *);

void Pop(StackEntry *, Stack *);

int StackEmpty(Stack *);

int StackFull(Stack *);

void Clear(Stack *);

void TraverseStack(Stack *, void(*)(StackEntry));

int StackSize(Stack *);

#endif