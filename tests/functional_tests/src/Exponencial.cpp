#include "Exponencial.h"

//Constructors
Exponencial::Exponencial(const std::string& name, System* source, System* target){
    this->name = name;
    this->source = source;
    this->target = target;
}

//Copia de other
Exponencial::Exponencial(const Exponencial& other){
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

//Destructors
Exponencial::~Exponencial(){}

bool Exponencial::execute(){
    double exc = source->getValue() * 0.01;
    target->setValue( exc + target->getValue());
    source->setValue(source->getValue() - exc);
    return true;
}