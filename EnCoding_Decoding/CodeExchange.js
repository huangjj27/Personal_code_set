// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.

// the dictionary of Morse codes.
var enMorse = {
  // letters
  'a': ".-",   'b': "-...", 'c': "-.-.", 'd': "-..",  'e': ".",    'f': "..-.",
  'g': "--.",  'h': "....", 'i': "..",   'j': ".---", 'k': "-.-",  'l': ".-..",
  'm': "--",   'n': "-.",   'o': "---",  'p': ".--.", 'q': "--.-", 'r': ".-.",
  's': "...",  't': "-",    'u': "..-",  'v': "...-", 'w': ".--",  'x': "-..-",
  'y': "-.--", 'z': "--..",

  // nubmers
  '0': "-----", '1': ".----", '2': "..---", '3': "...--", '4': "....-",
  '5': ".....", '6': "-....", '7': "--...", '8': "---..", '9': "----.",

  // signs.
  // the space and the '\n' are here to simplify the encoding operation.
  ' ': "/", '\n': "\n",
  '.': ".-.-.-",  ',': "--..--", '?': "..--..", '\'': ".----.", '!': "-.-.--",
  '/': "-..-.",   '(': "-.--.",  ')': "-.--.-", '&': ".-...",   ':': "---...",
  ';': "-.-.-.",  '=': "-...-",  '+': ".-.-.",  '-': "-....-",  '_': "..--.-",
  '\"': ".-..-.", '$': "...-..-", '@': ".--.-."
}
var deMorse = {
  // letters
  ".-": 'a',   "-...": 'b', "-.-.": 'c', "-..": 'd',  ".": 'e',    "..-.": 'f',
  "--.": 'g',  "....": 'h', "..": 'i',   ".---": 'j', "-.-": 'k',  ".-..": 'l',
  "--": 'm',   "-.": 'n',   "---": 'o',  ".--.": 'p', "--.-": 'q', ".-.": 'r',
  "...": 's',  "-": 't',    "..-": 'u',  "...-": 'v', ".--": 'w',  "-..-": 'x',
  "-.--": 'y', "--..": 'z',

  // nubmers
  "-----": '0', ".----": '1', "..---": '2', "...--": '3', "....-": '4',
  ".....": '5', "-....": '6', "--...": '7', "---..": '8', "----.": '9',

  // signs.
  // the space and the '\n' are here to simplify the decoding operation.
  "/": ' ', "\n": '\n',
  ".-.-.-": '.',  "--..--": ',', "..--..": '?', ".----.": '\'', "-.-.--": '!',
  "-..-.": '/',   "-.--.": '(',  "-.--.-": ')', ".-...": '&',   "---...": ':',
  "-.-.-.": ';',  "-...-": '=',  ".-.-.": '+',  "-....-": '-',  "..--.-": '_',
  ".-..-.": '\"', "...-..-": '$', ".--.-.": '@'
}

function MorseEncode(text) {
  // post: default text is consist of ascii codes, such as letters, nubmers,
  // and some usual signs. Otherwise it can't be encode
  var code = "";
  var words = text.trim().split(/\s+/);
  for (var i = 0; i < words.length; i++) {
    if(i) code += ' ';
    for (var j = 0; j < words[i].length; j++) {
      if (j) code += '/';
      code +=enMorse[words[i][j]];
    }
  }
  return code;
}

function MorseDecode(code) {
  // post: the encoded Morse code must be in this format so that it can to be
  // decoded:  "letter_code/letter_code letter_code/letter_code/letter_code"
  var text = "";
  var words = code.trim().split(/\s+/);
  for (var i = 0; i < words.length; i++) {
    if (i) text +=' ';
    var letters = words[i].split('/');
    for (var j = 0; j < letters.length; j++) {
      text += deMorse[letters[j]];
    }
  }
  return text;
}
