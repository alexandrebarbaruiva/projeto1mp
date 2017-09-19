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
    SECTION("Casos de quebras básicas"){
        // Para string nula
        REQUIRE(soma_string("") == -1);
        // Para número negativo
        REQUIRE(soma_string("-1\n") == -1);
        // Para string sem \n
        REQUIRE(soma_string("1") == -1);
        // Para string sem número, não há especificação, portanto retorna -1
        REQUIRE(soma_string("\n") == -1);
    }

    SECTION("Casos básicos que dão certo"){
        SECTION("Casos com 1 número e 1 casa decimal"){
            // Passar nestes testes quer dizer que o REGEX
            // está bem estruturado para \d\n
            REQUIRE(soma_string("0\n") == 0);
            REQUIRE(soma_string("1\n") == 1);
            REQUIRE(soma_string("7\n") == 7);
            REQUIRE(soma_string("9\n") == 9);
        }
        SECTION("Casos com 1 número e 2 casas decimais"){
            // Passar nestes testes quer dizer que o REGEX
            // está bem estruturado para \d\d\n
            REQUIRE(soma_string("10\n") == 10);
            REQUIRE(soma_string("23\n") == 23);
            REQUIRE(soma_string("99\n") == 99);
        }
        SECTION("Casos com 1 número e 3 casas decimais"){
            // Passar nestes testes quer dizer que o REGEX
            // está bem estruturado para \d+\n
            REQUIRE(soma_string("100\n") == 100);
            REQUIRE(soma_string("230\n") == 230);
            REQUIRE(soma_string("990\n") == 990);
        }
        SECTION("Casos com 1 número e 4 casas decimais"){
            // Passar nestes testes quer dizer que o REGEX
            // está bem estruturado para \d+\n e número menor que 1000
            REQUIRE(soma_string("1000\n") == 1000);
            REQUIRE(soma_string("1001\n") == 0);
            REQUIRE(soma_string("9999999\n") == 0);
        }
        SECTION("Casos com 2 ou mais números"){
            // Passar nestes testes quer dizer que o código consegue somar
            // 2 ou mais números sem erros
            REQUIRE(soma_string("1,1\n") == 2);
            REQUIRE(soma_string("15,39\n") == 54);
            REQUIRE(soma_string("1000,1000,9000\n") == 2000);
            REQUIRE(soma_string("10,20,3\n") == 33);
        }
    }
    SECTION("Casos complexos que dão certo"){
        SECTION("Muitas quebras de linhas entre números"){
            // Passar nestes testes quer dizer que o código não sofre
            // interferência de excesso de \n, somente de faltas quando
            // a quantidade de números na linha superar 3
            REQUIRE(soma_string("\n\n\n\n3\n\n\n\n,\n\n\n\n4\n\n\n\n") == 7);
            REQUIRE(soma_string("15,0,7,\n10,0\n,0,1\n") == 33);
            REQUIRE(soma_string("15,0,7,10\n,0\n,0,1\n") == -1); // mais de 3 n
        }
    }
    SECTION("Casos complexos que dão errado"){
        SECTION("Múltiplas vírgulas"){
            // Passar nestes testes quer dizer que o programa identifica
            // problemas e trata-os adequadamente
            REQUIRE(soma_string("3,,4") == -1);
            REQUIRE(soma_string(",2,4,5") == -1);
        }
    }
    SECTION("Testes documentados nos requisitos"){
        // Passar nestes testes quer dizer que o programa
        // está próximo do comportamento esperado pelo cliente
        REQUIRE(soma_string("3,2,1\n") == 6);
        REQUIRE(soma_string("1,\n") == -1);
        REQUIRE(soma_string(",2\n") == -1);
        REQUIRE(soma_string(",\n") == -1);
        REQUIRE(soma_string("3;2\n") == -1);
        REQUIRE(soma_string("1,2") == -1);
        REQUIRE(soma_string("1,2 \n") == -1);
        REQUIRE(soma_string("1\n,2\n") == 3);
        REQUIRE(soma_string("1,2,3\n,4\n") == 10);


    }
    SECTION("Testes com delimitadores diferentes"){
        // Passar nestes testes quer dizer que o programa identifica
        // multiplos delimitadores e trata-os corretamente
        REQUIRE(soma_string("//[.]\n3,2,1\n") == -1);
        REQUIRE(soma_string("//[.]\n3.2.1\n") == 6);
        REQUIRE(soma_string("//[.]3.2.1\n") == -1);
        REQUIRE(soma_string("//[i]\n4i4i4\n") == 12);
        REQUIRE(soma_string("//[ ]\n2 4 8\n") == 14);
        REQUIRE(soma_string("//[,]\n,3,2,1\n") == -1);
        REQUIRE(soma_string("//[ ][.]\n2 4.8\n") == 14);
        REQUIRE(soma_string("//[ ][.][i]\n1 2i7\n") == 10);
        REQUIRE(soma_string("//[ ][.][i]1 2i7\n") == -1);
    }
}
