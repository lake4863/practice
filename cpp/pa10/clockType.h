/// @file clockType.h
/// @author <YOUR NAME>
/// @date <THE DATE>
/// @note I pledge my word of honor that I have abided by the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for class <code>clockType</code>.
/// @note

#ifndef CLOCKTYPE_H_
#define CLOCKTYPE_H_
#include <stdio.h>
#include <iostream>
#include <iomanip>

class clockType {
public:
    /// @brief Default constructor.
    /// The time is set to 00:00:00.
    /// @post hr = 0; min = 0; sec = 0.

    clockType();

    clockType(int hours, int minutes, int seconds);

    /// functions prototypes
// ============================================================================
    ///
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    void setTime(int hours, int minutes, int seconds);
    void incrementHours();
    void incrementMinutes();
    void incrementSeconds();

    void printTime();
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void getTime(int& hours, int& minutes, int& seconds) const;
    int elapsed() const;
    int remaining() const;
    void diff(const clockType& other) const;
    bool equalTime(clockType& other);

private:
    int hr;   ///< instance variable to store the hours
    int min;  ///< instance variable to store the minutes
    int sec;  ///< instance variable to store the seconds
};

#endif  // CLOCKTYPE_H_

/* EOF */
