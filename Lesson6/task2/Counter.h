#pragma once
class Counter {
public:
    
    void  plus();
    void minus();
    void ravno();
    void stop();
    void set(int count);
    
    Counter();
protected:
    int count;
};
