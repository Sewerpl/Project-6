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

    // Zapis/odczyt z pliku binarnego
    void saveToBinary(const std::string& fileName);
    void loadFromBinary(const std::string& fileName);

    // Operacje analizy danych
    void calculateSum(const std::string& startDate, const std::string& startTime,
                      const std::string& endDate, const std::string& endTime, const std::string& type);
    void calculateAverage(const std::string& startDate, const std::string& startTime,
                          const std::string& endDate, const std::string& endTime, const std::string& type);
    void compareRanges(const std::string& startDate1, const std::string& startTime1,
                       const std::string& endDate1, const std::string& endTime1,
                       const std::string& startDate2, const std::string& startTime2,
                       const std::string& endDate2, const std::string& endTime2, const std::string& type);
    void searchRecords(double value, double tolerance, const std::string& startDate,
                       const std::string& startTime, const std::string& endDate, const std::string& endTime, const std::string& type);

    // Menu główne
    void menu();
};

#endif // PROGRAM_H
