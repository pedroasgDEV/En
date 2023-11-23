/*************************************************
 * @file Flow.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the flow Interface
*************************************************/

#ifndef FLOW_H
#define FLOW_H

#include "System.h"
#include <string>
#include <iostream>

/**************************************************************************************
 *@brief The Flow Interface is the Interface that defines the methods to be implemented
**************************************************************************************/

class Flow{
    public:
        //Destructor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~Flow() {};

        //Geters e seters
        //Name
        /**
         * @brief This method returns the name of a flow
         * @return a string containing the name is returned
        */
        virtual std::string getName() const = 0;
        /**
         * @brief This method assigns a string to the name of a flow obj
         * @param name string must be passed to the method
        */
        virtual void setName(const std::string& name) = 0;
        //Source
        /**
         * @brief This method returns the source system poiter
         * @return a system poiter containing the source memory address is returned
        */
        virtual System* getSource() const = 0;
        /**
         * @brief This method assigns a system poiter to the source of a flow obj
         * @param source system poiter must be passed to the method
        */
        virtual void setSource(System* source) = 0;
        //Target
        /**
         * @brief This method returns the target system poiter
         * @return a system poiter containing the target memory address is returned
        */
        virtual System* getTarget() const = 0;
        /**
         * @brief This method assigns a system poiter to the target of a flow obj
         * @param target system poiter must be passed to the method
        */
        virtual void setTarget(System* target) = 0;

        //Metodos
        /**
         * @brief Pure virtual method that will be inherited by subclasses created by the user, this one will contain an equation that will be executed in the flow by the model.
         * @return double 
        */
        virtual double execute() = 0;
};


#endif 