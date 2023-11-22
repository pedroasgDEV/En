/************************************************************
 * @file Exponencial.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the logistical simulation flow
************************************************************/

#ifndef FUNCTIONAL_TESTS_H  
#define FUNCTIONAL_TESTS_H  

#include "../../../src/ModelIMP.h"
#include "../../../src/SystemIMP.h"
#include "../../../src/FlowIMP.h"
#include "Exponencial.h"
#include "Logistical.h"
#include <assert.h>
#include <cmath>
#include <iostream>
#include <cstdlib>

/**************************************
 * @brief execution of functional tests
**************************************/

/**
 * @brief This function performs the exponential functional test
*/
void exponencial_test_run();

/**
 * @brief This function performs the logistic test
*/
void logistical_test_run();

/**
 * @brief  This function runs the "complex" test, which has multiple systems and flows
*/
void Complex_test_run();

#endif