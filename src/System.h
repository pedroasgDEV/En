/****************************************************
 * @file System.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the System interface
****************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

/****************************************************************************************
 *@brief The System Interface is the Interface that defines the methods to be implemented
****************************************************************************************/

class System{
    public:
        //Destructors
        /**
         * @brief This destructor is a virtual destructor of the Class
        */
        virtual ~System() {};
 
        //Geters e seters
        //Nome
        /**
         * @brief This method returns the name of a system
         * @return a string containing the name is returned
        */
        virtual std::string getName() const = 0;
        /**
         * @brief This method assigns a string to the name of a system
         * @param name string must be passed to the method
        */
        virtual void setName(const std::string& name) = 0;
        //Value
        /**
         * @brief This method returns the value of a system
         * @return a double containing the value is returned
        */
        virtual double getValue() const = 0;
        /**
         * @brief This method assigns a double to the value of a system
         * @param value double must be passed to the method
        */
        virtual void setValue(const double& value) = 0;
};

#endif