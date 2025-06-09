#ifndef MICROEMPREENDEDOR_HPP
#define MICROEMPREENDEDOR_HPP

#include "pessoa.hpp"
#include "empresa.hpp"

class Microempreendedor : public virtual Pessoa, Empresa {
public:
    Microempreendedor(const std::string& nome, int idade, int cpf, int cnpj);
    void exibe_cpf();
    void exibe_cnpj();
    virtual ~Microempreendedor();
};

#endif /* MICROEMPREENDEDOR_HPP */