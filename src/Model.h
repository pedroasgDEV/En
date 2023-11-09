#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"
#include <string>
#include <iostream>
#include <vector>

typedef std::vector<System*>::iterator systemIterator;
typedef std::vector<Flow*>::iterator flowIterator;

class Model{
    protected:
        std::string name;
        std::vector<System*> systems;
        std::vector<Flow*> flows; 
        int startTime;
        int endTime;


        Model& operator=(const Model& other); // Operador de atribuição

    public:
        //Contructors
        Model(const std::string& name, const int& startTime, const int& endTime);
        Model(const Model& other); //Copia outro flow 
        //Destrutor
        virtual ~Model();

        //Geters e seters
        //Name
        std::string getName() const;
        void setName(const std::string& name);
        //Time
        int getStartTime() const;
        int getEndtTime() const;
        void setStartTime(const int& startTime);
        void setEndTime(const int& endTime);
        void setTime(const int& startTime, const int& endTime);

        //Metodos
        //add
        void add(System* system);
        void add(Flow* flow);
        //remove
        bool rmv(const systemIterator& system);
        bool rmv(const flowIterator& flow);
        //Others
        bool run();

        bool operator==(const Model& other) const; // Operador de igualdade
        friend std::ostream& operator<<(std::ostream& out, const Model& obj); //Operador de saida
};

#endif