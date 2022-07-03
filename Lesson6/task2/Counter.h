#pragma once
class Counter {
public:
    
    void  plus();
    void minus();
    void ravno();
    void stop();
    
    
    Counter();
    Counter(int count);
protected:
    int count;
};
