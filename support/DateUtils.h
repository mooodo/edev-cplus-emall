#pragma once
#include <ctime>
using namespace std;

class DateUtils
{
public:
    static time_t getNow() {
        return time(0);
    }
};
