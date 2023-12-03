/************************************************************
 * @file Exponencial.hpp
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the logistical simulation flow
************************************************************/

#ifndef FUNCTIONAL_TESTS_HPP
#define FUNCTIONAL_TESTS_HPP

#include "../../../src/ModelIMP.hpp"
#include "../../../src/SystemIMP.hpp"
#include "../../../src/FlowIMP.hpp"
#include "Exponencial.hpp"
#include "Logistical.hpp"
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