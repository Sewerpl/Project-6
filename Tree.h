#ifndef TREE_H
#define TREE_H

#include <map>
#include <vector>
#include <string>
#include "Record.h"

/**
 * @brief Klasa reprezentująca hierarchiczne drzewo do przechowywania danych pomiarowych.
 * 
 * Drzewo organizuje dane według następującej struktury:
 * - Rok -> Miesiąc -> Dzień -> Ćwiartka (6-godzinny przedział czasowy).
 * 
 * Każda ćwiartka zawiera listę rekordów danych pomiarowych.
 */
class Tree {
public:
    /**
     * @brief Struktura reprezentująca dane w ćwiartce (6-godzinny przedział czasowy).
     */
    struct Quarter {
        /**
         * @brief Wektor przechowujący rekordy danych dla danej ćwiartki.
         */
        std::vector<Record> records; 
    };

    /**
     * @brief Struktura reprezentująca dane dla pojedynczego dnia.
     * 
     * Dzień zawiera 4 ćwiartki:
     * - Ćwiartka 0: 00:00 - 05:45
     * - Ćwiartka 1: 06:00 - 11:45
     * - Ćwiartka 2: 12:00 - 17:45
     * - Ćwiartka 3: 18:00 - 23:45
     */
    struct Day {
        /**
         * @brief Mapa przechowująca ćwiartki (klucz: numer ćwiartki, wartość: dane ćwiartki).
         */
        std::map<int, Quarter> quarters; 
    };

    /**
     * @brief Struktura reprezentująca dane dla pojedynczego miesiąca.
     * 
     * Miesiąc zawiera dni z mapy:
     * - Klucz: numer dnia (1-31)
     * - Wartość: dane dnia
     */
    struct Month {
        /**
         * @brief Mapa przechowująca dni miesiąca.
         */
        std::map<int, Day> days; 
    };

    /**
     * @brief Struktura reprezentująca dane dla pojedynczego roku.
     * 
     * Rok zawiera miesiące z mapy:
     * - Klucz: numer miesiąca (1-12)
     * - Wartość: dane miesiąca
     */
    struct Year {
        /**
         * @brief Mapa przechowująca miesiące roku.
         */
        std::map<int, Month> months; 
    };

    /**
     * @brief Mapa przechowująca dane dla wszystkich lat.
     * 
     * Klucz: numer roku (np. 2021).
     * Wartość: dane roku.
     */
    std::map<int, Year> years; 

    /**
     * @brief Dodaje rekord pomiarowy do odpowiedniego miejsca w drzewie.
     * 
     * Rekord jest klasyfikowany według daty i czasu, a następnie umieszczany w odpowiednim roku, miesiącu, dniu i ćwiartce.
     * 
     * @param record Obiekt klasy Record reprezentujący pojedynczy punkt pomiarowy.
     */
    void addRecord(const Record& record);

    /**
     * @brief Funkcja pomocnicza do określenia ćwiartki na podstawie czasu.
     * 
     * Funkcja przypisuje godzinę i minutę do jednej z czterech ćwiartek:
     * - Ćwiartka 0: 00:00 - 05:45
     * - Ćwiartka 1: 06:00 - 11:45
     * - Ćwiartka 2: 12:00 - 17:45
     * - Ćwiartka 3: 18:00 - 23:45
     * 
     * @param time Czas w formacie HH:MM.
     * @return int Numer ćwiartki (0-3).
     */
    static int getQuarter(const std::string& time);
};

#endif // TREE_H
