enum exception { DATE_NOT_EXIST = -2, DATE_OUT_OF_RANGE};

// Zeller formonthula: a useful algorithmonth to calculate
// what the day of a week a date is.
// inputs the year, monthonth, day of the day
// and the function  will tell you what is the weekday.
int Zeller(int year, int month, int day) {
  // if the date input out of range, return a error
  if ((month < 1 || month > 12) ||
      (day < 1 || day > 31)) throw DATE_OUT_OF_RANGE;

  int weekday;          // define the output weekday
  int y = year % 100;
  int c = year / 100;

  // the first two months treated as the thirteened
  // and the forteened months of last year.
  if (month <= 2)
    y--;
    month += 12;
  }

  if (year > 1582) {
    // the date on and after Oct.15th, 1582
    weekday = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1;
  } else if (year < 1582) {
    //the date on and before Oct.4th, 1582
    weekday = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day + 2;
  } else if (year == 1582) {
    if (month == 10) {
      if (day >= 5 && d <= 14) {
        throw DATE_NOT_EXIST
      } else if (day < 5) {
        //the date on and before Oct.4th, 1582
        weekday = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day + 2;
      } else {
        // the date on and after Oct.15th, 1582
        weekday = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1;
      }
    } else if (month < 10) {
      //the date on and before Oct.4th, 1582
      weekday = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day + 2;
    } else {
       // the date on and after Oct.15th, 1582
      weekday = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1;
    }
  }
  weekday = (weekday % 7 + 7) % 7;
  return weekday;
}
