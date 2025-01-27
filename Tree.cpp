void Tree::addRecord(const Record& record) {
    int year, month, day;
    sscanf(record.date.c_str(), "%d-%d-%d", &year, &month, &day);
    int quarter = getQuarter(record.time);

    years[year].months[month].days[day].quarters[quarter].records.push_back(record);
}

