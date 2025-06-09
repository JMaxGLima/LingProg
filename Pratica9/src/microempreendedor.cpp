#include "./include/microempreendedor.hpp"

Microempreendedor::Microempreendedor(const std::string& nome, int idade, int cpf, int cnpj)
    : Pessoa(nome, idade, cpf), Empresa(cnpj){}

void Microempreendedor::exibe_cpf() {
    std::cout << "CPF de Microempreendedor: " << cpf << std::endl;
}

void Microempreendedor::exibe_cnpj() {
    std::cout << "CNPJ de Microempreendedor: " << cnpj << std::endl;}

Microempreendedor::~Microempreendedor() {
    std::cout << "Destruindo Microempreendedor " << std::endl;
}