#include "unit_Model.hpp"

void test_Model_constructor(){
    std::cout << "        * Constructor tests\n";
    Model* m1 = new ModelIMP();
    assert(m1->getName() == "NO_NAME");
    assert(m1->getStartTime() == 0);
    assert(m1->getEndTime() == 1);

    Model* m2 = new ModelIMP("m2");
    assert(m2->getName() == "m2");
    assert(m2->getStartTime() == 0);
    assert(m2->getEndTime() == 1);

    Model* m3 = new ModelIMP("m3", 2);
    assert(m3->getName() == "m3");
    assert(m3->getStartTime() == 2);
    assert(m3->getEndTime() == 1);

    Model* m4 = new ModelIMP("m4", 2, 5);
    assert(m4->getName() == "m4");
    assert(m4->getStartTime() == 2);
    assert(m4->getEndTime() == 5);

    delete m1;
    delete m2;
    delete m3;
    delete m4;
}
 
void test_Model_destructor(){
    std::cout << "        * Destructor tests\n";
    Model* m1 = new ModelIMP();
    m1->~Model();
}

void test_Model_getName(){
    std::cout << "        * getName tests\n";
    Model* m1 = new ModelIMP();
    assert(m1->getName() == "NO_NAME");

    Model* m2 = new ModelIMP("m2");
    assert(m2->getName() == "m2");

    delete m1;
    delete m2;
}

void test_Model_getSystems_and_add(){
    std::cout << "        * getSystems and add Systems tests\n";
    System* s1 = new SystemIMP("s1");
    Model* m1 = new ModelIMP("m1");
    std::vector<System*> systems;
    systems.push_back(s1);
    m1->add(s1);
    assert(m1->getSystems() == systems);

    delete s1;
    delete m1;
}

void test_Model_getFlows_and_add(){
    std::cout << "        * getFlows and add Flows tests\n";
    Flow* f1 = new Flow_unit_test("f1");
    Model* m1 = new ModelIMP("m1");
    std::vector<Flow*> flows;
    flows.push_back(f1);
    m1->add(f1);
    assert(m1->getFlows() == flows);

    delete f1;
    delete m1;
}

void test_Model_getStartTime(){
    std::cout << "        * getStartTime tests\n";
    Model* m1 = new ModelIMP();
    assert(m1->getStartTime() == 0);

    Model* m2 = new ModelIMP("m2", 1);
    assert(m2->getStartTime() == 1);

    delete m1;
    delete m2;
}

void test_Model_getEndTime(){
    std::cout << "        * getEndTime tests\n";
    Model* m1 = new ModelIMP();
    assert(m1->getEndTime() == 1);

    Model* m2 = new ModelIMP("m2", 0, 2);
    assert(m2->getEndTime() == 2);

    delete m1;
    delete m2;
}

void test_Model_setName(){
    std::cout << "        * setName tests\n";
    Model* m1 = new ModelIMP();
    m1->setName("m1");
    assert(m1->getName() != "NO_NAME");

    Model* m2 = new ModelIMP("m");
    m2->setName("m2");
    assert(m2->getName() == "m2");

    delete m1;
    delete m2;  
}

void test_Model_setSystems(){
    std::cout << "        * setSystems tests\n";
    System* s1 = new SystemIMP("s1");
    Model* m1 = new ModelIMP("m1");
    std::vector<System*> systems;
    systems.push_back(s1);
    m1->setSystems(systems);
    assert(m1->getSystems() == systems);

    delete s1;
    delete m1;
}

void test_Model_setFlows(){
    std::cout << "        * setFlows tests\n";
    Flow* f1 = new Flow_unit_test("f1");
    Model* m1 = new ModelIMP("m1");
    std::vector<Flow*> flows;
    flows.push_back(f1);
    m1->setFlows(flows);
    assert(m1->getFlows() == flows);

    delete f1;
    delete m1;
}

void test_Model_setStartTime(){
    std::cout << "        * setStartTime tests\n";
    Model* m1 = new ModelIMP();
    m1->setStartTime(3);
    assert(m1->getStartTime() != 0);

    Model* m2 = new ModelIMP("m2", 3);
    m2->setStartTime(1);
    assert(m2->getStartTime() == 1);

    delete m1;
    delete m2;
}

void test_Model_setEndTime(){
    std::cout << "        * setEndTime tests\n";
    Model* m1 = new ModelIMP();
    m1->setEndTime(3);
    assert(m1->getEndTime() != 1);

    Model* m2 = new ModelIMP("m2", 0, 1);
    m2->setEndTime(2);
    assert(m2->getEndTime() == 2);

    delete m1;
    delete m2;   
}

void test_Model_setTime(){
    std::cout << "        * setTime tests\n";
    Model* m1 = new ModelIMP();
    m1->setTime(1, 3);
    assert(m1->getStartTime() != 0);
    assert(m1->getEndTime() != 1);

    Model* m2 = new ModelIMP("m2", 0, 1);
    m2->setTime(3, 4);
    assert(m2->getStartTime() == 3);
    assert(m2->getEndTime() == 4);

    delete m1;
    delete m2;   
}

void test_Model_equal(){
    std::cout << "        * Equal tests\n";

    ModelIMP* m1 = new ModelIMP();
    ModelIMP* m2 = new ModelIMP();
    assert(*m1 == *m2);

    m1->setName("m1");
    assert(m1 != m2);

    delete m1;
    delete m2;
}

void test_Model_rmv_Sytem(){
    std::cout << "        * Remove System tests\n";

    Model* model1 = new ModelIMP();
    System* system1 = new SystemIMP("system1");

    model1->add(system1);
    assert(model1->rmv(system1));

    delete model1;
    delete system1;
}

void test_Model_rmv_Flow(){
    std::cout << "        * Remove Flow tests\n";

    Model* model1 = new ModelIMP();
    FlowIMP* flow1 = new Flow_unit_test("flow1");

    model1->add(flow1);
    assert(model1->rmv(flow1));

    delete model1;
    delete flow1;
}

void test_Model_run(){
    std::cout << "        * Run tests\n";

    System* s1 = new SystemIMP("s1", 100);
    System* s2 = new SystemIMP("s2", 0.0);
    Flow* f1 = new Flow_unit_test("f1", s1, s2);
    Model* m1 = new ModelIMP("m1", 0, 1);

    m1->add(s1);
    m1->add(s2);
    m1->add(f1);

    m1->run();

    assert(s1->getValue() == 0);
    assert(s2->getValue() == 100);
    
    delete s1;
    delete s2;
    delete f1;
}

void run_Model_unit_test(){
    std::cout << "    Start Model unit tests\n";
    test_Model_constructor();
    test_Model_destructor();
    test_Model_getName();
    test_Model_getSystems_and_add();
    test_Model_getFlows_and_add();
    test_Model_getStartTime();
    test_Model_getEndTime();
    test_Model_setName();
    test_Model_setSystems();
    test_Model_setFlows();
    test_Model_setStartTime();
    test_Model_setEndTime();
    test_Model_setTime();
    test_Model_rmv_Sytem();
    test_Model_rmv_Flow();
    test_Model_run();
    test_Model_equal();
    std::cout << "    End Model unit tests\n";
}