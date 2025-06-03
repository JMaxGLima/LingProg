#include "./include/pessoa.hpp"
#include "./include/empregado.hpp"
#include "./include/empresa.hpp"
#include "./include/microempreendedor.hpp"

void exibir_cpf(Microempreendedor* me){
    me->exibe_cpf();
}

void exibir_cnpj(Microempreendedor* me){
    me->exibe_cnpj();
}

int main() {
    Pessoa* p = new Pessoa("Lucas", 30, 1182345678);
    Empregado* e = new Empregado("Luis", 23, 1500.00);
    Pessoa* p2 = e;
    Empresa empresa(2905700001);
    
    // Ampliacao
    empresa.paga(*e);
    // Estreitamento
    empresa.contrata(*(static_cast<Empregado*> (p2))); 
    
    delete p;
    delete e;
    
    Microempreendedor* me = new Microempreendedor("Max", 25, 909995468, 101011010);
    exibir_cpf(me);
    exibir_cnpj(me);

    delete me;
    return 0;
}