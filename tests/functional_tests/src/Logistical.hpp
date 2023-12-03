/************************************************************
 * @file Logistical.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the logistical simulation flow
************************************************************/

#ifndef LOGISTICAL_HPP
#define LOGISTICAL_HPP

#include <string.h>
#include "../../../src/FlowIMP.hpp"

/**************************************************************************************************************************
 * @brief This Flow class connects two systems and through the entered equation transfers values ​​from one system to another 
**************************************************************************************************************************/

class Logistical : public FlowIMP{
    private:
        /**
         * @brief Construct a new Logistical by a obj
         * @param other Logistical obj
        */
        Logistical(const Logistical& other);
      
    public:
        //Contructor
        /**
         * @brief Construct a new Logistical by name, source and target
         * @param name string with default value "NO_NAME"
         * @param source System pointer with default value NULL
         * @param target System pointer with default value NULL
        */
        Logistical(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL);

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
