
#include "Calendar.h"
//using namepsace std;
Calendar::Calendar(int size)
{
  m_eventList = new Event[size];
  m_numevents = 0;
}
void Calendar::setSize(int s)
{
  m_numevents = s;
}
int Calendar::getSize()
{
  return m_numevents;
}
void Calendar::insertEvent(Event x)
{
  delete m_eventList;
  m_numevents++;
  m_eventList = new Event[m_numevents];
  m_eventList[m_numevents] = x;
}
Event* Calendar::getEvents(std::string month)
{
  int numEventsInMonth = 0;
  int y = 0;
  for(int i = 0; i<m_numevents; i++)
  {
    if(m_eventList[i].getMonth() == month)
    {
      numEventsInMonth++;
    }
  }
  m_Month = new Event[numEventsInMonth];
  for(int j = 0; j<m_numevents; j++)
  {
    if(m_eventList[j].getMonth() == month)
    {
      m_Month[y] = m_eventList[j];
      y++;
    }
  }
  return m_Month;
}
