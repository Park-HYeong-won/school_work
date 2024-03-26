#include <stdio.h>

int pop();
int push(int data);
int isEmpty();
int isFull();
int compare(char* char_array, int c_top);

int MAXSIZE = 8;
int stack[8];
int top = -1;


int main(void) {
	char str_array[8];
	printf("preorder 수식 적기 : ");
	fgets(str_array, sizeof(str_array), stdin);
	compare(str_array, 0);
	if (!isEmpty()) {
		printf("결과: %d\n", stack[top]);
	}
	return 0;
}

int pop() {
	int data;
	if (!isEmpty()) {
		data = stack[top];
		top = top - 1;
		return data;
	}
	else {
		printf("비어있음");
		return 0;
	}
}

int push(int data) {
	if (!isFull()) {
		top = top + 1;
		stack[top] = data;
		return 0;
	}
	else {
		printf("꽉참");
		return 0;
	}
}

int isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if (top == MAXSIZE)
		return 1;
	else
		return 0;
}
int compare(char *char_array,int c_top) {
	switch (char_array[c_top]) {
	case 49:
		push(1);
		break;

	case 50:
		push(2);
		break;

	case 51:
		push(3);
		break;

	case 52:
		push(4);
		break;

	case 53:
		push(5);
		break;

	case 54:
		push(6);
		break;

	case 55:
		push(7);
		break;

	case 56:
		push(8);
		break;

	case 57:
		push(9);
		break;

	case 40:
		break;

	case 41:
		break;

	case 42:
		push(pop() * pop());
		break;

	case 43:
		push(pop() + pop());
		break;

	case 45:
		push((0 - pop()) + pop());
		break;

	case 47:
		push((1/pop()) * pop());

	default:
		return -1;
	}
	if (c_top < 8)
		compare(char_array, c_top + 1);
	return 0;
}