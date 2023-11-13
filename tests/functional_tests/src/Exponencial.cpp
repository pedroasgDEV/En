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

double Exponencial::execute(){
    return getSource()->getValue() * 0.01;
}