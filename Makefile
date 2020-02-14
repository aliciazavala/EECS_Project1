CalendarApp: main.o Executive.o Calendar.o Display.o Event.o
	g++ -std=c++11 -g -Wall main.o Executive.o Calendar.o Display.o Event.o -o CalendarApp

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Display.h Calendar.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Calendar.o: Calendar.h Calendar.cpp
	g++ -std=c++11 -g -Wall -c Calendar.cpp

Display.o: Display.h Display.cpp Stack.h Stack.cpp project1_lib.h PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c Display.cpp

Event.o: Event.h Event.cpp People.h
	g++ -std=c++11 -g -Wall -c Event.cpp

People.o: People.h People.cpp
	g++ -std=c++11 -g -Wall -c People.cpp

clean:
	rm *.o CalendarApp
