#include "TimeUtils.h"

#include <time.h>
#include <iostream>
#include <sstream>

using namespace std;

namespace ssccutils{

  TimeUtils::TimeUtils(){

  }

  string TimeUtils::getTime(){
    const time_t t = time(NULL);
    struct tm* current_time = gmtime(&t);

    ostringstream timeStream;
    
    timeStream << getDayInWeek(current_time->tm_wday);
    timeStream << ", ";
    timeStream << current_time->tm_mday;
    timeStream << " ";
    timeStream << getMonthInYear(current_time->tm_mon);
    timeStream << " ";
    timeStream << current_time->tm_year + 1900;
    timeStream << " ";
    timeStream << current_time->tm_hour;
    timeStream << ":";
    timeStream << current_time->tm_min;
    timeStream << ":";
    timeStream << current_time->tm_sec;
    timeStream << " ";
    timeStream << "GMT";

    return timeStream.str();

    //return "testing";
    
  }

  string TimeUtils::getDayInWeek(int inputDay){
    switch (inputDay){
      case 0:{
        return "Sun";
      }
      case 1:{
        return "Mon";
      }
      case 2:{
        return "Tues";
      }
      case 3:{
        return "Wed";
      }
      case 4:{
        return "Thur";
      }
      case 5:{
        return "Fri";
      }
      case 6:{
        return "Sat";
      }
    }
    return "Error";  
  }

  string TimeUtils::getMonthInYear(int inputMonth){
    switch (inputMonth){
      case 0:{
        return "Jan";
      }
      case 1:{
        return "Feb";
      }
      case 2:{
        return "Mar";
      }
      case 3:{
        return "Apr";
      }
      case 4:{
        return "May";
      }
      case 5:{
        return "Jun";
      }
      case 6:{
        return "Jul";
      }
      case 7:{
        return "Aug";
      }
      case 8:{
        return "Sep";
      }
      case 9:{
        return "Oct";
      }
      case 10:{
        return "Nov";
      }
      case 11:{
        return "Dec";
      }
    }
    return "Error";  
  }

}