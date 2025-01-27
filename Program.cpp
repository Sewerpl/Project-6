/**
 * @brief Wczytuje dane z pliku CSV i przetwarza je do struktury danych.
 * 
 * Funkcja otwiera plik CSV o podanej nazwie, odczytuje linie i przetwarza je na obiekty typu `Record`. 
 * Następnie dodaje poprawne rekordy do struktury drzewa, a błędne zapisuje do pliku z błędami. 
 * W trakcie wczytywania pliku funkcja prowadzi logowanie poprawnych i błędnych rekordów.
 * 
 * Funkcja obsługuje również zapisywanie logów do dwóch plików:
 * - `log_data.txt` - dla poprawnych rekordów,
 * - `log_error_data.txt` - dla błędnych rekordów.
 * 
 * Po zakończeniu wczytywania pliku, funkcja wypisuje na ekranie liczbę poprawnych i błędnych rekordów.
 * 
 * @param fileName Nazwa pliku CSV, z którego mają zostać wczytane dane.
 * 
 * @note Jeśli plik nie może zostać otwarty, funkcja wypisuje błąd na standardowe wyjście i kończy działanie.
 * 
 * Przykład:
 * Jeśli plik `data.csv` zawiera poprawne rekordy, po zakończeniu działania funkcji
 * na ekranie zostanie wypisane: 
 * "Wczytywanie zakończone. Poprawne: 100, Błędne: 5".
 * 
 * @see parseLine, logMessage
 */
void Program::loadCSV(const std::string& ChartExport) {
    // Otwarcie pliku CSV do odczytu
    std::ifstream file(ChartExport);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << ChartExport<< std:endl;
        return;
    }

    // Otwarcie plików do logowania danych
    std::ofstream log("log_data.txt");
    std::ofstream errorLog("log_error_data.txt");

    std::string line;
    while (std::getline(file, line)) {
        Record record;
        // Parsowanie linii do obiektu Record
        if (parseLine(line, record)) {
            // Jeśli linia została poprawnie sparsowana, dodajemy rekord do drzewa
            tree.addRecord(record);
            validRecords++;
            // Logowanie poprawnego rekordu
            logMessage("Poprawny rekord: " + line, "log_data.txt");
        } else {
            // Jeśli linia jest błędna, inkrementujemy licznik błędnych rekordów
            invalidRecords++;
            // Logowanie błędnego rekordu
            logMessage("Błędny rekord: " + line, "log_error_data.txt");
        }
    }

    // Zamknięcie plików
    file.close();
    log.close();
    errorLog.close();

    // Wypisanie podsumowania
    std::cout << "Wczytywanie zakończone. Poprawne: " << validRecords << ", Błędne: " << invalidRecords << std::endl;
}

/**
 * @brief Parsuje pojedynczą linię tekstu z pliku CSV na obiekt typu `Record`.
 * 
 * Funkcja przetwarza pojedynczą linię z pliku CSV, dzieląc ją na odpowiednie części 
 * (datę, godzinę i wartości liczbowe odpowiadające różnym typom energii). Jeśli linia 
 * zawiera dane w poprawnym formacie, tworzy obiekt klasy `Record` i ustawia jego wartości.
 * 
 * Funkcja zakłada, że linia jest poprawnie sformatowana, w przeciwnym razie zwraca wartość 
 * `false`, co sygnalizuje, że linia jest niepoprawna i nie powinna być dodana do struktury danych.
 * 
 * @param line Pojedyncza linia tekstu z pliku CSV, która ma zostać sparsowana.
 * @param record Obiekt typu `Record`, do którego zapisane będą dane, jeśli linia będzie poprawna.
 * 
 * @return `true` jeśli linia została poprawnie sparsowana i obiekt `record` został zaktualizowany, 
 *         w przeciwnym razie zwraca `false`.
 * 
 * @note Funkcja zakłada, że dane w linii są oddzielone spacjami lub tabulatorami.
 * 
 * Przykład:
 * Jeśli linia w pliku CSV wygląda następująco:
 * ```
 * 2021-10-15 12:00 10.5 2.3 3.1 4.0 6.2
 * ```
 * Funkcja przetworzy ją na obiekt `Record`, w którym:
 * - `date = "2021-10-15"`,
 * - `time = "12:00"`,
 * - `autokonsumpcja = 10.5`,
 * - `eksport = 2.3`,
 * - `import_ = 3.1`,
 * - `pobor = 4.0`,
 * - `produkcja = 6.2`.
 * 
 * @see loadCSV
 */
bool Program::parseLine(const std::string& line, Record& record) {
    std::istringstream iss(line);
    std::string date, time;
    double autokonsumpcja, eksport, import_, pobor, produkcja;

    // Próba sparsowania danych z linii
    if (iss >> date >> time >> autokonsumpcja >> eksport >> import_ >> pobor >> produkcja) {
        // Jeśli parsowanie się powiodło, tworzymy obiekt Record
        record = Record(date, time, autokonsumpcja, eksport, import_, pobor, produkcja);
        return true; // Zwracamy true, jeśli linia została poprawnie sparsowana
    }
    return false; // Zwracamy false, jeśli linia zawiera błędy
}
