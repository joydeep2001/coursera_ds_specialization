#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    vector<string>phone_book(10000000, "");

    for(int i = 0;i < queries.size();i++)
    {
        int hash_ = queries[i].number;

        if(queries[i].type == "add")
        {
            phone_book[hash_] = queries[i].name;
        }
        else if(queries[i].type == "find")
        {


            if(phone_book[hash_] == "")
                result.push_back("not found");
            else
                result.push_back(phone_book[hash_]);


        }
        else if(queries[i].type == "del")
        {
            phone_book[hash_] = "";
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
