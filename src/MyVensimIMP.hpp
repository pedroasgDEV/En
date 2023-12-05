/********************************************************
 * @file MyVensimIMP.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the factory implementation 
********************************************************/

#ifndef MYVENSIMIMP_HPP
#define MYVENSIMIMP_HPP

#include "MyVensim.hpp"

/**********************************************************************************
 *@brief The MyVensin implementation defines the attributes and implements the methods
**********************************************************************************/

class MyVensimIMP : public MyVensim{
    private:
        /**
         * @brief This method is overloading the '=' operator, "cloning" from one MyVensim to another
         * @param other MyVensim obj to be cloned must be passed 
         * @return A MyVensim is returned that is a clone of what was passed to the method
        */
        MyVensimIMP& operator=(const MyVensimIMP& other); // Operador de atribuição
        /**
         * @brief Construct a new MyVensim by a obj
         * @param other MyVensim obj
        */
        MyVensimIMP(const MyVensimIMP& other); //Copia outro MyVensim 

    protected:
        std::string name; /**< Name string attribute. */
        std::vector<Model*> models; /**< Model pointers vector. */
        std::vector<System*> systems; /**< System pointers vector. */
        std::vector<Flow*> flows; /**< Flow pointers vector. */

    public:

        //Constructor
        /**
         * @brief Construct a new Model by name and sart and end time
         * @param name string with default value "NO_NAME"
        */
        MyVensimIMP(const std::string& name = "NO_NAME");
        
        //Destructor
        /**
         * @brief This destructor is a virtual destructor of the class
        */
        virtual ~MyVensimIMP() override;

        /**
         * @brief Create a instance of System
         * @param name string with default value "NO_NAME"
         * @param value double with default value 0.0
         * @return A System pointer to the new instance of System
         */
        System* createSystem(const std::string& name = "NO_NAME", const double& value = 0.0) override;

        /**
         * @brief Create a instance of Model
         * @param name string with default value "NO_NAME"
         * @param startTime int with default value 0
         * @param endTime int with default value 1
         * @return A Model pointer to the new instance of Model
         */
        Model* createModel(const std::string& name = "NO_NAME", const int& startTime = 0, const int& endTime = 1) override;

         //add
        /**
         * @brief This method add a System pointer to the vector
         * @param system System pointer must be passed to the method
        */
        void add(System* system) override;
        /**
         * @brief This method add a Flow pointer to the vector
         * @param flow Flow pointer must be passed to the method
        */
        void add(Flow* flow) override;
        /**
         * @brief This method add a Model pointer to the vector
         * @param model Model pointer must be passed to the method
        */
        void add(Model* model) override;
        //remove
        /**
         * @brief This method remove a System pointer of the vector
         * @param system System pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        bool rmv(const System* system) override;
        /**
         * @brief This method remove a Flow pointer of the vector
         * @param flow Flow pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        bool rmv(const Flow* flow) override;
        /**
         * @brief This method remove a Model pointer of the vector
         * @param model Model pointer iterator must be passed to the method
         * @return a bool value, true if can remove, false if not
        */
        bool rmv(const Model* model) override;

        //Geters e seters
        //Name
        /**
         * @brief This method returns the name of a MyVensim
         * @return a string containing the name is returned
        */
        std::string getName() const;
        /**
         * @brief This method assigns a string to the name of a MyVensim
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
         * @brief This method returns the vector of Models
         * @return a vector containing Models is returned
        */
        std::vector<Model*> getModels() const;
        /**
         * @brief This method assigns a vector to the systems of a MyVensim
         * @param systems int must be passed to the method
        */
        void setSystems(const std::vector<System*> systems);
        /**
         * @brief This method assigns a vector to the flows of a MyVensim
         * @param flows int must be passed to the method
        */
        void setFlows(const std::vector<Flow*> flows);
        /**
         * @brief This method assigns a vector to the models of a MyVensim
         * @param models int must be passed to the method
        */
        void setModels(const std::vector<Model*> models);

        /**
         * @brief This method run all model
         * @return a bool value, true if can run, false if not
        */
        bool run() override;

        //Sobrecarga de operadores
        /**
         * @brief This method is overloading the '==' operator, compare two models objs
         * @param other model obj to be compare must be passed 
         * @return A bool is returned, true if they are equal and false if not
        */
        bool operator==(const MyVensimIMP& other) const; // Operador de igualdade
        /**
         * @brief This method is overloading the '!=' operator, compare two models objs
         * @param other model obj to be compare must be passed 
         * @return A bool is returned, false if they are equal and true if not
        */
        bool operator!=(const MyVensimIMP& other) const; // Operador de igualdade
};

#endif