/****************************************************
 * @file Model.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the simulation model
****************************************************/

#ifndef MODEL_HPP
#define MODEL_HPP

#include "System.hpp"
#include "Flow.hpp"

/*****************************************************************************************************************
 *@brief This class represents the general simulation model, it contains figures for simulation and its execution.
*****************************************************************************************************************/

#include <string>
#include <iostream>
#include <vector>

class Model{
    public:
        //Iteradores
        /**
        * @brief typedef vetors iterators
        */
        typedef std::vector<System*>::iterator systemIterator;
        typedef std::vector<Flow*>::iterator flowIterator;

        //Destrutor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~Model() {};

        //Geters e seters
        //Name
        /**
         * @brief This method returns the name of a Model
         * @return a string containing the name is returned
        */
        virtual std::string getName() const = 0;
        /**
         * @brief This method assigns a string to the name of a Model
         * @param name string must be passed to the method
        */
        virtual void setName(const std::string& name) = 0;
        //Vector
        /**
         * @brief This method returns the vector of Systems
         * @return a vector containing Systems is returned
        */
        virtual std::vector<System*> getSystems() const = 0;
        /**
         * @brief This method returns the vector of flows
         * @return a vector containing Flows is returned
        */
        virtual std::vector<Flow*> getFlows() const = 0;
        /**
         * @brief This method assigns a vector to the systems of a Model
         * @param systems int must be passed to the method
        */
        virtual void setSystems(const std::vector<System*> systems) = 0;
        /**
         * @brief This method assigns a vector to the flows of a Model
         * @param flows int must be passed to the method
        */
        virtual void setFlows(const std::vector<Flow*> flows) = 0;
        //Time
        /**
         * @brief This method returns the startTime of a Model
         * @return a int containing the startTime is returned
        */
        virtual int getStartTime() const = 0;
        /**
         * @brief This method returns the end of a Model
         * @return a int containing the end is returned
        */
        virtual int getEndTime() const = 0;
        /**
         * @brief This method assigns a int to the startTime of a Model
         * @param startTime int must be passed to the method
        */
        virtual void setStartTime(const int& startTime) = 0;
        /**
         * @brief This method assigns a int to the endTime of a Model
         * @param endTime int must be passed to the method
        */
        virtual void setEndTime(const int& endTime) = 0;
        /**
         * @brief This method assigns a int to the startTime and endTime of a Model
         * @param startTime int must be passed to the method
         * @param endTime int must be passed to the method
        */
        virtual void setTime(const int& startTime, const int& endTime) = 0;

        //Metodos
        //add
        /**
         * @brief This method add a System pointer to the vector of a Model
         * @param system System pointer must be passed to the method
        */
        virtual void add(System* system) = 0;
        /**
         * @brief This method add a Flow pointer to the vector of a Model
         * @param flow Flow pointer must be passed to the method
        */
        virtual void add(Flow* flow) = 0;
        //remove
        /**
         * @brief This method remove a System pointer of the vector of a Model
         * @param system System pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        virtual bool rmv(const System* system) = 0;
        /**
         * @brief This method remove a Flow pointer of the vector of a Model
         * @param flow Flow pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        virtual bool rmv(const Flow* flow) = 0;
        //Others
        /**
         * @brief This method run all model
         * @return a bool value, true if can run, false if not
        */
        virtual bool run() = 0;

};

#endif