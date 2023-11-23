#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

int main(){
    std::cout << "\nStart unit tests\n"
              << "*******************************************************\n";
    run_System_unit_test();
    run_Flow_unit_test();
    run_Model_unit_test(); 
    std::cout << "*******************************************************\n"
              << "End unit tests\n\n";
    return 0;
}