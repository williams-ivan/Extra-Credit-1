#include <iostream>
#include <iomanip> //for setprecision
#include <algorithm> //for transform
#include <string>
#include "DrinkMachine.h" //for the DrinkMachine class

using namespace std;

void DrinkMachine::inputMoney(int i) {
	if (balance >= drinks[i].cost) { //runs if the balance variable's value is greater or equal to the value of the cost variable in the specific structure in the drinks array pointer
		if (drinks[i].amount == 0) { //runs if the value of the amount variable in the structure is 0
			cout << "Sold out." << endl;
		}
		else { //runs if the value of the amount variable in the structure isn't 0
			balance -= drinks[i].cost; //subtracts the value of the cost variable in the structure from the balance variable
			setAmountOfDrinks(--drinks[i].amount, i);//runs the setAmountOfDrinks function
			revenue += drinks[i].cost; //adds the value of the cost variable in the structure to the revenue variable
			cout << "Here is your beverage!" << endl;
		}
	}
	else { //runs if the balance variable's value is less than the value of the cost variable in the structure
		cout << "You do not have enough money." << endl;
	}
}

void DrinkMachine::dailyReport() { //displays the daily report
								   //outputs the drink names and the amount left over
	cout << "==========================================================" << endl;
	cout << "Drink Name\t\t\tNumber in Machine" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			cout << drinks[i].name << "\t\t\t\t\t" << drinks[i].amount << endl;
		}
		else {
			cout << drinks[i].name << "\t\t\t\t" << drinks[i].amount << endl;
		}
	}
	cout << "----------------------------------------------------------" << endl;
	cout << "Total Revenue: $" << setprecision(2) << fixed << getRevenue() << endl; //outputs the total revenue
}

DrinkMachine::~DrinkMachine() { //a destructor; runs when the DrinkMachine object is deleted or destroyed
	dailyReport(); //runs the dailyReport function
}

void DrinkMachine::displayChoices() {//this displays the DrinkMachine menu
									 //outputs the drink names, prices, amount
	cout << "==========================================================" << endl;
	cout << "Drink Name\t\tCost\t\tNumber in Machine" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			cout << drinks[i].name << "\t\t\t" << setprecision(2) << fixed << drinks[i].cost << "\t\t\t" << drinks[i].amount << endl;
		}
		else {
			cout << drinks[i].name << "\t\t" << setprecision(2) << fixed << drinks[i].cost << "\t\t\t" << drinks[i].amount << endl;
		}
	}
	cout << "----------------------------------------------------------" << endl;
}

void DrinkMachine::buyDrink(int i) { //a function that 
	string choice;
	cout << "Are you sure?" << endl;
	cin >> choice; //retrieves the input
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower); //turns the input into all lowercases
	while (choice != "yes" && choice != "no") { //if the input isn't "yes" or "no" then this loop will run and will keep running until the input is "yes" or "no"
		cout << "Invalid entry." << endl << "Are you sure?" << endl; //asks for a new answer which should be "yes" or "no"
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	}
	if (choice == "yes") { //runs if the input is "yes"
		inputMoney(i); //runs the inputMoney function
	}
}

void DrinkMachine::setDrinks(Drink d[]) { //mutator for the drinks pointer
	drinks = d;
}

void DrinkMachine::setRevenue(double r) { //mutator for the revenue variable
	revenue = r;
}

void DrinkMachine::setBalance(double b) { //mutator for the balance variable
	balance = b;
}

void DrinkMachine::setDrinkName(string n, int i) { //mutator for the name variable in the Drink structure
	drinks[i].name = n;
}

void DrinkMachine::setDrinkCost(double c, int i) { //mutator for the vost variable in the Drink structure
	drinks[i].cost = c;
}

void DrinkMachine::setAmountOfDrinks(int a, int i) { //mutator for the amount variable in the Drink structure
	drinks[i].amount = a;
}

double DrinkMachine::getRevenue() { //accessor for the revenue variable
	return revenue;
}

double DrinkMachine::getBalance() { //accessor for the balance variable
	return balance;
}

string DrinkMachine::getDrinkName(int i) { //accessor for the name variable in the Drink structure
	return drinks[i].name;
}

double DrinkMachine::getDrinkCost(int i) { //accessor for the vost variable in the Drink structure
	return drinks[i].cost;
}

int DrinkMachine::getAmountOfDrinks(int i) { //accessor for the amount variable in the Drink structure
	return drinks[i].amount;
}