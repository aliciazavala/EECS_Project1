#include "People.h"

People::People(std::string fname)
{
    m_firstName = fname;
}

void People::setFirstName(std::string fname)
{
    m_firstName=fname;
    
}

std::string People::getFirstName() const
{
    return m_firstName;
}
