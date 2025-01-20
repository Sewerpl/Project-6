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

};

#endif // RECORD_H
