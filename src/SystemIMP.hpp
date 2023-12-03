/*******************************************************
 * @file SystemIMP.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the system implementation
*******************************************************/

#ifndef SYSTEMIMP_HPP
#define SYSTEMIMP_HPP

//Bibliotecas
#include "System.hpp"

/****************************************************************************************
 *@brief The System implementation defines the attributes and implements the methods
****************************************************************************************/

class SystemIMP : public System{
    private:
        /**
         * @brief Construct a new System by a obj
         * @param other System obj
        */
        SystemIMP(const SystemIMP& other); //Copia outro system
        /**
         * @brief This method is overloading the '=' operator, "cloning" from one system to another
         * @param other system obj to be cloned must be passed 
         * @return A system is returned that is a clone of what was passed to the method
        */
        SystemIMP& operator=(const SystemIMP& other);  // Operador de atribuição

    protected:
        std::string name; /**< Name string attribute. */
        double value; /**< Value double attribute. */

    public:
        //Contructors
        /**
         * @brief Construct a new System by name and value
         * @param name string with default value "NO_NAME"
         * @param value double with default value 0.0
        */
        SystemIMP(const std::string& name = "NO_NAME", const double& value = 0.0);

        /**
         * @brief This destructor is a virtual destructor of the Class
        */
        //Destructors
        virtual ~SystemIMP();
 
        //Geters e seters
        //Nome
        /**
         * @brief This method returns the name of a system
         * @return a string containing the name is returned
        */
        std::string getName() const;
        /**
         * @brief This method assigns a string to the name of a system
         * @param name string must be passed to the method
        */
        void setName(const std::string& name);
        //Value
        /**
         * @brief This method returns the value of a system
         * @return a double containing the value is returned
        */
        double getValue() const;
        /**
         * @brief This method assigns a double to the value of a system
         * @param value double must be passed to the method
        */
        void setValue(const double& value);

        //Sobrecarga de operadores
        /**
         * @brief This method is overloading the '==' operator, compare two systems objs
         * @param other system obj to be compare must be passed 
         * @return A bool is returned, true if they are equal and false if not
        */
        bool operator==(const SystemIMP& other) const;  // Operador de igualdade
        /**
         * @brief This method is overloading the '!=' operator, compare two systems objs
         * @param other system obj to be compare must be passed 
         * @return A bool is returned, false if they are equal and true if not
        */
        bool operator!=(const SystemIMP& other) const;  // Operador de diferença
};

#endif