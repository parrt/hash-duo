#include <iostream>
#include <vector>
#include <string>

#include "duohash.hpp"

using namespace std;

int main()
{
    DuoHashTable<string,string> *h = new DuoHashTable<string,string>(101);
    cout << "Hello\n";
}