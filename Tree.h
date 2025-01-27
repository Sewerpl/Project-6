#ifndef TREE_H
#define TREE_H

#include <map>
#include <vector>
#include "Record.h"

class Tree {
public:
    // Tutaj będzie struktura hierarchiczna

};

#endif // TREE_H#ifndef TREE_H
#define TREE_H

#include <map>
#include <vector>
#include "Record.h"

class Tree {
public:
    // Struktura hierarchiczna
    struct Quarter {
        std::vector<Record> records; // Dane dla ćwiartki
    };

    struct Day {
        std::map<int, Quarter> quarters; // Ćwiartki: 0-3
    };

    struct Month {
        std::map<int, Day> days; // Dni w miesiącu
    };

    struct Year {
        std::map<int, Month> months; // Miesiące w roku
    };

    std::map<int, Year> years; // Korzeń drzewa (lata)


};

#endif // TREE_H
