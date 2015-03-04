#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "email.h"
#include "EmailFilter.h"
#include <string>
using namespace std;



int main()
{
	//This will create the input stream for the spamwords text file
	ifstream spamwordsTextFileInput;

	// THis is output stream that will output the score for the email
	ofstream outputText;

	//This is a string with all the spam words
	string spamWordsList;

	// This vector will hold all the filters
	vector<EmailFilter> filters;
	
	//An email object is created from a text a file
	email testing("emailtoRead.txt");

	//The email is tokenized by white spaces
	vector<string> tokenEmail = testing.tokenizeEmail();

	//Here the list of spam words from the text file is opened from the text file
	spamwordsTextFileInput.open("spamWords.txt");
	if(spamwordsTextFileInput.is_open())
	{
		while( getline(spamwordsTextFileInput, spamWordsList));
	}

	//Spam words are tokenized and put into spamtokens vector
	string buf; 
	stringstream ss(spamWordsList); 
	vector<string> Spamtokens; 
	while (ss >> buf)
		Spamtokens.push_back(buf);

	//spam tokens are put into vector of spam filters
	for(vector<string>::iterator spamWords = Spamtokens.begin(); spamWords != Spamtokens.end(); ++spamWords)
	{
		filters.push_back(EmailFilter(*spamWords));
	}

	//Here the email searched and compared with the spam filters
	for(int i = 0; i < tokenEmail.size(); i++)
	{
		for(int j = 0; j < filters.size(); j++)
		{
			EmailFilter currentFilter = filters.at(j);
			if(tokenEmail.at(i) == currentFilter.getFilter())
			{
				testing.setSpamScore(testing.getSpamScore() + currentFilter.getSpamFilterValue());
			}
		}
	}

	cout << "Tom's Email Spam Filter 2015 \n";
	cout << "To change the email, edit emailtoRead.txt \n";
	cout << "\n";
	cout << "Email Message: ";
	cout << testing.getMessage();
	cout << "\n";
	cout << "\n";
	cout << "Number of words : ";
	cout << tokenEmail.size();
	cout << "\n";
	cout << "Spam score (Number of words Considered Spam): " ;

	cout << testing.getSpamScore();
	cout << "\n";

	double spamRatio = (double)testing.getSpamScore()/(double)tokenEmail.size();

	cout << "Spam Ratio: ";
	cout << spamRatio;
	cout << "\n";
	if (spamRatio > .15)
	{
		cout << "The spam ratio for this email is greater than .15, hence this email is spam \n";
	}
	
	else
	{
		cout << " This Email had a spam ratio of less than .15, hence this email is not spam \n"; 
	}
	cin.get();
}