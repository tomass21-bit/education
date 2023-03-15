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



    class LogCommand {
    public:
        virtual ~LogCommand() = default;
        void warning(const std::string& message) const { mailer(message,"Warning"); }
        void error(const std::string& message) const { mailer(message,"Error"); }
        void fatalError(const std::string& message) const { mailer(message,"FatalError"); }

    
        void AddObserver(Observer* observer,const std::string& interest) {
            if (interest == "FatalError") {
                fatalerror_.push_back(observer);
            }
            else if(interest == "Error") {
                error_.push_back(observer);
            }
            else if (interest == "Warning") {
                warning_.push_back(observer);
            }
            
        }
        void RemoveObserver(Observer* observer, const std::string& interest) {
            if (interest == "FatalError") {
                auto it = std::remove(fatalerror_.begin(), fatalerror_.end(), observer);
            }
            else if (interest == "Error") {
                auto it = std::remove(error_.begin(), error_.end(), observer);
            }
            else if (interest == "Warning") {
                auto it = std::remove(warning_.begin(), warning_.end(), observer);
            }
            
        }
       
    private: 
        void mailer(const std::string& message, const std::string& interest) const {
            if (interest == "Warning") {
                for (auto t1 : warning_)
                {
                    t1->onWarning(message);
                }
            }
            else if (interest == "Error") {
            for (auto t2 : error_)
            {
                t2->onError(message);
            }
            }
            else if (interest == "FatalError") {
                for (auto t3 : fatalerror_)
                {
                    t3->onFatalError(message);
                }
            }
        }
        std::vector<Observer*> warning_;
        std::vector<Observer*> error_;
        std::vector<Observer*> fatalerror_;
        std::string message_;
};

    class Warning :public Observer {
    public:
        Warning(LogCommand& log): log_(log) {
            this->log_.AddObserver(this,"Warning");
        }
        void onWarning(const std::string& message) override {

            std::cout << message << std::endl;
        }
        ~Warning() {
            this->log_.RemoveObserver(this, "Warning");
        }
    private:
        LogCommand& log_;
    };

    class Error :public Observer {
    public:
        Error(LogCommand& log) : log_(log) {
        this->log_.AddObserver(this,"Error");
    }
        void onError(const std::string& message) override {

            std::ofstream fout("log.txt", std::ios::app);
            fout << message << std::endl;
            fout.close();
        }
        ~Error() {
            this->log_.RemoveObserver(this, "Error");
        }
    private:
        LogCommand& log_;

    };
    class FatalError :public Observer {
    public:
        FatalError(LogCommand& log) : log_(log) {
            this->log_.AddObserver(this, "FatalError");
        }
        void onFatalError(const std::string& message) override {
            std::cout << message << std::endl;
            std::ofstream fout("log.txt", std::ios::app);
            fout << message << std::endl;
            fout.close();
        }
        ~FatalError() {
            this->log_.RemoveObserver(this, "FatalError");
        }
    private:
        LogCommand& log_;
    };

int main()
{
    LogCommand l;
    FatalError f (l);
    Warning w(l);
    Error e(l);
    l.warning("Allarm ");
    
    l.error("error");
    return 0;
}