#ifndef DAMONDENG_TIMEUTILS
#define DAMONDENG_TIMEUTILS

#include <string>
#include <iostream>

using namespace std;

namespace ssccutils{

  class TimeUtils{  
    public:
      TimeUtils();
      static string getTime();
      static string getDayInWeek(int inputDay);
      static string getMonthInYear(int inputMonth);
  
  };
  
}

#endif