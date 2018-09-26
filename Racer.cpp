//Honor Pledge: I pledge that I have neither given nor received any help on this assignment.

#include <iostream>
#include <stdlib.h> 
#include <ctime>
#include <iomanip>

#define RACE_LENGTH 50

void advanceRacerA(int* ptrRacerA);
void advanceRacerB(int* ptrRacerB);
void printPosition(int* ptrRacerA, int* ptrRacerB);

int main()
{
	int ptrRacerA = 0;
	int ptrRacerB = 0;
	srand (time(NULL));
	
    std::cout << "Welcome to Elijah's Spartan Race! \n READY...SET...GO!" << std::endl;
	
	//loop to run until one of the racers finishes the race
	for (int i = 0; i < 500; i++) {
	advanceRacerA(&ptrRacerA);
	advanceRacerB(&ptrRacerB);
	printPosition(&ptrRacerA, &ptrRacerB); 
	
	//if statement to determine if racer A has won the race
	if (ptrRacerA >= 50) {
		break;
	}
	//if statement to determine if racer B has won the race
	if (ptrRacerB >= 50) {
		std::cout <<"Your friend won the race - I must train harder!" << std::endl;
		break;
	}
	}
}

void advanceRacerA(int* ptrRacerA) {
	//Create a way for random number generator to generate an obstacle
	//had to create a code to store values in char array
	//r = run, s = sprint, m = fall in mud, t = fall of rope, b = fall off monkey bars
	char MyArray[10] = {'r', 'r', 'r', 's', 'm', 'm', 'm', 't', 't', 'b'};
	
	//generate a random number
	int choice;
	choice = (rand() % 9 + 0);
	
	//discern which obstacle correlates to the random number
	switch(MyArray[choice]){
		case 'r':
			*ptrRacerA = (*ptrRacerA) + 4;
		break;
		case 's':
			*ptrRacerA = (*ptrRacerA) + 5;
		break;
		case 'm':
			*ptrRacerA = (*ptrRacerA) - 2;
		break;
		case 't':
			*ptrRacerA = (*ptrRacerA) - 3;
		break;
		case 'b':
			*ptrRacerA = (*ptrRacerA) - 4;
		break;
	}
	
}

void advanceRacerB(int* ptrRacerB) {
	//Create a way for random number generator to generate an obstacle
	//had to create a code to store values in char array
	//r = run, s = sprint, m = fall in mud, t = fall of rope, b = fall off monkey bars
	char MyArray[10] = {'r', 'r', 'r', 'r', 's', 'm', 'm', 't', 't', 'b'};
	
	//generate a random number
	
	int choice;
	choice = (rand() % 9 + 0);
	
	//discern which obstacle correlates to the random number
	switch(MyArray[choice]){
		case 'r':
			*ptrRacerB = (*ptrRacerB) + 5;
		break;
		case 's':
			*ptrRacerB = (*ptrRacerB) + 6;
		break;
		case 'm':
			*ptrRacerB = (*ptrRacerB) - 1;
		break;
		case 't':
			*ptrRacerB = (*ptrRacerB) - 2;
		break;
		case 'b':
			*ptrRacerB = (*ptrRacerB) - 4;
		break;
	}
	
}

void printPosition(int* ptrRacerA, int* ptrRacerB) {
	//format way to display race
	//I had originally used <iomanip>, but could not figure out where to go from here:
	//std::cout << std::left << std::setw(RACE_LENGTH) << std:: setfill(' ') << *ptrRacerA;
	char printArray[51] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' '};

	//if statement determining where to print racer A
	if (*ptrRacerA >= 0) {
		printArray[*ptrRacerA] = 'A';
	}
	else if (*ptrRacerA >= 50) {
		printArray[49] = 'A';
	}
	else {
		printArray[0] = 'A';
	}
	
	//if statement determining where to print racer B
	if (*ptrRacerB >= 0) {
		printArray[*ptrRacerB] = 'B';
	}
	else if (*ptrRacerA = *ptrRacerB) {
		printArray[(*ptrRacerA) + 1] = 'B';
		
	}
	else if (*ptrRacerB < 0){
		printArray[0] = 'B';
	}
	else if (*ptrRacerB >= 49) {
		printArray[49] = 'B';
	}
	
	//Display the race, printing the locations of the array using a loop
	std::cout << "|";
	for (int i = 0; i <= 50; i++) {
		std::cout << printArray[i];
	}
	std::cout << "|" << std::endl;
	
}


