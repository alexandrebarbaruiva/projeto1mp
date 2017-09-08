#define CATCH_CONFIG_MAIN
#include "others/catch.hpp"
#include "classes.cpp"

/**
* @brief Unit Tests.
*
* 1. Criar teste;
* 2. Teste falhar;
* 3. Implementar código (mantém-se no 3 enquanto 4 não ocorrer);
* 4. Teste bem sucedido;
* 5. Voltar ao passo (1) até conclusão do projeto.
*
* Estrutura dos testes é a seguinte:
* 1. Inicializa testes com TEST_CASE;
* 2. Inicializa objetos para teste
* 3. Verifica funções de classes, separando diferentes classes com SECTION
* 4. No início e no final do teste de uma classe, imprime na linha de comando qual classe
* está sendo testada.
*
*/
TEST_CASE("Verificação da função soma_string") {

    SECTION("Verifica classe Usuário", "[Informação]" ){
        std::cout<<"USUARIO BEGIN"<<std::endl;
        REQUIRE(userTest.getNome() == "Alexandre");
        REQUIRE(userTest.getSobrenome() == "Augusto");
        REQUIRE(userTest.getCPF() == "0124567890");
        REQUIRE(userTest.getId() == 1);

        // Não há eventos, todos os requisitos devem retornar -1 (que é acesso negado)
        REQUIRE(userTest.requisitarAcesso(labTest, 0, 8) == -1);
        REQUIRE(userTest.requisitarAcesso(labTest, 0, 10) == -1);

        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getSobrenome() == "");
        REQUIRE(otherTest.getCPF() == "");
        REQUIRE(otherTest.getId() == -1);
        std::cout<<"USUARIO OK\n"<<std::endl;
    }

    SECTION("Verifica classe Evento", "[Informação]"){
        std::cout<<"EVENTO BEGIN"<<std::endl;
        SECTION("Construtor com nome"){
            REQUIRE(eventoTest.getNomeEvento() == "Django Jam");
            eventoTest.setNomeEvento("Jungle Jazz");
            REQUIRE(eventoTest.getNomeEvento() == "Jungle Jazz");
            REQUIRE(eventoTest.adicionaParticipante("01234567890") == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
            REQUIRE(eventoTest.verificaParticipante("01234567890") == "Participante encontra-se registrado no evento.");
            REQUIRE(eventoTest.removeParticipante("01234567890") == "Participante removido com sucesso. Há 20 vagas disponíveis.");
            REQUIRE(eventoTest.removeEvento() == "Evento removido com sucesso.");
            REQUIRE(eventoTest.adicionaProposito("Aula") == "Propósito adicionado com sucesso.");
            REQUIRE(eventoTest.getProposito() == "Aula");
        }
        SECTION("Construtor vazio"){
            REQUIRE(otherEventoTest.getNomeEvento() == "");
            REQUIRE(otherEventoTest.adicionaParticipante("01234567890") == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
        }
        std::cout<<"EVENTO OK\n"<<std::endl;
    }

}
