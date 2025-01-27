/**
 * @brief Dodaje rekord do odpowiedniego miejsca w strukturze drzewa.
 * 
 * Funkcja przetwarza datę i godzinę rekordu, aby umieścić go w odpowiednim roku, miesiącu, dniu 
 * i ćwiartce dnia w strukturze drzewa. Struktura ta jest hierarchiczna: lata -> miesiące -> dni -> ćwiartki dnia.
 * 
 * @param record Obiekt klasy `Record`, który zawiera dane do dodania.
 * 
 * Przykład działania:
 * - Jeśli rekord zawiera datę `2025-01-27` i godzinę `13:45`,
 *   to zostanie umieszczony w:
 *   - roku: `2025`,
 *   - miesiącu: `1` (styczeń),
 *   - dniu: `27`,
 *   - ćwiartce dnia: `2` (popołudnie: godziny 12:00-18:00).
 */
void Tree::addRecord(const Record& record) {
    int year, month, day;

    // Parsowanie daty w formacie YYYY-MM-DD na rok, miesiąc i dzień
    sscanf(record.date.c_str(), "%d-%d-%d", &year, &month, &day);

    // Wyznaczenie ćwiartki dnia na podstawie czasu
    int quarter = getQuarter(record.time);

    // Dodanie rekordu do odpowiedniej ćwiartki w strukturze drzewa
    years[year].months[month].days[day].quarters[quarter].records.push_back(record);
}

/**
 * @brief Określa ćwiartkę dnia na podstawie czasu.
 * 
 * Funkcja przydziela czas do jednej z czterech ćwiartek dnia:
 * - Ćwiartka 0: godziny od 00:00 do 05:59,
 * - Ćwiartka 1: godziny od 06:00 do 11:59,
 * - Ćwiartka 2: godziny od 12:00 do 17:59,
 * - Ćwiartka 3: godziny od 18:00 do 23:59.
 * 
 * @param time Czas w formacie HH:MM.
 * @return Numer ćwiartki dnia:
 * - 0: noc,
 * - 1: poranek,
 * - 2: popołudnie,
 * - 3: wieczór.
 * 
 * Przykład:
 * - Dla czasu `05:45` funkcja zwraca `0`.
 * - Dla czasu `13:30` funkcja zwraca `2`.
 */
int Tree::getQuarter(const std::string& time) {
    int hour, minute;

    // Parsowanie czasu w formacie HH:MM na godziny i minuty
    sscanf(time.c_str(), "%d:%d", &hour, &minute);

    // Wyznaczanie ćwiartki dnia na podstawie godziny
    if (hour < 6) return 0;           // Noc: 00:00 - 05:59
    else if (hour < 12) return 1;     // Poranek: 06:00 - 11:59
    else if (hour < 18) return 2;     // Popołudnie: 12:00 - 17:59
    else return 3;                    // Wieczór: 18:00 - 23:59
}
