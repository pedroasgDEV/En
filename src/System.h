#ifndef SYSTEM_H
#define SYSTEM_H

//Bibliotecas
#include <string>
#include <iostream>

class System{
    protected:
        std::string name;
        double value;

    public:
        //Contructors
        System(const std::string& name = "NO_NAME", const double& value = 0.0);
        System(const System& other); //Copia outro system

        //Destructors
        virtual ~System();
 
        //Geters e seters
        //Nome
        std::string getName() const;
        void setName(const std::string& name);
        //Value
        double getValue() const;
        void setValue(const double& value);

        //Sobrecarga de operadores
        System& operator=(const System& other);  // Operador de atribuição
        bool operator==(const System& other) const;  // Operador de igualdade
        friend std::ostream& operator<<(std::ostream& out, const System& obj); //Operador de saida
};

#endif