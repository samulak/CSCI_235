/** @file Bird.cpp */
#include "Bird.hpp" // Include header file

Bird::Bird() : Animal(){
	airborne_  = false;
	aquatic_ = false;
} //end default constrctor

Bird::Bird(std::string name, bool domestic, bool predator) : Animal(name, domestic, predator){
	airborne_ = false;
	aquatic_ = false;
} //end constructor

bool Bird::isAirborne() const{
	return airborne_;
} //end isAirborne

bool Bird::isAquatic() const{
	return aquatic_;
} //end isAquatic

void Bird::setAirborne(){
	if(airborne_ == true){
		airborne_ = false;
	}else{
		airborne_ = true;
	}
} //end setAirborne

void Bird::setAquatic(){
	if(aquatic_ = true){
		airborne_ = false;
	}else{
		airborne_ = true;
	}
} //end setAquatic
//end of implementation file

