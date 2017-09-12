#define CATCH_CONFIG_MAIN
#include "others/catch.hpp"
#include "string_soma.cpp"

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
*/
TEST_CASE("Verificação da função soma_string") {
    SECTION("Verifica quebras básicas"){
        REQUIRE(soma_string("") == -1); //string nula
        REQUIRE(soma_string("-1\n") == -1); //negativo
        REQUIRE(soma_string("1") == -1); //sem \n
        // REQUIRE(soma_string() == -1);
        // REQUIRE(soma_string() == -1);
    }

    SECTION("Casos básicos que dão certo"){
        SECTION("Casos com 1 número"){
            REQUIRE(soma_string("1\n") == 1);
            REQUIRE(soma_string("7\n") == 7);
            REQUIRE(soma_string("1000\n") == 1000);
            REQUIRE(soma_string("1001\n") == -1);
        }

    }
}
