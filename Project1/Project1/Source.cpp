#include <iostream>
#include <string>
#include "DrinkMachine.h" //for the DrinkMachine class and Drink structure

using namespace std;

int main() {
	int selection; //int variable for selection
				   //parallel arrays below
	string names[5] = { "Cola", "Root beer", "Orange soda", "Grape soda", "Bottled water" }; //array that holds all of the drink names
	double prices[5] = { 1, 1, 1, 1, 1.5 }; //array that holds all of the drink prices
	DrinkMachine *machine = new DrinkMachine; //DrinkMachine object
	(*machine).setBalance(110); //sets the balance variable in the DrinkMachine class to 110
	Drink *drinks = new Drink[5]; //an array pointer that holds 5 Drink structure elements
	(*machine).setDrinks(drinks); //sets the drinks pointer in the DrinkMachine class to the drinks array pointer
	for (int i = 0; i < 5; i++) { //a for loop that runs 5 times
		(*machine).setDrinkName(names[i], i); //sets the names of each structure in the drinks array pointer
		(*machine).setDrinkCost(prices[i], i); //sets the cost of each structure in the drinks array pointer
		(*machine).setAmountOfDrinks(20, i); //sets the amount of each structure in the drinks array pointer
	}
	do { //a do...while loop that runs as long as the selection variable isn't set to 0
		(*machine).displayChoices(); //runs the displayChoices function in the DrinkMachine class
		cout << "Enter selection (1 - 5) or type 0 to cancel: ";
		cin >> selection; //retrieves the input
		while (selection < 0 || selection > 5) { //runs if the input isn't between 0 and 5
			cout << "Invalid. Re-enter selection: ";
			cin >> selection;
		}
		if (selection >= 1 && selection <= 5) { //runs if the input is between 1 and 5
			(*machine).buyDrink(selection - 1); //runs the buyDrink function in the DrinkMachine class
		}
		cout << endl;
	} while (selection != 0);
	delete machine; //deletes the DrinkMachine object
	machine = NULL; //sets the machine pointer to NULL
	delete[] drinks; //deletes the memory allocated for the pointer variable
	drinks = NULL; //sets the drinks pointer to NULL
	return 0;
}