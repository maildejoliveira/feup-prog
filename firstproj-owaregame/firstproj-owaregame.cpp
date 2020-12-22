#include <iostream>
#include <string>

#define STD_OUTPUT_HANDLE ((DWORD)-11)
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <cstddef>
#include <stdio.h>     
#include <stdlib.h>
#include <string>

using namespace std;

void setColor(unsigned int color)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
}


//this function starts the game by presenting de user two options reading the rules or start playing
void init()
{
	setColor(7);
	cout << endl << endl << "				LET US PLAY THE ";
	setColor(2);
	cout << "OWARE GAME";
	setColor(7);
	cout << "!" << endl << endl;
	cout << "	If you don't know how to play it type 'rules', \n	if you want to play it right away type 'play' : ";
	string c;
	string s;
	bool validinput = false;
	cin >> c;
	while (!validinput)
	{
		if (c == "rules")
		{
			cout << endl;
			validinput = true;
			cout << "				THESE ARE THE ";
			setColor(2); cout << "OWARE GAME ";
			setColor(7); cout << "RULES:" << endl << endl;

			setColor(2); cout << "  OBJECTIVE:";
			setColor(7); cout << " The aim of the game is to capture more seeds than the opponent." << endl;
			cout << "The winner is the player who obtains more than half of the seeds (25 or more seeds).\n";
			cout << "It is possible for the game to end in a draw, where each player has captured 24 seeds." << endl << endl;

			setColor(2); cout << "  SOWING: ";
			setColor(7); cout << "Players take turns moving the seeds. On a turn, a player chooses one of the six pits under their control.\n";
			cout << "The player removes all seeds from this pit, and distributes them in each pit counter - clockwise from this house." << endl << endl;

			setColor(2); cout << "  CAPTURING: ";
			setColor(7); cout << "After a turn, if the last seed was placed into an opponent's pit that brought its total\n";
			cout << "to two or three seeds, all the seeds in that house are captured and placed in the player's scoring pit.\n";
			cout << "If the previous to last seed also brought an opponent's pit to two or three, these are captured as well,\n";
			cout << "and so on until a pit is reached which does not contain two or three seeds or does not belong to the opponent.\n";
			cout << "However, if a move would capture all an opponent's seeds, the seeds are not captured,\n";
			cout << "and are instead left on the board, since this would prevent the opponent from continuing the game." << endl << endl;

			setColor(2); cout << "  EXCEPTION: ";
			setColor(7); cout << "The exception disallowing capture of all an opponent's seeds is related to a more general idea,\n";
			cout << "that one ought to make a move that allows the opponent to continue playing.\n";
			cout << "If an opponent's pits are all empty, the current player must make a move that gives the opponent seeds.\n";
			cout << "If no such move is possible, the current player captures all seeds in their own territory, ending the game." << endl << endl;

			setColor(2);
			cout << "	ARE YOU READY TO PLAY ";
			setColor(7);
			cout << "(type 'yes')? ";
			cin >> s;
			while (s != "yes")
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "	We wait until you are ready, please type 'yes' when you are: ";
				cin >> s;
			}
			cout << endl << endl;
			setColor(2);
			cout << "				LET'S PLAY!!" << endl << endl;
			setColor(7);
		}
		else if (c == "play")
		{
			cout << endl;
			validinput = true;
			setColor(2);
			cout << "				LET'S PLAY!!" << endl << endl;
			setColor(7);
		}
		else
		{
			cout << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "	You didn't choose a valid option, please try again." << endl;
			cout << "	If you don't know how to play it type 'rule', \n	if you want to play it right away type 'play': ";
			cin >> c;
		}
	}
}

int decideBetweenPCorFriend()
{
	setColor(7);
	cout << "	Do you want to play against a friend or against the computer (type 'friend' or 'pc')? ";
	string c;
	bool validinput = false;
	cin >> c;
	while (!validinput)
	{
		if (c == "pc")
		{
			validinput = true;
			return 0;
		}
		else if (c == "friend")
		{
			validinput = true;
			return 1;
		}
		else
		{
			cout << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "	You didn't choose a valid option, please try again." << endl;
			cout << "	Do you wnat to play against a friend or against the computer (type 'friend' or 'pc')? ";
			cin >> c;
		}
	}
}


