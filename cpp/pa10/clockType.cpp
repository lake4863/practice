/// @file clockType.cpp
/// @author <AUTHOR>
/// @date <THE DATE>
/// @note I pledge my word of honor that I have abided by the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the implementation of class <code>clockType</code>.
/// @note

#include "clockType.h"

// using namespace std;

// ----------------------------------------------------------------------------

clockType::clockType() {
    hr = min = sec = 0;
}

// ----------------------------------------------------------------------------

clockType::clockType(int hours, int minutes, int seconds) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

// ----------------------------------------------------------------------------

void clockType::setHours(int hours) {
    if (hours >= 0 && hours <= 23 ) {
        hr = hours;
    } else {
        hr = 0;
    }
}

void clockType::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <= 59 ) {
        min = minutes;
    } else {
        min = 0;
    }
}

void clockType::setSeconds(int seconds) {
    if (seconds >= 0 && seconds <= 59 ) {
        sec = seconds;
    } else {
        sec = 0;
    }
}

void clockType::incrementHours() {
    hr++;

    if(hr == 24) {
        hr = 0;
    }
}

void clockType::incrementMinutes() {
    min++;

    if(min == 60) {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementSeconds() {
    sec++;

    if(sec == 60) {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::setTime(int hours, int minutes, int seconds) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

void clockType::printTime() {
    std::cout
    << std::setfill('0')
    << std::setw(2) << hr << ':'
    << std::setw(2) << min << ':'
    << std::setw(2) << sec;
}

int clockType::getHours() const {
    return hr;
}

int clockType::getMinutes() const {
    return min;
}

int clockType::getSeconds() const {
    return sec;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

int clockType::elapsed() const {
    return (hr * 3600 + min * 60 + sec);
}

int clockType::remaining() const {
    return (86400 - hr * 3600 - min * 60 - sec);
}

void clockType::diff(const clockType& other) const {
    int diff = (other.getHours() * 3600 +
                 other.getMinutes() * 60  +
                 other.getSeconds() - elapsed()
                );

    int diff_hours= ((diff >= 0) ?
        (other.getHours() - hr) :
        (hr - other.getHours()));

    int diff_minutes= ((diff >= 0) ?
        (other.getMinutes() - min) :
        (min - other.getMinutes()));

    int diff_seconds= ((diff >= 0) ?
        (other.getSeconds() - sec) :
        (sec - other.getSeconds()));

    if(diff_seconds < 0) {
        diff_seconds += 60;
        diff_minutes--;
        if(diff_minutes < 0) {
            diff_minutes += 60;
            diff_hours--;
        }
    }

    if(diff_minutes < 0) {
        diff_minutes += 60;
        diff_hours--;
    }

    std::cout
    << std::setfill('0')
    << std::setw(2) << diff_hours << ':'
    << std::setw(2) << diff_minutes << ':'
    << std::setw(2) << diff_seconds;
}

bool clockType::equalTime(clockType& other) {
    return (getHours() == other.getHours() &&
            getMinutes() == other.getMinutes() &&
            getSeconds() == other.getSeconds()
            )? true : false;
}

// ----------------------------------------------------------------------------

/* EOF */

int main() {
    int hr = 0;
    int min = 0;
    int sec = 0;

    std::cout
    << std::setfill('0')
    << std::setw(2) << hr << ':'
    << std::setw(2) << min << ':'
    << std::setw(2) << sec << std::endl
    << std::endl;

    //~ clockType clock1(1, 2, 3);
    //~ clockType clock2(00, 59, 30);

    clockType clock1(0, 0, 0);
    clockType clock2(23, 59, 59);

    clock1.diff(clock1);    // output captured in our buffer
    std::cout << std::endl;
    clock2.diff(clock2);
    std::cout << std::endl;
    clock1.diff(clock2);
    std::cout << std::endl;
    clock2.diff(clock1);
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}
