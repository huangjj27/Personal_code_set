#include "codeexchange.h"

CodeExchange::CodeExchange() {}

std::string CodeExchange::MorseEnCode(std::string text) {
  std::string code;
  for (int i = 0; text[i]; i++) {
    if (i && (text[i] != '\n' && text[i-1] != '\n')
        && (text[i] != ' ' && text[i-1] != ' ')) code += " ";
    switch(text[i]) {
      case 'a': case 'A':
        code += ".-";
        break;
      case 'b': case 'B':
        code += "-...";
        break;
      case 'c': case 'C':
        code += "-.-.";
        break;
      case 'd': case 'D':
        code += "-..";
        break;
      case 'e': case 'E':
        code += ".";
        break;
      case 'f': case 'F':
        code += "..-.";
        break;
      case 'g': case 'G':
        code += "--.";
        break;
      case 'h': case 'H':
        code += "....";
        break;
      case 'i': case 'I':
        code += "..";
        break;
      case 'j': case 'J':
        code += ".---";
        break;
      case 'k': case 'K':
        code += "-.-";
        break;
      case 'l': case 'L':
        code += ".-..";
        break;
      case 'm': case 'M':
        code += "--";
        break;
      case 'n': case 'N':
        code += "-.";
        break;
      case 'o': case 'O':
        code += "---";
        break;
      case 'p': case 'P':
        code += ".--.";
        break;
      case 'q': case 'Q':
        code += "--.-";
        break;
      case 'r': case 'R':
        code += ".-.";
        break;
      case 's': case 'S':
        code += "...";
        break;
      case 't': case 'T':
        code += "-";
        break;
      case 'u': case 'U':
        code += "..-";
        break;
      case 'v': case 'V':
        code += "...-";
        break;
      case 'w': case 'W':
        code += ".--";
        break;
      case 'x': case 'X':
        code += "-..-";
        break;
      case 'y': case 'Y':
        code += "-.--";
        break;
      case 'z': case 'Z':
        code += "--..";
        break;
      case '0':
        code += "-----";
        break;
      case '1':
        code += ".----";
        break;
      case '2':
        code += "..---";
        break;
      case '3':
        code += "...--";
        break;
      case '4':
        code += "....-";
        break;
      case '5':
        code += ".....";
        break;
      case '6':
        code += "-....";
        break;
      case '7':
        code += "--...";
        break;
      case '8':
        code += "---..";
        break;
      case '9':
        code += "----.";
        break;
      case ' ':
        code += "/";
        break;
      case '\n':
        code += "\n";
        break;
      default:
        code = "unexpected text!";
        break;
    }
  }
  return code;
}

std::string CodeExchange::MorseDeCode(std::string code) {
  std::string text;
  int sentence_begin = 0, sentence_end = 0;
  while (sentence_end != std::string::npos) {
    sentence_end = code.find('\n', sentence_begin);
    int sentence_length = sentence_end-sentence_begin;
    std::string sentence(code, sentence_begin, sentence_length);

    int word_begin = 0, word_end = 0;
    while (word_end != std::string::npos) {
      word_end = sentence.find('/',word_begin);
      int word_length = word_end - word_begin;
      std::string word(sentence, word_begin, word_length);

      int letter_begin = 0, letter_end = 0;
      while (letter_end != std::string::npos) {
        letter_end = word.find(' ', letter_begin);
        int letter_length = letter_end - letter_begin;
        std::string letter(word, letter_begin, letter_length);

        if (letter == ".-")         text += "a";
        else if (letter == "-...")  text += "b";
        else if (letter == "-.-.")  text += "c";
        else if (letter == "-..")   text += "d";
        else if (letter == ".")     text += "e";
        else if (letter == "..-.")  text += "f";
        else if (letter == "--.")   text += "g";
        else if (letter == "....")  text += "h";
        else if (letter == "..")    text += "i";
        else if (letter == ".---")  text += "j";
        else if (letter == "-.-")   text += "k";
        else if (letter == ".-..")  text += "l";
        else if (letter == "--")    text += "m";
        else if (letter == "-.")    text += "n";
        else if (letter == "---")   text += "o";
        else if (letter == ".--.")  text += "p";
        else if (letter == "--.-")  text += "q";
        else if (letter == ".-.")   text += "r";
        else if (letter == "...")   text += "s";
        else if (letter == "-")     text += "t";
        else if (letter == "..-")   text += "u";
        else if (letter == "...-")  text += "v";
        else if (letter == ".--")   text += "w";
        else if (letter == "-..-")  text += "x";
        else if (letter == "-.--")  text += "y";
        else if (letter == "--..")  text += "z";
        else if (letter == "-----")  text += "0";
        else if (letter == ".----")  text += "1";
        else if (letter == "..---")  text += "2";
        else if (letter == "...--")  text += "3";
        else if (letter == "....-")  text += "4";
        else if (letter == ".....")  text += "5";
        else if (letter == "-....")  text += "6";
        else if (letter == "--...")  text += "7";
        else if (letter == "---..")  text += "8";
        else if (letter == "----.")  text += "9";
        else text += letter;

        letter_begin = letter_end+1;
      }
      if (word_end != std::string::npos
          && code[word_end] == '/') text += " ";
      word_begin = word_end+1;
    }
    if (sentence_end != std::string::npos
        && code[sentence_end] == '\n') text += "\n";
    sentence_begin = sentence_end+1;
  }

  return text;
}
