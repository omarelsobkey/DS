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