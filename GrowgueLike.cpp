#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//#include <Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


typedef struct{
	short x;
	short y;
} vec2;

typedef struct{
	short health;
	short hunger;
	short age;
	short state;
	vec2 pos;
	vec2 size;
	string name;
	string description;
} creature;

char arborArray[80][30];
bool visibleArray[80][30];
creature chickens[20]; 	short chickenCount;
creature bears[10];	short bearCount;
int stepClock = 0;
creature wolf;
creature player;
vec2 bonfires[3];
sf::Window window(sf::VideoMode(800, 600), "SFML window");


void printStats(){

}
void testRender(){
	for (int y = 0; y < 30; y++){
		for (int x= 0; x < 80; x++){
			cout << arborArray[x][y];
		}
		cout << '\n';
	}
}

void render(){
	for (int c = 0; c < 50; c++)
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	int x = player.pos.x;
	int y = player.pos.y;
	for (int y = 0; y < 30; y++){
		for (int x= 0; x < 80; x++){
			if (visibleArray[x][y])
				cout << arborArray[x][y];
			else
				cout << ' ';
		}
		cout << '\n';
	}
}

void updateChickens(){}
void updateBears(){}
void updateWolf(){
	arborArray[wolf.pos.x][wolf.pos.y] = '.';
	wolf.pos = player.pos;
	arborArray[wolf.pos.x][wolf.pos.y] = wolf.name[0];
}
bool updatePlayer(){
	vec2 pos;
	pos = player.pos;
	sf::Event event;


	while (window.pollEvent(event)){
		while (event.type != sf::Event::KeyPressed){
		    switch (event.key.code){
		    	case sf::Keyboard::W:
	   			pos.y--;
		    	break;
		    	case sf::Keyboard::A:
				pos.x--;
		    	break;
		    	case sf::Keyboard::S:
				pos.y++;
		    	break;
		    	case sf::Keyboard::D:
				pos.x++;
		    	break;
		    	default:
		    	return false;
		    }
		}
	}

	if (arborArray[pos.x][pos.y] == '.'){
		updateWolf();
		player.pos = pos;
		arborArray[player.pos.x][player.pos.y] = '@';	
		return true;
	}
	return false;
}
void updateLighting(){
	for (int x = 0; x < 80; x++){
		for (int y = 0; y < 30; y++){
			visibleArray[x][y] = false;
		}
	}
	int x = player.pos.x;
	int y = player.pos.y;
	for (int a = x-3; a <= x+3; a++){
		for (int b = y-3; b <= y+3; b++){
			if (abs(x-a) + abs(y-b) <= 3)
				visibleArray[a][b] = true;
		}
	}


}
void update(){
	bool check = updatePlayer();
	if (check){
		updateLighting();
	}
}

creature generateChicken(){

	creature temp;
 	int randAge = rand() % 30;
 	temp.age = randAge;

 	if (randAge < 15){
 		temp.state = 0;
 		temp.name = "chick";
 		temp.description = "it's a baby chicken";
 	}
 	else if (randAge< 25){
 		temp.state = 1;
 		temp.name = "Chicken";
 		temp.description = "it's an ancient forest chicken";
 	}
 	else{
 		temp.state = 2;
 		temp.name = "House";
 		temp.size.x = 3;
 		temp.size.y = 3;
 		temp.description = "it's a chicken-legged hut";
 	}

 	temp.health = temp.state * temp.state * 10 + 1 + (rand() % 5);
 	temp.hunger = temp.health;

 	bool valid = false;
 	int randomNumberX;
 	int randomNumberY;
 	while (!valid)
 	{
 		randomNumberX  = rand() % 80;
 		randomNumberY = rand() % 30;
 		if (temp.state == 2){
 			valid = true;
 			for (int x = 0; x < 3; x++){
 				for (int y = 0; y < 3; y++){
 					if (arborArray[randomNumberX+x][randomNumberY+y] != '.')
 						valid = false;
 				}
 			}
 		}
 		else if (arborArray[randomNumberX][randomNumberY] == '.')
 			valid = true;
 	}
	if (temp.state == 2){
		for (int x = 0; x < 3; x++){
			for (int y = 0; y < 3; y++){
				arborArray[randomNumberX+x][randomNumberY+y] = temp.name[0];
			}
		}
	}
	else{
		arborArray[randomNumberX][randomNumberY] = temp.name[0];
	}

 	return temp;
}
creature generateBear(){


	creature temp;
 	int randAge = rand() % 30;
 	temp.age = randAge;

 	if (randAge < 15){
 		temp.state = 0;
 		temp.name = "baby bear";
 		temp.description = "it's a bear cub";
 	}
 	else if (randAge< 22){
 		temp.state = 1;
 		temp.name = "Bear";
 		temp.description = "it's an adolescent bear";
 	}
 	else{
 		temp.state = 2;
 		temp.name = "Bear";
 		temp.size.x = 1;
 		temp.size.y = 2;
 		temp.description = "it's an ancienct forest bear";
 	}

 	temp.health = temp.state * 10 + 5 + (rand() % 10);
 	temp.hunger = temp.health;

 	bool valid = false;
 	int randomNumberX;
 	int randomNumberY;
 	while (!valid)
 	{
 		randomNumberX  = rand() % 80;
 		randomNumberY = rand() % 30;
 		if (temp.state == 2){
 			valid = true;
 			for (int x = 0; x < 1; x++){
 				for (int y = 0; y < 2; y++){
 					if (arborArray[randomNumberX+x][randomNumberY+y] != '.')
 						valid = false;
 				}
 			}
 		}
 		else if (arborArray[randomNumberX][randomNumberY] == '.')
 			valid = true;
 	}
	if (temp.state == 2){
		for (int x = 0; x < 1; x++){
			for (int y = 0; y < 2; y++){
				arborArray[randomNumberX+x][randomNumberY+y] = temp.name[0];
			}
		}
	}
	else{
		arborArray[randomNumberX][randomNumberY] = temp.name[0];
	}

 	return temp;
	
}
void generate(){
	srand (time(NULL));

	fstream map;
	map.open("map");
	for (int y = 0; y < 30; y++){
		for (int x = 0; x < 80; x++){
			map >> arborArray[x][y];
		}
	}

	player.health = 10;
	player.hunger = 10;
	player.age = 0; 
	player.pos.x = 40;
	player.pos.y = 15;
	wolf.health = 5;
	wolf.hunger = 5;
	wolf.age = 1;
	wolf.state = 0;
	wolf.pos.x = 40;
	wolf.pos.y = 14;
	for (int c = 0; c < 3; c++){
		bonfires[c].x = -10;
		bonfires[c].y = -10;
	}	
	arborArray[40][15] = '@';
	arborArray[40][14] = 'w';

	chickenCount = rand() % 5 + 5;
 	for (int i = 0; i< chickenCount; i++){
 		chickens[i] = generateChicken();
	}
	bearCount = rand()  % 5 + 2;
 	for (int i = 0; i< bearCount; i++){
 		bears[i] = generateBear();
	}
	updateLighting();
}


int main(int argc, char const *argv[])
{
	generate();
	while(true){
		render();
		update();
	}
	return 0;
}