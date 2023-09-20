#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "ArrayList.h"

template <typename T>
class SortedList : public ArrayList<T> {
    bool binarySearch(T value, int start, int end) const {
        if (start > end){
            return false;
        }

        int mid = (start + end) / 2;

        if (this->arr[mid] == value){
            return true;
        }
        else if (this->arr[mid] > value){
            return binarySearch(value, start, mid-1);
        }
        else{
            return binarySearch(value, mid+1, end);
        }
    }
public:
    void append(T value){
        this->arr[this->count] = value;
        

        int curr = this->count;
        while (curr > 0 && this->arr[curr] < this->arr[curr-1]){
            T temp = this->arr[curr];
            this->arr[curr] = this->arr[curr-1];
            this->arr[curr-1] = temp;
            curr--;
        }

        this->count++;
        if (this->count == this->capacity){
            this->inflate();
        }

    }

    bool search(T value) const {
        int lastIndex = this->count - 1;
        return binarySearch(value, 0, lastIndex);
    }

    // This needs to be here because of the unit tests
    friend struct TestSortedList;

};

#endif