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
    // SECTION("Casos de quebras básicas"){
    //     REQUIRE(soma_string("") == -1); //string nula
    //     REQUIRE(soma_string("-1\n") == -1); //negativo
    //     REQUIRE(soma_string("1") == -1); //sem \n
    //     REQUIRE(soma_string("\n") == -1);
    // }
    //
    // SECTION("Casos básicos que dão certo"){
    //     SECTION("Casos com 1 número e 1 casa decimal"){
    //         REQUIRE(soma_string("0\n") == 0);
    //         REQUIRE(soma_string("1\n") == 1);
    //         REQUIRE(soma_string("7\n") == 7);
    //         REQUIRE(soma_string("9\n") == 9);
    //     }
    //     SECTION("Casos com 1 número e 2 casas decimais"){
    //         REQUIRE(soma_string("10\n") == 10);
    //         REQUIRE(soma_string("23\n") == 23);
    //         REQUIRE(soma_string("99\n") == 99);
    //     }
    //     SECTION("Casos com 1 número e 3 casas decimais"){
    //         REQUIRE(soma_string("100\n") == 100);
    //         REQUIRE(soma_string("230\n") == 230);
    //         REQUIRE(soma_string("990\n") == 990);
    //     }
    //     SECTION("Casos com 1 número e 4 casas decimais"){
    //         REQUIRE(soma_string("1000\n") == 1000);
    //         REQUIRE(soma_string("1001\n") == 0);
    //         REQUIRE(soma_string("9999999\n") == 0);
    //     }
    //     SECTION("Casos com 2 ou mais números"){
    //         REQUIRE(soma_string("1,1\n") == 2);
    //         REQUIRE(soma_string("15,39\n") == 54);
    //         REQUIRE(soma_string("1000,1000,9000\n") == 2000);
    //         REQUIRE(soma_string("10,20,1,3\n") == 34);
    //         REQUIRE(soma_string("15,7,10,1\n") == 33);
    //         REQUIRE(soma_string("15,0,7,10,1\n") == 33);
    //         REQUIRE(soma_string("15,0,7,10,0,1\n") == 33);
    //     }
    // }
    // SECTION("Casos complexos que dão certo"){
    //     SECTION("Muitas quebras de linhas entre números"){
    //         REQUIRE(soma_string("\n\n\n\n3\n\n\n\n,\n\n\n\n4\n\n\n\n") == 7);
    //         REQUIRE(soma_string("15,0,7,\n10,0\n,0,1\n") == 33);
    //         REQUIRE(soma_string("15,0,7,10\n,0\n,0,1\n") == 33);
    //     }
    //
    // }
    // SECTION("Casos complexos que dão errado"){
    //     SECTION("Múltiplas vírgulas"){
    //         REQUIRE(soma_string("3,,4") == -1);
    //         REQUIRE(soma_string(",2,4,5") == -1);
    //     }
    // }
    // SECTION("Testes documentados nos requisitos"){
    //     REQUIRE(soma_string("3,2,1\n") == 6);
    //     REQUIRE(soma_string("1,\n") == -1);
    //     // REQUIRE(soma_string(",2\n") == -1);
    //     REQUIRE(soma_string(",\n") == -1);
    //     REQUIRE(soma_string("3;2\n") == -1);
    //     REQUIRE(soma_string("1,2") == -1);
    // }
    SECTION("Testes com delimitadores diferentes"){
        REQUIRE(soma_string("//[.]\n3,2,1\n") == -1);
        REQUIRE(soma_string("//[.]\n3.2.1\n") == 6);
    }
}