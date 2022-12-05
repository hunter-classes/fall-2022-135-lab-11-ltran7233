CXXFLAGS=-std=c++11 -Wall -Wpedantic

main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o $(CXXFLAGS)

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o $(CXXFLAGS)

profile.o: profile.cpp profile.h
	g++ -c profile.cpp

network.o: network.cpp network.h
	g++ -c network.cpp

main.o: main.cpp profile.h network.h
	g++ -c main.cpp $(CXXFLAGS)

tests.o: tests.cpp doctest.h profile.h network.h
	g++ -c tests.cpp $(CXXFLAGS)

clean:
	rm -f main.o tests.o profile.o network.o
