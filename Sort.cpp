//
//  Sort.cpp
//  sort
//
//  Created by Ayne Delgado on 2/15/15.

//I Ayne Delgado have not used any code other than my own (or that in the textbook) for this project.
//I also have not used any function or data-structure from the Standard-Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#include "Sort.h"

Sort::Sort(int aSize)
{
    size=aSize;
    array=new int[size];
}
Sort::~Sort()
{
    delete[] array;
    array=nullptr;
}
void Sort::init_array()
{
    assert(size>0);
    
    for(int i=0; i<size; i++)
    {
        array[i] = rand()%size;
    }
}
void Sort::merge(int data[], int n1, int n2)
{
    int* temp = new int [n1+n2];
    int copied =0;
    int copied1 = 0;
    int copied2 = 0;
    int i;
    while((copied1<n1)&&(copied2<n2))
    {
        if(data[copied1]<(data+n1)[copied2])
            temp[copied++] = data[copied1++];
        else
            temp[copied++] = (data+n1)[copied2++];
        
    }
    while(copied1<n1)
        temp[copied++]=data[copied1++];
    while(copied2<n2)
        temp[copied++]=(data+n1)[copied2++];
    for(i=0; i<n1+n2;++i)
        data[i]=temp[i];
    delete [] temp;

}
void Sort::merge_sort_helper(int data[], int n)
{
    int n1 = n/2;
    int n2 = n-n1;
    if(n>1)
    {
        
        merge_sort_helper(data, n1);
        merge_sort_helper((data+n1), n2);
        merge(data, n1, n2);
    }
    merge(data, n1, n2);
}

void Sort::merge_sort()
{
    assert(size>0);
    merge_sort_helper(array, size);
}

void Sort::insertion_sort()
{
    assert(size>0);
    for(int i=0; i<size-1; i++)
    {
        if(array[i+1]<array[i])
        {
            int temp = array[i+1];
            int insert = 0;
            
            while(temp>array[insert])
                insert++;
            for(int j=i+1; j>insert; j--)
                array[j]=array[j-1];
            
            array[insert]=temp;
            
        }
        
        
        
    }
    
}
void Sort::swap(int& a, int& b)
{
    int temp = a;
    a=b;
    b=temp;
    
}
void Sort::selection_sort()
{
    assert(size>0);
    int i, j, index_of_largest;
    int largest;
    if(size==0)
        return;
    for(i=size-1; i>0; --i)
    {
        largest=array[0];
        index_of_largest = 0;
        for(j=1; j<=i; ++j)
        {
            if(array[j]>largest)
            {
                largest=array[j];
                index_of_largest=j;
            }
            
        }
        swap(array[i], array[index_of_largest]);
    }
}
void Sort::partition(int data[], int n, int& pivot_index)
{
   
    int pivot=data[0];
    int left_index = 1;
    int right_index = n-1;
    while(left_index<=right_index)//while left hasnt crossed right
    {
        while(left_index<n && data[left_index]<=pivot)//find next largest
            left_index++;
        while(data[right_index]>pivot)//find next smallest
            right_index--;
        if(left_index<right_index)//if indecies haven't crossed, swap them
        {
            int temp = data[left_index];
            data[left_index]=data[right_index];
            data[right_index]=temp;
        }
    }
    pivot_index=right_index; //set pivot index
    
    //swap right_index and pivot
    data[0] = data[pivot_index];
    data[pivot_index]=pivot;
    
    
    
    
    
}
void Sort::quick_sort_helper(int data[], int n)
{
    int pivot_index; //array index for the pivot element
    int n1;//number of elements before the pivot element
    int n2;//number of elements after the pivot element
    if(n>1)
    {
        partition(data, n, pivot_index);
        n1=pivot_index;
        n2= n-n1-1;
        quick_sort_helper(data, n1);
        quick_sort_helper((data + pivot_index + 1), n2);
    }
}
void Sort::quick_sort()
{
    assert(size>0);
    quick_sort_helper(array, size);
}
int Sort::get_size()const
{
    return size;

}
int Sort::at(unsigned index) const
{
    assert(index<size);
    return array[index];
}
ostream& operator<<(ostream& out, const Sort& s)
{
    if(s.get_size()<0)
    {
        out<<"Empty array"<<endl;
        return out;
    }
    
    for(int i=0; i<s.get_size(); i++)
    {
        out<<s.at(i)<<endl;
    }
    return out;

}








