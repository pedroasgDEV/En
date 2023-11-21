/****************************************************
 * @file Model.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the simulation model
****************************************************/

#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"
#include <string>
#include <iostream>
#include <vector>

/*****************************************************************************************************************
 *@brief This class represents the general simulation model, it contains figures for simulation and its execution.
*****************************************************************************************************************/
class Model{
    private:
        /**
         * @brief This method is overloading the '=' operator, "cloning" from one Model to another
         * @param other Model obj to be cloned must be passed 
         * @return A Model is returned that is a clone of what was passed to the method
        */
        Model& operator=(const Model& other); // Operador de atribuição
        /**
         * @brief Construct a new Model by a obj
         * @param other Model obj
        */
        Model(const Model& other); //Copia outro flow 

    protected:
        std::string name; /**< Name string attribute. */
        std::vector<System*> systems; /**< System pointers vector. */
        std::vector<Flow*> flows; /**< Flow pointers vector. */
        int startTime; /**< Start time simulation integer attribute. */
        int endTime; /**< End time simulation integer attribute. */

    public:
        /**
        * @brief typedef vetors iterators
        */
        //Iteradores
        typedef std::vector<System*>::iterator systemIterator;
        typedef std::vector<Flow*>::iterator flowIterator;

        //Contructors
        /**
         * @brief Construct a new Model by name and sart and end time
         * @param name string with default value "NO_NAME"
         * @param startTime int with default value 0
         * @param endTime int with default value 1
        */
        Model(const std::string& name = "NO_NAME", const int& startTime = 0, const int& endTime = 1);

        //Destrutor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~Model();

        //Geters e seters
        //Name
        //Nome
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
        int getEndtTime() const;
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
        bool rmv(const systemIterator& system);
        /**
         * @brief This method remove a Flow pointer of the vector of a Model
         * @param flow Flow pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        bool rmv(const flowIterator& flow);
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
        bool operator==(const Model& other) const; // Operador de igualdade
        /**
         * @brief This method is overloading the '<<' operator, print the model obj info
         * @param out is a ostream obj
         * @param obj is a model obj
         * @return a ostream obj to print the obj info
        */
        friend std::ostream& operator<<(std::ostream& out, const Model& obj); //Operador de saida
};

#endif