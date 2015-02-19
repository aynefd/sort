//
//  main.cpp
//  sort
//
////I Ayne Delgado have not used any code other than my own (or that in the textbook) for this project.
//I also have not used any function or data-structure from the Standard-Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.
//

#include <iostream>
#include <ctime>
#include "Sort.h"
using namespace std;

//----------------------CONSTANTS----------------------
int const BIG = 1000;
int const GIANT = 1000;
double const SEC_TO_MILLISEC=1000;
int const PRECISION = 3;

int main()
{
    
    
    Sort sort1(BIG);
    sort1.init_array();
    
    Sort sort2(BIG);
    sort2.init_array();
    
    Sort sort3(BIG);
    sort3.init_array();
    
    Sort sort4(BIG);
    sort4.init_array();
    
    
    clock_t start1 = clock();
    for(int i = 0; i<GIANT; i++)
    {
        sort1.init_array();
        sort1.insertion_sort();
    }
    clock_t end1 = clock();
    clock_t diff1 = end1-start1;
    
    
 
    clock_t start2 = clock();
    for(int i = 0; i<GIANT; i++)
    {
        sort2.init_array();
        sort2.selection_sort();
    }
    clock_t end2 = clock();
    clock_t diff2 = end2-start2;

    clock_t start3 = clock();
    for(int i = 0; i<GIANT; i++)
    {
        sort3.init_array();
        sort3.merge_sort();
    }
    clock_t end3 = clock();
    clock_t diff3 = end3-start3;

    clock_t start4 = clock();
    for(int i =0; i<GIANT; i++)
    {
        sort4.init_array();
        sort4.quick_sort();
    }
    clock_t end4 = clock();
    clock_t diff4 = end4-start4;
    
    //calculate clocks per tick to milliseceonds for one loop per sort
    double time1 = ((((double)diff1)/CLOCKS_PER_SEC)*SEC_TO_MILLISEC)/GIANT;
    double time2 = ((((double)diff2)/CLOCKS_PER_SEC)*SEC_TO_MILLISEC)/GIANT;
    double time3 = ((((double)diff3)/CLOCKS_PER_SEC)*SEC_TO_MILLISEC)/GIANT;
    double time4 = ((((double)diff4)/CLOCKS_PER_SEC)*SEC_TO_MILLISEC)/GIANT;
    
    //show 3 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(PRECISION);
    
    //display time each sort took for 1 loop in milliseconds for an array of size sort.get_size
    
    cout<<"The insertion sort took: "<<time1<<" milliseconds, for an array of size "<< sort1.get_size() <<endl;
    cout<<"The selection sort took: "<<time2<<" milliseconds, for an array of size "<< sort2.get_size() <<endl;
    cout<<"The merge sort took: "<<time3<<" milliseconds, for an array of size "<< sort3.get_size() <<endl;
    cout<<"The quick sort took: "<<time4<<" milliseconds, for an array of size "<< sort4.get_size();
    
    cout<<endl;
    
    //system("PAUSE");
    return 0;
    
}



















