#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Query {
    string type, s;
    size_t ind;
};

struct Node {
    string data;
    Node* link;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    //vector<string> elems;
    Node** hash_table = new Node*[bucket_count];





    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void insert_(Node** ptr, string str)
    {
        Node* newNode = new Node;
        newNode->data = str;
        newNode->link = NULL;

        if(*ptr == NULL)
        {
            *ptr = newNode;
            return;
        }


        Node* prev = *ptr;
        Node* temp = *ptr;

        for(temp = *ptr;temp != NULL;temp = temp->link)
        {
            if(temp->data == str)
            {
                delete newNode;
                return;
            }
            prev = temp;
        }

        prev->link = newNode;


    }

    void check(Node* ptr)
    {
        if(ptr == NULL){
            return;
        }
        check(ptr->link);
        std::cout << ptr->data << " ";

    }

    bool del(string s, Node** ptr)
    {
        if(*ptr == NULL)
            return false;
        if((*ptr)->data == s)
        {
            //if deleting the first link
            Node* temp = *ptr;
            *ptr = (*ptr)->link;
             delete temp;
             return true;
        }
        for(Node* temp = *ptr;temp->link != NULL;temp = temp->link)
        {
            if(temp->link->data == s)
            {
                Node* temp2 = temp->link;
                temp->link = temp2->link;
                delete temp2;
                return true;
            }
        }
        return false;
    }

    bool find_(string s)
    {
        size_t hash_ = hash_func(s);
        if(hash_table[hash_] == NULL)
            return false;
        for(Node* temp = hash_table[hash_]; temp != NULL; temp = temp->link)
        {
            if(temp->data == s)
                return true;
        }
        return false;
    }

    void processQuery(const Query& query) {



        if(query.type == "add")
        {
            size_t hash_ = hash_func(query.s);

            insert_(&hash_table[hash_], query.s);


        }
        else if(query.type == "check")
        {

            check(hash_table[query.ind]);
            cout << endl;
        }
        else if(query.type == "find")
        {
            writeSearchResult(find_(query.s));
        }
        else if(query.type == "del")
        {
            size_t hash_ = hash_func(query.s);
            del(query.s, &hash_table[hash_]);
        }


    }

    void processQueries() {

        int n;
        for(int i = 0;i < bucket_count;i++)
            hash_table[i] = NULL;

        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
