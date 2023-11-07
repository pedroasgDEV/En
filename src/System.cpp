#include "System.h"//Nome e valor

//Contructors
System::System(const std::string& name, const double& value) : name(name), value(value) {}
//Copia outro system
System::System(const System& other) : name(other.name), value(other.value) {}

//Destructors
System::~System(){};

//Geters e seters
//Noma
std::string System::getName() const { return name; }
void System::setName(const std::string& name) { this->name = name; }
//Value
double System::getValue() const { return value; }
void System::setValue(const double& value) { this->value = value; }

//Sobrecarga de operadores
// Operador de atribuição
System& System::operator=(const System& other) {
    if(other == *this) return *this;
    name = other.name;
    value = other.value;
    return *this;
}
// Operador de igualdade
bool System::operator==(const System& other) const{
    return (name == other.name && value == other.value);
    // Compare todos os membros para verificar igualdade
}
//Operador de saida
std::ostream& operator<<(std::ostream& out, const System& obj){
    out << "(System)(Name: " << obj.name << ", Value: " << obj.value << ")"; 
    return out;
}