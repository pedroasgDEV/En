#include "ModelIMP.h"

//Constructors
ModelIMP::ModelIMP (const std::string& name, const int& startTime, const int& endTime) : name(name), startTime(startTime), endTime(endTime) {}
//Copia outro model
ModelIMP::ModelIMP (const ModelIMP& other) : name(other.name), startTime(other.startTime), endTime(other.endTime) {
    flows.clear();
    systems.clear();
    for (auto i : other.flows) flows.push_back(i);
    for (auto i : other.systems) systems.push_back(i);
}

//Destructor
ModelIMP::~ModelIMP(){systems.clear(); flows.clear();}

//Geters e seters
//Name
std::string ModelIMP::getName() const { return name; }
void ModelIMP::setName(const std::string& name) { this->name = name; }
//Timer
int ModelIMP::getStartTime() const { return startTime; }
int ModelIMP::getEndtTime() const { return endTime; }
void ModelIMP::setStartTime(const int& startTime) { this->startTime = startTime; }
void ModelIMP::setEndTime(const int& endTime) { this->endTime = endTime; }
void ModelIMP::setTime(const int& startTime, const int& endTime) { this->startTime = startTime; this->endTime = endTime; }

//Metodos
//add
void ModelIMP::add(System* system) { systems.push_back(system); } 
void ModelIMP::add(Flow* flow) { flows.push_back(flow); } 
//remove
bool ModelIMP::rmv(const systemIterator& system) { return (systems.erase(system) != systems.end()); }
bool ModelIMP::rmv(const flowIterator& flow) { return (flows.erase(flow) != flows.end()); }

//Others
bool ModelIMP::run(){
    std::vector<double> flowValue;
    flowIterator f;
    std::vector<double>::iterator d;
    double calcValue;

    for(int i = startTime; i < endTime; i++){

        f = flows.begin();

        while (f != flows.end()) {
            flowValue.push_back((*f)->execute());
            f++;
        }
        
        f = flows.begin();
        d = flowValue.begin();
        
        while(f != flows.end()){
            calcValue = (*f)->getSource()->getValue() - (*d);
            (*f)->getSource()->setValue(calcValue);
            calcValue = (*f)->getTarget()->getValue() + (*d);
            (*f)->getTarget()->setValue(calcValue);
            f++;
            d++;
        }

        flowValue.clear();

    }

    return true;
} 

//* Proibir a copia para resolver os problemas a dos vetores

//Sobrecarga de operadores
// Operador de atribuição
ModelIMP& ModelIMP::operator=(const ModelIMP& other){
    if(other == *this) return *this;
    name = other.name;
    systems = other.systems;
    flows.clear();
    systems.clear();
    for (auto i : other.flows) flows.push_back(i);
    for (auto i : other.systems) systems.push_back(i);
    startTime = other.startTime;
    endTime = other.endTime;
    return *this;
}
// Operador de igualdade
bool ModelIMP::operator==(const ModelIMP& other) const{
    return (name == other.name && systems == other.systems && flows == other.flows && startTime == other.startTime && endTime == other.endTime);
}
//Operador de saida
std::ostream& operator<<(std::ostream& out, const ModelIMP& obj){
    out << "Name: " << obj.name << ";\n"
        << "Systems:\n";
    for (auto item : obj.systems) out << item << "\n";
    out << "Flows:\n";
    for (auto item : obj.flows) out << item << "\n";
    return out;
}

