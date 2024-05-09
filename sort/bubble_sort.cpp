#include <iostream>
using namespace std;

int main(void) {
	int bubble_sort[5]={ 15,11,1,3,8 };
	int buffer;
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (bubble_sort[i] > bubble_sort[i + 1]) {
				buffer = bubble_sort[i];
				bubble_sort[i] = bubble_sort[i + 1];
				bubble_sort[i + 1] = buffer;
				cnt++;
			}
		}
		if (cnt == 0)break;
	}
	
	for (int i = 0; i < 5; i++) {
		cout << bubble_sort[i] << " ";
	}
	return 0;
}