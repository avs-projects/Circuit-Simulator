#include "SaveFile.hpp"

void SaveFile::inputExpression(string nameFile, string expressionToSave) {

    // Link to file
    string path = "backup/";

    // Create and open the file
    ofstream file(path + nameFile + ".txt");

    // Write to file
    file << expressionToSave;

    // Close file
    file.close();
}

void SaveFile::removeFile(string nameFile) {

    // Link to file
    string path = "backup/";

    string file = path + nameFile + ".txt";

    // Create and open the file
    if (std::remove(file.c_str()) != 0) {
        perror("Error deleting file");
    } else {
        puts("File successfully deleted");
    }
}

void SaveFile::renameFile(string nameFile, string newName) {

    // Link to file
    string path = "backup/";

    string file = path + nameFile + ".txt";

    string newNameFile = path + newName + ".txt";

    // Create and open the file
    if (std::rename(file.c_str(), newNameFile.c_str()) != 0) {
        perror("Error renoming file");
    } else {
        puts("File successfully renomed");
    }
}

string SaveFile::getExpression(string nameFile) {

    // exit
    string myExpression;

    string path = "backup/";

    // Read file
    ifstream readFile(path + nameFile + ".txt");

    // Loop to read lines from file
    getline(readFile, myExpression);

    // Close file
    readFile.close();

    return myExpression;
}

bool SaveFile::checkFile(string nameFile) {
    ifstream fileToCheck;

    string path = "backup/";

    fileToCheck.open(path + nameFile + ".txt");
    if (fileToCheck) {
        return true;
    } else {
        return false;
    }
}
