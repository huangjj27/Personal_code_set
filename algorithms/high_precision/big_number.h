#ifndef BIG_NUMBER_CPP
#define BIG_NUMBER_CPP

#include <string>
using std::string;

#define MAX_SIZE 1000
#define MODULE 100000000

class BigNumber {
 public:
  // constructor
  BigNumber();

  // 5 fundamental operations
  friend BigNumber& operator +(const BigNumber& A, const BigNumber& B);
  friend BigNumber& operator -(const BigNumber& A, const BigNumber& B);
  friend BigNumber& operator *(const BigNumber& A, const BigNumber& B);
  friend BigNumber& operator /(const BigNumber& A, const BigNumber& B);
  friend BigNumber& operator %(const BigNumber& A, const BigNumber& B);

  // change to a output string
  string toString();

 private:
  // datas
   bool sign_;             // 0 for negative and 1 for passative
  int length_;             // how many elements of the data_ array are used.
  int data_[MAX_SIZE];    // datas.each element store 8 demical digits

  // private methods
  friend BigNumber& Sub(const BigNumber& A, const BigNumber& B);
  friend int isBigger(const BigNumber& A, const BigNumber& B);

};

#endif