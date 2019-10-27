#!/bin/bash
#===========================================================================
#
#          FILE:  test-pa08.sh
#         USAGE:  ./test-pa08.sh
#
#   DESCRIPTION:  This script tests programming assignment pa08, FALL 2019
#
#       VERSION:  0.1.1
#       CREATED:  10/13/2019 15:04:30 PDT
#      REVISION:  1
#===========================================================================

PROJECT='pa08'                              # the project identifier
DIALECT='c'
export CFLAGS='-std=c99 -Weverything'       # used by make
export CXXFLAGS='-std=c++14 -Weverything'   # used by make
LOGFILE=/dev/null                           # log file
LINE=$(printf "%.s=" $(seq 80))             # construct a dashed line
ERRORFILE=ERRORS.txt                        # compiler warnings and errors

export count=0                              # count of tests completed
export score=42                             # correctness point accumulator
export style=20                             # style point accumulator

# Colorful output
_red=$(tput setaf 1)
_green=$(tput setaf 2)
_orange=$(tput setaf 3)
# _blue=$(tput setaf 4)
# _purple=$(tput setaf 5)
# _cyan=$(tput setaf 6)
# _white=$(tput setaf 7)
_reset=$(tput sgr0)

# Logging functions
log() {
    printf "${_green}%b${_reset}\n" "$*"
    printf "\n%b\n" "$*" >>"$LOGFILE"
}
logstdout() {
    printf "${_green}%b${_reset}\n" "$*" 2>&1 
}
warn() {
    printf "${_orange}%b${_reset}\n" "$*"
    printf "%b\n" "$*" >>"$LOGFILE"
}
fail() {
    printf "${_red}ERROR: %s${_reset}\n" "$*"
    printf "ERROR: %s\n" "$*" >>"$LOGFILE"
}

#===========================================================================

### Appends a value to an array.
### \param $1 Name of the variable to modify
### \param $2 Value to append

