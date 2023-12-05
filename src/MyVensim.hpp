/******************************************************
 * @file MyVensim.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the factory interface
******************************************************/

#ifndef MYVENSIM_HPP
#define MYVENSIM_HPP

#include "ModelIMP.hpp"
#include "FlowIMP.hpp"
#include "SystemIMP.hpp"

#include <vector>
#include <iostream>
#include <string>

/******************************************************************************************
 *@brief  he MyVensim Interface is the Interface that defines the methods to be implemented
******************************************************************************************/

class MyVensim{
    public:
        //Iteradores
        /**
         *@brief typedef System vetor iterator
        */
        typedef std::vector<System*>::iterator systemIterator;
        /**
         *@brief typedef Flow vetor iterator
        */
        typedef std::vector<Flow*>::iterator flowIterator;
        /**
         *@brief typedef Model vetor iterator
        */
        typedef std::vector<Model*>::iterator modelIterator;
        
        //Destrutor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~MyVensim() {}

        /**
         * @brief Create a instance of System
         * @param name string with default value "NO_NAME"
         * @param value double with default value 0.0
         * @return A System pointer to the new instance of System
         */
        virtual System* createSystem(const std::string& name = "NO_NAME", const double& value = 0.0) = 0;
        
        /**
         * @brief Create a instance of Flow
         * @param name string with default value "NO_NAME"
         * @param source System pointer with default value NULL
         * @param target System pointer with default value NULL
         * @return A Flow pointer to the new instance of Flow
         */
        template <typename FlowType>
        Flow* createFlow(const std::string name = "NONAME", System* source = nullptr, System* destiny = nullptr){
            Flow* f = new FlowType(name, source, destiny);
            add(f);
            return f;
        }

        /**
         * @brief Create a instance of Model
         * @param name string with default value "NO_NAME"
         * @param startTime int with default value 0
         * @param endTime int with default value 1
         * @return A Model pointer to the new instance of Model
         */
        virtual Model* createModel(const std::string& name = "NO_NAME", const int& startTime = 0, const int& endTime = 1) = 0;

         //add
        /**
         * @brief This method add a System pointer to the vector
         * @param system System pointer must be passed to the method
        */
        virtual void add(System* system) = 0;
        /**
         * @brief This method add a Flow pointer to the vector
         * @param flow Flow pointer must be passed to the method
        */
        virtual void add(Flow* flow) = 0;
        /**
         * @brief This method add a Model pointer to the vector
         * @param model Model pointer must be passed to the method
        */
        virtual void add(Model* model) = 0;
        //remove
        /**
         * @brief This method remove a System pointer of the vector
         * @param system System pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        virtual bool rmv(const System* system) = 0;
        /**
         * @brief This method remove a Flow pointer of the vector
         * @param flow Flow pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        virtual bool rmv(const Flow* flow) = 0;
        /**
         * @brief This method remove a Model pointer of the vector
         * @param model Model pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        virtual bool rmv(const Model* model) = 0;

        //Geters e seters
        //Name
        /**
         * @brief This method returns the name of a MyVensim
         * @return a string containing the name is returned
        */
        virtual std::string getName() const = 0;
        /**
         * @brief This method assigns a string to the name of a MyVensim
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
         * @brief This method returns the vector of Models
         * @return a vector containing Models is returned
        */
        virtual std::vector<Model*> getModels() const = 0;
        /**
         * @brief This method assigns a vector to the systems of a MyVensim
         * @param systems int must be passed to the method
        */
        virtual void setSystems(const std::vector<System*> systems) = 0;
        /**
         * @brief This method assigns a vector to the flows of a MyVensim
         * @param flows int must be passed to the method
        */
        virtual void setFlows(const std::vector<Flow*> flows) = 0;
        /**
         * @brief This method assigns a vector to the models of a MyVensim
         * @param models int must be passed to the method
        */
        virtual void setModels(const std::vector<Model*> models) = 0;

        /**
         * @brief This method run all model
         * @return a bool value, true if can run, false if not
        */
        virtual bool run() = 0;

};

#endif