#include <iostream>
using namespace std;

#define SIZE 20

char temp[SIZE+2][SIZE+2];

void flushTemp(){
	for (int x = 0; x < SIZE; x++){
		for (int y = 0; y < SIZE; y++){
			temp[x][y] = 0;
		}
	}
}

void printGrid(char grid[][SIZE]){
	int xCount=0, oCount=0;
	for (int x = 0; x < SIZE; x++){
		for (int y = 0; y < SIZE; y++){
			if (grid[x][y] == 1){
				xCount++;
				std::cout << 'X';
			}
			else if (grid[x][y] == -1){
				oCount++;
				std::cout << 'O';
			}
			else
				std::cout << '_';
			cout << ' ';
		}
		std::cout << '\n';
	}
	//std::cout << "X: " << xCount << '\n' < "O: " << oCount << '\n';
	std::cout << xCount << ' ' << oCount;
	std::cout << "\n\n\n";
}

void updateGrid(int player, char grid[][SIZE]){
	flushTemp();
	//char **temp = &temp[1][1];
	for (int x = 0; x < SIZE; x++){
		for (int y = 0; y < SIZE; y++){
			if (grid[x][y] == player){
				temp[x-1][y]++;
				temp[x+1][y]++;
				temp[x][y-1]++;
				temp[x][y+1]++;
			}
		}
	}
	for (int x = 0; x < SIZE; x++){
		for (int y = 0; y < SIZE; y++){
			if (temp[x][y]){
				if (grid[x][y] == 0)
					grid[x][y] = player;
				else if (grid[x][y] != player){
					if (temp[x][y] == 1)
						grid[x][y] = 0;
					else
						grid[x][y] = player;
				}
			}
		}
	}

}
int main(){
	char grid[SIZE][SIZE] = {0};

	int x, y;

	for (int i = 0; i < 60; i++){
		printGrid(grid);


		std::cin >> x >> y;
		if (i%2){
			grid[x][y] = 1;
			updateGrid(1, grid);
		}
		else{
			grid[x][y] = -1;
			updateGrid(-1, grid);
		}

		//updateGrid(i%2, grid);
	}

	return 0;
}