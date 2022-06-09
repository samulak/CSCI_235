/** @file Fish interface.hpp */
#ifndef FISH_INTERFACE_
#define FISH_INTERFACE_
#include <iostream>
#include <string>
#include "Animal.hpp" // Include header file

/** Fish class (derived from Animal class) definition. */
class Fish : public Animal{
	private:
		bool venomous_; //Bird's venomous value
	public:
		/** Default constructor: Creates a fish and initializes venomous value to
		false. Inhereted animal's values are set to default.
		Precondition: None
		Postcondition: A fish with defaul animal's values and fish's values false
		exists*/
		Fish();

		/** Costructor: Creates a fish with user provided parameters (inhereted from animal)
		and sets fish's value to default.
		Precondition: Name, domestic and predator values are the desired imputs.
		Postcondition: A fish with name, domestic, and predator desired values exists. */
		Fish(std::string name, bool domestic = false, bool predator = false);

		/** Gets this fish's venomous value.
		Precondition: None
		Postcondition: Returns the venomous value. */
		bool isVenomous() const;

		/** Sets (alters) venomous value of this fish.
		Precondition: venomous value is ethier true or false.
		Postcondition: Fish's venomous value is now ethier false or true. */
		void setVenomous();

		//Compiler-generated destructor is sufficient
};	//End of Mammal
#endif //End of header file.
