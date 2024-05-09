#include <iostream>
using namespace std;

int main(void) {
	int insertion_sort[5] = { 15,11,1,3,8 };
	int buffer = 0;
	for (int i = 1; i < 5; i++) {
		buffer = insertion_sort[i];
		for (int j = i; j >= 0; j--) {
			if (buffer < insertion_sort[j]) {
				insertion_sort[j + 1] = insertion_sort[j];
				insertion_sort[j] = buffer;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << insertion_sort[i] << " ";
	}
	return 0;
}