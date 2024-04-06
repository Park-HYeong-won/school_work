#include "TicTacToe.h"


int main(void) {
	TicTacToe bingo;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bingo.tic_array[i][j] = 'e';
		}
	}
	//배열이 꽉차면 full() == 1
	while (bingo.full() == 0) {
		bingo.pick();
		bingo.show();
		// correct 가 1을 리턴하면 1번 사용자 우승 2번 리턴하면 2번 사용자 우승
		if (bingo.correct() == 1) {
			std::cout << "1번 사용자 우승 !";
			return 0;
		}
		else if (bingo.correct() == 2) {
			std::cout << "2번 사용자 우승 !";
			return 0;
		}
		else continue;

	}
	if (bingo.full() == 1) std::cout << "배열을 모두 사용하였습니다. 다시 프로그램을 실행해주세요.";
	return 0;
}