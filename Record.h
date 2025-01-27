#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <sstream>
#include <iomanip>

/**
 * @brief Klasa reprezentująca pojedynczy punkt pomiarowy (rekord danych).
 * 
 * Klasa przechowuje dane z jednego pomiaru energetycznego, w tym datę, godzinę,
 * oraz wartości takie jak autokonsumpcja, eksport, import, pobór i produkcja energii.
 */
class Record {
public:
    /**
     * @brief Data pomiaru w formacie YYYY-MM-DD.
     */
    std::string date;

    /**
     * @brief Godzina pomiaru w formacie HH:MM.
     */
    std::string time;

    /**
     * @brief Wartość autokonsumpcji energii w watach [W].
     * 
     * Autokonsumpcja to energia elektryczna, która została wyprodukowana 
     * przez falownik i od razu zużyta przez odbiorniki elektryczne.
     */
    double autokonsumpcja;

    /**
     * @brief Wartość energii wyeksportowanej do sieci w watach [W].
     */
    double eksport;

    /**
     * @brief Wartość energii zaimportowanej z sieci w watach [W].
     */
    double import_;

    /**
     * @brief Wartość energii pobranej przez odbiorniki elektryczne w watach [W].
     */
    double pobor;

    /**
     * @brief Wartość energii wyprodukowanej przez falownik w watach [W].
     */
    double produkcja;

    /**
     * @brief Konstruktor klasy Record.
     * 
     * Inicjalizuje obiekt klasy Record danymi z jednego punktu pomiarowego.
     * 
     * @param date Data pomiaru w formacie YYYY-MM-DD.
     * @param time Godzina pomiaru w formacie HH:MM.
     * @param autokonsumpcja Wartość autokonsumpcji energii w watach [W].
     * @param eksport Wartość energii wyeksportowanej do sieci w watach [W].
     * @param import_ Wartość energii zaimportowanej z sieci w watach [W].
     * @param pobor Wartość energii pobranej przez odbiorniki w watach [W].
     * @param produkcja Wartość energii wyprodukowanej przez falownik w watach [W].
     */
    Record(const std::string& date, const std::string& time, 
           double autokonsumpcja, double eksport, 
           double import_, double pobor, double produkcja)
        : date(date), time(time), autokonsumpcja(autokonsumpcja), eksport(eksport),
          import_(import_), pobor(pobor), produkcja(produkcja) {}

    /**
     * @brief Funkcja zwracająca tekstową reprezentację rekordu.
     * 
     * Generuje czytelną reprezentację rekordu w formie ciągu znaków.
     * Zawiera wszystkie informacje o rekordzie (data, godzina, wartości pomiarowe).
     * 
     * @return std::string Tekstowa reprezentacja rekordu.
     */
    std::string toString() const {
        std::ostringstream oss;
        oss << "Record(date=" << date << ", time=" << time
            << ", autokonsumpcja=" << autokonsumpcja
            << ", eksport=" << eksport << ", import=" << import_
            << ", pobor=" << pobor << ", produkcja=" << produkcja << ")";
        return oss.str();
    }
};

#endif // RECORD_H
