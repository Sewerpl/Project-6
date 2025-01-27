void Program::loadCSV(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << fileName << std::endl;
        return;
    }

    std::ofstream log("log_data.txt");
    std::ofstream errorLog("log_error_data.txt");

    std::string line;
    while (std::getline(file, line)) {
        Record record;
        if (parseLine(line, record)) {
            tree.addRecord(record);
            validRecords++;
            logMessage("Poprawny rekord: " + line, "log_data.txt");
        } else {
            invalidRecords++;
            logMessage("Błędny rekord: " + line, "log_error_data.txt");
        }
    }

    file.close();
    log.close();
    errorLog.close();

    std::cout << "Wczytywanie zakończone. Poprawne: " << validRecords << ", Błędne: " << invalidRecords << std::endl;
}

bool Program::parseLine(const std::string& line, Record& record) {
    std::istringstream iss(line);
    std::string date, time;
    double autokonsumpcja, eksport, import_, pobor, produkcja;

    if (iss >> date >> time >> autokonsumpcja >> eksport >> import_ >> pobor >> produkcja) {
        record = Record(date, time, autokonsumpcja, eksport, import_, pobor, produkcja);
        return true;
    }
    return false;
}
