#include "unit_System.hpp"
#include "unit_Flow.hpp"
#include "unit_Model.hpp"

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