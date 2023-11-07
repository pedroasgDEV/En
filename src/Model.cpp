#include "Model.h"

//Constructors
Model::Model (const std::string& name, const int& startTime, const int& endTime) : name(name), startTime(startTime), endTime(endTime) {}
//Copia outro system
Model::Model (const Model& other) : name(other.name), systems(other.systems), flows(other.flows), startTime(other.startTime), endTime(other.endTime) {}

//Destructor
Model::~Model(){systems.clear(); flows.clear();}

//Geters e seters
//Name
std::string Model::getName() const { return name; }
void Model::setName(const std::string& name) { this->name = name; }
//Timer
int Model::getStartTime() const { return startTime; }
int Model::getEndtTime() const { return endTime; }
void Model::setStartTime(const int& startTime) { this->startTime = startTime; }
void Model::setEndTime(const int& endTime) { this->endTime = endTime; }
void Model::setTime(const int& startTime, const int& endTime) { this->startTime = startTime; this->endTime = endTime; }

//Metodos
//add
void Model::add(System* system) { this->systems.push_back(system); } 
void Model::add(Flow* flow) { this->flows.push_back(flow); } 
//remove
bool Model::rmv(const systemIterator& system) { return (this->systems.erase(system) != systems.end()); }
bool Model::rmv(const flowIterator& flow) { return (this->flows.erase(flow) != flows.end()); }
//Others
bool Model::run(){
    for(int i = startTime; i < endTime; i++)
        for(auto item : flows) if(!item->execute()) return false;
    return true;
}

//* Proibir a copia para resolver os problemas a dos vetores

//Sobrecarga de operadores
// Operador de atribuição
Model& Model::operator=(const Model& other){
    if(other == *this) return *this;
    name = other.name;
    systems = other.systems;
    flows = other.flows; //! Erro de sematica, pois o vetor do this e do other apontam para os msm objetos e se a this.run() a other tbm muda
    startTime = other.startTime; //! Erro de sematica, pois o vetor do this e do other apontam para os msm objetos e se a this.run() a other tbm muda
    endTime = other.endTime;
    return *this;
}
// Operador de igualdade
bool Model::operator==(const Model& other) const{
    return (name == other.name && systems == other.systems && flows == other.flows && startTime == other.startTime && endTime == other.endTime);
}
//Operador de saida
std::ostream& operator<<(std::ostream& out, const Model& obj){
    out << "Name: " << obj.name << ";\n"
        << "Systems:\n";
    for (auto item : obj.systems) out << item << "\n";
    out << "Flows:\n";
    for (auto item : obj.flows) out << item << "\n";
    return out;
}

