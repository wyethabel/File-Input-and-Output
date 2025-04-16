//============================================================================
// Name        : File Input and Output.cpp
// Author      : Wyeth A.
// Description : This program is designed to accept initial input from a user,
//					write that input to a provided file, reverse the text
//					locally, and write it to a new file.
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	 // Gather initial text to append.
	 string textToAppend;
	 cout << "Please enter the test to add to the file: " << endl;
	 getline(cin, textToAppend);

	 // Write the text to the starting file.
	 ofstream writeToFile("src/CSC450_CT5_mod5.txt", ios::app);
	 writeToFile << textToAppend << endl;
	 writeToFile.close();

	 // Collect the text including what was just appended.
	 // Build a range iterator to grab all text as a local variable.
	 ifstream readFromFile("src/CSC450_CT5_mod5.txt");
	 string fileData, row;
	 while (getline(readFromFile, row)) {
		 fileData += row + "\n";
	 }
	 readFromFile.close();

	 // Reverse the text using a start and end pointer that work inwards.
	 int start = 0;
	 int end = fileData.length() - 1;
	 while (start < end) {
		 char tempCharacter = fileData[start];
		 fileData[start] = fileData[end];
		 fileData[end] = tempCharacter;
		 ++start;
		 --end;
	 }

	 // Write the reversed text to the new file.
	 ofstream writeToReversed("src/CSC450-mod5-reverse.txt", ios::app);
	 writeToReversed << fileData << endl;
	 writeToReversed.close();

	 return 0;
}
