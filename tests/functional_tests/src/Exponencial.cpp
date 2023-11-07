#include "Exponencial.h"

//Constructors
Exponencial::Exponencial(const std::string& name, System* source, System* target) : Flow(name, source, target) {}
Exponencial::Exponencial(const Exponencial& other) : Flow(other.name, other.source, other.target) {}

//Destructors
Exponencial::~Exponencial(){}

bool Exponencial::execute(){
    double exc = source->getValue() * 0.01;
    target->setValue( exc + target->getValue());
    source->setValue(source->getValue() - exc);
    return true;
}