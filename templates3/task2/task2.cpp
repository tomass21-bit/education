#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};
class Warning :public Observer {
public:
     void onWarning(const std::string& message) override {

        std::cout << message << std::endl;
    }
};

class Error :public Observer {
public:
    void onError(const std::string& message) override {
       
        std::ofstream fout("log.txt", std::ios::app);
        fout << message << std::endl;
        fout.close();
    }

};
class FatalError:public Observer {
public:
    void onFatalError(const std::string& message) override {
        std::cout << message << std::endl;
        std::ofstream fout("log.txt", std::ios::app);
        fout << message << std::endl;
        fout.close();
    }

    class LogCommand {
    public:
        virtual ~LogCommand() = default;
        void warning(const std::string& message) const { };
        void error(const std::string& message) const {  };
        void fatalError(const std::string& message) const {  };

    
        void AddObserver(Observer* observer) {
            observers_.push_back(observer);
        }
        void RemoveObserver(Observer* observer) {
            auto it = std::remove(observers_.begin(), observers_.end(), observer);
        };
        
        std::vector<Observer*> observers_;
        
        
};



int main()
{
    LogConsole l;
    print(l, "halt process");
    LogFile f;
    print(f, "error flag");
    return 0;
}