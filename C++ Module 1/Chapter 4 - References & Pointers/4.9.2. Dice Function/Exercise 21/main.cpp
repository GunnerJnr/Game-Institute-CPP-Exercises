// includes
#include <iostream>
#include <cstdlib>
#include <ctime>

// using std's
using std::cout;
using std::cin;
using std::endl;

// global variables
bool quit = false;
bool firstTurn = true;
char userChoice = ' ';
int rollDice = 0;
int randomDie[2];
int die1, die2 = 0;
double playerChips = 1000.00f;
double playerBet = 0;

// function prototypes
void DisplayRules();
void Menu();
void DisplayPlayerChips(double chips);
void EnterBet();
void RollOutcome();
int Random(int low, int high);
void Dice(int& die1, int& die2);
void Dice(int* die1, int* die2);

// main program entry point
int main()
{
	// local variables
	// seed random numbers
	srand((unsigned int)time(NULL));
	// output a message
	cout << "\t\t\t\t\t\t==========" << endl;
	cout << "\t\t\t\t\t\tCraps V1.0" << endl;
	cout << "\t\t\t\t\t\t==========" << endl << endl;

	// Call the Menu function
	Menu();

	cin.get();
	cin.ignore();
	return 0;
}

// function declarations

// Display the Rules
void DisplayRules()
{
	// output the rules of the game
	cout << " Craps Game Rules" << endl;
	cout << " ----------------" << endl << endl;
	// Rules taken from http ://www.bigmcasino.com/learn-more/learn-to-play-craps/what-are-the-basic-rules-of-craps/
	cout << " What are the basic rules of craps ? " << endl << endl;
	cout << " You will soon find yourself on a roll (pun intended), if you can understand the basic rules of craps." << endl << endl;
	cout << "   The players take turns by rolling two dice.The player that is rolling the dice is considered the shooter." << endl;
	cout << "   The shooter MUST bet at least the table minimum on either the pass line or the don't pass line." << endl;
	cout << "   The game is played in rounds consisting of two phases : 'Come Out' and 'Point'." << endl;
	cout << "   Come Out – to start a round, the 'Shooter' makes a 'Come Out' roll.." << endl;
	cout << "   If the 'Come Out' roll is a 2, 3, or 12, then the round ends." << endl;
	cout << "   The rules of craps state that the 'Shooter' is said to 'Crap Out' and players lose their pass line bets." << endl;
	cout << "   If the come out roll is a 7 or 11, this results in a win for pass line bets." << endl;
	cout << "   The shooter continues to make come out rolls until he rolls 4, 5, 6, 8, 9, or 10." << endl;
	cout << "   This number becomes the point and in turn the point phase begins." << endl;
	cout << "   Point – during this phase, if the shooter rolls a point number then it's a win for the pass line bets." << endl;
	cout << "   If the shooter rolls a seven, it's a loss for the pass line bets and the round is over." << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl << endl;
}

// Menu
void Menu()
{
	// Output the menu options
	cout << " Please choose "
		"[P]lay "
		"[R]ules, "
		"[E]xit :";
	cin >> userChoice;
	cout << endl;
	// while not quit
	while (!quit)
	{
		// output appropriate cases based on the users input/choice
		switch (userChoice)
		{
		case 'p':
		case 'P':
			// if its the users first turn of the game
			if (firstTurn == true)
			{
				cout << " Starting your game, Welcome to Craps!" << endl << endl;
				// Call display chips
				DisplayPlayerChips(playerChips);
				// call enter bet
				EnterBet();
				// prompt user 
				cout << " Press [1] to Roll : ";
				cin >> rollDice;
				cout << endl;
				// call the outcome
				RollOutcome();
			}
			else
			{
				// ask the user to make their choice
				cout << " Press [1] to Roll Or [2] to Crap Out : ";
				cin >> rollDice;
				cout << endl;
				// if user presses 1
				if (rollDice == 1)
				{
					// Call Enter Bet
					EnterBet();
					// Call Display Chips
					DisplayPlayerChips(playerChips);
					// Call the Outcome Function
					RollOutcome();
				}
				// if user presses 2
				if (rollDice == 2)
				{
					// Did we manage to crap out ?
				}
			}
			break;
		case 'r':
		case 'R':
			cout << " Loading rules please wait.." << endl << endl;
			DisplayRules();
			cout << " To go back to the [M]enu press 'M'";
			cin >> userChoice;
			cout << endl;
			// If the user presses the 'M' key
			if (userChoice == 'm' || userChoice == 'M')
			{
				// Call the Menu
				Menu();
			}
			break;
		case 'e':
		case 'E':
			cout << " Exiting..." << endl << endl;
			quit = true;
			cout << " Press any Key to exit" << endl;
			break;
		default:
			cout << " Invalid choice, please try again.." << endl << endl;
			// Call the Menu
			Menu();
			break;
		}
	}
}

