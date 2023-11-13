#ifndef EXPONENCIAL_DEF
#define EXPONENCIAL_DEF

#include <string.h>
#include "../../../src/Flow.h"
class Exponencial : public Flow{
    public:
        //Contructor
        Exponencial(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL);
        Exponencial(const Exponencial& other);
        //Destructor
        virtual ~Exponencial();

        //Metodos
        virtual double execute() override;
};

#endif