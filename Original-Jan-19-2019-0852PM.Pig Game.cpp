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
	
	Htotal = 0;
	Ctotal = 0;
	std::cout << "It is your turn to roll\n";
	while (Htotal < 100 && Ctotal < 100)
	{
		Hturn(Htotal);
		Cturn(Ctotal);
		std::cout << "Human score " << Htotal << "\n";
		std::cout << "Computer score " << Ctotal << "\n";
	}
	if (Htotal > 99)
		std::cout << "Winner\n";
	else
		std::cout << "Lost\n";

	return 0;
}
int Dice()
{
	int roll = rand() & 6 + 1;
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
		if (roll == 1 )
		{
			std::cout << "Rolled a 1 \n";
			turn = false;
		}
		
		else
		{
			
			std::cout << "Your roll " << roll << "\n";
			HumanScore = HumanScore + roll;
			std::cout << "Would you like to roll again? \n";
			std::cin >> response;
			if (response != "R")
			{
				
				turn = false;

			}else if (HumanScore > 19)
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
		if (roll == 1 )
		{
			std::cout << "Computer roll a 1\n";
			ComputerScore = 0;
			turn = false;

		}
		else

		{
			std::cout << "Computer roll " << roll << "\n";
			ComputerScore = ComputerScore + roll;
			if (ComputerScore > 19)
			{
				turn = false;
			}
		}
	} while (ComputerScore < 0 && turn);
	Ctotal = Ctotal + ComputerScore;
	return 0;
}


















