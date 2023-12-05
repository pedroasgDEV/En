#include "MyVensimIMP.hpp"

MyVensimIMP::MyVensimIMP(const std::string& name) : name(name) {}

MyVensimIMP::MyVensimIMP(const MyVensimIMP& other){
    models.clear();
    flows.clear();
    systems.clear();
    for (auto i : other.models) models.push_back(i);
    for (auto i : other.flows) flows.push_back(i);
    for (auto i : other.systems) systems.push_back(i);
}

MyVensimIMP::~MyVensimIMP() {
    models.clear();
    flows.clear();
    systems.clear();
}

System* MyVensimIMP::createSystem(const std::string& name, const double& value){
    System* s = new SystemIMP(name, value);
    add(s);
    return s;
}

Model* MyVensimIMP::createModel(const std::string& name, const int& startTime, const int& endTime){
    Model* m = new ModelIMP(name, startTime, endTime);
    add(m);
    return m;
}

//Geters e seters
//Name
std::string MyVensimIMP::getName() const { return name; }
void MyVensimIMP::setName(const std::string& name) { this->name = name; }
//Vector
std::vector<System*> MyVensimIMP::getSystems() const { return systems; }
std::vector<Flow*> MyVensimIMP::getFlows() const { return flows; }
std::vector<Model*> MyVensimIMP::getModels() const { return models; }
void MyVensimIMP::setSystems(const std::vector<System*> systems) { this->systems.clear(); for(auto i : systems) this->systems.push_back(i); }
void MyVensimIMP::setFlows(const std::vector<Flow*> flows) { this->flows.clear(); for(auto i : flows) this->flows.push_back(i); }
void MyVensimIMP::setModels(const std::vector<Model*> models) { { this->models.clear(); for(auto i : models) this->models.push_back(i); } }

//add
void MyVensimIMP::add(System* system){ systems.push_back(system); }
void MyVensimIMP::add(Flow* flow){ flows.push_back(flow); }
void MyVensimIMP::add(Model* model){ models.push_back(model); };

//remove
bool MyVensimIMP::rmv(const System* system){
    for(systemIterator i = systems.begin(); i < systems.end(); i++)
        if(*i == system){
            systems.erase(i);
            return true;
        }
    return false; 
}
bool MyVensimIMP::rmv(const Flow* flow){
    for(flowIterator i = flows.begin(); i < flows.end(); i++)
        if(*i == flow){
            flows.erase(i);
            return true;
        }
    return false; 
}
bool MyVensimIMP::rmv(const Model* model){
    for(modelIterator i = models.begin(); i < models.end(); i++)
        if(*i == model){
            models.erase(i);
            return true;
        }
    return false; 
}

bool MyVensimIMP::run(){
    if(models.empty()) return false;
    for(auto i : models) if(!(i->run())) return false;
    return true;
}

//Sobrecarga de operadores
// Operador de atribuição
MyVensimIMP& MyVensimIMP::operator=(const MyVensimIMP& other){
    if(other == *this) return *this;
    name = other.name;
    flows.clear();
    systems.clear();
    models.clear();
    for (auto i : other.flows) flows.push_back(i);
    for (auto i : other.systems) systems.push_back(i);
    for (auto i : other.models) models.push_back(i);
    return *this;
}
// Operador de igualdade
bool MyVensimIMP::operator==(const MyVensimIMP& other) const{
    return (name == other.name && systems == other.systems && flows == other.flows && models == other.models );
}
// Operador de diferença
bool MyVensimIMP::operator!=(const MyVensimIMP& other) const{
    return (name != other.name || systems != other.systems || flows != other.flows || models != other.models );
}

