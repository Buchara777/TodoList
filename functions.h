#include <iostream>
#include <limits>


void requestEnter() {
    std::cout << "Press Enter to continue...";
    std::cin.get();
}


int getIntegerInput(bool tryAgain = false) {
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        if (tryAgain) {
            return getIntegerInput(tryAgain);
        } else {
            throw std::invalid_argument("Invalid input. Not an integer.");
        }
    }
    else {
        return value;
    }
}

int getIndexInput(bool tryAgain = false) {
    int index = getIntegerInput(tryAgain);
    if (index < 0) {
        std::cout << "Index cannot be negative. Please enter a valid index." << std::endl;
        if (tryAgain) {
            return getIndexInput(tryAgain);
        } else {
            throw std::invalid_argument("Invalid index");
        }
    }
    return index;
}