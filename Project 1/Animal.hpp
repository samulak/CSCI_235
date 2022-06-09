/** @file Animal interface.hpp */
#ifndef ANIMAL_INTERFACE_
#define ANIMAL_INTERFACE_
#include <string>
#include <iostream>

/** Animal class definition */
class Animal{
	private:
		std::string name_; //Name of the object
		bool domestic_; //Animal is set to ethier domestic or not.
		bool predator_; //Animal is set to ethier predator or not
	public:
		/** Default constructor: Creates an animal and initializes its name to N/A and
		sets both domestic and predator values to false.
		Precondition: None
		Postcondition: A not domestic and not predator animal with the name N/A exists. */
		Animal();

		/** Constructor: Creates an animal with users provided parameters or sets the
		values to default values.
		Precondition: Name and value for domestic and predator are the desired inputs.
		Postcondition: An animal with name, domestic, and predator values exists. */
		Animal(std::string name, bool domestic = false, bool predator = false);

		/** Gets this animal's name.
		Precondition: None
		Postcondition: Returns the name */
		std::string getName() const;

		/** Gets this animal's domestic value.
		Precondition: None
		Postcondition: Returns domestic's value */
		bool isDomestic() const;

		/** Gets this animal's predator value.
		Precondition: None
		Postcondition: Returns predator's value */
		bool isPredator() const;

		/** Sets (alters) the name of this animal.
		Precondition: name is the desired name.
		Postcondition: Animals new name is name */
		void setName(std::string name);

		/** Sets (alters) domestic_ value of this animal.
		Precondition: domestic_ is ethier true or false.
		Postcondition: Animal's domestic_ value is now ethier false or true. */
		void setDomestic();

		/** Sets (alters) predator_ value of this animal.
		Precondition: predator_ is ethier true or false.
		Postcondition: Animal's predator_ value is now ethier false or true. */
		void setPredator();

		//Compiler-generated destructor is sufficient
};	//End of Animal
#endif //End of header file.