// this function only has the objective of showing the board situation 
void displays(const vector <int>& n_seeds, int& n1, int& n2) //nesta função o vetor não muda
{
	system("CLS");
	cout << endl;
	setColor(12);
	cout << "        PLAYER 1";
	setColor(7);
	cout << "	    A       B       C       D       E       F		 " << endl;
	setColor(8);
	cout << " ----------------------------------------------------------------------------------------------- " << endl;
	cout << "|	        	|	|	|	|	|	|	|	        	|" << endl;
	cout << "|	        	|";
	for (size_t i = 0; i < 6; i++)
	{
		if (n_seeds[i] / 10 == 0)
		{
			setColor(12);
			cout << "   " << n_seeds[i];
			setColor(8);
			cout << "   |";
		}
		else
		{
			setColor(12);
			cout << "  " << n_seeds[i];
			setColor(8);
			cout << "   |";
		}
	}
	cout << "	        	|" << endl;
	cout << "|	        	|	|	|	|	|	|	|	        	|" << endl;

	cout << "|	   ";
	setColor(12);
	cout << n1;
	setColor(8);
	cout << "		-------------------------------------------------	    ";
	setColor(9);
	cout << n2;
	setColor(8);
	cout << "   	|" << endl;

	cout << "|	        	|	|	|	|	|	|	|	        	|" << endl;
	cout << "|	        	|";
	for (size_t i = 11; i >= 6; i--)
	{
		if (n_seeds[i] / 10 == 0)
		{
			setColor(9);
			cout << "   " << n_seeds[i];
			setColor(8);
			cout << "   |";
		}
		else
		{
			setColor(9);
			cout << "  " << n_seeds[i];
			setColor(8);
			cout << "   |";
		}
	}
	cout << "	        	|" << endl;
	cout << "|	        	|	|	|	|	|	|	|	        	|" << endl;
	cout << " ----------------------------------------------------------------------------------------------- " << endl;
	setColor(7);
	cout << "                	    A       B       C       D       E       F		 ";
	setColor(9);
	cout << "PLAYER 2" << endl << endl;
	setColor(7);
}

//this function is only called one time to choose the player who starts the game
int startingplayer()
{
	srand(time(NULL));
	return rand() % 2 + 1;
}

void announcingfirstplayer(int pl)
{
	cout << "The first player to play is ";
	if (pl == 1) setColor(12);
	else setColor(9);
	cout << "PLAYER " << pl;
	setColor(7);
	cout << "." << endl;
}

//evaluates if in player 1 houses there are no seeds at all
bool allzero_pl1(const vector <int>& n_seeds)
{
	for (int i = 0; i < 6; i++)
	{
		if (n_seeds[i] != 0) return false;
	}
	return true;
}

//evaluates if in player 2 houses there are no seeds at all returns true if it is all zero and false if there is one house with seeds
bool allzero_pl2(const vector <int>& n_seeds)
{
	for (int i = 6; i < 12; i++)
	{
		if (n_seeds[i] != 0) return false;
	}
	return true;
}

void moving(vector <int>& n_seeds, int& indx, int& indx_lastcase)
{
	if (n_seeds[indx] >= 12)
	{
		for (int i = 0; i < 12; i++)
		{
			if (i != indx)	n_seeds[i]++;
		}
		n_seeds[indx] = n_seeds[indx] - 11;
	}
	for (int i = 0; i < n_seeds[indx]; i++)
	{
		if (indx - 1 - i < 0)
		{
			n_seeds[11 + indx - i] = n_seeds[11 + indx - i] + 1;
			indx_lastcase = 11 + indx - i;
		}
		else
		{
			n_seeds[indx - 1 - i] = n_seeds[indx - 1 - i] + 1;
			indx_lastcase = indx - 1 - i;
		}
	}
	n_seeds[indx] = n_seeds[indx] - n_seeds[indx];
}

