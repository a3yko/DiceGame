#pragma once
#include <stdlib.h>
#include <time.h>
class Roll
{
public:
	Roll();

	~Roll();
	int result();
	int roll();
private:
	int die;
};

