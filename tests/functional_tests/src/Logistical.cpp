#include "Logistical.hpp"

//Constructors
Logistical::Logistical(const std::string& name, System* source, System* target){
    this->name = name;
    this->source = source;
    this->target = target;
}


Logistical::Logistical(const Logistical& other){
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

//Destructors
Logistical::~Logistical(){}

double Logistical::execute(){
    return 0.01 * getTarget()->getValue() * (1.0 - getTarget()->getValue() / 70.0);
}