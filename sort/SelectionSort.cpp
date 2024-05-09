#include <iostream>

using namespace std;
int main(void) {
	int selection_sort[5] = {3,1,4,9,8 };
	int buffer;
	int pos;
	for (int i = 0; i < 4; i++) {
		buffer = selection_sort[i];
		pos = i;
		for (int j = i; j < 5; j++) {
			if (buffer > selection_sort[j]) {
				buffer = selection_sort[j];
				pos = j;	
			}
		}
		selection_sort[pos] = selection_sort[i];
		selection_sort[i] = buffer;
	}
	for (int i = 0; i < 5; i++) {
	cout << selection_sort[i] << " ";
	}
	return 0;
}