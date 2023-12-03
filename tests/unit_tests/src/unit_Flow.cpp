#include "unit_Flow.hpp"
//Constructors
Flow_unit_test::Flow_unit_test(const std::string& name, System* source, System* target){
    this->name = name;
    this->source = source;
    this->target = target;
}

//Copia de other
Flow_unit_test::Flow_unit_test(const Flow_unit_test& other){
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

//Destructors
Flow_unit_test::~Flow_unit_test(){}

double Flow_unit_test::execute(){
    return getSource()->getValue();
}

void test_Flow_constructor(){
    std::cout << "        * Constructor tests\n";
    Flow* f1 = new Flow_unit_test();
    assert(f1->getName() == "NO_NAME");
    assert(f1->getSource() == NULL);
    assert(f1->getTarget() == NULL);

    Flow* f2 = new Flow_unit_test("f2");
    assert(f2->getName() == "f2");
    assert(f2->getSource() == NULL);
    assert(f2->getTarget() == NULL);

    System* s1 = new SystemIMP();
    Flow* f3 = new Flow_unit_test("f3", s1);
    assert(f3->getName() == "f3");
    assert(f3->getSource() == s1);
    assert(f3->getTarget() == NULL);

    System* s2 = new SystemIMP();
    System* s3 = new SystemIMP();
    Flow* f4 = new Flow_unit_test("f4", s2, s3);
    assert(f4->getName() == "f4");
    assert(f4->getSource() == s2);
    assert(f4->getTarget() == s3);

    delete f1;
    delete f2;    
    delete s1;    
    delete f3;
    delete s2;    
    delete s3;    
    delete f4;
}

void test_Flow_destructor(){
    std::cout << "        * Destructor tests\n";
    Flow* f1 = new Flow_unit_test();
    f1->~Flow();
}

void test_Flow_getName(){
    std::cout << "        * getName tests\n";
    Flow* f1 = new Flow_unit_test();
    assert(f1->getName() == "NO_NAME");

    Flow* f2 = new Flow_unit_test("f2");
    assert(f2->getName() == "f2");

    delete f1;
    delete f2;
}

void test_Flow_getSource(){
    std::cout << "        * getSource tests\n";
    Flow* f1 = new Flow_unit_test();
    assert(f1->getSource() == NULL);

    System* s1 = new SystemIMP();
    Flow* f2 = new Flow_unit_test("f2", s1);
    assert(f2->getSource() == s1);

    delete f1;
    delete s1;
    delete f2;
}

void test_Flow_getTarget(){
    std::cout << "        * getTarget tests\n";
    Flow* f1 = new Flow_unit_test();
    assert(f1->getTarget() == NULL);

    System* s1 = new SystemIMP();
    System* s2 = new SystemIMP();
    Flow* f2 = new Flow_unit_test("f2", s1, s2);
    assert(f2->getTarget() == s2);

    delete f1;
    delete s1;
    delete s2;
    delete f2;
}

void test_Flow_setName(){
    std::cout << "        * setName tests\n";
    Flow* f1 = new Flow_unit_test();
    f1->setName("f1");
    assert(f1->getName() != "NO_NAME");

    Flow* f2 = new Flow_unit_test("f");
    f2->setName("f2");
    assert(f2->getName() == "f2");

    delete f1;
    delete f2;
}

void test_Flow_setSource(){
    std::cout << "        * setSource tests\n";
    System* s1 = new SystemIMP();
    Flow* f1 = new Flow_unit_test();
    f1->setSource(s1);
    assert(f1->getSource() != NULL);

    System* s2 = new SystemIMP();
    Flow* f2 = new Flow_unit_test("f2", s1);
    f2->setSource(s2);
    assert(f2->getSource() == s2);
    
    delete s1;
    delete s2;
    delete f1;
    delete f2;
}

void test_Flow_setTarget(){
    std::cout << "        * setTarget tests\n";
    System* s1 = new SystemIMP();
    Flow* f1 = new Flow_unit_test();
    f1->setTarget(s1);
    assert(f1->getTarget() != NULL);

    System* s2 = new SystemIMP();
    System* s3 = new SystemIMP();
    Flow* f2 = new Flow_unit_test("f2", s1, s2);
    f2->setTarget(s3);
    assert(f2->getTarget() == s3);
    
    delete s1;
    delete s2;
    delete s3;
    delete f1;
    delete f2;
}

void test_Flow_execute(){
    std::cout << "        * Execute tests\n";

    System* s1 = new SystemIMP("s1", 100);
    System* s2 = new SystemIMP("s2", 0.0);
    Flow* f1 = new Flow_unit_test("f1", s1, s2);
    double result = f1->execute();
    f1->getTarget()->setValue(f1->getTarget()->getValue() + result);
    f1->getSource()->setValue(f1->getSource()->getValue() - result);

    assert(s1->getValue() == 0);
    assert(s2->getValue() == 100);
    
    delete s1;
    delete s2;
    delete f1;
}

void test_Flow_equal(){
    std::cout << "        * Equal tests\n";

    FlowIMP* f1 = new Flow_unit_test();
    FlowIMP* f2 = new Flow_unit_test();
    assert(*f1 == *f2);

    f1->setName("f1");
    assert(*f1 != *f2);

    delete f1;
    delete f2;
}

void run_Flow_unit_test(){
    std::cout << "    Start Flow unit tests\n";
    test_Flow_constructor();
    test_Flow_destructor();
    test_Flow_getName();
    test_Flow_getSource();
    test_Flow_getTarget();
    test_Flow_setName();
    test_Flow_setSource();
    test_Flow_setTarget();
    test_Flow_execute();
    test_Flow_equal();
    std::cout << "    End Flow unit tests\n\n";
}