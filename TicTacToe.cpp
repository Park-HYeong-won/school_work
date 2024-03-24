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
	//�迭�� ������ full() == 1
	while (full() == 0) {
		pick();
		show();
		// correct �� 1�� �����ϸ� 1�� ����� ��� 2�� �����ϸ� 2�� ����� ���
		if (correct() == 1) {
			std::cout << "1�� ����� ��� !";
			return 0;
		}
		else if (correct() == 2) {
			std::cout << "2�� ����� ��� !";
			return 0;
		}
		else continue;
			
	}
	if (full() == 1) std::cout << "�迭�� ��� ����Ͽ����ϴ�. �ٽ� ���α׷��� �������ּ���.";
	return 0;
}
int full() {
	//�迭�� �� ã���� ����
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
	//����� �Ǿ����� Ȯ��
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
	//����� �����ϱ�
	std::cout << "����� ��ȣ�� �����ʽÿ� ��) 1 :";
	std::cin >> user;
	std::cout << "���ϴ°��� �ۼ��Ͻÿ� ��)2 3 :";
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
			std::cout << "����ڸ� �߸��Է��Ͽ����ϴ�.";
			break;
		}
		return 0;
	}
	else {
		std::cout << "�̹� ����Ѱ��Դϴ�. �ٽ� ����ֽʽÿ�." << std::endl;
		pick();
		return 0;
	}
}

void show() {
	// �迭�� �����ֱ�
	std::cout << std::endl <<"------------------"<< std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << tic_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}