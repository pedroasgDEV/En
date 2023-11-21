/************************************************************
 * @file Exponencial.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the logistical simulation flow
************************************************************/

#ifndef LOGISTICAL_DEF
#define LOGISTICAL_DEF

#include <string.h>
#include "../../../src/Flow.h"

class Logistical : public Flow{
    public:
        //Contructor
        /**
         * @brief Construct a new Logistical by name, source and target
         * @param name string with default value "NO_NAME"
         * @param source System pointer with default value NULL
         * @param target System pointer with default value NULL
        */
        Logistical(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL);
       /**
         * @brief Construct a new Logistical by a obj
         * @param other Logistical obj
        */
        Logistical(const Logistical& other);

        //Destructor
        /**
         * @brief This destructor is a virtual destructor of the Class
        */
        virtual ~Logistical();

        //Metodos
        /**
         * @brief Pure virtual method that will contain an equation that will be executed in the flow by the model.
         * @return double 
        */
        virtual double execute() override;
};

#endif
