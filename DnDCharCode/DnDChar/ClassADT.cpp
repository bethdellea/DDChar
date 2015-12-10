//ClassADT.cpp
//Joseph Yull
//12-10-2015

#include "stdafx.h"
#include "ClassADT.h"

//Returns a random number with values bewteen min and max, including both min and max
int ClassADT::generateRandomNum(int min, int max)
{
	srand(time(NULL));

	return rand() % (max - min + 1) + min;
}