// Written by Luke Stephen for CPS 171, on May 24, 2022

#include <iostream>
#include <fstream>
using namespace std;

// Performs the encryption using the key matrix and filestream
void encrypt(char keyMatrix[5][5], ifstream& file) {
  // gets the unencrypted line, minus the E, and stores it in a string
  string encrypted;
  getline(file, encrypted);
  cout << encrypted << "\nEncrypts to: \n";

  // for every letter in the unencrypted word, if the letter at [i, j] equals it, change the letter in encrypted to the letter at [j, i]
  for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < encrypted.length(); k++) {
						if (encrypted[k] == tolower(keyMatrix[i][j])) {
							encrypted[k] = toupper(keyMatrix[j][i]);
						}
					}
				}
			}
  cout << encrypted << '\n';
	cout << "\n************************************************************\n\n";
}

void decrypt(char keyMatrix[5][5], ifstream& file) {
  // gets the encrypted line, minus the D, and stores it in a string
  string decrypted;
  getline(file, decrypted);
  cout << decrypted << "\nDecrypts to: \n";

  // for every letter in the encrypted word, if the letter at [i, j] equals it, change the letter in encrypted to the letter at [j, i]
  for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < decrypted.length(); k++) {
						if (decrypted[k] == keyMatrix[i][j]) {
							decrypted[k] = tolower(keyMatrix[j][i]);
						}
						
					}
				}
			}
  cout << decrypted << '\n';
	cout << "\n************************************************************\n\n";
}

void crypt(string keyword, ifstream& file) {

  // Formats keyword string by removing duplicates
	for (int i = 0; i < keyword.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (keyword[i] == keyword[j]) {
				keyword.erase(j, 1);
			}
		}
	}

  // Formats alphabet by removing letters contained by string alphabet that are already in the keyword
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";
  for (int i = 0; i < keyword.size(); i++) {
		for (int j = 0; j < alphabet.size(); j++) {
			if (keyword[i] == alphabet[j]) {
				alphabet.erase(j, 1);
			}
		}
	}

  // Writes the keyword, minus duplicates, then the alphabet, minus the characters in the keyword, to a 5x5 matrix
  char keyMatrix[5][5]; 
  int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			keyMatrix[i][j] = keyword.append(alphabet)[k];
			k++;
		}
	}

  // Writes the key matrix
  cout << "Key Matrix: \n\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << keyMatrix[i][j] << ' ';
		}

		cout << '\n';
	}
  cout << '\n';
  
  // Loops through each line in the file, calls encrypt or decrypt based on the first token in each line
  char encOrDec;
  while (!file.eof()) {
    file >> encOrDec;
    if (encOrDec == 'E') {
      encrypt(keyMatrix, file);
    }
    if (encOrDec == 'D') {
      decrypt(keyMatrix, file);
    }
  }
}

// Simple keyword getter that returns only the first word of the input file
string getKeyword(ifstream &file) {
  string keyword;
  file >> keyword;
  return keyword;
}

// A simple main function that just instantiates an instream, then calls two functions in order, and closes the instream
int main() {
  ifstream file ("mp5input.txt");
  
  crypt(getKeyword(file), file);

  file.close();
}