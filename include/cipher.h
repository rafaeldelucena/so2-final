#ifndef _GLUE_CIPHER_H_
#define _GLUE_CIPHER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class Cipher
{

public:
    Cipher(std::string chave, std::string vetor);
   ~Cipher(void);
    std::string cipherMsg(std::string plaintext);
    std::string decipherMsg(std::string ciphertext);

private:
    bool _err;
    std::string _errMsg;

    std::string chave;
    std::string vetor;
};

#endif // _GLUE_CIPHER_H_