//this refreshes the possible options for the player who is going to choose
void casesvalidfunction(int& pl, vector <int>& n_seeds, vector <int>& casesvalid)
{
	vector <int> n_seeds_imag;
	casesvalid = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int indx_lastcase_imag = -1;
	for (int i = 0; i < n_seeds.size(); i++)
	{
		n_seeds_imag.push_back(n_seeds[i]);
	}
	if (pl == 1 && allzero_pl2(n_seeds)) //entao o pl1 tem que dar seeds ao 2 se nao puder acaba o jogo e pl1 recolhe as suas seeds
	{
		for (int i = 0; i < 6; i++)
		{
			if (n_seeds_imag[i] != 0)
			{
				moving(n_seeds_imag, i, indx_lastcase_imag);
				if (allzero_pl2(n_seeds_imag) == true) casesvalid[i] = 0;
				n_seeds_imag.resize(0);
				for (int i = 0; i < n_seeds.size(); i++)
				{
					n_seeds_imag.push_back(n_seeds[i]);
				}
			}
			else
			{
				casesvalid[i] = 0;
			}
		}
	}
	else if (pl == 2 && allzero_pl1(n_seeds))  //entao o pl2 tem que dar seeds ao 1 se nao puder acaba o jogo e pl2 recolhe as suas seeds
	{
		for (int i = 6; i < 12; i++)
		{
			if (n_seeds_imag[i] != 0)
			{
				moving(n_seeds_imag, i, indx_lastcase_imag);
				if (allzero_pl1(n_seeds_imag) == true) casesvalid[i] = 0;
				n_seeds_imag.resize(0);
				for (int i = 0; i < n_seeds.size(); i++)
				{
					n_seeds_imag.push_back(n_seeds[i]);
				}
			}
			else
			{
				casesvalid[i] = 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < 12; i++)
		{
			if (n_seeds[i] == 0) casesvalid[i] = 0;
		}
	}
}

//this function evaluates if the player who is currently choosing is able to choose or not (=has some seed in his cases)
bool validchoosing(int& pl, vector <int>& n_seeds, vector <int>& casesvalid)
{
	if (pl == 1)
	{
		for (int i = 0; i < 6; i++)
		{
			if (casesvalid[i] == 1) return true;
		}
	}
	else if (pl == 2)
	{
		for (int i = 6; i < 12; i++)
		{
			if (casesvalid[i] == 1) return true;
		}
	}
	else return false;
}

//if it is not valid choosing then catch the seeds
void ifisnotvalidchoosing(vector <int> n_seeds, int& pl1, int& pl2)
{
	for (int i = 0; i < 6; i++)
	{
		pl1 = pl1 + n_seeds[i];
		n_seeds[i] = 0;
	}
	for (int i = 6; i < 12; i++)
	{
		pl2 = pl2 + n_seeds[i];
		n_seeds[i] = 0;
	}
}



void choosing(int& pl, vector <int>& n_seeds, int& indx_case_selected, vector<int>& casesvalid)
{
	char c; //the player chosen case
	if (pl == 1) setColor(12);
	else setColor(9);
	cout << "PLAYER " << pl;
	setColor(7);
	cout << " is your turn!" << endl << "Please choose one of your board cases (A, B, C, D, E, F): ";
	cin >> c;
	bool validcase = false;
	while (validcase == false)
	{
		if (!cin.fail() && cin.peek() == '\n')
		{
			validcase = true;
			if (pl == 1)
			{
				switch (toupper(c))
				{
				case'A': indx_case_selected = 0;
					break;
				case'B': indx_case_selected = 1;
					break;
				case'C': indx_case_selected = 2;
					break;
				case'D': indx_case_selected = 3;
					break;
				case'E': indx_case_selected = 4;
					break;
				case'F': indx_case_selected = 5;
					break;
				default:
					validcase = false;
					cin.clear();
					cin.ignore(10000, '\n');
					if (pl == 1) setColor(12);
					else setColor(9);
					cout << "PLAYER " << pl;
					setColor(7);
					cout << " you didn't choose a valid case." << endl;
					cout << "Please choose one of your board cases (A, B, C, D, E, F): ";
					cin >> c;
				}
				if (casesvalid[indx_case_selected] == 0 && validcase == true)
				{
					validcase = false;
					cin.clear();
					cin.ignore(10000, '\n');
					if (pl == 1) setColor(12);
					else setColor(9);
					cout << "PLAYER " << pl;
					setColor(7);
					cout << " you didn't choose a valid case." << endl;
					setColor(2);
					cout << "IMPORTANT NOTES to remember: \n";
					setColor(7);
					cout << "1. You can't choose a case that has no seeds. \n";
					cout << "2. If your oponnent doesn't have seeds you must choose a case that gives seeds to your opponents, if possible." << endl;
					cout << "Please choose one of your board cases (A, B, C, D, E, F): ";
					cin >> c;
				}
			}
			else if (pl == 2)
			{
				switch (toupper(c))
				{
				case'A': indx_case_selected = 11;
					break;
				case'B': indx_case_selected = 10;
					break;
				case'C': indx_case_selected = 9;
					break;
				case'D': indx_case_selected = 8;
					break;
				case'E': indx_case_selected = 7;
					break;
				case'F': indx_case_selected = 6;
					break;
				default:
					validcase = false;
					cin.clear();
					cin.ignore(10000, '\n');
					if (pl == 1) setColor(12);
					else setColor(9);
					cout << "PLAYER " << pl;
					setColor(7);
					cout << " you didn't choose a valid case." << endl;
					cout << "Please choose one of your board cases (A, B, C, D, E, F): ";
					cin >> c;
				}
				if (casesvalid[indx_case_selected] == 0 && validcase == true)
				{
					validcase = false;
					cin.clear();
					cin.ignore(10000, '\n');
					if (pl == 1) setColor(12);
					else setColor(9);
					cout << "PLAYER " << pl;
					setColor(7);
					cout << " you didn't choose a valid case." << endl;
					setColor(2);
					cout << "IMPORTANT NOTES to remember: \n";
					setColor(7);
					cout << "1. You can't choose a case that has no seeds. \n";
					cout << "2. If your oponnent doesn't have seeds you must choose a case that gives seeds to your opponents, if possible." << endl;
					cout << "Please choose one of your board cases (A, B, C, D, E, F): ";
					cin >> c;
				}
			}
		}
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
			if (pl == 1) setColor(12);
			else setColor(9);
			cout << "PLAYER " << pl;
			setColor(7);
			cout << " you didn't choose a valid case." << endl;
			cout << "Please choose one of your board cases (A, B, C, D, E, F): ";
			cin >> c;
		}
	}
	//cout << "PLAYER " << pl << " chose case " << indx_case_selected << " with " << ns_case_selected << " seeds" << endl << endl;
}

