// Written by Lucas Stephen for CPS 171 on May 23, 2022

#include <iostream>
#include <fstream>
using namespace std;

// Converts Roman numerals to Decimal numbers- called once per character
int convert_from_Roman_to_Decimal(char c) {
  switch (c) {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default:  return 0;
  }
}

// Iterates through the number by half place values
string convert_from_Decimal_to_Roman(int i) {
  string result = "";
  while (i >= 1000) {
    result += "M";
    i -= 1000;
  }
  while (i >= 500) {
    result += "D";
    i -= 500;
  }
  while (i >= 100) {
    result += "C";
    i -= 100;
  }
  while (i >= 50) {
    result += "L";
    i -= 50;
  }
  while (i >= 10) {
    result += "X";
    i -= 10;
  }
  while (i >= 5) {
    result += "V";
    i -= 5;
  }
  while (i >= 1) {
    result += "I";
    i -= 1;
  }
  return result;
}

// Prints the second part of the output, starting from the result integer
void print_Result(int i) {
  cout << i << '\n';
  cout << "(" << convert_from_Decimal_to_Roman(i) << ")\n";
  cout << "************************************************\n";
}

// Crunches the numbers based on which operator is passed in, 'returns' an int
void calc_Romans(int operand1, int operand2, char operate, int& result) {
  switch (operate) {
    case '+': {
      result = (operand1 + operand2);
      break;
      }
    case '-': { 
      result = (operand1 - operand2);
      break;
      }
    case '*': {
      result = (operand1 * operand2);
      break;
      }
    case '/': {
      result = (operand1 / operand2);
      break;
      }
    default: {
      exit(0);
    } 
    }
  print_Result(result);
}

// Takes tokens from file and stores them, then calls the conversion n times, where n is the length of the Roman numeral
void get_Data(ifstream& file, string& operand1, string& operand2, char& op, int& result) {
  // Variables + storage
  file >> operand1 >> operand2 >> op;
  int op1 = 0;
  int op2 = 0;

  // Secondary loops
  for (int i = 0; i < operand1.length(); i++) {
    op1 += convert_from_Roman_to_Decimal(operand1.at(i));
  }
  for (int i = 0; i < operand2.length(); i++) {
    op2 += convert_from_Roman_to_Decimal(operand2.at(i));
  }

  // Performs the first half of the output, up to "the result is"
  if (operand1 != "null") {
    cout << "The first number is " << operand1 << " (" << op1 << ").\n";
    cout << "The second number is " << operand2 << " (" << op2 << ").\n";
    cout << "The operator is " << op << '\n';
    cout << "The result is ";
    calc_Romans(op1, op2, op, result);
    }
  }

int main() {
  // Instantiate file
  ifstream file ("mp4romanletrdata.txt");

  // Primary loop which creates the storage variables for each operand and operator and calls the data function
  while(!file.eof()) {
    string operand1 = "null";
    string operand2 = "null";
    char op = 'o';
    int result;
    get_Data(file, operand1, operand2, op, result);
    }
}