#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>

class People
{
	public:
		People(){};
		People(std::string fname);
		void setFirstName(std::string fname);
		std::string getFirstName() const;

	private:

		//int id; ID feature will be added later
		std::string m_firstName;



	
};

#endif
