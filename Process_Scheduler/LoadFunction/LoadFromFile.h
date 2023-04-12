#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

  //////////////////////////////////////////////
 //////        Loading Function        ////////
//////////////////////////////////////////////

void LoadFile() {
	// Creating a stream object to access reading the file
	ifstream InputFile;
	string Line;
	InputFile.open("Input_File.txt"); // directing the stream object to the input file
		
	if (InputFile.is_open()) { //Read the file’s content into the stream object if possible
		
		while (InputFile) { 
			getline(InputFile, Line);
			cout << Line << '\n';
		}
	}
	else { //if the file is not in the directed path it will not open
		cout << "Couldn't open file\n";
	}
	InputFile.close(); //close the opened file
}