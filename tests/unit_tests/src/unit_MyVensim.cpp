#include "unit_MyVensim.hpp"

void test_MyVensim_constructor(){
    std::cout << "        * Constructor tests\n";
    
    MyVensim* m1 = new MyVensimIMP();
    assert(m1->getName() == "NO_NAME");

    MyVensim* m2 = new MyVensimIMP("m2");
    assert(m2->getName() == "m2");

    delete m1;
    delete m2;
}
 
void test_MyVensim_destructor(){
    std::cout << "        * Destructor tests\n";
    MyVensim* m1 = new MyVensimIMP();
    m1->~MyVensim();
}

void test_MyVensim_getName(){
    std::cout << "        * getName tests\n";
    MyVensim* m1 = new MyVensimIMP();
    assert(m1->getName() == "NO_NAME");

    MyVensim* m2 = new MyVensimIMP("m2");
    assert(m2->getName() == "m2");

    delete m1;
    delete m2;
}

void test_MyVensim_getSystems_and_add(){
    std::cout << "        * getSystems and add Systems tests\n";

    MyVensim* m1 = new MyVensimIMP("m1");
    System* s1 = m1->createSystem("s1");

    std::vector<System*> systems;
    systems.push_back(s1);

    assert(m1->getSystems() == systems);

    delete s1;
    delete m1;
}

void test_MyVensim_getFlows_and_add(){
    std::cout << "        * getFlows and add Flows tests\n";

    MyVensim* m1 = new MyVensimIMP("m1");
    Flow* f1 = m1->createFlow<Flow_unit_test>("f1");
    
    std::vector<Flow*> flows;
    flows.push_back(f1);
    
    assert(m1->getFlows() == flows);

    delete f1;
    delete m1;
}

void test_MyVensim_getModels_and_add(){
    std::cout << "        * getModels and add Models tests\n";

    MyVensim* m1 = new MyVensimIMP("m1");
    Model* f1 = m1->createModel("f1");
    
    std::vector<Model*> Models;
    Models.push_back(f1);
    
    assert(m1->getModels() == Models);

    delete f1;
    delete m1;
}

void test_MyVensim_setName(){
    std::cout << "        * setName tests\n";

    MyVensim* m1 = new MyVensimIMP();

    m1->setName("m1");
    assert(m1->getName() != "NO_NAME");

    MyVensim* m2 = new MyVensimIMP("m");

    m2->setName("m2");

    assert(m2->getName() == "m2");

    delete m1;
    delete m2;  
}

void test_MyVensim_setSystems(){
    std::cout << "        * setSystems tests\n";

    System* s1 = new SystemIMP("s1");
    MyVensim* m1 = new MyVensimIMP("m1");

    std::vector<System*> systems;
    systems.push_back(s1);
    m1->setSystems(systems);

    assert(m1->getSystems() == systems);

    delete s1;
    delete m1;
}

void test_MyVensim_setFlows(){
    std::cout << "        * setFlows tests\n";
    MyVensim* m1 = new MyVensimIMP("m1");
    Flow* f1 = new Flow_unit_test("f1");
    
    std::vector<Flow*> flows;
    flows.push_back(f1);
    m1->setFlows(flows);
    
    assert(m1->getFlows() == flows);

    delete f1;
    delete m1;
}

void test_MyVensim_setModels(){
    std::cout << "        * setModels tests\n";

    Model* f1 = new ModelIMP("f1");
    MyVensim* m1 = new MyVensimIMP("m1");

    std::vector<Model*> Models;
    Models.push_back(f1);
    m1->setModels(Models);

    assert(m1->getModels() == Models);

    delete f1;
    delete m1;
}

void test_MyVensim_equal(){
    std::cout << "        * Equal tests\n";

    MyVensimIMP* m1 = new MyVensimIMP();
    MyVensimIMP* m2 = new MyVensimIMP();
    assert(*m1 == *m2);

    m1->setName("m1");
    assert(m1 != m2);

    delete m1;
    delete m2;
}

void test_MyVensim_rmv_Sytem(){
    std::cout << "        * Remove System tests\n";

    MyVensim* MyVensim1 = new MyVensimIMP();
    System* system1 = new SystemIMP("system1");

    MyVensim1->add(system1);
    assert(MyVensim1->rmv(system1));

    delete MyVensim1;
    delete system1;
}

void test_MyVensim_rmv_Flow(){
    std::cout << "        * Remove Flow tests\n";

    MyVensim* MyVensim1 = new MyVensimIMP();
    FlowIMP* flow1 = new Flow_unit_test("flow1");

    MyVensim1->add(flow1);
    assert(MyVensim1->rmv(flow1));

    delete MyVensim1;
    delete flow1;
}

void test_MyVensim_rmv_Model(){
    std::cout << "        * Remove Model tests\n";

    MyVensim* MyVensim1 = new MyVensimIMP();
    ModelIMP* Model1 = new ModelIMP("Model1");

    MyVensim1->add(Model1);
    assert(MyVensim1->rmv(Model1));

    delete MyVensim1;
    delete Model1;
}

void test_MyVensim_run(){
    std::cout << "        * Run tests\n";

    MyVensim* mv = new MyVensimIMP("mv");
    System* s1 = mv->createSystem("s1", 100);
    System* s2 = mv->createSystem("s2", 0.0);
    Flow* f1 = mv->createFlow<Flow_unit_test>("f1", s1, s2);
    Model* m1 = mv->createModel("m1", 0, 1);

    m1->add(s1);
    m1->add(s2);
    m1->add(f1);

    mv->run();

    assert(s1->getValue() == 0);
    assert(s2->getValue() == 100);
    
    delete mv;
    delete s1;
    delete s2;
    delete f1;
    delete m1;
}

void run_MyVensim_unit_test(){
    std::cout << "    Start MyVensim unit tests\n";
    test_MyVensim_constructor();
    test_MyVensim_destructor();
    test_MyVensim_getName();
    test_MyVensim_getSystems_and_add();
    test_MyVensim_getFlows_and_add();
    test_MyVensim_getModels_and_add();
    test_MyVensim_setName();
    test_MyVensim_setSystems();
    test_MyVensim_setFlows();
    test_MyVensim_setModels();
    test_MyVensim_rmv_Sytem();
    test_MyVensim_rmv_Flow();
    test_MyVensim_rmv_Model();
    test_MyVensim_run();
    test_MyVensim_equal();
    std::cout << "    End MyVensim unit tests\n";
}

