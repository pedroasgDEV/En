#include "Functional_tests.hpp"

int main(){
    std::cout << "\nStart functional tests\n"
              << "*******************************************************\n";
    exponencial_test_run();
    logistical_test_run();
    Complex_test_run();
    std::cout << "*******************************************************\n"
              << "End functional tests\n\n";
    return 0;
}