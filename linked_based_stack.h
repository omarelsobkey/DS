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