#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

string SpecificLine(fstream& file, int num)
{
	int* line = new int;
	for (unsigned int i = 0; i < num - 1; ++i)
	{
		file.ignore();
	}
	return ;
	
}
  //////////////////////////////////////////////
 //////        Loading Function        ////////
//////////////////////////////////////////////

void LoadFile() {
	// Creating a stream object to access reading the file
	ifstream InputFile;
	int	line = 0;
	string lines;
	InputFile.open("Input_File.txt"); // directing the stream object to the input file
		
	if (InputFile.is_open()) { //Read the file’s content into the stream object if possible

	}
	else { //if the file is not in the directed path it will not open
		cout << "Couldn't open file\n";
	}
	InputFile.close(); //close the opened file

}

