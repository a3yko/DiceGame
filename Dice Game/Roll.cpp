#include "stdafx.h"
#include "Roll.h"

Roll::Roll()
{
	srand(time(NULL));
}


Roll::~Roll()
{
}

int Roll::roll()
{
	die = rand() % 6 + 1;
	return die;
}
int Roll::result()
{
	return die;
}