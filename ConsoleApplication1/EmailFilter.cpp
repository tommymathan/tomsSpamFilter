#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "EmailFilter.h"
using namespace std;

EmailFilter::EmailFilter(string input)
{
	word = input;
	spamFilterValue = 1;
}

EmailFilter::EmailFilter(string input, int spamValue)
{
	word = input;
	spamFilterValue = spamValue;
}

void EmailFilter::setFilter(string FilterString)
{
	word = FilterString;
}

void EmailFilter::setSpamFilterValue(int value)
{
	spamFilterValue = value;
}

string EmailFilter::getFilter()
{
	return word;
}

int EmailFilter::getSpamFilterValue()
{
	return spamFilterValue;
}
