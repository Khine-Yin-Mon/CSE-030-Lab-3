#include <iostream>
#include "SortedList.h"

int main() {
    SortedList<int> list;

    // Append values to the list
    list.append(5);
    list.append(3);
    list.append(8);
    list.append(1);
    list.append(4);

    // Display the sorted list
    std::cout << "Sorted List: ";
    for (int i = 0; i < 5; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    // Search for values in the list
    int valuesToSearch[] = {3, 7, 8, 1, 10};
    for (int i = 0; i < 5; i++) {
        if (list.search(valuesToSearch[i])) {
            std::cout << valuesToSearch[i] << " is in the list." << std::endl;
        } else {
            std::cout << valuesToSearch[i] << " is not in the list." << std::endl;
        }
    }

    return 0;
}
