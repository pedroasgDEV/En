#include "SystemIMP.h"//Nome e valor

//Contructors
SystemIMP::SystemIMP(const std::string& name, const double& value) : name(name), value(value) {}
//Copia outro system
SystemIMP::SystemIMP(const SystemIMP& other) : name(other.name), value(other.value) {}

//Destructors
SystemIMP::~SystemIMP(){};

//Geters e seters
//Noma
std::string SystemIMP::getName() const { return name; }
void SystemIMP::setName(const std::string& name) { this->name = name; }
//Value
double SystemIMP::getValue() const { return value; }
void SystemIMP::setValue(const double& value) { this->value = value; }

//Sobrecarga de operadores
// Operador de atribuição
SystemIMP& SystemIMP::operator=(const SystemIMP& other) {
    if(other == *this) return *this;
    name = other.name;
    value = other.value;
    return *this;
}
// Operador de igualdade
bool SystemIMP::operator==(const SystemIMP& other) const{
    return (name == other.name && value == other.value);
    // Compare todos os membros para verificar igualdade
}

// Operador de diferença
bool SystemIMP::operator!=(const SystemIMP& other) const{
    return (name != other.name || value != other.value);
    // Compare todos os membros para verificar igualdade
}