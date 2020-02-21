CalendarApp: main.o Executive.o Menu.o MainMenu.o MonthMenu.o project1_lib.o NewEventMenu.o SettingsMenu.o TimeMenu.o EventMenu.o
	g++ -std=c++11 -g -Wall main.o Executive.o Menu.o  MainMenu.o MonthMenu.o project1_lib.o EventMenu.o NewEventMenu.o SettingsMenu.o TimeMenu.o -o CalendarApp

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp StackInterface.h Stack.h Stack.cpp SLNode.h Menu.h SettingsMenu.h NewEventMenu.h TimeMenu.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Menu.o: Menu.h Menu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c Menu.cpp

MainMenu.o: Menu.h MainMenu.h MainMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c MainMenu.cpp

MonthMenu.o: Menu.h MonthMenu.h MonthMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c MonthMenu.cpp

EventMenu.o: Menu.h EventMenu.h EventMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c EventMenu.cpp

NewEventMenu.o: Menu.h MonthMenu.h project1_lib.h NewEventMenu.h NewEventMenu.cpp
	g++ -std=c++11 -g -Wall -c NewEventMenu.cpp 

SettingsMenu.o: Menu.h SettingsMenu.h SettingsMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c SettingsMenu.cpp

TimeMenu.o: Menu.h TimeMenu.h TimeMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c TimeMenu.cpp

project1_lib.o: project1_lib.h project1_lib.cpp
	g++ -std=c++11 -g -Wall -c project1_lib.cpp

clean:
	rm *.o CalendarApp
