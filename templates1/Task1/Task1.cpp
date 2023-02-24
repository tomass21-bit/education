// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "map"
#include <queue>
#include "iostream"
#include <vector>

class SQL {
public:
    
    std::queue <std::string> column;
    std::string from;
    std::map<std::string, std::string>where;
    std::string znak= "=";
};

class SqlSelectQueryBuilder {
    
public:
    SqlSelectQueryBuilder(){};
    SqlSelectQueryBuilder& AddColumn(const std::string& col) {
        sql.column.push(col);
        return *this;
    }
    SqlSelectQueryBuilder& AddFrom(const std::string& form) {
        sql.from = form;
        return *this;
    }
    SqlSelectQueryBuilder& AddWhere(const std::string& id, const std::string& vol) {
        sql.where[id] = vol;
        return *this;
    }
    void BuildQuery() {
        if (sql.column.empty()) {
            sql.column.push(" * ");
        }
        else
            std::cout << '"' << "SELECT ";
        while (!sql.column.empty()) {
            if (sql.column.size() == 1) {
                std::cout << sql.column.front();
                sql.column.pop();
            }
            else {
                std::cout << sql.column.front() << ", ";
                sql.column.pop();
            }
        }
        std::cout << " FROM " << sql.from << " WHERE ";
        for (auto it = sql.where.begin(); it != sql.where.end();++it) {
            auto itend = sql.where.end();
            itend--;
            if (it== itend) {
                std::cout << it->first << sql.znak << it->second;
            }
            else {
                std::cout << it->first << sql.znak << it->second << " END ";
            }
        }
        std::cout << ';' << '"'<<std::endl;
    }
     SqlSelectQueryBuilder&  AddWheres(const std::map<std::string, std::string>& kv) noexcept {
        sql.where = kv;
        return *this;
    }
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        for (auto t : columns) {
            sql.column.push(t);
        }
        return *this;
    }
    ~SqlSelectQueryBuilder() {
        sql.where.clear();
        sql.from.clear();

    }
protected:
    
    SQL sql;
};




int main() {
    
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    query_builder.BuildQuery();
    
    
    SqlSelectQueryBuilder query_builder1;
    std::vector < std::string > col= {"name1","phone1"};
    std::map< std::string, std::string>where = { {"id","45"},{"name", "Johnb"} };

    query_builder1.AddColumns(col);
    query_builder1.AddFrom("students");
    query_builder1.AddWheres(where);
    query_builder1.BuildQuery();


    


    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
