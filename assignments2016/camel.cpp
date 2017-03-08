#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand((unsigned int)time(NULL));
	
	cout << "Welcome to Camel!" << endl;
	cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
	cout << "The natives want their camel back and are chasing you down! Survive your" << endl;
	cout << "desert trek and out run the natives." << endl;

	int done = 0;

	int milesTraved = 0;
	int thirst = 0;
	int tiredness = 0;

	int milesOfNative = -20;
	int canteen = 5;
	
	
	while (done == 0) {
		cout << "=======================================" << endl;
		cout << "A. Drink from your canteen." << endl;
		cout << "B. Ahead moderate speed." << endl;
		cout << "C. Ahead full speed." << endl;
		cout << "D. Stop for the night." << endl;
		cout << "E. Status check." << endl;
		cout << "Q. Quit." << endl;

		cout << "Your choice? ";
		char choiceOfUser;
		cin >> choiceOfUser;

		if (choiceOfUser == 'q' || choiceOfUser == 'Q'){
			done = 1;
		} else if (choiceOfUser == 'e' || choiceOfUser == 'E') {
			cout << "Miles traveled: " << milesTraved << endl;
			cout << "Drinks in canteen:  " << canteen << endl;
			cout << "The natives are " << milesTraved - milesOfNative << " miles behind you." << endl;
		} else if (choiceOfUser == 'd' || choiceOfUser == 'D') {
			tiredness = 0;
			cout << "Camel is very happy!" << endl;
			milesOfNative += 7 + rand() % 8;
		} else if (choiceOfUser == 'c' || choiceOfUser == 'C') {
			int delta = 10 + rand() % 11;
			milesTraved += delta;
			cout << "You have travled " << delta << " miles." << endl;
			thirst += 1;
			tiredness += 1 + rand() % 3;
			milesOfNative += 7 + rand() % 8;
		} else if (choiceOfUser == 'b' || choiceOfUser == 'B') {
			int delta = 5 + rand() % 8;
			milesTraved += delta;
			cout << "You have travled " << delta << " miles." << endl;
			thirst += 1;
			tiredness += 1 + rand() % 2;
			milesOfNative += 7 + rand() % 8;
		} else if (choiceOfUser == 'a' || choiceOfUser == 'A') {
			if (canteen > 0) {
				thirst = 0;
				canteen -= 1;
			} else {
				cout << "You have drunk out all the water." << endl;
			}
		} 

		if (thirst > 4 && done == 0) {
			cout << "You are thirsty!" << endl;
		}
		
		if (thirst > 6 && done == 0) {
			cout << "You died of thirst!" << endl;
			done = 1;
		}

		if (tiredness > 5 && done == 0) {
			cout << "Your camel is getting tired." << endl;
		}

		if (tiredness > 8 && done == 0) {
			cout << "Your camel is dead." << endl;
			done = 1;
		}

		if (milesOfNative >= milesTraved && done == 0) {
			cout << "You failed." << endl;
			done = 1;
		} else if (milesTraved - milesOfNative < 15 && done == 0) {
			cout << "The natives are getting close!" << endl;
		}

		if (milesTraved >= 200 && done == 0) {
			cout << "You win!!" << endl;
			done = 1;
		}

		int dice = rand() % 20;
		if (dice == 0) {
			cout << "Oasis!" << endl;
			canteen = 5;
			thirst = 0;
			tiredness = 0;
		}


	}

	return 0;
}
