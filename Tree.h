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

};

#endif // TREE_H