void capturing(vector <int>& n_seeds, int& indx_lastcase, int& pl1, int& pl2, int& pl)
{
	vector <int> n_seeds_imag = n_seeds;
	int indx_lastcase_imag = indx_lastcase;
	while (n_seeds_imag[indx_lastcase_imag] == 3 || n_seeds[indx_lastcase_imag] == 2)
	{
		if (pl == 1 && indx_lastcase_imag > 5)
		{
			n_seeds_imag[indx_lastcase_imag] = 0;
		}
		else if (pl == 2 && indx_lastcase_imag < 6)
		{
			n_seeds_imag[indx_lastcase_imag] = 0;
		}
		if (indx_lastcase_imag + 1 == 12)
		{
			indx_lastcase_imag = -1;
		}
		indx_lastcase_imag++;
	}
	if ((!allzero_pl1(n_seeds_imag) && pl == 2) || (!allzero_pl2(n_seeds_imag) && pl == 1))
	{
		while (n_seeds[indx_lastcase] == 3 || n_seeds[indx_lastcase] == 2)
		{
			if (pl == 1 && indx_lastcase > 5)
			{
				pl1 = pl1 + n_seeds[indx_lastcase];
				n_seeds[indx_lastcase] = 0;
			}
			else if (pl == 2 && indx_lastcase < 6)
			{
				pl2 = pl2 + n_seeds[indx_lastcase];
				n_seeds[indx_lastcase] = 0;
			}
			if (indx_lastcase + 1 == 12)
			{
				indx_lastcase = -1;
			}
			indx_lastcase++;
		}
	}
}

