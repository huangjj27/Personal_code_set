#include "big_number.h"

#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) > (y) ? (x) : (y)

BigNumber::BigNumber() {
  sign_ = 1;
  length_ = 0;
  for (int i = 0; i < MAX_SIZE; i++) data_[i] = 0;
}

BigNumber& operator +(const BigNumber& A, const BigNumber& B) {
  BigNumber result;
  int carry = 0;
  result.length_ = MAX(A.length_, B.length_);
  for (int i = 0; i < result.length_; i++) {
    result.data_[i] = (A.data_[i] + B.data_[i] + carry) % MODULE;
    carry = (A.data_[i] + B.data_[i] + carry) / MODULE;
    result.data_[i + 1] += carry;
  }
  if (result.data_[result.length_]) result.length_++;

  return result;
}

BigNumber& operator -(const BigNumber& A, const BigNumber& B) {
  BigNumber result;
  switch (isBigger(A, B)) {
    case 0: 
      result.sign_ = 0;
      result.length_ = 1;
      break;
    case 1: 
      result = Sub(A, B);
      break;
    case -1:
      result = Sub(B, A);
      break;
  }
  return result;
}

BigNumber& operator *(const BigNumber& A, const BigNumber& B) {
  BigNumber result;
  return result;
}

BigNumber& operator /(const BigNumber& A, const BigNumber& B) {
  BigNumber result;
  return result;
}

BigNumber& operator %(const BigNumber& A, const BigNumber& B) {
  BigNumber result;
  return result;
}

string BigNumber::toString() {
  string data_str;
  return data_str;
}

BigNumber& Sub(const BigNumber& A, const BigNumber& B) {
  BigNumber result;
  result.length_ = A.length_;
  for (int i = A.length_; i >= 0; i--) {
    result.data_[i] = A.data_[i] - B.data_[i];
    if (result.data_[i] < 0) {
      result.data_[i + 1]--;
      result.data_[i] += MODULE;
    }
  }

  return result;
}

int isBigger(const BigNumber& A, const BigNumber& B) {
  if (A.length_ > B.length_) {
    return 1;
  } else if (A.length_ < B.length_) {
    return -1;
  } else {
    for (int length = A.length_ - 1; length >= 0; length--) {
      if (A.data_[length] > B.data_[length]) {
        return 1;
      } else if (A.data_[length] < B.data_[length]) {
        return -1;
      } else {
        continue;
      }
    }

    return 0;
  }
}
