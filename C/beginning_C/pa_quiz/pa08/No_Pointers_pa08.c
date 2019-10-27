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


void menu(void);
void printResult(int userInput[], size_t amount);
void getData(int userInput[], size_t *amount);
size_t count(const int userInput[], size_t amount);
size_t countMax(const int userInput[], size_t amount);
int countMin(const int userInput[], size_t amount);
double countMean(const int userInput[], size_t amount);
double countMedian(int userInput[], size_t amount);
void selectionSort(int userInput[], size_t amount);
int countFrequency(const int userInput[], size_t amount);
void countMode(const int userInput[], size_t amount);

int main(void) {
    // declare local variables for compute parking fare
    int userInput[100] = {0};      // user's choice for operation
    size_t amount = 0;

	getData(userInput, &amount);
	
	selectionSort(userInput, amount);
	
	printResult(userInput, amount);

    return 0;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
void printResult(int userInput[], size_t amount) {   
	printf("count:\t%zu", amount);
	printf("\nmin:\t%d", countMin(userInput, amount));
    printf("\nmax:\t%d", userInput[countMax(userInput, amount)]);	
	printf("\nmean:\t%1.1f", countMean(userInput, amount));	
	printf("\nmedian:\t%1.1f", countMedian(userInput, amount));
	printf("\nmode:\t");
	countMode(userInput, amount);
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
void getData(int userInput[], size_t *amount) {   
	while (scanf(" %d", &userInput[*amount]) != EOF) {
		if((*amount) < 100) {
			(*amount)++;
		}
    }
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
size_t count(const int userInput[], size_t amount) {
    size_t num = 0;
	
	for (size_t i = 0; i < amount; i++) {
        if(userInput[i + 1] != userInput[i]) {
            num++;
        }
    }
    return num;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
size_t countMax(const int userInput[], size_t amount) {
    size_t maxIndex = 0;
    for (size_t i = 0; i < amount; i++) {
        if(userInput[i] > userInput[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
int countMin(const int userInput[], size_t amount) {
    int min = INT_MAX;
    for (size_t i = 0; i < amount; i++) {
        if(userInput[i] < min) {
            min = userInput[i];
        }
    }
    return min;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
double countMean(const int userInput[], size_t amount) {
    double sum = 0;
    for (size_t i = 0; i < amount; i++) {
        sum += userInput[i];
    }
    return sum / (double)amount;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
double countMedian(int userInput[], size_t amount) {
    double median = INT_MAX;
	
	// selectionSort(userInput, amount);
	
	if((amount % 2) != 0) {
		median = userInput[amount / 2];
	} else {
		median = (userInput[(amount / 2) - 1] + 
			userInput[amount / 2]) / 2.0;
	}
	return median;
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
void selectionSort(int userInput[], size_t amount) {
    int temp = INT_MAX;    // store the first unsorted element for swap
	size_t smallest = 0;  // store the smallest index in unsorted array
	
    for (size_t i = 0; i < amount; i++) {
		smallest = i;
		for (size_t j = i + 1; j < amount; j++) { 
			if(userInput[smallest] > userInput[j]) {
				smallest = j;
			}
		}
		temp = userInput[i];
		userInput[i] = userInput[smallest];
		userInput[smallest] = temp;
    }
}

/// ----------------------------------------------------------------------
/// Validate the option input by user.
///
/// @param userInput        the data input by user for computing.
/// @param amount			the number of data input by user.
/// ----------------------------------------------------------------------
void countMode(const int userInput[], size_t amount) {
    int frequency[101] = {0};
	size_t num = count(userInput, amount);
	size_t maxIndex;
	
	frequency[0] = 1;
	
	for (size_t i = 0; i < amount; i++) {
        if(userInput[i + 1] != userInput[i]) {
            frequency[i + 1]++;
        } else {
			frequency[i]++;
		}
    }
	
	maxIndex = countMax(frequency, num);
	
	selectionSort(frequency, num);
	
	if((frequency[num - 1] == frequency[num - 2]) || 
		(frequency[num - 1] == 1)) {
		printf("n/a\n\n");
	} else {
		printf("%d\n\n", userInput[maxIndex]);
	}
}
