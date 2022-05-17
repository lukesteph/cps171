/*
Written by Luke Stephen on May 16, 2022 for CPS 171
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Initialise a class to create Student objects
class Students {
public:
	char alumni = 'x';			// Initialise a char that defines whether the student has a parent who is an alum
	char school = 'x';			// Initialise a char that defines whether the student is applying to Music or LA
	float GPA   = 0.0;			// Initialise a float that defines the student's GPA
	int satMath =   0;			// Initialise an integer that defines the student's math SAT score
	int satVerb =   0;			// Initialise an integer that defines the student's verbal SAT score
	int applicantNumber = 0;	// Initialise an integer that defines the student's place in the queue
};

// Create a catchall instance of Student object
Students newStudent;   

// Define global variables
int musicAccepted = 0;
int libartsAccepted = 0;

// Arbitrates whether the student is accepted or not
string acceptanceCheck() {		
	if (newStudent.school == 'L') {
		if (libartsAccepted < 5) {
			if (newStudent.alumni == 'Y') {
				if (newStudent.GPA >= 3.0 && (newStudent.satMath + newStudent.satVerb) >= 1000) {
					libartsAccepted++;
					return "Accepted to Liberal Arts!";
				}
				else if (newStudent.GPA >= 3.0) {
					return "Rejected: SAT too low.";
				}
				else {
					return "Rejected: GPA too low.";
				}
			}
			if (newStudent.alumni == 'N') {
				if (newStudent.GPA >= 3.5 && (newStudent.satMath + newStudent.satVerb) >= 1200) {
					libartsAccepted++;
					return "Accepted to Liberal Arts!";
				}
				else if (newStudent.GPA >= 3.5) {
					return "Rejected: SAT too low.";
				}
				else {
					return "Rejected: GPA too low.";
				}
			}
		}
		else {
			return "Rejected: School is full.";
		}
	}

	else if (newStudent.school == 'M') {
		if (musicAccepted < 3) {
			if (newStudent.satMath > 500 && newStudent.satVerb > 500) {
				musicAccepted++;
				return "Accepted to Music!";
			}
			else {
				return "Rejected: SAT is too low.";
			}
		}
		else {
			return "Rejected: School is full.";
		}
	}
  else {
    return "Error with school choice";
  }
}

// Parses a string from the char school selected (created for aesthetic purposes)
string schoolParser(char school) {
	if (school == 'L') {
		return "Liberal Arts";
	}
	if (school == 'M') {
		return "Music";
	}
}

// Main method which iterates through each student
int main() {
  // Creates a filestream and a variable to increment and display student's place in the queue
	ifstream inStream;
	inStream.open("mp2Input.txt");
	int lineNumber = 0;

  // Primary for loop which edits the student class each iteration and renders the student's decision letter.
	for (int i = 0; i < 14; i++) {
		lineNumber++;

		inStream >> newStudent.school;
		inStream >> newStudent.GPA;
		inStream >> newStudent.satMath;
		inStream >> newStudent.satVerb;
		inStream >> newStudent.alumni;
		newStudent.applicantNumber = lineNumber;

		cout << "Applicant #" << newStudent.applicantNumber << '\n';
		cout << "School = " << newStudent.school << " GPA = " << newStudent.GPA << " SAT Math = " << newStudent.satMath << " SAT Verbal = " << newStudent.satVerb << " Alumnus = " << newStudent.alumni << '\n';
		cout << "Applying to " << schoolParser(newStudent.school) << '\n';
		cout << acceptanceCheck() << '\n';
		cout << "*******************************" << '\n';
	}
  // Output requested summary
  cout << "There were " << lineNumber << " applicants in the file." << '\n';
  cout << "There were " << libartsAccepted << " acceotances to Liberal Arts." << '\n';
  cout << "There were " << musicAccepted << " acceptances to Music." << '\n';
  
  // Close input stream because it's good practice
	inStream.close();
	return 0;
}