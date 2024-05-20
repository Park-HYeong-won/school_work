#include <iostream>
using namespace std;

int queue_array[5];
int front_index = 0;
int rear_index = 0;

int InQueue(int num) {
	if ((rear_index + 1) % 5 == front_index ) {
		cout << "Over Flow!!";
		return 0;
	}
	else {
		queue_array[rear_index % 5] = num;
		rear_index++;
		
	}
	rear_index = rear_index % 5;
	return 0;

}
int DeQueue() {
	if (front_index  == rear_index) {
		cout << "Empty array!!";
		return 0;
	}
	else {
		queue_array[front_index] = 0;
		front_index++;
	}
	front_index = front_index % 5;
	return 0;
}
void print() {
	for (int i = 0; i < 5; i++) {
		cout << queue_array[i] << " ";
	}
}

int main(void) {

	InQueue(1);
	InQueue(2);
	InQueue(3);
	InQueue(4);
	InQueue(5);


	print();


	return 0;
}