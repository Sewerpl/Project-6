#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <fstream>
#include "Tree.h"

class Program {
private:
    Tree tree; // Drzewo danych
    int validRecords = 0;   // Liczba poprawnych rekordów
    int invalidRecords = 0; // Liczba błędnych rekordów

    // Funkcje pomocnicze
    bool parseLine(const std::string& line, Record& record);
    void logMessage(const std::string& message, const std::string& logFile);

public:
    // Wczytywanie pliku CSV
    void loadCSV(const std::string& fileName);

};

#endif // PROGRAM_H
