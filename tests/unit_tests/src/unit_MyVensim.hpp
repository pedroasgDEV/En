/************************************************************
 * @file unit_MyVensim.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the MyVensim units tests
************************************************************/

#ifndef UNIT_MYVENSIM_HPP
#define UNIT_MYVENSIM_HPP

#include "../../../src/MyVensimIMP.hpp"
#include "unit_Flow.hpp"

#include <assert.h>

/**
*@brief This function run the unit test of the MyVensim constructor
*/
void test_MyVensim_constructor();
/**
*@brief This function run the unit test of the MyVensim destructor
*/
void test_MyVensim_destructor();
/**
*@brief This function run the unit test of the MyVensim getName
*/
void test_MyVensim_getName();
/**
*@brief This function run the unit test of the MyVensim getSystems and add System
*/
void test_MyVensim_getSystems_and_add();
/**
*@brief This function run the unit test of the MyVensim getFlows and add Flow
*/
void test_MyVensim_getFlows_and_add();
/**
*@brief This function run the unit test of the MyVensim getModels and add Model
*/
void test_MyVensim_getModels_and_add();
/**
*@brief This function run the unit test of the MyVensim setName
*/
void test_MyVensim_setName();
/**
*@brief This function run the unit test of the MyVensim setSystems
*/
void test_MyVensim_setSystems();
/**
*@brief This function run the unit test of the MyVensim setFlows
*/
void test_MyVensim_setFlows();
/**
*@brief This function run the unit test of the MyVensim setModels
*/
void test_MyVensim_setModels();
/**
*@brief This function run the unit test of the MyVensim rmv System
*/
void test_MyVensim_rmv_Sytem();
/**
*@brief This function run the unit test of the MyVensim rmv Flow
*/
void test_MyVensim_rmv_Flow();
/**
*@brief This function run the unit test of the MyVensim rmv Model
*/
void test_MyVensim_rmv_Model();
/**
*@brief This function run the unit test of the MyVensim equal
*/
void test_MyVensim_equal();
/**
*@brief This function run the unit test of the MyVensim run
*/
void test_MyVensim_run();
/**
*@brief This function run the unit tests of the MyVensim
*/
void run_MyVensim_unit_test();


#endif