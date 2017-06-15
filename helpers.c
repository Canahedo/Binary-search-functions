/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"


/**
 * Binary search function
 * Array values[] must be sorted.
 */
bool binsearch(int value, int values[], int l, int r){
    
    // Sets middle point
    int m = (r + l) / 2;
    
    // If left, mid, or right point equals value, return true
    if (values[m] == value){
        return true;
    }    
    if (values[l] == value){
        return true;
    }
    if (values[r] == value){
        return true; 
    }
    
    // If mid point is also left or right point, return false
    if (m == l){
        return false;
    }
    if (m == r){
        return false;
    }
    
    // Adjust bounderies and binsearch again
    if (value > values[m]){
        l = m + 1;
    }else if (value < values[m]){
        r = m - 1;
    }
    if (binsearch(value, values, l, r)){
        return true;
    }
    
    // Else return false
    return false;
}


/**
 * Sets up for binsearch
 * 
 */
bool search(int value, int values[], int n){
    
    // Ensures a positive number of values
    if (n < 0){
        return false;
    }
    
    // Sets initial left and right point
    int l = 0;
    int r = n - 1;
    
    // Run binsearch
    if (binsearch(value, values, l, r)){
        return true;
    }
    
    // Else return false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    // Finds largest number in values[]
    int max_int = 0;
    for (int i = 0; i < n; i++){
        if (values[i] > max_int){
            max_int = values[i];
        }
    }
    
    int array[max_int + 1]; // Placeholder array for moving around numbers
        memset(array, 0, sizeof array); // Sets all values in array[] to 0
    int count = 0; // Keeps track of what place of values[] is being changed
    
    // Make array[i] = the number of times i appears in values[]
    for (int i = 0; i < n; i++){
        array[values[i]]++;
    }
    
    // Increments values[count] by array[i] times.
    for (int i = 0; i < (max_int + 1) ; i++){
        while (array[i] > 0){
            values[count] = i;
            array[i]--;
            count++;
        }
    }
    return;
}
