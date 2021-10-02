#include <iostream>
#include <vector>
#include <string>

#include "duohash.hpp"

using namespace std;

int main()
{
    cout << "Hello\n";
    DuoHashTable<int,string> *h = new DuoHashTable<int,string>(101);
//    unique_ptr<DuoHashTable<int,string>> h(new DuoHashTable<int,string>(101));
    h->put(99,"parrt");
    cout << "result" << h->get(99) << "\n";
}