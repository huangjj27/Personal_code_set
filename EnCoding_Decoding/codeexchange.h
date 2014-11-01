#ifndef CODEEXCHANGE_H
#define CODEEXCHANGE_H

#include <string>

class CodeExchange
{
public:
  CodeExchange();
  std::string MorseEnCode(std::string text);
  std::string MorseDeCode(std::string code);
  std::string Reverse(std::string text);
  std::string ReverseReplace(std::string text);
};

#endif // CODEEXCHANGE_H
