#ifndef PROJECTC___SAVEFILE_HPP
#define PROJECTC___SAVEFILE_HPP

#include <iostream>
#include <fstream>

using namespace std;

class SaveFile {
private:
    string expression;
    string nameFile;
public:
    // Function to create file and write expression
    void inputExpression(string nameFile, string expressionToSave);
		// Function to delete a file
    void removeFile(string nameFile);
		// Function to rename a file
    void renameFile(string nameFile, string newName);
		// Function to see if file exists
    bool checkFile(string nameFile);
		// Get expression from file
    string getExpression(string nameFile);
};

#endif //PROJECTC___SAVEFILE_HPP
