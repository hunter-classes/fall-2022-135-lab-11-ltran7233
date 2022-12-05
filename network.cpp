#include <iostream>
#include <cwctype>
#include <string>
#include "network.h"

int Network::findID(std::string usrn)
{
	int num = -1;
	for (int i=0; i<20; i++)
	{
		if (profiles[i].getUsername()==usrn)
		{
			num = i;
		}
	}
	return num;
}

Network::Network()
{
	numUsers = 0;
	for (int i=0; i<MAX_USERS; i++)
	{
		for (int j=0; j<MAX_USERS; j++)
		{
			following[i][j] = false;
		}
	}
}

bool Network::addUser(std::string usrn, std::string dspn)
{
	bool pass = false;
	if (checkAlphaNum(usrn) && checkOtherUsers(usrn) && checkProfilesFull())
	{
		Profile per = Profile(usrn, dspn);
		profiles[numUsers] = per;
		numUsers++;
		pass = true;
	}
	return pass;
}

bool Network::checkAlphaNum(std::string usrn)
{
	bool check = true;
	if (!usrn.empty())
	{
		for (int i=0; i<usrn.length(); i++)
		{
			if (!iswalnum(usrn[i]))
			{
				check = false;
			}
		}
	}
	else
	{
		check = false;
	}
	return check;
}

bool Network::checkOtherUsers(std::string usrn)
{
	bool check = true;
	if (findID(usrn)!=-1)
	{
		check = false;
	}
	return check;
}

bool Network::checkProfilesFull()
{
	bool check = true;
	if (numUsers==20)
	{
		check = false;
	}
	return check;
}

bool Network::follow(std::string usrn1, std::string usrn2)
{
	bool check = false;
	if (findID(usrn1)!=-1 && findID(usrn2)!=-1)
	{
		following[findID(usrn1)][findID(usrn2)] = true;
		check = true;
	}
	return check;
}

void Network::printDot()
{
	std::cout << "digraph {" << std::endl;
	for (int i=0; i<numUsers; i++)
	{
		std::cout << "\t\"@" << profiles[i].getUsername() << "\"" << std::endl;
	}
	std::cout << "\n";
	for (int i=0; i<MAX_USERS; i++)
	{
		for (int j=0; j<MAX_USERS; j++)
		{
			if (following[i][j])
			{
				std::cout << "\t\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << std::endl;
			}
		}
	}
	std::cout << "}" << std::endl;
}
