#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include "serial.h"
#include "cipher.h"
#include <stdio.h>

int main(int argc, char * const argv[])
{

    //Cipher* cipher = new Cipher("5C1A9AF9DDAD73901EFAB29DCA1E602A", "33E764D3B8F97B2918895BE311D0BE9DC0D5ACD7FB03854068357D4196048DBD14E8539879A6A1B099BF004B8F054E80");

    // Gera chave e vetor inicial
    std::string chave = BasicCryptoPPWrap::BitGen(128);          //Chave 128 bit
    std::string vetorInicial = BasicCryptoPPWrap::ByteGen(16);   // AES usa blocos de 16 bytes, portanto o vetor inicial deve ter 16 bytes

    std::cout << "Chave: " << BasicCryptoPPWrap::HexEncode(chave) << "\n";
    std::cout << "Vetor Inicial: " << BasicCryptoPPWrap::HexEncode(vetorInicial) << "\n";

    std::string textoPuro = "Mensagem em texto puro para teste da classe Cipher...";
    std::cout << "Mensagem em texto puro: " << textoPuro << "\n";

    std::string textoCifrado = cipher->cipherMsg(textoPuro);
    std::cout << "Mensagem cifrada: " << textoCifrado;
    
    std::string textoDecifrado = cipher->decipherMsg(textoCifrado);
    std::cout << "Mensagem decifrada: " << textoDecifrado << "\n"
    std::cout << "\n## Fim do teste ##\n";

    delete cipher;

    return 0;
}
