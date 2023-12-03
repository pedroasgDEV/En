#include "FlowIMP.hpp"

//Destructor
FlowIMP::~FlowIMP() {}

//Geters e seters
//Name
std::string FlowIMP::getName() const { return name; }
void FlowIMP::setName(const std::string& name) { this->name = name; }
//Source
System* FlowIMP::getSource() const { return source; }
void FlowIMP::setSource(System* source) { this->source = source; }
//Target
System* FlowIMP::getTarget() const { return target; }
void FlowIMP::setTarget(System* target) { this->target = target; }

//Sobrecarga de Operadores
// Operador de atribuição
FlowIMP& FlowIMP::operator=(const FlowIMP& other) {
    if(other == *this) return *this;
    name = other.name;
    source = other.source;
    target = other.target;
    return *this;
}

// Operador de igualdade
bool FlowIMP::operator==(const FlowIMP& other) const {
    return (name == other.name && source == other.source && target == other.target);
}

 // Operador de diferença
bool FlowIMP::operator!=(const FlowIMP& other) const{
    return (name != other.name || source != other.source || target != other.target);
}

