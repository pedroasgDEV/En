#ifndef LOGISTICAL_DEF
#define LOGISTICAL_DEF

#include <string.h>
#include "../../../src/Flow.h"

class Logistical : public Flow{
    public:
        //Contructor
        Logistical(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL); //! O Construtor é reduntante
        Logistical(const Logistical& other); //! O Construtor é reduntante

        //Destructor
        virtual ~Logistical(); //! O Destrutor é reduntante

        //Metodos
        virtual bool execute() override;
};

#endif
