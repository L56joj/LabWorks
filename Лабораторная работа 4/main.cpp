#include <iostream>
#include "Lab3.h"
#include <ctime> 

using namespace std;

int main() {
	cout << "Lets play" << endl;
	setlocale(LC_ALL, "Russian");
	srand(std::time(NULL));
	char h;
	while (1) {
		cout << "Plese choise 0 or x" << endl;
		cin >> h;
		if (h == 'X' || h == 'O' || h == '0' || h == 'x') break;
	}
	
	Game game = initGame(h);

	if (game.isUserTurn) {
		while (true) {
		userTurn(&game);
		updateDisplay(game);
			if (updateGame(&game)) {
				break;
			}
		botTurn(&game);
		updateDisplay(game);
			if (updateGame(&game)) {
				break;
			}
		}
	}
	else {
		while (true) {
			botTurn(&game);
		updateDisplay(game);
			if (updateGame(&game)) {
				break;
			}
		userTurn(&game);
		updateDisplay(game);
			if (updateGame(&game)) {
				break;
			}
		}
	}
	switch (game.status) {
	case USER_WIN:
		cout << "�� ��������";
		break;
	case BOT_WIN:
		cout << "�� ���������";
		break;
	case NOT_WIN:
		cout << "�����";
		break;
	}
	
}