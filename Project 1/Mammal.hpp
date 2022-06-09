/** @file Mammal interface.hpp */
#ifndef MAMMAL_INTERFACE_
#define MAMMAL_INTERFACE_
#include <iostream>
#include <string>
#include "Animal.hpp" // Include header file

/** Mammal class (derived from Animal class) definition */
class Mammal : public Animal{
	private:
		bool hair_; //Mammal's hair value
		bool airborne_; //Mammals's airborne value
		bool aquatic_; //Mammal's aquatic value
		bool toothed_; //Mammal's toothed value
		bool fins_; //Mammal's fins value
		bool tail_; //Mammal's tail value
		int legs_; //Number of mammal's legs
	public:
		/** Default constructor: Creates a mammal and initializes all of it's bool values to
		false and sets legs_ to zero. Inhereted animal's values are set to default.
		Precondition: None
		Postcondition: A mammal with defaul animal's values and mammal's values set to false
		and 0 exists*/
		Mammal();

		/** Costructor: Creates a mammal with user provided parameters (inhereted from animal)
		and sets mammal's values to default.
		Precondition: Name, domestic and predator values are the desired imputs.
		Postcondition: A mammal with name, domestic, and predator desired values exists. */
		Mammal(std::string name, bool domestic = false, bool predator = false);

		/** Gets this mammal's hair value
		Precondition: None
		Postcondition: Returns the hair value */
		bool hasHair() const;

		/** Gets this mammal's airborne value.
		Precondition: None
		Postcondition: Returns the airborne value. */
		bool isAirborne() const;

		/** Gets this mammal's aquatic value.
		Precondition: None
		Postcondition: Returns the aquatic value. */
		bool isAquatic() const;

		/** Gets this mammal's toothed value.
		Precondition: None
		Postcondition: Returns the toothed value. */
		bool isToothed() const;

		/** Gets this mammal's fins value.
		Precondition: None
		Postcondition: Returns the fins value. */
		bool hasFins() const;

		/** Gets this mammal's tail value.
		Precondition: None
		Postcondition: Returns the tail value. */
		bool hasTail() const;

		/** Gets this mammal's legs number.
		Precondition: None
		Postcondition: Returns the legs number. */
		int legs() const;

		/** Sets (alters) hair value of this mammal.
		Precondition: hair is ethier true or false.
		Postcondition: Mammmal's hair value is now ethier false or true. */
		void setHair();

		/** Sets (alters) airborne value of this mammal.
		Precondition: airborne is ethier true or false.
		Postcondition: Mammmal's airborne value is now ethier false or true. */
		void setAirborne();

		/** Sets (alters) aquatic value of this mammal.
		Precondition: aquatic is ethier true or false.
		Postcondition: Mammmal's aquatic value is now ethier false or true. */
		void setAquatic();

		/** Sets (alters) toothed value of this mammal.
		Precondition: toothed is ethier true or false.
		Postcondition: Mammmal's toothed value is now ethier false or true. */
		void setToothed();

		/** Sets (alters) fins value of this mammal.
		Precondition: fins is ethier true or false.
		Postcondition: Mammmal's fins value is now ethier false or true. */
		void setFins();

		/** Sets (alters) tail value of this mammal.
		Precondition: tail is ethier true or false.
		Postcondition: Mammmal's tail value is now ethier false or true. */
		void setTail();

		/** Sets (alters) the number of legs of this mammal.
		Precondition: legs is the desired numer of legs.
		Postcondition: Animals desired legs is legs_. */
		void setLegs(int legs);

		//Compiler-generated destructor is sufficient
};	//End of Mammal
#endif //End of header file.
