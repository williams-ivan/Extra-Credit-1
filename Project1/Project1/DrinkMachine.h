#ifndef DRINKMACHINE_H //checks if the value has been defined earlier and if it's not, the code will be included
#define DRINKMACHINE_H //defines the value
#include <string>

using namespace std;

struct Drink { //the Drink structure
	string name;
	double cost;
	int amount;
};

//the DrinkMachine class and its headers
class DrinkMachine {
private:
	double revenue, balance; //2 double variables that will hold the machine's revenue and the user's balance
	Drink *drinks; //a pointer with the Drink structure as its data type
	void inputMoney(int i); //the inputMoney function
	void dailyReport(); //the dailyReport function
public:
	~DrinkMachine(); //a destructor
	void displayChoices(); //the displayChoices function
	void buyDrink(int i); //the buyDrink function
	void setDrinks(Drink d[]); //mutator for the drinks pointer
	void setRevenue(double r); //mutator for the revenue variable
	void setBalance(double b); //mutator for the balance variable
	void setDrinkName(string n, int i); //mutator for the name variable in the Drink structure
	void setDrinkCost(double c, int i); //mutator for the vost variable in the Drink structure
	void setAmountOfDrinks(int a, int i); //mutator for the amount variable in the Drink structure
	double getRevenue(); //accessor for the revenue variable
	double getBalance(); //accessor for the balance variable
	string getDrinkName(int i); //accessor for the name variable in the Drink structure
	double getDrinkCost(int i); //accessor for the vost variable in the Drink structure
	int getAmountOfDrinks(int i); //accessor for the amount variable in the Drink structure
};

#endif