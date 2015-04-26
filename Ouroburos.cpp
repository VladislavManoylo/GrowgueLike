#include <iostream>
#include <deque>
using namespace std;

#define SIZE 10

char grid[SIZE][SIZE];
enum snake{TAIL=1, UP=2, DOWN=3, LEFT=4, RIGHT=5, HEAD=6};

void printGrid(){
	for (int x = 0; x < SIZE; x++){
		for (int y = 0; y < SIZE; y++){
			switch(grid[x][y]{
				case 1:
				case -1:
				cout << '*';
				break;

				case 2:
				case -2:
				case 3:
				case -3:
				cout << '|';
				break;

				case 4:
				case -4:
				case 5:
				case -5:
				case << '-';
				break;

				case 6:
				cout << 'S';
				break;

				case -6:
				cout << '$';
				break;

				default:
				cout << 'o'
			}
		}
		cout << '\n';
	}
}

snake move(int player, char input){
	input = tolower(input);
	if (player == 1){
		switch (input){
			case 'w':
			return UP;
			case 'a':
			return LEFT;
			case 's':
			return DOWN;
			case 'd':
			return RIGHT;
			default:
			return HEAD;
		}
	}
	if (player == 2){
		switch (input){
			case 'i':
			return UP;
			case 'j':
			return LEFT;
			case 'k':
			return DOWN;
			case 'l':
			return RIGHT;
			default:
			return HEAD;
		}
	}
}

int main(){

	for (int x = 0; x < SIZE; x++){
		for (int y = 0; y < SIZE; y++){
			grid[x][y] = 0;
		}
	}

	char player = 1;
	bool player1Done= false;
	bool player2Done= false;
	char input;
	snake direction;
	while (!player1Done && !player2Done){
		cin >> input;
		direction = move(player, input);
		if (direction == HEAD)
			continue;

		if (player == 1 && !player1Done){
			
		} 
		else if (player == 2 && !player2Done){
			
		}
		player = 3-player;
	}
	
	return 0;
}

