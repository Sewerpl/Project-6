#include <gtest/gtest.h>
#include "lineData.hpp"
#include "treeData.hpp"
#include <sstream>

// Testy dla klasy LineData
class LineDataTest : public ::testing::Test {
protected:
    LineData lineData;
    
    void SetUp() override {
        // Inicjalizacja przykładowych danych
        lineData = LineData("01.01.2023 12:30", 100.0f, 50.0f, 30.0f, 120.0f, 80.0f);
    }
};

TEST_F(LineDataTest, GettersTest) {
    EXPECT_EQ(lineData.getDate(), "01.01.2023 12:30");
    EXPECT_FLOAT_EQ(lineData.getAutokonsumpcja(), 100.0f);
    EXPECT_FLOAT_EQ(lineData.getEksport(), 50.0f);
    EXPECT_FLOAT_EQ(lineData.getImport(), 30.0f);
    EXPECT_FLOAT_EQ(lineData.getPobor(), 120.0f);
    EXPECT_FLOAT_EQ(lineData.getProdukcja(), 80.0f);
}

TEST_F(LineDataTest, SerializeTest) {
    std::ostringstream oss;
    lineData.serialize(oss);
    EXPECT_EQ(oss.str(), "01.01.2023 12:30,100.0,50.0,30.0,120.0,80.0\n");
}

// Testy dla klasy TreeData
class TreeDataTest : public ::testing::Test {
protected:
    TreeData treeData;

    void SetUp() override {
        // Dodanie przykładowych danych do drzewa
        LineData lineData1("01.01.2023 12:30", 100.0f, 50.0f, 30.0f, 120.0f, 80.0f);
        LineData lineData2("01.01.2023 13:30", 110.0f, 55.0f, 35.0f, 130.0f, 85.0f);
        treeData.addData(lineData1);
        treeData.addData(lineData2);
    }
};

TEST_F(TreeDataTest, AddDataTest) {
    // Test dodawania danych
    const auto& years = treeData.getYears();
    ASSERT_EQ(years.size(), 1);  // Sprawdzamy, czy dodany został jeden rok
    const auto& year = years.begin()->second;
    ASSERT_EQ(year.months.size(), 1);  // Jeden miesiąc
    const auto& month = year.months.begin()->second;
    ASSERT_EQ(month.days.size(), 1);  // Jeden dzień
    const auto& day = month.days.begin()->second;
    ASSERT_EQ(day.quarters.size(), 2);  // Dwa kwartały
}

TEST_F(TreeDataTest, CalculateSumsBetweenDatesTest) {
    // Test obliczania sum dla danych w danym przedziale czasowym
    float autokonsumpcjaSum = 0.0f, eksportSum = 0.0f, importSum = 0.0f, poborSum = 0.0f, produkcjaSum = 0.0f;
    treeData.calculateSumsBetweenDates("01.01.2023 12:00", "01.01.2023 14:00", autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum);

    EXPECT_FLOAT_EQ(autokonsumpcjaSum, 210.0f);
    EXPECT_FLOAT_EQ(eksportSum, 105.0f);
    EXPECT_FLOAT_EQ(importSum, 65.0f);
    EXPECT_FLOAT_EQ(poborSum, 250.0f);
    EXPECT_FLOAT_EQ(produkcjaSum, 165.0f);
}

TEST_F(TreeDataTest, CalculateAveragesBetweenDatesTest) {
    // Test obliczania średnich dla danych w danym przedziale czasowym
    float autokonsumpcjaAvg = 0.0f, eksportAvg = 0.0f, importAvg = 0.0f, poborAvg = 0.0f, produkcjaAvg = 0.0f;
    treeData.calculateAveragesBetweenDates("01.01.2023 12:00", "01.01.2023 14:00", autokonsumpcjaAvg, eksportAvg, importAvg, poborAvg, produkcjaAvg);

    EXPECT_FLOAT_EQ(autokonsumpcjaAvg, 105.0f);
    EXPECT_FLOAT_EQ(eksportAvg, 52.5f);
    EXPECT_FLOAT_EQ(importAvg, 32.5f);
    EXPECT_FLOAT_EQ(poborAvg, 125.0f);
    EXPECT_FLOAT_EQ(produkcjaAvg, 82.5f);
}

TEST_F(TreeDataTest, CompareDataBetweenDatesTest) {
    // Test porównania danych dla dwóch przedziałów czasowych
    float autokonsumpcjaDiff = 0.0f, eksportDiff = 0.0f, importDiff = 0.0f, poborDiff = 0.0f, produkcjaDiff = 0.0f;
    treeData.compareDataBetweenDates("01.01.2023 12:00", "01.01.2023 14:00", "01.01.2023 12:30", "01.01.2023 13:30", autokonsumpcjaDiff, eksportDiff, importDiff, poborDiff, produkcjaDiff);

    EXPECT_FLOAT_EQ(autokonsumpcjaDiff, 10.0f);  // 110 - 100
    EXPECT_FLOAT_EQ(eksportDiff, 5.0f);         // 55 - 50
    EXPECT_FLOAT_EQ(importDiff, 5.0f);          // 35 - 30
    EXPECT_FLOAT_EQ(poborDiff, 10.0f);          // 130 - 120
    EXPECT_FLOAT_EQ(produkcjaDiff, 5.0f);       // 85 - 80
}

TEST_F(TreeDataTest, SearchRecordsWithToleranceTest) {
    // Test wyszukiwania danych z tolerancją
    auto result = treeData.searchRecordsWithTolerance("01.01.2023 12:00", "01.01.2023 14:00", 100.0f, 15.0f);
    
    ASSERT_EQ(result.size(), 2);  // Sprawdzamy, czy są dwa rekordy w przedziale
    EXPECT_FLOAT_EQ(result[0].getAutokonsumpcja(), 100.0f);
    EXPECT_FLOAT_EQ(result[1].getAutokonsumpcja(), 110.0f);
}
