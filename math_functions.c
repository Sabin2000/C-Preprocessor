#include "math_functions.h"

#define X 100
#define Y 50
#define Z 25
#define PI 3.142
#define E 2.71828
#define SPEED_OF_LIGHT 299792458 

#include "string_functions.h"

// Sums two integers.
// Parameters: a, the first integer; b the second integer.
// Returns: the sum.
int add(int a, int b) 
{
    return a + b; // An inline comment.
}

// Subtracts an integer from a preprocessor defined constant.
// Parameters: n, the integer to subtract.
// Returns: the constant - n.
int subtract_from_const(int n) 
{
    return X - n;
}

// Multiplies an integer by a preprocessor defined constant.
// Parameters: n, the integer to multiply.
// Returns: the constant * n.
int multiply_by_const(int n) 
{
    return Y * n;
}

// Divides an integer by a preprocessor defined constant.
// Parameters: n, the integer to divide.
// Returns: the constant / n.
double divide_by_const(int n) 
{
    return (double) Z / n;
}

// Calculates the average of an array of integers.
// Parameters: size, the number of elements in the array; array, the array.
// Returns: the mean of the elements in array.
double average(int size, int *array) 
{
    int total = 0; // Store a running total.
    for(int i=0; i<size; i++) 
    {
        total += array[i];
    }
    return (double)total/size;
}

// Calculates the area of a circle.
// Parameters: radius, the radius of the circle.
// Returns: the area.
double area_of_circle(double radius)
{
    return radius * radius * PI ;
}

int light_speed()
{
    return SPEED_OF_LIGHT ;
}
