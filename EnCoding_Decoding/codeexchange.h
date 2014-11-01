#ifndef CODEEXCHANGE_H
#define CODEEXCHANGE_H

#include <string>

class CodeExchange
{
public:
  CodeExchange();
  std::string MorseEnCode(std::string text);
  std::string MorseDeCode(std::string code);

};

#endif // CODEEXCHANGE_H
