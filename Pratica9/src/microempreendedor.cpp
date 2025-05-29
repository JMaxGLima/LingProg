#include "./include/microempreendedor.hpp"

Microempreendedor::Microempreendedor(const std::string& nome, int idade, int cpf, int cnpj): 
    Pessoa(nome, idade, cpf), 
    Empresa(cnpj), 
    exibe_cpf(cpf),
    exibe_cnpj {}

Microempreendedor::~Microempreendedor() {
    std::cout << "Destruindo Microempreendedor " << std::endl;
}