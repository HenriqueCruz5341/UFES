#include "Date.h"

#include <fstream>
#include <iostream>
#include <sstream>

Date::Date() {
}

Date::Date(const string& date_string) {
    string day, month, year;
    stringstream check1(date_string);
    getline(check1, day, '/');
    getline(check1, month, '/');
    getline(check1, year, '/');

    this->day = stoi(day);
    this->month = stoi(month);
    this->year = stoi(year);
}

int Date::calc_age(const Date& date_born, const Date& date_now) const {
    int age = 0;

    if (date_born.month > date_now.month) {
        age = -1;
    }
    if (date_born.month == date_now.month && date_born.day > date_now.day) {
        age = -1;
    }

    age = date_now.year - date_born.year + age;

    return age;
}

bool Date::operator<(const Date& date) const {
    int year = this->year - date.year;
    if (year == 0) {
        int month = this->month - date.month;
        if (month == 0) {
            return this->day < date.day;
        }
        return month < 0;
    }
    return year < 0;
}

string Date::to_string() const {
    string day = std::to_string(this->day) + "/";
    string month = std::to_string(this->month) + "/";
    string year = std::to_string(this->year);

    return day + month + year;
}

Date::~Date() {
}