#include "Functional_tests.hpp"

void exponencial_test_run(){
    std::cout << "  Exponencial functional test" << std::endl;

    SystemIMP* pop1 = new SystemIMP("pop1", 100.0);
    SystemIMP* pop2 = new SystemIMP("pop2", 0.0);
    Exponencial* exp = new Exponencial("exp", pop1, pop2);
    ModelIMP* exponencial = new ModelIMP("Exponencial", 0, 100);

    //Add os systems e flows ao modelo
    exponencial->add(pop1);
    exponencial->add(pop2);
    exponencial->add(exp);

    //Roda o modelo
    exponencial->run();

    assert(fabs((round(pop1->getValue() * 10000) - 10000 * 36.6032)) < 0.0001);
    assert(fabs((round(pop2->getValue() * 10000) - 10000 * 63.3968)) < 0.0001);

    delete(exponencial);
    delete(exp);
    delete(pop1);
    delete(pop2);

    std::cout << "  Exponencial functional test passed\n" << std::endl;
}

void logistical_test_run(){
    std::cout << "  Logistical functional test" << std::endl;

    SystemIMP* p1 = new SystemIMP("p1", 100.0);
    SystemIMP* p2 = new SystemIMP("p2", 10.0);
    Logistical* log = new Logistical("log", p1, p2);
    ModelIMP* logistical = new ModelIMP("Logistical", 0, 100);

    //Add os systems e flows ao modelo
    logistical->add(p1);
    logistical->add(p2);
    logistical->add(log);

    //Roda o modelo
    logistical->run();

    assert(fabs(round(p1->getValue() * 10000) - 10000 * 88.2167) < 0.0001);
    assert(fabs(round(p2->getValue() * 10000) - 10000 * 21.7833) < 0.0001);

    delete(logistical);
    delete(log);
    delete(p1);
    delete(p2);

    std::cout << "  Logistical functional test passed\n" << std::endl;
}

void Complex_test_run(){
    std::cout << "  Complex functional test" << std::endl;

    ModelIMP* model = new ModelIMP("Model", 0, 100);
    SystemIMP* q1 = new SystemIMP("q1", 100.0);
    SystemIMP* q2 = new SystemIMP("q2", 0.0);
    SystemIMP* q3 = new SystemIMP("q3", 100.0);
    SystemIMP* q4 = new SystemIMP("q4", 0.0);
    SystemIMP* q5 = new SystemIMP("q5", 0.0);
    Exponencial* f = new Exponencial("f", q1, q2);
    Exponencial* t = new Exponencial("t", q2, q3);
    Exponencial* u = new Exponencial("u", q3, q4);
    Exponencial* v = new Exponencial("v", q4, q1);
    Exponencial* g = new Exponencial("g", q1, q3);
    Exponencial* r = new Exponencial("r", q2, q5);
    
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

    model->run();

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

    std::cout << "  Complex functional test passed" << std::endl;
}