#ifndef email_h
#define email_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


class email
{

public:
	email(string , string, string );
	email(string);
	string getMessage();
	string getSubject();
	string getSender();
	vector<string> tokenizeEmail();
	int getSpamScore();
	void setMessage(string);
	void setSubject(string);
	void setSender(string);
	void setSpamScore(int);

private:
	string message;
	string subject;
	string sender;
	int spamScore;
	ifstream inputText;
	ofstream outputText;
};

#endif