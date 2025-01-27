#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <fstream>
#include "Tree.h"

/**
 * @brief Klasa odpowiedzialna za zarządzanie logiką programu.
 * 
 * Klasa `Program` umożliwia wczytywanie danych z pliku CSV, zapisywanie i odczytywanie danych 
 * z plików binarnych, analizę danych oraz obsługę menu użytkownika.
 */
class Program {
private:
    /**
     * @brief Drzewo przechowujące dane pomiarowe w strukturze hierarchicznej.
     */
    Tree tree; 

    /**
     * @brief Liczba poprawnie przetworzonych rekordów.
     */
    int validRecords = 0;   

    /**
     * @brief Liczba błędnych rekordów.
     */
    int invalidRecords = 0; 

    /**
     * @brief Funkcja pomocnicza do parsowania linii z pliku CSV.
     * 
     * Funkcja przekształca linię tekstu z pliku CSV w obiekt `Record`.
     * Jeśli linia jest niepoprawna, funkcja zwraca `false`.
     * 
     * @param line Linia tekstu do sparsowania.
     * @param record Obiekt klasy `Record`, który zostanie wypełniony danymi.
     * @return true, jeśli parsowanie zakończyło się sukcesem, false w przeciwnym razie.
     */
    bool parseLine(const std::string& line, Record& record);

    /**
     * @brief Funkcja pomocnicza do logowania komunikatów do pliku.
     * 
     * @param message Treść komunikatu do zapisania.
     * @param logFile Nazwa pliku logu, do którego zostanie zapisany komunikat.
     */
    void logMessage(const std::string& message, const std::string& logFile);

public:
    /**
     * @brief Wczytuje dane z pliku CSV do drzewa.
     * 
     * Plik CSV jest analizowany linia po linii. Poprawne rekordy są dodawane do drzewa,
     * natomiast błędne rekordy są logowane w plikach błędów.
     * 
     * @param fileName Nazwa pliku CSV do wczytania.
     */
    void loadCSV(const std::string& fileName);

    /**
     * @brief Zapisuje dane drzewa do pliku binarnego.
     * 
     * Dane są zapisywane w formacie binarnym, co umożliwia szybki odczyt w przyszłości.
     * 
     * @param fileName Nazwa pliku binarnego, do którego zostaną zapisane dane.
     */
    void saveToBinary(const std::string& fileName);

    /**
     * @brief Wczytuje dane z pliku binarnego do drzewa.
     * 
     * Dane w pliku binarnym muszą być zgodne z formatem wygenerowanym przez `saveToBinary`.
     * 
     * @param fileName Nazwa pliku binarnego do wczytania.
     */
    void loadFromBinary(const std::string& fileName);

    /**
     * @brief Oblicza sumę wartości dla określonego typu danych w wybranym przedziale czasowym.
     * 
     * @param startDate Data początkowa w formacie YYYY-MM-DD.
     * @param startTime Godzina początkowa w formacie HH:MM.
     * @param endDate Data końcowa w formacie YYYY-MM-DD.
     * @param endTime Godzina końcowa w formacie HH:MM.
     * @param type Typ danych (np. "autokonsumpcja", "eksport", "import", "pobor", "produkcja").
     */
    void calculateSum(const std::string& startDate, const std::string& startTime,
                      const std::string& endDate, const std::string& endTime, const std::string& type);

    /**
     * @brief Oblicza średnią wartość dla określonego typu danych w wybranym przedziale czasowym.
     * 
     * @param startDate Data początkowa w formacie YYYY-MM-DD.
     * @param startTime Godzina początkowa w formacie HH:MM.
     * @param endDate Data końcowa w formacie YYYY-MM-DD.
     * @param endTime Godzina końcowa w formacie HH:MM.
     * @param type Typ danych (np. "autokonsumpcja", "eksport", "import", "pobor", "produkcja").
     */
    void calculateAverage(const std::string& startDate, const std::string& startTime,
                          const std::string& endDate, const std::string& endTime, const std::string& type);

    /**
     * @brief Porównuje dane dla dwóch przedziałów czasowych.
     * 
     * Funkcja porównuje sumy wartości dla dwóch zakresów czasowych dla wybranego typu danych.
     * 
     * @param startDate1 Data początkowa pierwszego zakresu w formacie YYYY-MM-DD.
     * @param startTime1 Godzina początkowa pierwszego zakresu w formacie HH:MM.
     * @param endDate1 Data końcowa pierwszego zakresu w formacie YYYY-MM-DD.
     * @param endTime1 Godzina końcowa pierwszego zakresu w formacie HH:MM.
     * @param startDate2 Data początkowa drugiego zakresu w formacie YYYY-MM-DD.
     * @param startTime2 Godzina początkowa drugiego zakresu w formacie HH:MM.
     * @param endDate2 Data końcowa drugiego zakresu w formacie YYYY-MM-DD.
     * @param endTime2 Godzina końcowa drugiego zakresu w formacie HH:MM.
     * @param type Typ danych (np. "autokonsumpcja", "eksport", "import", "pobor", "produkcja").
     */
    void compareRanges(const std::string& startDate1, const std::string& startTime1,
                       const std::string& endDate1, const std::string& endTime1,
                       const std::string& startDate2, const std::string& startTime2,
                       const std::string& endDate2, const std::string& endTime2, const std::string& type);

    /**
     * @brief Wyszukuje rekordy spełniające określone kryteria.
     * 
     * Funkcja wyszukuje rekordy w wybranym przedziale czasowym, gdzie wartość danego typu 
     * mieści się w zakresie `value ± tolerance`.
     * 
     * @param value Wartość, której należy szukać.
     * @param tolerance Zakres tolerancji dla wyszukiwanej wartości.
     * @param startDate Data początkowa w formacie YYYY-MM-DD.
     * @param startTime Godzina początkowa w formacie HH:MM.
     * @param endDate Data końcowa w formacie YYYY-MM-DD.
     * @param endTime Godzina końcowa w formacie HH:MM.
     * @param type Typ danych (np. "autokonsumpcja", "eksport", "import", "pobor", "produkcja").
     */
    void searchRecords(double value, double tolerance, const std::string& startDate,
                       const std::string& startTime, const std::string& endDate, const std::string& endTime, const std::string& type);

    /**
     * @brief Wyświetla menu główne programu.
     * 
     * Menu umożliwia użytkownikowi wybór opcji, takich jak wczytanie pliku CSV, analiza danych 
     * lub zapis do pliku binarnego.
     */
    void menu();
};

#endif // PROGRAM_H
