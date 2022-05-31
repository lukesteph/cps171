// Written by Luke Stephen on 5/26/22 for CPS 171

#include <iostream>
#include <fstream>
using namespace std;

// Map chars to words for readability
enum maritalStatus {SINGLE = 'S', MARRIED = 'M', DIVORCED = 'D'};

// Formats the name passed to it and returns the formatted name
string formatName(string originalName) {
  // Declarations
  string formattedName, firstName, lastName, middleInitial;
  int index;
  bool hasMiddle = false;

  // Remove all spaces in originalName string
  while (originalName.find(' ')<originalName.length()) {
    originalName = originalName.erase(originalName.find(' '), 1);
  }

  // Isolates the last name based on the position of the comma + removes it from originalName string
  index = originalName.find(',');
  lastName = originalName.substr(0, index);
  originalName.erase(0, index +1);

  // if a '.' exists (denoting a middle initial), isolate and erase initial and period.
  if (originalName.find(".")<originalName.length()) {
    hasMiddle = true;
    middleInitial = originalName.at(originalName.find('.') - 1);
    originalName.erase((originalName.find('.') - 1), 2);
  }

  // Remainder of the originalName string is stored in firstName
  firstName = originalName;

	//Build final formatted name string
	formattedName.append(firstName + ' ');
	if (hasMiddle) formattedName.append(middleInitial + ". ");
	formattedName.append(lastName); 
	return formattedName;
}

/* Picks out a title for the client based on the first two chars
in each line. */
string titleArbitration(char userGender, char maritalStatus) {
  // Returns Mr. if client has flag M, otherwise proceeds to female titles
  switch (userGender) {
    case 'M': return "Mr. ";
    case 'F': break;
  }

  // Skipped if male
  switch (maritalStatus) {
    case MARRIED:  return "Mrs. ";
    case SINGLE:   return "Ms. ";
    case DIVORCED: return "Ms. ";
  }
}

// Print output to the console. Takes in a reference to title + both names.
void output(string& title, string originalName, string formattedName) {
  cout << "original: " << originalName << endl;
  cout << "formatted: " << title << formattedName << '\n' << endl;
}

// Main loop. 
int main() {

  // Declare a file
  ifstream file("mp6input.txt");
  
  // Loop, used once per line.
  while (!file.eof()) {

    // Read title flags and handle them
    char g = file.get();
    char m = file.get();
    string title = titleArbitration(g, m);

    // Read remainder of the line and handle it
    string name0;
    getline(file, name0);
    string name1 = formatName(name0);

    // Print output to console
    output(title, name0, name1);
  }
  file.close();
}