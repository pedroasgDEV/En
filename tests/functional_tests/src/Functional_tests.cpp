#include "Functional_tests.h"

void exponencial_test_run(){
    std::cout << "Exponencial funcional test" << std::endl;

    System* pop1 = new System("pop1", 100.0);
    System* pop2 = new System("pop2", 0.0);
    Exponencial* exp = new Exponencial("exp", pop1, pop2);
    Model* exponencial = new Model("Exponencial", 0, 100);

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

    std::cout << "Passed exponencial funcional test" << std::endl;
}

void logistical_test_run(){
    std::cout << "Logistical funcional test" << std::endl;

    System* p1 = new System("p1", 100.0);
    System* p2 = new System("p2", 10.0);
    Logistical* log = new Logistical("log", p1, p2);
    Model* logistical = new Model("Logistical", 0, 100);

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
}

void Complex_test_run(){
    std::cout << "Complex funcional test" << std::endl;

    Model* model = new Model("Model", 0, 100);
    System* q1 = new System("q1", 100.0);
    System* q2 = new System("q2", 0.0);
    System* q3 = new System("q3", 100.0);
    System* q4 = new System("q4", 0.0);
    System* q5 = new System("q5", 0.0);
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

    std::cout << "Passed Complex funcional test" << std::endl;
}