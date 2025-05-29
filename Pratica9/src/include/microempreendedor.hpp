#ifndef MICROEMPREENDEDOR_HPP
#define MICROEMPREENDEDOR_HPP

#include "pessoa.hpp"
#include "empresa.hpp"

class Microempreendedor : public Pessoa {
public:
    Microempreendedor(const std::string& nome, int idade, int cpf, int cnpj);
    virtual ~Microempreendedor();
};

#endif /* MICROEMPREENDEDOR_HPP */