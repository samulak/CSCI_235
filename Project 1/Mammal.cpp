/** @file Mammal.cpp */
#include "Mammal.hpp" // Include header file

Mammal::Mammal() : Animal(){
	hair_ = false;
	airborne_ = false;
	aquatic_ = false;
	toothed_ = false;
	fins_ = false;
	tail_ = false;
	legs_ = 0;
} //end default constructor

Mammal::Mammal(std::string name, bool domestic, bool predator ) : Animal(name, domestic, predator){
	hair_ = false;
	airborne_ = false;
	aquatic_ = false;
	toothed_ = false;
	fins_ = false;
	tail_ = false;
	legs_ = 0;
} //end constructor

bool Mammal::hasHair() const {
	return hair_;
} //end hasHair

bool Mammal::isAirborne() const {
	return airborne_;
} //end isAirborne

bool Mammal::isAquatic() const {
	return aquatic_;
} //end isAquatic

bool Mammal::isToothed() const {
	return toothed_;
} //end isToothed

bool Mammal::hasFins() const {
	return fins_;
} //end hasFins

bool Mammal::hasTail() const {
	return tail_;
} //end hasTail

int Mammal::legs() const {
	return legs_;
} //end legs

void Mammal::setHair() {
	if(hair_ == true){
		hair_ = false;
	}else{
		hair_ = true;
	}

} //end setHair

void Mammal::setAirborne() {
	if(airborne_ == true){
		airborne_ = false;
	}else{
		airborne_ = true;
	}
} //end setAirborne

void Mammal::setAquatic() {
	if(aquatic_ == true){
		aquatic_ = false;
	}else{
		aquatic_ = true;
	}
} //end setAquatic

void Mammal::setToothed() {
	if(toothed_ == true){
		toothed_ = false;
	}else{
		toothed_ = true;
	}
} //end setToothed

void Mammal::setFins() {
	if(fins_ == true){
		fins_ = false;
	}else{
		fins_ = true;
	}
} //end setFins

void Mammal::setTail() {
	if(tail_ == true){
		tail_ = false;
	}else{
		tail_ = true;
	}
} //end setTail

void Mammal::setLegs(int legs){
	legs_ = legs;
} //end setLegs
//end of implementation file
