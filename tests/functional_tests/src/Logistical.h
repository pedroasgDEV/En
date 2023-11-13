#ifndef LOGISTICAL_DEF
#define LOGISTICAL_DEF

#include <string.h>
#include "../../../src/Flow.h"

class Logistical : public Flow{
    public:
        //Contructor
        Logistical(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL);
        Logistical(const Logistical& other);

        //Destructor
        virtual ~Logistical();

        //Metodos
        virtual double execute() override;
};

#endif
