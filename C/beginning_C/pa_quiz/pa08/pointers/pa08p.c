/// Copyright [2019] <Chane Li>
/// @file <pa08.c>
/// @author <Chane Li>
/// @date <Oct 10th, 2019>
/// @note I pledge my word of honor that I have abided by the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Compute maximum, minimum, mean, median, mode.
/// @note Time taken to develop, write, test and debug solution: 6 hour.

#include <stdio.h>
#include <limits.h>
#include <math.h>
#define SIZE_OF_ARRAY    100        // size of the array container
#define SIZE_OF_INTEGER    4        // size of the integer in this system

void menu(void);
void printResult(int *userInput, int *end, char *str);
// void getData(int *userInput, int *end);
size_t count(int *userInput, int *end);
int countMax(const int *userInput, const int *end);
int countMin(const int *userInput, const int *end);
double countMean(int *userInput, int *end);
double countMedian(int *userInput, int *end);
void selectionSort(int *userInput, int *end);
int countFrequency(int *userInput, int *end);
char* countMode(int *userInput, int *end, char *str);
void swap(int *lhs, int *rhs);

int main(void) {
    // declare local variables for computing
    int userInput[SIZE_OF_ARRAY] = {0};    // user's choice for operation
    int *end = userInput;                // mark possible end of the array
    char str[42];                        // store return value from countMode

    while (scanf("%d", end) == 1) {
        printf("\n2__________%d", *end);
        if (end < (userInput + SIZE_OF_ARRAY)) {
            end++;
        }
    }

    printf("__________%d", userInput[4]);

    selectionSort(userInput, end);

    printResult(userInput, end, str);

    return 0;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
void printResult(int *userInput, int *end, char *str) {
    printf("\ncount:\t%ld\n", (end - userInput) / SIZE_OF_INTEGER);
    printf("\nmin:\t%d", countMin(userInput, end));
    printf("\nmax:\t%d", countMax(userInput, end));
    printf("\nmean:\t%1.1f", countMean(userInput, end));
    printf("\nmedian:\t%1.1f", countMedian(userInput, end));
    printf("\nmode:\t%s\n\n", countMode(userInput, end, str));
}

/// ----------------------------------------------------------------------
/// Get the numbers value and end from user.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
// void getData(int *userInput, int *end) {
//     while (scanf("%d", end) != EOF) {
//         printf("\n2------%d", *end);
//         if (end < (userInput + SIZE_OF_ARRAY)) {
//             end++;
//         }
//     }
// }

/// ----------------------------------------------------------------------
/// Count the end of different values from user.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
size_t count(int *userInput, int *end) {
    size_t num = 0;

    while (userInput < end) {
        if (*(userInput + 1) != *userInput) {
            num++;
        }
        userInput++;
    }
    return num;
}

/// ----------------------------------------------------------------------
/// Count the maximum value from user's input.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
int countMax(const int *userInput, const int *end) {
    int max = INT_MIN;

    while (userInput < end) {
        if (*userInput > max) {
            max = *userInput;
            userInput++;
            printf("max===%d", max);
        }
    }
    return max;
}

/// ----------------------------------------------------------------------
/// Count the minimum value from user's input.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
int countMin(const int *userInput, const int *end) {
    int min = INT_MAX;
// printf("min==%d, userInput==%d", min, *userInput);
    while (userInput < end) {
        if (*userInput < min) {
            min = *userInput;
        }
        userInput++;
    }
    return min;
}

/// ----------------------------------------------------------------------
/// Count the average value computed based on user's input
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
double countMean(int *userInput, int *end) {
    int sum = 0;
    while (userInput < end) {
        sum += *userInput;
        userInput++;
    }
    return (double)sum / (double)((end - userInput) / SIZE_OF_INTEGER);
}

/// ----------------------------------------------------------------------
/// Count the mean value from user's input
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
double countMedian(int *userInput, int *end) {
    int size = (int)((end - userInput) / SIZE_OF_INTEGER);    // size of array
    double median = (double)(*(userInput + size / 2) + *(end - size / 2))
        / 2.0;

    return median;
}

/// ----------------------------------------------------------------------
/// Sort array of integer from smallest to biggest using selection sort.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
void selectionSort(int *userInput, int *end) {
    int *smallest = NULL;  // store the smallest index in unsorted array
    int size = (int)((end - userInput)); // SIZE_OF_INTEGER);    // size of array

    for (int i = 0; i < size; i++) {
        int min = countMin(userInput + i + 1, end);
        smallest = &min;
        swap((userInput + i), smallest);
    }
}

/// ----------------------------------------------------------------------
/// Count the mode of an array of integer input by user.
///
/// @param userInput    the data input by user for computing.
/// @param end            the end of the userInput array.
/// ----------------------------------------------------------------------
char* countMode(int *userInput, int *end, char *str) {
    int frequency[101] = {0};
    int* maxAddress = NULL;
    size_t num = count(userInput, end);
    int size = (int)((end - userInput) / SIZE_OF_INTEGER);    // size of array


    frequency[0] = 1;

    for (int i = 0; i < size; i++) {
        if (userInput[i + 1] != userInput[i]) {
            frequency[i + 1]++;
        } else {
            frequency[i]++;
        }
    }

    int max = countMax(frequency, &frequency[num - 1]);
    maxAddress = &max;

    selectionSort(frequency, &frequency[num - 1]);

    if ((frequency[num - 1] == frequency[num - 2]) ||
        (frequency[num - 1] == 1)) {
        *str = 'n';
        *(str + 1) = '/';
        *(str + 2) = 'a';
    } else {
        sprintf(str, "%d", *maxAddress);
    }
    return str;
}

/// ----------------------------------------------------------------------
/// Swap two items through these two elements' address
///
/// @param lhs    the left hand side data need swap.
/// @param rhs    the right hand side data need swap.
/// ----------------------------------------------------------------------
void swap(int *lhs, int *rhs) {
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}
