#include "Counter.h"
#include <iostream>
    



    void Counter:: plus() {
        count++;
    }
    void Counter::minus() {
        count--;
    }
    void Counter::ravno() {
        std::cout << count << std::endl;
    }
    void Counter::stop() {
        std::cout << "До свидания!" << std::endl;

    }
    void Counter:: set(int count) {
        this->count = count;

    }
    Counter::Counter() {
        count = 0;

    }


