#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int numbers[] = {7,5,4,8,9,6,3,1,2,14,11,10,12,13};
int temp;
int sizeOfArray = sizeof(numbers) / sizeof(int);
int rand_num;

void sort(int array[], int size) {
	for (int i = 0; i < sizeOfArray - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


char getComputerChoice(){
	srand(time(NULL));
	rand_num = rand() % 3 ;
	
	switch (rand_num) {
	case 0: return 'r';
	case 1: return 'p';
	case 2: return 's';
	}
}

int comp_score, man_score = 0;
char userChoice;

void chooseWinner(char comp, char player) {
	switch (player) {
	case 'r':
		if (comp == 'r') {
			cout << "It's a tie." << '\n';
			comp_score++;
			man_score++;
		}
		else if (comp == 'p') {
			cout << "Sorry. You lost." << '\n';
			comp_score++;
		}
		else if (comp == 's') {
			cout << "You win!!" << '\n';
			man_score++;
		}
	case 'p':
		if (comp == 'r') {
			cout << "You win!!" << '\n';
			man_score++;
		}
		else if (comp == 'p') {
			cout << "It's a tie." << '\n';
			comp_score++;
			man_score++;
		}
		else if (comp == 's') {
			cout << "Sorry. You lost." << '\n';
			comp_score++;
		}
	case 's':
		if (comp == 'r') {
			cout << "Sorry. You lost." << '\n';
			comp_score++;
		}
		else if (comp == 'p') {
			cout << "You won!!" << '\n';
			man_score++;
		}
		else if (comp == 's') {
			cout << "It's a tie." << '\n';
			man_score++;
			comp_score++;
		}
	}
}


int main() {
	while (1 == 1) {
		cout << "Enter your choice: 'r' for rock, 'p' for paper, 's' for scissors, 'e' to exit: " << '\n';
		cin >> userChoice;
		if (userChoice == 'e') {
			cout << "Thank you for playing. The final scores are: " << '\n';
			cout << "Player: " << man_score << '\n';
			cout << "Computer: " << comp_score << '\n';
			break;
		}
		else {
			char compChoice = getComputerChoice();
			chooseWinner(compChoice, userChoice);
		}
	}
	return 0;
}