append() {
    eval $1[\${#$1[*]}]=$2
}

#===========================================================================

### Checks input file to verify it exists and is of the correct file type.
### Displays a warning message if CRLF line endings are detected.
### Terminates script if file not found or wrong type.

check_file_type() {
    logstdout "Checking $PROJECT.$DIALECT file type..."
    ftype=$(file $PROJECT.$DIALECT)
    sys_type=$(uname)

    if [ "$sys_type" = 'Linux' ]; then
        target='C source'                 # Linux
    elif [ "$sys_type" = 'Darwin' ]; then
        target='program text'               # Darwin
    fi

    grep -q "$target" <<< "$ftype"
    if [ $? -ne 0 ]; then
        # unexpected file type or file not found
        { fail "$ftype"; exit 1; }
    else
        # check for CRLF line endings
        grep -q 'CRLF' <<< "$ftype"
        if [ $? -eq 0 ]; then
            warn 'WARNING: CRLF line terminator(s) detected.'
            ((style -= 2))
        fi
    fi
}

#===========================================================================

### Check if source code has items required by syllabus:
### (1) author's name,  and (2) academic integrity statement
### Terminates script if either item not found.

check_syllabus_reqs() {
    logstdout 'Checking syllabus requirements...'
    cpplint --filter="-,+legal/copyright" --counting=total --quiet "$PROJECT.$DIALECT"
    [ $? -ne 0 ] && { fail 'Syllabus requirements not met.'; exit 1; }
}

#===========================================================================

### Run a variety of static analysis tools on the source code

run_static_analysis() {
    logstdout 'Performing static analysis...'
    logstdout 'Counting lines of code'
    cloc --by-file --quiet --by-percent='cmb' "$PROJECT.$DIALECT" | sed -n '3,$p'
    logstdout 'Looking for potential bugs'
    cppcheck --std=c99 --language=c --enable=all "$PROJECT.$DIALECT"
    logstdout 'Looking for style issues'
    cpplint --filter="-build/namespaces" --counting=total --quiet \
        --filter=-readability/casting,-runtime/int "$PROJECT.$DIALECT"
    ((style -= $?))                 # subtract points from style score
    logstdout 'Looking for potentially misspelled words:'
    aspell --list <"$PROJECT.$DIALECT" | sort | uniq -c | column
}

#===========================================================================

### Compiles and builds the executable. Uses Makefile if located in the same
### directory, else uses default make rules for file type. Relies upon
### exported $CXXFLAGS defined above. Terminates script on make failure.

build_executable() {
    logstdout 'Building executable...'
    [ -f $PROJECT.o ] && rm -f $PROJECT.o >/dev/null
    make "$PROJECT" 2>&1 >/dev/null | tee "$ERRORFILE"
    ((score -= $(grep -c ': warning:' "$ERRORFILE") * 2))
    [ -s "$ERRORFILE" ] || rm -f "$ERRORFILE"
}

#===========================================================================

### Runs one test case and compares program's output with expected output.
### Note: This function is specific to grading pa02. The last line of output
### is compared for equality with the expected output.

run_test() {
    ((++count))
    logstdout "Running test $count..."

    # run program and save output
    output=$(./"$PROJECT" <<< "$1")
    echo -e "Your program's output:\n$output\n"
    # check program's output
    grep " $2$" <<< "$output" | grep -q "count"
    if [ $? -ne 0 ]; then
        fail "count incorrect" 
        ((score -= 1))
    else
        logstdout "Count correct."
    fi
    grep " $3$" <<< "$output" | grep -q "min"
    if [ $? -ne 0 ]; then
        fail "min incorrect" 
        ((score -= 1))
    else
        logstdout "min correct."
    fi
    #~ ([ $? -ne 0 ] && { fail "min incorrect" ; ((score -= 1)); })    || logstdout "Min correct."
    grep " $4$" <<< "$output" | grep -q "max"
    if [ $? -ne 0 ]; then
        fail "max incorrect" 
        ((score -= 1))
    else
        logstdout "max correct."
    fi
    #~ ([ $? -ne 0 ] && { fail "max incorrect" ; ((score -= 1)); })    || logstdout "Max correct."
    grep " $5$" <<< "$output" | grep -q "mean"
    if [ $? -ne 0 ]; then
        fail "mean incorrect" 
        ((score -= 1))
    else
        logstdout "mean correct."
    fi
    #~ ([ $? -ne 0 ] && { fail "mean incorrect" ; ((score -= 1)); })   || logstdout "Mean correct."
    grep " $6$" <<< "$output" | grep -q "median"
    if [ $? -ne 0 ]; then
        fail "median incorrect" 
        ((score -= 1))
    else
        logstdout "median correct."
    fi
    #~ ([ $? -ne 0 ] && { fail "median incorrect" ; ((score -= 2)); }) || logstdout "Median correct."
    grep " $7$" <<< "$output" | grep -q "mode"
    if [ $? -ne 0 ]; then
        fail "mode incorrect" 
        ((score -= 1))
    else
        logstdout "mode correct."
    fi
    #~ ([ $? -ne 0 ] && { fail "mode incorrect" ; ((score -= 2)); })   || logstdout "Mode correct."
    echo
}

#===========================================================================

### Build and test a project

main() {
    # validate file
    check_file_type "$PROJECT.$DIALECT"
    check_syllabus_reqs "$PROJECT.$DIALECT"

    # lint and build
    run_static_analysis
    build_executable

    # run tests
    logstdout "Running tests on $PROJECT $(date)"
    run_test '1 2 3 9 8 7 4 6 5' 9 1 9 5.0 5.0 'n/a'
    run_test '10 1 2 3 9 8 7 4 6 5' 10 1 10 5.5 5.5 'n/a'
    run_test '10 1 2 3 9 8 7 4 6 5 10' 11 1 10 5.9 6.0 10
    run_test '39 37 79 90 24 51 55 16 12 41 78 30 88 69 97 1 75 2 36 38 57 76 67 33 7 65 101 31 68 71 77 59 34 64 80 70 35 48 93 82 23 99 11 62 8 10 17 89 92 54 22 98 47 13 18 19 44 40 50 73 72 91 46 49 20 15 21 94 28 45 87 66 81 96 86 100 43 6 25 9 56 5 3 74 26 61 84 32 63 85 27 14 53 60 83 58 95 4 29 52 42' 100 1 101 51.1 51.5 'n/a'
    run_test '39 37 79 90 24 51 55 16 12 41 78 30 88 69 97 1 75 2 36 38 57 76 67 33 7 65 101 31 68 71 77 59 34 64 80 70 35 48 93 82 23 99 11 62 8 10 17 89 92 54 42 98 47 13 18 19 44 40 73 72 91 46 49 20 15 21 94 28 45 87 66 81 96 86 100 43 6 25 9 56 5 3 74 26 61 84 32 63 85 27 14 53 60 83 58 95 4 29 52 42' 100 1 101 51.2 51.5 42
    run_test '39 37 79 90 24 51 55 16 12 41 78 30 88 69 97 1 75 2 36 38 57 76 67 33 7 65 101 31 68 71 77 59 34 64 80 70 35 48 93 82 23 99 11 62 8 10 17 89 92 54 42 98 47 13 18 19 44 40 73 72 91 46 49 20 15 21 94 28 45 87 66 81 96 86 43 6 25 9 56 5 3 74 26 61 84 32 63 85 27 14 53 60 83 58 95 4 29 52 42' 99 1 101 50.7 51.0 42

    # compute and display correctness score (see rubric)
    echo "$LINE"
    # [ $score -eq 39 ] && ((++score))    # round up to 40
    ((score = 40 * score / 42))
    [ $style -lt 0 ] && style=0         # not below zero
    logstdout "Date:    $(date)"
    logstdout "Project: $PROJECT"
    logstdout "Author:  $(grep '@author' $PROJECT.$DIALECT | sed 's/^.\+@author //')"
    logstdout "Score:   $score/40 ($((100 * score / 40))%)"
    logstdout "Style:   $style/20 ($((100 * style / 20))%)"
}

#===========================================================================

# execute grading script
time main

# EOF

