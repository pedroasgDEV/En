/************************************************************
 * @file unit_Syste,.h
 * @author Pedro Augusto Sousa Gonçalves
 * @brief This file represents the system units tests
************************************************************/

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include "../../../src/SystemIMP.h"

#include <iostream>
#include <assert.h>
#include <string>

/**
*@brief This function run the unit test of the system constructor
*/
void test_System_constructor();
/**
*@brief This function run the unit test of the system destructor
*/
void test_System_destructor();
/**
*@brief This function run the unit test of the system getName
*/
void test_System_getName();
/**
*@brief This function run the unit test of the system getValue
*/
void test_System_getValue();
/**
*@brief This function run the unit test of the system setName
*/
void test_System_setName();
/**
*@brief This function run the unit test of the system setValeu
*/
void test_System_setValue();
/**
*@brief This function run the unit test of the system equal comparation
*/
void test_System_equal();
/**
*@brief This function run the unit tests of the system
*/
void run_System_unit_test();

#endif