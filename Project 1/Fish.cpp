/** @file Fish.cpp */
#include "Fish.hpp" // Include header file

Fish::Fish() : Animal(){
	venomous_ = false;
} //end default constructor

Fish::Fish(std::string name, bool domestic, bool predator) : Animal(name, domestic, predator){
	venomous_ = false;
} //end constructor

bool Fish::isVenomous() const{
	return venomous_;
} //end isVenomous

void Fish::setVenomous(){
	if(venomous_ == true){
		venomous_ = false;
	}else{
		venomous_ = true;
	}
} //end setVenomous
//end of implementation file
