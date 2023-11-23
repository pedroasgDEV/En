/************************************************************
 * @file unit_Flow.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the model units tests
************************************************************/

#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../../src/FlowIMP.h"
#include "../../../src/SystemIMP.h"
#include "../../../src/ModelIMP.h"
#include "unit_Flow.h"

#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

/**
*@brief This function run the unit test of the model constructor
*/
void test_Model_constructor();
/**
*@brief This function run the unit test of the model destructor
*/
void test_Model_destructor();
/**
*@brief This function run the unit test of the model getName
*/
void test_Model_getName();
/**
*@brief This function run the unit test of the model getSystems and add System
*/
void test_Model_getSystems_and_add();
/**
*@brief This function run the unit test of the model getFlows and add Flow
*/
void test_Model_getFlows_and_add();
/**
*@brief This function run the unit test of the model getStartTime
*/
void test_Model_getStartTime();
/**
*@brief This function run the unit test of the model getEndTime
*/
void test_Model_getEndTime();
/**
*@brief This function run the unit test of the model setName
*/
void test_Model_setName();
/**
*@brief This function run the unit test of the model setSystems
*/
void test_Model_setSystems();
/**
*@brief This function run the unit test of the model setFlows
*/
void test_Model_setFlows();
/**
*@brief This function run the unit test of the model setStartTime
*/
void test_Model_setStartTime();
/**
*@brief This function run the unit test of the model setEndTime
*/
void test_Model_setEndTime();
/**
*@brief This function run the unit test of the model setTime
*/
void test_Model_setTime();
/**
*@brief This function run the unit test of the model rmv System
*/
void test_Model_rmv_Sytem();
/**
*@brief This function run the unit test of the model rmv Flow
*/
void test_Model_rmv_Flow();
/**
*@brief This function run the unit test of the model equal
*/
void test_Model_equal();
/**
*@brief This function run the unit test of the model run
*/
void test_Model_run();
/**
*@brief This function run the unit tests of the model
*/
void run_Model_unit_test();


#endif