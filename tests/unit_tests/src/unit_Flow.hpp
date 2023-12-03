/************************************************************
 * @file unit_Flow.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the flow units tests
************************************************************/

#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

#include "../../../src/FlowIMP.hpp"
#include "../../../src/SystemIMP.hpp"

#include <assert.h>

/**************************************************************************************************************************
 * @brief This Flow class connects two systems and through the entered equation transfers values ​​from one system to another 
**************************************************************************************************************************/
class Flow_unit_test : public FlowIMP{
    private:
        /**
         * @brief Construct a new Exponencial by a obj
         * @param other Exponencial obj
        */
        Flow_unit_test(const Flow_unit_test& other);

    public:
        //Contructor
        /**
         * @brief Construct a new Flow_unit_test by name, source and target
         * @param name string with default value "NO_NAME"
         * @param source System pointer with default value NULL
         * @param target System pointer with default value NULL
        */
        Flow_unit_test(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL);
    
        //Destructor
        /**
         * @brief This destructor is a virtual destructor of the Class
        */
        virtual ~Flow_unit_test();

        //Metodos
        /**
         * @brief Pure virtual method that will contain an equation that will be executed in the flow by the model.
         * @return double 
        */
        virtual double execute() override;
};

/**
*@brief This function run the unit test of the flow constructor
*/
void test_Flow_constructor();
/**
*@brief This function run the unit test of the flow destructor
*/
void test_Flow_destructor();
/**
*@brief This function run the unit test of the flow getName
*/
void test_Flow_getName();
/**
*@brief This function run the unit test of the flow getSource
*/
void test_Flow_getSource();
/**
*@brief This function run the unit test of the flow getTarge
*/
void test_Flow_getTarget();
/**
*@brief This function run the unit test of the flow setName
*/
void test_Flow_setName();
/**
*@brief This function run the unit test of the flow setSource
*/
void test_Flow_setSource();
/**
*@brief This function run the unit test of the flow setTarge
*/
void test_Flow_setTarget();
/**
*@brief This function run the unit test of the flow execute
*/
void test_Flow_execute();
/**
*@brief This function run the unit test of the flow equal comparation
*/
void test_Flow_equal();
/**
*@brief This function run the unit tests of the flow
*/
void run_Flow_unit_test();

#endif