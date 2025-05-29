#include "./include/pessoa.hpp"

Pessoa::Pessoa(const std::string& nome, int idade, int cpf) 
    :nome(nome), 
    idade(idade), 
    cpf(cpf) {}

const std::string& Pessoa::pega_nome() {
    return nome;
}

const int& Pessoa::exibe_cpf() {
    std::cout << "Exibindo cpf: " << nome << std::endl;
    return cpf;
}

Pessoa::~Pessoa() {
    std::cout << "Destruindo Pessoa: " << nome << std::endl;
}