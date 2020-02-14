#include "Event.h"

Event::Event()
{
    mMonth = "";
}

void Event::setMonth(std::string month)
{
    mMonth = month;
}

std::string Event::getMonth() const
{
    return mMonth;
}
