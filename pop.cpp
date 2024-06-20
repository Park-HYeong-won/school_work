#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int* array;
	int max;
	int top;
};

void InitStack(Stack* stack, int max) {
	stack->max = max;
	stack->top = -1;
	stack->array = (int*)malloc(stack->max * sizeof(int));

}

void push(Stack* stack, int value) {
	if (stack->top + 1 != stack->max) {
		stack->top++;
		stack->array[stack->top] = value;
	}
	else {
		printf("stack overflow!");
	}

}

int pop(Stack* stack) {
	if (stack->top != -1) {
		int pop = stack->array[stack->top];
		stack->array[stack->top] = NULL;
		stack->top--;
		return pop;
	}
	else {
		printf("stack is empty");
		return 0;
	}
}

void FreePop(Stack* stack) {
	free(stack->array);
	stack->top = -1;
	stack->max = 0;
	stack->array = NULL;
}
void Print(Stack* stack) {
	for (int i = 0; i < stack->top+1; i++) {
		printf("%d", stack->array[i]);
	}
	printf("\n");
}
int main(void) {
	Stack stack;
	InitStack(&stack, 10);
	for (int i = 0; i < 9; i++) {
		push(&stack, i);
	}
	Print(&stack);
	for (int j = 0; j < 6; j++) {
		pop(&stack);
	}
	Print(&stack);
	FreePop(&stack);

	return 0;
}
