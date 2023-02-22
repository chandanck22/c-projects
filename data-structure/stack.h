struct Stack {
    int top;
    int *array;
    int size;
};

struct Stack * createStack() {
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (int *) malloc(sizeof(int) * size);
    stack->size = size;
    return stack;
}

int isFull(struct Stack *stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int stack_item) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
        return;
    }
    stack->array[++stack->top] = stack_item;
    printf("\n %d pushed to stack.\n", stack_item);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top];
}

void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    int i;
    printf("\nStack elements: ");
    for (i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}
