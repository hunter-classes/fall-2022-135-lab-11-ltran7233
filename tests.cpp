#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Task A tests")
{
	Profile p1("steve", "Steve");
	CHECK(p1.getUsername()=="steve");
	CHECK(p1.getFullName()=="Steve (@steve)");
	
	p1.setDisplayName("Stevey");
	CHECK(p1.getFullName()=="Stevey (@steve)");
}

TEST_CASE("Task B tests")
{
	Network n1;
	CHECK(n1.addUser("ali", "Alice")==1);
	CHECK(n1.addUser("&mat", "Matthew")==0);
	CHECK(n1.addUser("ali", "Alina")==0);
}

TEST_CASE("Task C tests") // only testing follow
{
	Network n2;
	
	n2.addUser("bob", "Bob");
	n2.addUser("adam", "Adam");
	n2.addUser("drew", "Drew");

	CHECK(n2.follow("bob", "drew")==true);
	CHECK(n2.follow("bob", "adam")==true);
	CHECK(n2.follow("adam", "mark")==false);
}
