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
