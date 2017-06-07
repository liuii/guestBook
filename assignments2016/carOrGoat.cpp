#include <IOSTREAM>
#include <CSTDLIB>
#include <CTIME>
using namespace std;
const int N = 1000000;

struct GameData{
	int car;
	int player;
	int openDoor;
	int afterChange;
};

void chooseDoorForCar(GameData *game);
void chooseByPlayer(GameData *game);
void openDoor(GameData *game);
void changeDoor(GameData *game);

int main() {
	//cout << "\n\n\n\n";
	srand((unsigned int)time(NULL));
	GameData gameData;
	int M = 0;
	cout << "car,player,opendoor,afterchange" << endl;
	for(int i = 0; i < N; i ++){
		chooseDoorForCar(&gameData);
		chooseByPlayer(&gameData);
		openDoor(&gameData);
		changeDoor(&gameData);
		/* */
		cout << gameData.car << ','
			 << gameData.player << ','
			 << gameData.openDoor << ','
			 << gameData.afterChange << endl;
		if (gameData.car == gameData.afterChange)
			M++;
	}

	//cout << double(M)/double(N) << endl;
	return 0;
}

void chooseDoorForCar(GameData *game){
	game->car = rand() % 3;
}

void chooseByPlayer(GameData *game){
	game->player = rand() % 3;
}

void openDoor(GameData *game){
	if (game->car == game->player){
		int randomChoice[3][2] = {  
				{1, 2},
				{0, 2},
				{0, 1}};
		game->openDoor = randomChoice[game->car][rand() % 2];
	} else {
		int inequal[3][3]={
				{-1, 2, 1},
				{2, -1, 0},
				{1, 0, -1}};
		game->openDoor = inequal[game->player][game->car];
	}
}

void changeDoor(GameData *game){
	int tableOfChange[3][3] = { 
				{-1, 2, 1},
				{2, -1, 0},
				{1, 0, -1}};
	game->afterChange = tableOfChange[game->player][game->openDoor];
}
