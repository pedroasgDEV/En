#ifndef FLOW_H
#define FLOW_H

#include "System.h"
#include <string>
#include <iostream>


class Flow{
    protected:
        std::string name;
        System* source;
        System* target;
        
    public:
        //Contructors
        Flow(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL);
        Flow(const Flow& other); //Copia outro flow
        
        //Destrutor
        virtual ~Flow();

        //Geters e seters
        //Name
        std::string getName() const;
        void setName(std::string& name);
        //Source
        System* getSource() const;
        void setSource(System* source);
        //Target
        System* getTarget() const;
        void setTarget(System* target);

        //Metodos
        virtual bool execute() = 0;
    
        //Sobrecarga de operadores
        Flow& operator=(const Flow& other); // Operador de atribuição
        bool operator==(const Flow& other) const; // Operador de igualdade
        friend std::ostream& operator<<(std::ostream& out, const Flow& obj); //Operador de saida
};


#endif 