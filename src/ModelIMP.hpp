/******************************************************
 * @file ModelIMP.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the model implementation
******************************************************/

#ifndef MODELIMP_HPP
#define MODELIMP_HPP

#include "Model.hpp"

/***********************************************************************************
 *@brief This class implementation defines the attributes and implements the methods
***********************************************************************************/
class ModelIMP : public Model{
    private:
        /**
         * @brief This method is overloading the '=' operator, "cloning" from one Model to another
         * @param other Model obj to be cloned must be passed 
         * @return A Model is returned that is a clone of what was passed to the method
        */
        ModelIMP& operator=(const ModelIMP& other); // Operador de atribuição
        /**
         * @brief Construct a new Model by a obj
         * @param other Model obj
        */
        ModelIMP(const ModelIMP& other); //Copia outro flow 

    protected:
        std::string name; /**< Name string attribute. */
        std::vector<System*> systems; /**< System pointers vector. */
        std::vector<Flow*> flows; /**< Flow pointers vector. */
        int startTime; /**< Start time simulation integer attribute. */
        int endTime; /**< End time simulation integer attribute. */

    public:
        //Contructors
        /**
         * @brief Construct a new Model by name and sart and end time
         * @param name string with default value "NO_NAME"
         * @param startTime int with default value 0
         * @param endTime int with default value 1
        */
        ModelIMP(const std::string& name = "NO_NAME", const int& startTime = 0, const int& endTime = 1);

        //Destrutor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~ModelIMP();

        //Geters e seters
        //Name
        /**
         * @brief This method returns the name of a Model
         * @return a string containing the name is returned
        */
        std::string getName() const;
        /**
         * @brief This method assigns a string to the name of a Model
         * @param name string must be passed to the method
        */
        void setName(const std::string& name);
        //Vector
        /**
         * @brief This method returns the vector of Systems
         * @return a vector containing Systems is returned
        */
        std::vector<System*> getSystems() const;
        /**
         * @brief This method returns the vector of flows
         * @return a vector containing Flows is returned
        */
        std::vector<Flow*> getFlows() const;
        /**
         * @brief This method assigns a vector to the systems of a Model
         * @param systems int must be passed to the method
        */
        void setSystems(const std::vector<System*> systems);
        /**
         * @brief This method assigns a vector to the flows of a Model
         * @param flows int must be passed to the method
        */
        void setFlows(const std::vector<Flow*> flows);
        //Time
        /**
         * @brief This method returns the startTime of a Model
         * @return a int containing the startTime is returned
        */
        int getStartTime() const;
        /**
         * @brief This method returns the end of a Model
         * @return a int containing the end is returned
        */
        int getEndTime() const;
        /**
         * @brief This method assigns a int to the startTime of a Model
         * @param startTime int must be passed to the method
        */
        void setStartTime(const int& startTime);
        /**
         * @brief This method assigns a int to the endTime of a Model
         * @param endTime int must be passed to the method
        */
        void setEndTime(const int& endTime);
        /**
         * @brief This method assigns a int to the startTime and endTime of a Model
         * @param startTime int must be passed to the method
         * @param endTime int must be passed to the method
        */
        void setTime(const int& startTime, const int& endTime);

        //Metodos
        //add
        /**
         * @brief This method add a System pointer to the vector of a Model
         * @param system System pointer must be passed to the method
        */
        void add(System* system);
        /**
         * @brief This method add a Flow pointer to the vector of a Model
         * @param flow Flow pointer must be passed to the method
        */
        void add(Flow* flow);
        //remove
        /**
         * @brief This method remove a System pointer of the vector of a Model
         * @param system System pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        bool rmv(const System* system);
        /**
         * @brief This method remove a Flow pointer of the vector of a Model
         * @param flow Flow pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        bool rmv(const Flow* flow);
        //Others
        /**
         * @brief This method run all model
         * @return a bool value, true if can run, false if not
        */
        bool run();

        //Sobrecarga de operadores
        /**
         * @brief This method is overloading the '==' operator, compare two models objs
         * @param other model obj to be compare must be passed 
         * @return A bool is returned, true if they are equal and false if not
        */
        bool operator==(const ModelIMP& other) const; // Operador de igualdade
        /**
         * @brief This method is overloading the '!=' operator, compare two models objs
         * @param other model obj to be compare must be passed 
         * @return A bool is returned, false if they are equal and true if not
        */
        bool operator!=(const ModelIMP& other) const; // Operador de igualdade
};

#endif