//I Ayne Delgado have not used any code other than my own (or that in the textbook) for this project.
//I also have not used any function or data-structure from the Standard-Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.


#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
using namespace std;

class Sort
{
private:
    int size;
    int* array;
    void merge(int[], int, int);
    void merge_sort_helper(int[], int);
    void swap(int&, int&);
    void partition(int[], int, int&);
    void quick_sort_helper(int[], int);

public:
    Sort(int);
    ~Sort();
    void insertion_sort();
    void selection_sort();
    void merge_sort();
    void quick_sort();
    void init_array();
    int get_size() const;
    int at(unsigned) const;
    
};
ostream& operator<<(ostream&, const Sort&);
