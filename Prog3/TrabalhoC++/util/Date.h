#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
   private:
    int day;
    int month;
    int year;

   public:
    Date();

    Date(const string& date_string);

    int calc_age(const Date& date_born, const Date& date_now) const;

    bool operator<(const Date& date) const;

    string to_string() const;

    ~Date();
};

#endif  //DATE_H
