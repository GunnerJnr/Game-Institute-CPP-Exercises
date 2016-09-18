// includes
#include <iostream>
#include <cstdlib>
#include <ctime>

// using std's
using std::cout;
using std::cin;
using std::endl;

// globals
bool quitGame = false;
char playerChoice = ' ';
int playerChips = 1000;
int betAmount = 0;
int reelResults[3];

// function prototypes
void DisplayPlayerChips(int chips);
void Menu();
void EnterBet();
int Random(int low, int high);
void Reels();

// main program entry point
int main()
{
	// seed random numbers
	srand((unsigned int)time(NULL));

	// Display the Menu
	Menu();

	// output message
	cout << "Press any key key to exit";

	cin.get();
	cin.ignore();
	return 0;
}

// function declarations
// Display Players Chips
void DisplayPlayerChips(int chips)
{
	// assign the value of playerChips to chips
	chips = playerChips;
	// output a message
	cout << "Player's Chips: $" << chips << endl << endl;
}

// Menu
void Menu()
{
	// output message
	cout << "\t\t\t=================" << endl;
	cout << "\t\t\tSlot Machine V1.0" << endl;
	cout << "\t\t\t=================" << endl << endl;

	// Player Chips
	DisplayPlayerChips(playerChips);

	// Menu Options
	cout << "Press 'P' to [P]lay or 'E' to [E]xit : ";
	cin >> playerChoice;
	cout << endl << endl;

	// while quit game is not equal to true
	while (!quitGame)
	{
		// return appropriate case to players choice
		switch (playerChoice)
		{
			// the user chose to play the game
		case 'p':
		case 'P':
			// output a welcome message
			cout << "Welcome to your game of slots!" << endl;
			// Enter your bet choice
			EnterBet();
			break;

			// the user chose to quit
		case 'e':
		case 'E':
			// exit game
			cout << "Exiting..." << endl;
			quitGame = true;
			break;
		default:
			// output a message if user enters an incorrect choice
			cout << "Sorry you have entered an invalid choice please try again.." << endl << endl;
			// ignore input that isn't numerical
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

// Bet Choice
void EnterBet()
{
	// output a message
	cout << "Please enter your bet :";
	// store the users choice
	cin >> betAmount;
	cout << endl << endl;

	// check amounts are valid
	// if bet amount is less than or equal to zero
	if (betAmount <= 0)
	{
		// tell the user they have entered a wrong amount
		cout << "Sorry you have entered an incorrect amount please try again..." << endl << endl;
	}
	// or if the bet amount is more than the player has
	else if (betAmount > playerChips)
	{
		// tell them they do not have enough chips
		cout << "Sorry you do not have enough chips..." << endl << endl;
	}
	// otherwise..
	else
	{
		// continue running the program and display the slot reels to the user
		Reels();
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

// Seed 3 Random numbers to return as a result for each reel
void Reels()
{
	// loop through the 3 reels
	for (int i = 0; i < 3; i++)
	{
		// assign a random number to each of the reels
		reelResults[i] = Random(2, 7);
	}

	// output the result of the random number on each reel
	cout << "["<< reelResults[0] << "] [" << reelResults[1] << "] [" << reelResults[2] << "]" << endl;
	
	// if all 3 reels return the same number 
	if (reelResults[0] == reelResults[1] && reelResults[0] == reelResults[2])
	{
		// pay the player 5 times the amount they have bet
		betAmount *= 5;
		// output a message to let them know they have won 5 times the amount
		cout << "You won 5 times your bet!" << endl << endl;
		// update the players chips with the new amount
		playerChips += betAmount;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);
	}
	// if 2 of the reels match
	else if (reelResults[0] == reelResults[1] || reelResults[0] == reelResults[2] || reelResults[1] == reelResults[2])
	{
		// pay the player 3 times the amount they have bet
		betAmount *= 3;
		// output a message to let them know they have won 3 times the amount
		cout << "You won 3 times your bet!" << endl << endl;
		// update the players chips with the new amount
		playerChips += betAmount;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);
	}
	else
	{
		// output a message letting the user know they didn't win this time
		cout << "Sorry you didn't win!" << endl << endl;
		// update the players chips (subtract the bet amount)
		playerChips -= betAmount;
		// re-display the amount of chips the player has..
		DisplayPlayerChips(playerChips);

		// additional check!!
		// if the player has no chips left or the player presses 'e/E' to quit
		if (playerChips <= 0)
		{
			// exit game (as we don't want to keep asking them to enter a bet when they can't)
			cout << "Exiting..." << endl;
			// set quit game equal to true
			quitGame = true;
		}
	}
}