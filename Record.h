#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <sstream>
#include <iomanip>

// Klasa reprezentująca jeden punkt pomiarowy (rekord danych)
class Record {
public:
    std::string date;  // Data w formacie YYYY-MM-DD
    std::string time;  // Godzina w formacie HH:MM
    double autokonsumpcja;
    double eksport;
    double import_;
    double pobor;
    double produkcja;

    // Konstruktor do inicjalizacji rekordu
    Record(const std::string& date, const std::string& time, double autokonsumpcja, double eksport,
           double import_, double pobor, double produkcja)
        : date(date), time(time), autokonsumpcja(autokonsumpcja), eksport(eksport),
          import_(import_), pobor(pobor), produkcja(produkcja) {}

    // Funkcja zwracająca tekstową reprezentację rekordu
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
