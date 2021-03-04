#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "Roll.h"


using namespace std;

bool retry = false;

void rules(int, int, bool, int, int,int, Roll, Roll);
int rollDie(int, Roll, Roll);
int winLose(int, int,int, int, int);
int main()
{
	
	int result = 0, round = 1, orgnum, die = 0, dieSum;
	Roll first, second;
	dieSum = rollDie(result, first, second);
	orgnum = dieSum;
	
	while (retry == false)
	{
		
		winLose(result, round, orgnum, die, dieSum);
		rules(result, round, retry, orgnum, die,dieSum, first, second);
		dieSum = rollDie(result, first, second);
		round++;
		system("pause");
	}
}

int rollDie(int result, Roll first, Roll second)
{
	first.roll();
	second.roll();
	result = first.result() + second.result();
	return result;
}


void rules(int result, int round, bool retry, int orgnum, int die,int dieSum, Roll first, Roll second)
{
	cout << " Round: " << round << endl;
	cout << dieSum << endl;


	if (winLose(result, round, orgnum, die, dieSum) == 1)
	{	
		retry = true;
		cout << " You Win! " << endl;
	
	}
	else
	{
		retry = false;
		rollDie(result, first, second);
		
	}
	if (winLose(result, round, orgnum, die,dieSum) == 2)
	{
		retry = true;
		cout << " You Lose! " << endl;
		
	}
	else
	{
		retry = false;
		rollDie(result, first, second);
		
	}
}


int winLose(int result, int round, int orgnum, int die, int dieSum)
{
	if (round == 1)
	{
		if (dieSum == 7 || dieSum == 11)
		{
			die = 1;
			return die;
		}
		 if (dieSum == 2 || dieSum == 3 || dieSum == 12)
		{
			die = 2;
			return die;
		}
	}
	if (round > 1)
	{
		if (dieSum == 7)
		{
			die = 2;
			return die;
		}
		if (dieSum == orgnum)
		{
			die = 1;
			return die;
		}
	}
}
