/// @file clockType.h
/// @author Chane Li
/// @date 2019-09-06
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

    /// @brief Constructor with parameters.
    /// The time is set to passed in parameters.
    /// @post hr = hours; min = minutes; sec = seconds.
    clockType(int hours, int minutes, int seconds);

    /// functions prototypes
// ============================================================================
    /// @brief Function to set the hours.
    /// The hour variable hr is set to hours.
    /// @post hr = hours.
    /// @param hours  The number of hours in the time
    /// @see setTime
    void setHours(int hours);

    /// @brief Function to set the minutes.
    /// The minute variable min is set to minutes.
    /// @post min = minutes.
    /// @param minutes  The number of minutes in the time
    /// @see setTime
    void setMinutes(int minutes);

    /// @brief Function to set the seconds.
    /// The second variable sec is set to seconds.
    /// @post sec = seconds.
    /// @param seconds  The number of seconds in the time
    /// @see setTime
    void setSeconds(int seconds);

    /// @brief Function to set the time.
    /// The time is set to hours:minutes:seconds.
    /// @post hr = hours; min = minutes; sec = seconds.
    /// @param hours  The number of hours in the time
    /// @param minutes  The number of minutes in the time
    /// @param seconds  The number of seconds in the time
    /// @see setHours
    /// @see setMinutes
    /// @see setSeconds
    void setTime(int hours, int minutes, int seconds);

    /// @brief Function to increase 1 hour
    /// The hr = hr + 1
    /// @post hr++.
    void incrementHours();

    /// @brief Function to increase 1 minute
    /// The min = min + 1
    /// @post min++.
    void incrementMinutes();

    /// @brief Function to increase 1 second
    /// The sec = sec + 1
    /// @post sec++.
    void incrementSeconds();

    /// @brief Function to print the formatted time (HH:MM:SS).
    /// Output the formatted time as HH:MM:SS.
    /// @post hr, min, sec as HH:MM:SS.
    void printTime();

    /// @brief Function to return hours parameter
    /// Pass hr parameter to who call this funcion
    /// @post return hr
    int getHours() const { return hr; }

    /// @brief Function to return minutes parameter
    /// Pass min parameter to who call this funcion
    /// @post return min
    int getMinutes() const { return min; }

    /// @brief Function to return seconds parameter
    /// Pass sec parameter to who call this funcion
    /// @post return sec
    int getSeconds() const { return sec; }

    /// @brief Function to pass the time out
    /// Pass time(hr, min, sec) to who call this function
    /// by the passed in parameters hours, minutes and seconds
    /// @post hours = hr; minutes = min; seconds = sec.
    void getTime(int& hours, int& minutes, int& seconds) const;

    /// @brief Function to return elapsed time in seconds.
    /// Function to return elapsed time of a day in seconds.
    /// @post return (hr * 3600 + min * 60 + sec).
    int elapsed() const { return (hr * 3600 + min * 60 + sec); }

    /// @brief Function to return remaining time in seconds.
    /// Function to return remaining time of a day in seconds.
    /// @post return (86400 - hr * 3600 - min * 60 - sec).
    int remaining() const { return (86400 - hr * 3600 - min * 60 - sec); }

    /// @brief Function to output difference between two clocks.
    /// Determins and outputs how far apart in time two clocks are
    /// Outputs the time in the form of HH:MM:SS
    /// @post HH:MM:SS, HH=|hr1-hr2|, MM=|min1-min2|, SS=|sec1-sec2|.
    void diff(const clockType& other) const;

    /// @brief Function to determin if two clocks are equal.
    /// By checking the clock's hr, min and sec.
    /// @post hr1 == hr2; min1 == hr2; sec1 = sec2.
    bool equalTime(clockType& other);

private:
    int hr;   ///< instance variable to store the hours
    int min;  ///< instance variable to store the minutes
    int sec;  ///< instance variable to store the seconds
};

#endif  // CLOCKTYPE_H_

/* EOF */
