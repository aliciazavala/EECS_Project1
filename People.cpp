#include "People.h"

People::People(std::string fname)
{
    m_firstName = fname;
}

void People::setFirstName(std::string fname)
{
    m_firstName=fname;
    
}

void People::getFirstName()
{
    return m_firstName;
}
