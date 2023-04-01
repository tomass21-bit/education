#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};
//Созданы 3 отдельных клааса для соблюдения Принципа открытости\закрытости и разделения интерфейса.
class HTML : public Printable    
{
public:
    HTML(std::string data)
        : data_(std::move(data)){}

    std::string printAsHTML() const override    //Удалены исключения Принцип подстановки Лисков
    {
         return "<html>" + data_ + "<html/>";
    }
    void saveToAs(std::ofstream& file, const Printable& printable) {
        file << printable.printAsHTML();
    }
   private:
    std::string data_;
    
};

class Text : public Printable {
public:
    Text(std::string data): data_(std::move(data)) {}
    std::string printAsText() const override
    {
        return data_;
    }
    void saveToAs(std::ofstream& file, const Printable& printable) {
        file << printable.printAsText();
    }
private:
    std::string data_;
};

class JSON : public Printable {
public:
    JSON(std::string data) : data_(std::move(data)) {}
    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
    void saveToAs(std::ofstream& file, const Printable& printable) {
        file << printable.printAsJSON();
    }
private:
    std::string data_;
};








