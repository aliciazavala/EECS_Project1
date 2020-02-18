testing: main.o User.o Events.o
	g++ -g -std=c++11 -Wall main.o User.o Events.o -o testing

main.o: main.cpp User.h Events.h
	g++ -g -std=c++11 -Wall -c main.cpp

User.o: User.h User.cpp
	g++ -g -std=c++11 -Wall -c User.cpp

Events.o: Events.cpp Events.h User.h
	g++ -g -std=c++11 -Wall -c Events.cpp

clean:
	rm *.o testing
