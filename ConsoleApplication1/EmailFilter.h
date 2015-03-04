#ifndef EmailFilter_h
#define EmailFilter_h

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class EmailFilter
{
public:
	EmailFilter(string );
	EmailFilter(string , int);
	string getFilter();
	int getSpamFilterValue();
	void setFilter(string);
	void setSpamFilterValue(int); 
private:
	string word;
	int spamFilterValue;

};

#endif