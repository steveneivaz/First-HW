/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>


int ws = 100;
int Dice();
int Hturn(int & Htotal);
int Cturn(int & Ctotal);
int Hscore;
int Cscore;
int Htotal;
int Ctotal;

int main()
{
	int first = rand() % 2 +1 ;
	if (first == 2) {

		std::cout << "You will be player 2\n";

		Htotal = 0;
		Ctotal = 0;
		

		std::cout << "It is player 2's turn\n";
		while (Htotal < 100 && Ctotal < 100)
		{
			Hturn(Htotal);
			Cturn(Ctotal);
			std::cout << "Player 2 score: " << Htotal << "\n";
			std::cout << "Player 1 score: " << Ctotal << "\n";
		}
		if (Htotal > 99)
			std::cout << "Winner!\n";
		else
			std::cout << "Sorry you lost\n";
	}
	else {
		std::cout << "You will be player 1\n";

		Htotal = 0;
		Ctotal = 0;
		

		std::cout << "It is player 2's turn\n";
		while (Ctotal < 100 && Htotal < 100)
		{
			Cturn(Ctotal);
			Hturn(Htotal);
			std::cout << "Player 1 score: " << Htotal << "\n";
			std::cout << "Player 2 score: " << Ctotal << "\n";
		}
		if (Htotal > 99)
			std::cout << "Winner!\n";
		else
			std::cout << "Sorry you lost\n";
	}

	return 0;
}
int Dice()
{
	int roll = rand() % 6 + 1;
	return roll;
}
int Hturn(int & Htotal)
{
	int HumanScore = 0;
	bool turn = true;
	std::string response;
	int roll = 0;
	do
	{
		roll = Dice();
		if (roll == 1)
		{
			std::cout << "Rolled a 1 \n";
			turn = false;
		}

		else
		{

			std::cout << "Roll " << roll << "\n";
			HumanScore = HumanScore + roll;
			std::cout << "Turn total: " << HumanScore << "\n";
			std::cout << "Roll/Hold? (R) \n";
			std::cin >> response;
			if (response != "R")
			{

				turn = false;

			}
			else if (HumanScore > 19)
			{

				turn = false;
			}
		}Htotal = Htotal + HumanScore;
	} while (turn);
	return 0;
}
int Cturn(int &Ctotal)
{

	int ComputerScore = 0;
	bool turn = true;
	int roll = 0;
	do
	{
		roll = Dice();
		if (roll == 1)
		{
			std::cout << "Computer roll a 1\n";
			ComputerScore = 0;
			turn = false;

		}
		else

		{
			std::cout << "Roll " << roll << "\n";
			ComputerScore = ComputerScore + roll;
			std::cout << "Turn total:" << ComputerScore << "\n";
			if (ComputerScore > 19)
			{
				turn = false;
			}
		}
	} while (ComputerScore < 0 && turn);
	Ctotal = Ctotal + ComputerScore;
	return 0;
}

















