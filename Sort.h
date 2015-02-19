

//I Ayne Delgado have not used any code other than my own (or that in the textbook) for this project.
//I also have not used any function or data-structure from the Standard-Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.


#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
using namespace std;

//The sort class

class Sort
{
private:
    //------------Private Data Members---------------
    int size;
    int* array;
    
    //----------------Private Methods------------------
    
    //merge function
    //Purpose: merges two sorted subarrays together from the merge_sort function
    //Parameters: an int array, an int size of sub array 1, an int size of sub array 2
    //Returns: none
    //pre-conditions: size>1
    //post-conditions: two sub arrays are sorted and merged together into one array
    void merge(int[], int, int);
    
    //merge_sort_helper fucntion
    //Purpose: recursively sorts an array by sorting two sub arrays then merges them
    //Parameters: an int array, an int: the array size
    //Returns: none
    //pre-condition: array size>1
    //post-condtion: the array is sorted
    void merge_sort_helper(int[], int);
    
    //swap function
    //Purpose: swap two integers in an array in order to sort the array;
    //---part of the function to selection_sort function
    //Parameters: two integers to swap
    //Returns: none
    //pre-condition: non-empty array
    //post-condtion: numbers in array are swaped, array will eventually be sorted
    void swap(int&, int&);
    
    //partition function
    //Purpose: sort the array using a pivot_index, part of the quick_sort function
    //Parameters: an int array, in int size of the array, an int the pivot_index
    //Returns: none
    //Pre-conditions: non-empty array
    //Post-conditons: numbers in the array are swaped based on the pivot, until the array is sorted
    void partition(int[], int, int&);
    
    //quick_sort_helper function
    //Purpose: recursive helper method of the quick_sort function
    //Parameters: an int array, an int size of the array
    //Returns: none
    //pre-conditions: non-empty array
    //post-conditions: the array is sorted
    void quick_sort_helper(int[], int);

public:
    //Parameterized constructor
    //Purpose: create an array of size passed
    //Parameters: an int, size of the array
    //Returns: none
    //Pre-conditions: none
    //Post-condtions: a Sort object is created, with a dynamically allocated array in it
    Sort(int);
    
    //Destructor
    //Purpose: return dynamically allocated memory to the heap
    //Parameters: none
    //Returns: none
    //Pre-conditions: none
    //Post-condtions: dynamically allocated array is deleted
    ~Sort();
    
    //insertion_sort function
    //Purpose: sort an arrray using insertion algorithm
    //Parameters: none
    //Returns: none
    //Pre-conditions: non empty array
    //Post-conditions: the array is sorted
    void insertion_sort();
    
    //selection_sort function
    //Purpose: sort an arrray using selection algorithm
    //Parameters: none
    //Returns: none
    //Pre-conditions: non empty array
    //Post-conditions: the array is sorted
    void selection_sort();
    
    //merge_sort function
    //Purpose: sort an arrray by sorting each half of an array and merging both halves in order
    //Parameters: none
    //Returns: none
    //Pre-conditions: non empty array
    //Post-conditions: the array is sorted
    void merge_sort();
    
    //quick_sort function
    //Purpose: sort an arrray using a pivot point (quick sort alogorithm)
    //Parameters: none
    //Returns: none
    //Pre-conditions: non empty array
    //Post-conditions: the array is sorted
    void quick_sort();
    
    //init_array fuction
    //Purpose: add random elements into an array/re-randomize an array
    //Parameters: none
    //Returns: none
    //pre-condition: size>0
    //post-condition: the array is filled with random, unsorted numbers
    void init_array();
    
    //get_size function
    //Purpose: returns the size of the array
    //Parameters: none
    //Returns: int, size of the array
    //Pre-conditions: none
    //Post-conditions: size of the array is known
    int get_size() const;
    
    //at function
    //purpose: get a value at a specific index of the array, used in the << overload
    //parameters: an unsigned int, index of the array
    //returns: an int, value at the index
    //pre-conditions: index<size
    //post-conditions: value at the index is known
    int at(unsigned) const;
    
};

//operator << overload
//purpose: use << to print out the array in a Sort object
//parameters: an ostream object, a sort object
//returns: an ostream object
//pre-conditions: a non-empty array
//post-conditions: values in the array are printed
ostream& operator<<(ostream&, const Sort&);



