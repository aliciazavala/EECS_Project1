CalendarApp: main.o Executive.o Calendar.o Menu.o MainMenu.o MonthMenu.o Event.o People.o project1_lib.o NewEventMenu.o SettingsMenu.o
	g++ -std=c++11 -g -Wall main.o Executive.o Calendar.o Menu.o  MainMenu.o MonthMenu.o Event.o People.o project1_lib.o NewEventMenu.o SettingsMenu.o -o CalendarApp

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Calendar.h StackInterface.h Stack.h Stack.cpp SLNode.h Menu.h Event.h SettingsMenu.h NewEventMenu.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Calendar.o: Calendar.h Calendar.cpp project1_lib.h Event.h
	g++ -std=c++11 -g -Wall -c Calendar.cpp

Menu.o: Event.h Menu.h Menu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c Menu.cpp

MainMenu.o: Menu.h MainMenu.h MainMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c MainMenu.cpp

MonthMenu.o: Menu.h MonthMenu.h MonthMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c MonthMenu.cpp

NewEventMenu.o: Menu.h MonthMenu.h project1_lib.h NewEventMenu.h NewEventMenu.cpp
	g++ -std=c++11 -g -Wall -c NewEventMenu.cpp 

SettingsMenu.o: Menu.h SettingsMenu.h SettingsMenu.cpp project1_lib.h
	g++ -std=c++11 -g -Wall -c SettingsMenu.cpp

Event.o: Event.h Event.cpp People.h
	g++ -std=c++11 -g -Wall -c Event.cpp

People.o: People.h People.cpp
	g++ -std=c++11 -g -Wall -c People.cpp

project1_lib.o: project1_lib.h project1_lib.cpp
	g++ -std=c++11 -g -Wall -c project1_lib.cpp

clean:
	rm *.o CalendarApp
