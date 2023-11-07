#include "Logistical.h"

//Constructors
Logistical::Logistical(const std::string& name, System* source, System* target) : Flow(name, source, target) {}
Logistical::Logistical(const Logistical& other) : Flow(other.name, other.source, other.target) {}

//Destructors
Logistical::~Logistical(){}

bool Logistical::execute(){
    double exc = target->getValue() * 0.01 * (1 - target->getValue()/70);
    target->setValue( exc + target->getValue());
    source->setValue(source->getValue() - exc);
    return true;
}