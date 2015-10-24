// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
// valueTest.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// structure of a value
struct Value {
  string name;
  string type;
  int priority;

  Value(string name, string type, int priority) {
    this->name = name;
    this->type = type;
    this->priority = priority;
  }
};

// global varaible
vector<Value> finalValue;
vector<Value> toolValue;

// read values from values.txt
void init() {
  string name, type;
  fstream infile("values.txt", ios::in);
  cout << "数据读取中……" << endl;
  while (infile >> name >> type && !cin.eof()) {
    if (type == "final") {
      finalValue.push_back(Value(name, type, 0));
    }
    if (type == "tool") {
      toolValue.push_back(Value(name, type, 0));
    }
  }

  infile.close();
}

bool bigger(Value A, Value B) {
  return A.priority > B.priority;
}


void sortValues(vector<Value>& values) {
  char  answer;
  for (int i = 0; i < values.size(); i++) {
    for (int j = i + 1; j < values.size(); j++) {
      system("cls");
      cout << "你认为 " << values[i].name << " 比 " << values[j].name << " 更重要吗？" << endl;
      cout << "y/n" << endl;
      cin >> answer;
      if (answer == 'y') {
        (values[i].priority)++;
      } else if (answer == 'n') {
        (values[j].priority)++;
      }
    }
  }
  sort(values.begin(), values.end(), bigger);
}

void output() {
  fstream outfile("yourValues.txt", ios::out);
  outfile << "about your terminal values:" << endl;
  for (int i = 0; i < finalValue.size(); i++) {
    outfile << i + 1 << " "  << finalValue[i].name << " " << finalValue[i].priority << endl;
  }
  outfile << endl;

  outfile << "about your tool values:" << endl;
  for (int i = 0; i < toolValue.size(); i++) {
    outfile << i + 1 << " " << toolValue[i].name << " " << toolValue[i].priority << endl;
  }

  outfile.close();
}

int main() {
  init();
  sortValues(finalValue);
  sortValues(toolValue);
  output();

  return 0;
}
