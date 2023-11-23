/*************************************************
 * @file FlowIMP.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the flow implementation
*************************************************/

#ifndef FLOWIMP_H
#define FLOWIMP_H

#include "Flow.h"
#include <string>
#include <iostream>

/*********************************************************************************
 *@brief The Flow implementation defines the attributes and implements the methods
*********************************************************************************/

class FlowIMP : public Flow{
    private:
        /**
         * @brief This method is overloading the '=' operator, "cloning" from one flow to another
         * @param other flow obj to be cloned must be passed 
         * @return A flow is returned that is a clone of what was passed to the method
        */
        FlowIMP& operator=(const FlowIMP& other); // Operador de atribuição

    protected:
        std::string name; /**< Name string attribute. */
        System* source; /**< Source system pointer attribute. */
        System* target; /**< Target system pointer attribute. */
        
    public:
        //Destructor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~FlowIMP();

        //Geters e seters
        //Name
        /**
         * @brief This method returns the name of a flow
         * @return a string containing the name is returned
        */
        std::string getName() const;
        /**
         * @brief This method assigns a string to the name of a flow obj
         * @param name string must be passed to the method
        */
        void setName(const std::string& name);
        //Source
        /**
         * @brief This method returns the source system poiter
         * @return a system poiter containing the source memory address is returned
        */
        System* getSource() const;
        /**
         * @brief This method assigns a system poiter to the source of a flow obj
         * @param source system poiter must be passed to the method
        */
        void setSource(System* source);
        //Target
        /**
         * @brief This method returns the target system poiter
         * @return a system poiter containing the target memory address is returned
        */
        System* getTarget() const;
        /**
         * @brief This method assigns a system poiter to the target of a flow obj
         * @param target system poiter must be passed to the method
        */
        void setTarget(System* target);

        //Metodos
        /**
         * @brief Pure virtual method that will be inherited by subclasses created by the user, this one will contain an equation that will be executed in the flow by the model.
         * @return double 
        */
        virtual double execute() = 0;
    
        //Sobrecarga de operadores
        /**
         * @brief This method is overloading the '==' operator, compare two flows objs
         * @param other flow obj to be compare must be passed 
         * @return A bool is returned, true if they are equal and false if not
        */
        virtual bool operator==(const FlowIMP& other) const; // Operador de igualdade
        /**
         * @brief This method is overloading the '!=' operator, compare two flows objs
         * @param other flow obj to be compare must be passed 
         * @return A bool is returned, false if they are equal and true if not
        */
        virtual bool operator!=(const FlowIMP& other) const; // Operador de diferença
};


#endif 