int pcchoosing(vector <int>& casesvalid, int& player1_catch, int& player2_catch, vector <int>& n_seeds, int& pl)
{
	int playercatch_imag1 = player1_catch, playercatch_imag2 = player2_catch;
	vector <int> n_seeds_imag;
	int indx_lastcase = -1;
	vector <int> points;
	for (int i = 0; i < 6; i++)
	{
		n_seeds_imag = n_seeds;
		indx_lastcase = -1;
		playercatch_imag1 = player1_catch;
		if (n_seeds_imag[i] != 0)
		{
			moving(n_seeds_imag, i, indx_lastcase);
			capturing(n_seeds_imag, indx_lastcase, playercatch_imag1, playercatch_imag2, pl);
			points.push_back(playercatch_imag1);
		}
		else
		{
			points.push_back(-1);
		}
	}
	int max = points[0];
	int n;
	vector <int> valids = { 0, 0, 0, 0, 0, 0 };
	for (int i = 1; i < 6; i++)
	{
		if (max < points[i])
		{
			max = points[i];
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (points[i] == max)
			valids[i] = 1;
	}
	srand(time(NULL));
	n = rand() % 6;
	while (valids[n] == 0)
	{
		n = rand() % 6;
	}
	return n;
}

void anouncepcchoosing(int& n)
{
	setColor(12);
	cout << "PLAYER 1 ";
	setColor(7);
	cout << "chose case ";
	switch (n)
	{
	case 0: cout << "A";
		break;
	case 1: cout << "B";
		break;
	case 2: cout << "C";
		break;
	case 3: cout << "D";
		break;
	case 4: cout << "E";
		break;
	case 5: cout << "F";
		break;
	default: cout << "ERROR" << n;
		break;
	}
	cout << '\n' << "Write something to continue...";
	char c;
	cin >> c;
}

void changingplayer(int& pl)
{
	if (pl == 1) pl = 2;
	else pl = 1;
}

void announcingwinner(const int& pl1, const int& pl2)
{

	/*if (pl == 1) setColor(12);
	else setColor(9);*/
	if (pl1 > 24)
	{
		setColor(12);
		cout << "			PLAYER 1 WON" << endl;
	}
	else if (pl2 > 24)
	{
		setColor(9);
		cout << "			PLAYER 2 WON" << endl;
	}
	else if (pl1 == 24 && pl2 == 24)
	{
		setColor(2);
		cout << "			IT'S A DRAW" << endl;
	}
	setColor(7);
}

void game(vector <int> numberpieces, int& player1_catch, int& player2_catch, int& playerchoosing, int indx_case_selected, int indx_lastcase, vector <int> casesvalid)
{
	//to start
	init();
	if (decideBetweenPCorFriend() == 1)
	{
		displays(numberpieces, player1_catch, player2_catch);
		announcingfirstplayer(playerchoosing);

		while (player1_catch <= 24 && player2_catch <= 24 && !(player2_catch == 24 && player1_catch == 24))
		{
			casesvalidfunction(playerchoosing, numberpieces, casesvalid);
			if (validchoosing(playerchoosing, numberpieces, casesvalid) == false)
			{
				ifisnotvalidchoosing(numberpieces, player1_catch, player2_catch);
				break;
			}
			choosing(playerchoosing, numberpieces, indx_case_selected, casesvalid);
			moving(numberpieces, indx_case_selected, indx_lastcase);
			capturing(numberpieces, indx_lastcase, player1_catch, player2_catch, playerchoosing); cout << endl;
			displays(numberpieces, player1_catch, player2_catch);
			changingplayer(playerchoosing);
		}
		//tofinish
		announcingwinner(player1_catch, player2_catch);
		//make a cicle to let them play again
	}
	else
	{
		displays(numberpieces, player1_catch, player2_catch);
		announcingfirstplayer(playerchoosing);
		//player 1 is the pc
		//player 2 is the user

		while (player1_catch <= 24 && player2_catch <= 24 && !(player2_catch == 24 && player1_catch == 24))
		{
			if (playerchoosing == 1)
			{
				casesvalidfunction(playerchoosing, numberpieces, casesvalid);
				if (validchoosing(playerchoosing, numberpieces, casesvalid) == false)
				{
					ifisnotvalidchoosing(numberpieces, player1_catch, player2_catch);
					break;
				}
				indx_case_selected = pcchoosing(casesvalid, player1_catch, player2_catch, numberpieces, playerchoosing);
				anouncepcchoosing(indx_case_selected);
				moving(numberpieces, indx_case_selected, indx_lastcase);
				capturing(numberpieces, indx_lastcase, player1_catch, player2_catch, playerchoosing); cout << endl;

			}
			else
			{
				casesvalidfunction(playerchoosing, numberpieces, casesvalid);
				if (validchoosing(playerchoosing, numberpieces, casesvalid) == false)
				{
					ifisnotvalidchoosing(numberpieces, player1_catch, player2_catch);
					break;
				}
				choosing(playerchoosing, numberpieces, indx_case_selected, casesvalid);
				moving(numberpieces, indx_case_selected, indx_lastcase);
				capturing(numberpieces, indx_lastcase, player1_catch, player2_catch, playerchoosing); cout << endl;
			}
			displays(numberpieces, player1_catch, player2_catch);
			changingplayer(playerchoosing);
		}
		//tofinish
		announcingwinner(player1_catch, player2_catch);
		//make a cicle to let them play again
	}
}

int finishing()
{
	setColor(7);
	cout << "	The game finished, do you want to quit or play again?\n	(ctrl z to quit or write something to play again)";
	char c;
	cin >> c;
	if (cin.eof()) return 0;
	else return 1;
}

int main()
{
	do
	{
		vector <int> numberpieces = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }; //the game starts with 4 seeds in each space, there are 12 spaces in total 6 for each player
		int player1_catch = 0, player2_catch = 0;
		int playerchoosing = startingplayer(); // the player who is currently the one to make is move, note that in the first round it is generated randomly
		int indx_case_selected = -1;
		int indx_lastcase = -1;
		vector <int> casesvalid; //assumes value 1 if the case is valid to be chosen and 0 if it can't be chosen
		game(numberpieces, player1_catch, player2_catch, playerchoosing, indx_case_selected, indx_lastcase, casesvalid);
	} while (finishing() == 1);
}