void Tree::addRecord(const Record& record) {
    int year, month, day;
    sscanf(record.date.c_str(), "%d-%d-%d", &year, &month, &day);
    int quarter = getQuarter(record.time);

    years[year].months[month].days[day].quarters[quarter].records.push_back(record);
}

int Tree::getQuarter(const std::string& time) {
    int hour, minute;
    sscanf(time.c_str(), "%d:%d", &hour, &minute);

    if (hour < 6) return 0;
    else if (hour < 12) return 1;
    else if (hour < 18) return 2;
    else return 3;
}
