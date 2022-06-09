/** @file Animal.cpp */
#include "Animal.hpp" // Include header file

Animal::Animal(){
	name_ = "N/A";
	domestic_ = false;
	predator_ = false;
} //end default constructor

Animal::Animal(std::string name, bool domestic, bool predator){
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
} //end constructor

std::string Animal::getName() const{
	return name_;
} //end getName

bool Animal::isDomestic() const{
	return domestic_;
} //end isDomestic

bool Animal::isPredator() const{
	return predator_;
} //end isPredator

void Animal::setName(std::string name){
	name_ = name;
} //end setName

void Animal::setPredator(){
	if(predator_ == true){
		predator_ = false;
	}else{
		predator_ = true;
	}
} //end setPredator

void Animal::setDomestic(){
	if(domestic_ == true){
		domestic_ = false;
	}else{
		domestic_ = true;
	}
} //end setDomestic
//end of implementation file
