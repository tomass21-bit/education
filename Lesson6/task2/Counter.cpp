#include "Counter.h"
#include <iostream>
    



Counter::Counter() {
    count = 0;

}
Counter::Counter(int count) {
    this->count = count;
}



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
    
    

