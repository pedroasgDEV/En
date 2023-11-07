#ifndef EXPONENCIAL_DEF
#define EXPONENCIAL_DEF

#include <string.h>
#include "../../../src/Flow.h"

class Exponencial : public Flow{
    public:
        //Contructor
        Exponencial(const std::string& name = "NO_NAME", System* source = NULL, System* target = NULL); //! O Construtor é reduntante
        Exponencial(const Exponencial& other); //! O Construtor é reduntante

        //Destructor
        virtual ~Exponencial(); //! O destrutor é reduntante

        //Metodos
        virtual bool execute() override;
};

#endif