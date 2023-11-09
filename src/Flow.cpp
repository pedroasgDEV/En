#include "Flow.h"

//Geters e seters
//Name
std::string Flow::getName() const { return name; }
void Flow::setName(std::string& name) { this->name = name; }
//Source
System* Flow::getSource() const { return source; }
void Flow::setSource(System* source) { this->source = source; }
//Target
System* Flow::getTarget() const { return target; }
void Flow::setTarget(System* target) { this->target = target; }

//Sobrecarga de Operadores
// Operador de atribuição
Flow& Flow::operator=(const Flow& other) {
    if(other == *this) return *this;
    name = other.name;
    source = other.source;
    target = other.target;
    return *this;
}

// Operador de igualdade
bool Flow::operator==(const Flow& other) const {
    return (name == other.name && source == other.source && target == other.target);
}
//Operador de saida
std::ostream& operator<<(std::ostream& out, const Flow& obj){
    out << "(Flow) Name: " << obj.name << " - "
        << obj.source->getName() << " -----> " << obj.target->getName(); 
    return out;
}

