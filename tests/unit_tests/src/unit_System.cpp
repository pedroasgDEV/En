#include "unit_System.h"

void test_System_constructor(){
    std::cout << "        * Constructor tests\n";
    System* s1 = new SystemIMP();
    assert(s1->getName() == "NO_NAME");
    assert(s1->getValue() == 0.0);

    System* s2 = new SystemIMP("s2");
    assert(s2->getName() == "s2");
    assert(s2->getValue() == 0.0);

    System* s3 = new SystemIMP("s3", 2.0);
    assert(s3->getName() == "s3");
    assert(s3->getValue() == 2.0);

    delete s1;
    delete s2;
    delete s3;
}

void test_System_destructor(){
    std::cout << "        * Destructor tests\n";
    System* s1 = new SystemIMP();
    s1->~System();
}

void test_System_getName(){
    std::cout << "        * getName tests\n";
    System* s1 = new SystemIMP();
    assert(s1->getName() == "NO_NAME");

    System* s2 = new SystemIMP("s2");
    assert(s2->getName() == "s2");

    delete s1;
    delete s2;
}

void test_System_getValue(){
    std::cout << "        * getValue tests\n";
    System* s1 = new SystemIMP();
    assert(s1->getValue() == 0);

    System* s2 = new SystemIMP("s2", 22);
    assert(s2->getValue() == 22);

    delete s1;
    delete s2;
}

void test_System_setName(){
    std::cout << "        * setName tests\n";
    System* s1 = new SystemIMP();
    s1->setName("s1");
    assert(s1->getName() != "NO_NAME");

    System* s2 = new SystemIMP();
    s2->setName("s2");
    assert(s2->getName() == "s2");
    delete s1;
    delete s2;
}

void test_System_setValue(){
    std::cout << "        * setValue tests\n";
    System* s1 = new SystemIMP();
    s1->setValue(21);
    assert(s1->getValue() != 0);

    System* s2 = new SystemIMP("s2", 22);
    s2->setValue(45);
    assert(s2->getValue() == 45);

    delete s1;
    delete s2;
}

void test_System_equal(){
    std::cout << "        * Equal tests\n";
    SystemIMP* s1 = new SystemIMP("s1");
    SystemIMP* s2 = new SystemIMP("s2");
    assert(*s1 != *s2);

    SystemIMP* s3 = new SystemIMP();
    SystemIMP* s4 = new SystemIMP();
    assert(*s3 == *s4);

    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void run_System_unit_test(){
    std::cout << "    Start System unit tests\n";
    test_System_constructor();
    test_System_destructor();
    test_System_getName();
    test_System_getValue();
    test_System_setName();
    test_System_setValue();
    test_System_equal();
    std::cout << "    End System unit tests\n\n";
}