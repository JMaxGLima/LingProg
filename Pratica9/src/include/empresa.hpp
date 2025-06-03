#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "pessoa.hpp"
#include "empregado.hpp"

class Empresa {
    protected:
    int cnpj;
public:
    Empresa(int cnpj);
    virtual ~Empresa();
    void paga(Pessoa& pes);
    void contrata(Empregado& emp);
};

#endif /* EMPRESA_HPP */