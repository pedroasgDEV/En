#include "Functional_tests.hpp"

void exponencial_test_run(){
    std::cout << "  Exponencial functional test" << std::endl;

    MyVensim* mV = new MyVensimIMP("mV");
    System* pop1 = mV->createSystem("pop1", 100.0);
    System* pop2 = mV->createSystem("pop2", 0.0);
    Flow* exp = mV->createFlow<Exponencial>("exp", pop1, pop2);
    Model* exponencial = mV->createModel("Exponencial", 0, 100);

    //Add os systems e flows ao modelo
    exponencial->add(pop1);
    exponencial->add(pop2);
    exponencial->add(exp);

    //Roda o modelo
    mV->run();

    assert(fabs((round(pop1->getValue() * 10000) - 10000 * 36.6032)) < 0.0001);
    assert(fabs((round(pop2->getValue() * 10000) - 10000 * 63.3968)) < 0.0001);

    delete pop1;
    delete pop2;
    delete exp;
    delete exponencial;
    delete mV;


    std::cout << "  Exponencial functional test passed\n" << std::endl;
}

void logistical_test_run(){
    std::cout << "  Logistical functional test" << std::endl;

    MyVensim* mV = new MyVensimIMP("mV");
    System* p1 = mV->createSystem("p1", 100.0);
    System* p2 = mV->createSystem("p2", 10.0);
    Flow* log = mV->createFlow<Logistical>("log", p1, p2);
    Model* logistical = mV->createModel("Logistical", 0, 100);

    //Add os systems e flows ao modelo
    logistical->add(p1);
    logistical->add(p2);
    logistical->add(log);

    //Roda o modelo
    mV->run();

    assert(fabs(round(p1->getValue() * 10000) - 10000 * 88.2167) < 0.0001);
    assert(fabs(round(p2->getValue() * 10000) - 10000 * 21.7833) < 0.0001);

    delete logistical;
    delete log;
    delete p1;
    delete p2;
    delete mV;

    std::cout << "  Logistical functional test passed\n" << std::endl;
}

void Complex_test_run(){
    std::cout << "  Complex functional test" << std::endl;

    MyVensim* mV = new MyVensimIMP("mV");
    Model* model = mV->createModel("Model", 0, 100);
    System* q1 = mV->createSystem("q1", 100.0);
    System* q2 = mV->createSystem("q2", 0.0);
    System* q3 = mV->createSystem("q3", 100.0);
    System* q4 = mV->createSystem("q4", 0.0);
    System* q5 = mV->createSystem("q5", 0.0);
    Flow* f = mV->createFlow<Exponencial>("f", q1, q2);
    Flow* t = mV->createFlow<Exponencial>("t", q2, q3);
    Flow* u = mV->createFlow<Exponencial>("u", q3, q4);
    Flow* v = mV->createFlow<Exponencial>("v", q4, q1);
    Flow* g = mV->createFlow<Exponencial>("g", q1, q3);
    Flow* r = mV->createFlow<Exponencial>("r", q2, q5);
    
    model->add(q1);
    model->add(q2);
    model->add(q3);
    model->add(q4);
    model->add(q5);
    model->add(f);
    model->add(t);
    model->add(u);
    model->add(v);
    model->add(g);
    model->add(r);

    mV->run();

    assert(fabs((round((q1->getValue() * 10000)) - 10000 * 31.8513)) < 0.0001);
    assert(fabs((round((q2->getValue() * 10000)) - 10000 * 18.4003)) < 0.0001);
    assert(fabs((round((q3->getValue() * 10000)) - 10000 * 77.1143)) < 0.0001);
    assert(fabs((round((q4->getValue() * 10000)) - 10000 * 56.1728)) < 0.0001);
    assert(fabs((round((q5->getValue() * 10000)) - 10000 * 16.4612)) < 0.0001);
    
    delete model;
    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete f;
    delete t;
    delete u;
    delete v;
    delete g;
    delete r;
    delete mV;

    std::cout << "  Complex functional test passed" << std::endl;
}