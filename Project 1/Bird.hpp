/** @file Bird interface.hpp */
#ifndef BIRD_INTERFACE_
#define BIRD_INTERFACE_
#include <iostream>
#include <string>
#include "Animal.hpp" // Include header file

/** Bird class (derived from class Animal) definition */
class Bird : public Animal{
	private:
		bool airborne_; //Bird's airborne value
		bool aquatic_; //Bird's aquatic value
	public:
		/** Default constructor: Creates a bird and initializes all of it's airborne and
		aquatic values to false. Inhereted animal's values are set to default.
		Precondition: None
		Postcondition: A bird with defaul animal's values and bird's values set to false exists*/
		Bird();

		/** Costructor: Creates a bird with user provided parameters (inhereted from animal)
		and sets birds's values to default.
		Precondition: Name, domestic and predator values are the desired imputs.
		Postcondition: A bird with name, domestic, and predator desired values exists. */
		Bird(std::string name, bool domestic = false, bool predator = false);

		/** Gets this bird's airborne value
		Precondition: None
		Postcondition: Returns the airborne value */
		bool isAirborne() const;

		/** Gets this bird's aquatic value
		Precondition: None
		Postcondition: Returns the aquatic value */
		bool isAquatic() const;

		/** Sets (alters) airborne value of this bird.
		Precondition: airborne is ethier true or false.
		Postcondition: Bird's airborne value is now ethier false or true. */
		void setAirborne();

		/** Sets (alters) aquatic value of this bird.
		Precondition: aquatic is ethier true or false.
		Postcondition: Bird's aquatic value is now ethier false or true. */
		void setAquatic();

		//Compiler-generated destructor is sufficient
};	//End of Bird
#endif //End of header file.
