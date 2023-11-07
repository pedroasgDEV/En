#include "Functional_tests.h"

void exponencial_test_run(){
    std::cout << "Exponencial funcional test" << std::endl;

    System* pop1 = new System("pop1", 100);
    System* pop2 = new System("pop2", 0);
    Exponencial* exp = new Exponencial("exp", pop1, pop2);
    Model* exponencial = new Model("Exponencial", 0, 100);

    //Add os systems e flows ao modelo
    exponencial->add(pop1);
    exponencial->add(pop2);
    exponencial->add(exp);

    //Roda o modelo
    exponencial->run();

    assert(round(abs(pop1->getValue() - 36.6032) * 10000) < 0.0001);
    assert(round(abs(pop2->getValue() - 63.3968) * 10000) < 0.0001);

    delete(exponencial);
    delete(exp);
    delete(pop1);
    delete(pop2);

    std::cout << "Passed exponencial funcional test" << std::endl;
}

void logistical_test_run(){
    std::cout << "Logistical funcional test" << std::endl;

    System* p1 = new System("p1", 100);
    System* p2 = new System("p2", 10);
    Logistical* log = new Logistical("exp", p1, p2);
    Model* logistical = new Model("Logistical", 0, 100);

    //Add os systems e flows ao modelo
    logistical->add(p1);
    logistical->add(p2);
    logistical->add(log);

    //Roda o modelo
    logistical->run();

    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7833) < 0.0001);

    delete(logistical);
    delete(log);
    delete(p1);
    delete(p2);

    std::cout << "Passed logistical funcional test" << std::endl;
}

void Complex_test_run(){
    std::cout << "Complex funcional test" << std::endl;

    //Systems
    System *q1= new System("q1", 100.0);
    System *q2= new System("q2", 0.0);
    System *q3= new System("q3", 100.0);
    System *q4= new System("q4", 0.0);
    System *q5= new System("q5", 0.0);

    //Flows
    Exponencial* A = new Exponencial("A", q1,q2);
    Exponencial* B = new Exponencial("B", q2,q3);
    Exponencial* C = new Exponencial("C", q3,q4);
    Exponencial* D = new Exponencial("D", q4,q1);
    Exponencial* E = new Exponencial("E", q1,q3);
    Exponencial* F = new Exponencial("F", q2,q5);

    //Model
    Model* complex = new Model("Complex", 0, 100);

    complex->add(q1);
    complex->add(q2);
    complex->add(q3);
    complex->add(q4);
    complex->add(q5);

    complex->add(A);
    complex->add(B);
    complex->add(C);
    complex->add(D);
    complex->add(E);
    complex->add(F);

    complex->run();

    assert(round(abs(q1->getValue() - 31.8513) * 10000) < 0.0001);
    assert(round(abs(q2->getValue() - 18.4003) * 10000) < 0.0001);
    assert(round(abs(q3->getValue() - 77.1143) * 10000) < 0.0001);
    assert(round(abs(q4->getValue() - 56.1728) * 10000) < 0.0001);
    assert(round(abs(q5->getValue() - 16.4612) * 10000) < 0.0001);

    delete(complex);
    delete(q1);
    delete(q2);
    delete(q3);
    delete(q4);
    delete(q5);
    delete(A);
    delete(B);
    delete(C);
    delete(D);
    delete(E);
    delete(F);

    std::cout << "Passed complex funcional test" << std::endl;
}