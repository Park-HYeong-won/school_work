#include <iostream>

char tic_array[3][3];
int full();
int correct();
int pick();
void show();

int main(void) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tic_array[i][j] = 'e';
		}
	}
	//배열이 꽉차면 full() == 1
	while (full() == 0) {
		pick();
		show();
		// correct 가 1을 리턴하면 1번 사용자 우승 2번 리턴하면 2번 사용자 우승
		if (correct() == 1) {
			std::cout << "1번 사용자 우승 !";
			return 0;
		}
		else if (correct() == 2) {
			std::cout << "2번 사용자 우승 !";
			return 0;
		}
		else continue;
			
	}
	if (full() == 1) std::cout << "배열을 모두 사용하였습니다. 다시 프로그램을 실행해주세요.";
	return 0;
}
int full() {
	//배열이 다 찾는지 여부
	int k = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tic_array[i][j] == 'e') {
				k = 0;
				return k;
			}
		}
	}

	
}

int correct() {
	//삼목이 되었는지 확인
	for (int i = 0; i < 3; i++) {
		if (tic_array[i][0] == tic_array[i][1] && tic_array[i][1] == tic_array[i][2]) {
			if (tic_array[i][0] != 'e') {
				if (tic_array[i][0] == 'o') {
					return 1;
				}
				else if (tic_array[i][0] == 'x') return 2;
				else return 0;
			}
		}

		else if (tic_array[0][i] == tic_array[1][i] && tic_array[1][i] == tic_array[2][i]) {
			if (tic_array[0][i] != 'e') {
				if (tic_array[0][i] == 'o') {
					return 1;
				}
				else if (tic_array[0][i] == 'x') return 2;
				else return 0;
			}
		}
		else if (tic_array[0][0] == tic_array[1][1] && tic_array[1][1] == tic_array[2][2]) {
			if (tic_array[0][0] != 'e') {
				if (tic_array[0][0] == 'o') {
					return 1;
				}
				else if (tic_array[0][0] == 'x') return 2;
				else return 0;
			}
		}
		else if (tic_array[2][0] == tic_array[1][1] && tic_array[1][1] == tic_array[0][2]) {
			if (tic_array[2][0] != 'e') {
				if (tic_array[2][0] == 'o') {
					return 1;
				}
				else if (tic_array[2][0] == 'x') return 2;
				else return 0;
			}
		}
		else return 0;
	}
}
int pick() {
	int user,i,j;
	//사용자 선택하기
	std::cout << "사용자 번호를 적으십시오 예) 1 :";
	std::cin >> user;
	std::cout << "원하는곳을 작성하시오 예)2 3 :";
	std::cin >> i >> j;
	if (tic_array [i-1][j-1] == 'e') {
		switch (user) {
		case 1 :
			tic_array[i - 1][j - 1] = 'o';
			break;
		case 2:
			tic_array[i - 1][j - 1] = 'x';
			break;
		default:
			std::cout << "사용자를 잘못입력하였습니다.";
			break;
		}
		return 0;
	}
	else {
		std::cout << "이미 사용한곳입니다. 다시 골라주십시오." << std::endl;
		pick();
		return 0;
	}
}

void show() {
	// 배열판 보여주기
	std::cout << std::endl <<"------------------"<< std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << tic_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}