// Display Players Chips
void DisplayPlayerChips(double chips)
{
	// assign the value of playerChips to chips
	chips = playerChips;
	// output a message
	cout << " Player's Chips: \x9c" << chips << endl;
}

// Bet Choice
void EnterBet()
{
	cout << endl;
	// output a message
	cout << " Please enter your bet : \x9c";
	// store the users choice
	cin >> playerBet;
	cout << endl;

	// check amounts are valid
	// if bet amount is less than or equal to zero
	if (playerBet <= 0.0)
	{
		// tell the user they have entered a wrong amount
		cout << " Sorry you have entered an incorrect amount please try again..." << endl << endl;
	}
	// or if the bet amount is more than the player has
	else if (playerBet > playerChips)
	{
		// tell them they do not have enough chips
		cout << " Sorry you do not have enough chips..." << endl << endl;
	}
}

// output the outcome of the dice rolls
void RollOutcome()
{
	// set first turn to false as we have had it
	firstTurn = false;
	// check if the player choose to roll the dice
	if (rollDice == 1)
	{
		cout << " You rolled.." << endl;
		Dice(die1, die2);
		cout << endl << endl;
	}
	// or whether they chose to crap out
	if (rollDice == 2)
	{
		// crap out logic
	}
}

// Return Random Numbers
int Random(int low, int high)
{
	// create variable to store randomNum
	int randomNum = 0;

	// calculate the random number
	randomNum = low + rand() % ((high + 1) - low);

	// return the random number
	return randomNum;
}

// Dice function
void Dice(int& die1, int& die2)
{
	// loop through the 2 dice
	for (int i = 0; i < 2; i++)
	{
		// assign a random number to each of the dice
		randomDie[i] = Random(1, 6);
	}
	// assign the random numbers to each dice
	die1 = randomDie[0];
	die2 = randomDie[1];
	// output the results of each dice
	cout << " [" << die1 << "] [" << die2 << "]" << endl;

	// if all 3 reels return the same number 
	if (randomDie[0] == randomDie[1])
	{
		// pay the player 5 times the amount they have bet
		playerBet *= 5;
		// output a message to let them know they have won 5 times the amount
		cout << "\n You won 5 times your bet!" << endl << endl;
		// update the players chips with the new amount
		playerChips += playerBet;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);
	}
	// if 2 of the reels match
	else if (randomDie[0] == 3 && randomDie[1] == 5)
	{
		// pay the player 3 times the amount they have bet
		playerBet *= 3;
		// output a message to let them know they have won 3 times the amount
		cout << "\n You won 3 times your bet!" << endl << endl;
		// update the players chips with the new amount
		playerChips += playerBet;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);
	}
	else
	{
		// output a message letting the user know they didn't win this time
		cout << "\n Sorry you didn't win!" << endl << endl;
		// update the players chips (subtract the bet amount)
		playerChips -= playerBet;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);

		// additional check!!
		// if the player has no chips left or the player presses 'e/E' to quit
		if (playerChips <= 0.0)
		{
			cout << endl;
			cout << " Thanks for playing..." << endl;
			// set quit game equal to true
			quit = true;
		}
	}
}

// overloaded dice function
void Dice(int* die1, int* die2)
{
	// loop through the 2 dice
	for (int i = 0; i < 2; i++)
	{
		// assign a random number to each of the dice
		randomDie[i] = Random(1, 6);
	}
	// assign the random values
	*die1 = randomDie[0];
	*die2 = randomDie[1];
	// output the results of each dice
	cout << " [" << *die1 << "] [" << *die2 << "]" << endl;
	// if all 3 reels return the same number 
	if (randomDie[0] == randomDie[1])
	{
		// pay the player 5 times the amount they have bet
		playerBet *= 5;
		// output a message to let them know they have won 5 times the amount
		cout << "\n You won 5 times your bet!" << endl << endl;
		// update the players chips with the new amount
		playerChips += playerBet;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);
	}
	// if 2 of the reels match
	else if (randomDie[0] == 3 && randomDie[1] == 5)
	{
		// pay the player 3 times the amount they have bet
		playerBet *= 3;
		// output a message to let them know they have won 3 times the amount
		cout << "\n You won 3 times your bet!" << endl << endl;
		// update the players chips with the new amount
		playerChips += playerBet;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);
	}
	else
	{
		// output a message letting the user know they didn't win this time
		cout << "\n Sorry you didn't win!" << endl << endl;
		// update the players chips (subtract the bet amount)
		playerChips -= playerBet;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);

		// additional check!!
		// if the player has no chips left or the player presses 'e/E' to quit
		if (playerChips <= 0.0)
		{
			cout << endl;
			cout << " Thanks for playing..." << endl;
			// set quit game equal to true
			quit = true;
		}
	}
}