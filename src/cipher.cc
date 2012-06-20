#include "cipher.h"
#include "BasicCryptoPPWrap.h"
#include <fstream>
#include <sstream>
#include <stdio.h>

Cipher::Cipher(std::string key, std::string vector) {
    chave = key;			//chave
    vetor = vector;			// vetor inicial
}

std::string Cipher::cipherMsg(std::string plaintext) { 

    std::string ciphertext = BasicCryptoPPWrap::EncryptStringAES(plaintext, chave, vetor, _err, _errMsg);

    if (_err) {
        std::cout << _errMsg << "\n";
        return "-1";
    }

    return ciphertext;
}

std::string Cipher::decipherMsg(std::string ciphertext) {

    
    std::string deciphertext = BasicCryptoPPWrap::DecryptStringAES(ciphertext, chave, vetor,  _err, _errMsg); //Decifra mensagem

    if (_err) {
        std::cout << _errMsg << "\n";
        return "-1";
    }
 
    return deciphertext;
}

Cipher::~Cipher() { }

