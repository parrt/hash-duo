#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "duohash.hpp"

vector<string> load_words();

using namespace std;

vector<string> load_words() {
    vector<string> words;
    ifstream f("/usr/share/dict/words");
    string w;
    while ( f >> w ) {
//        cout << w ;
        words.push_back(w);
    }
    f.close();
//    for (auto w:words) {
//        cout << w << "\n";
//    }
    return words;
}

int main()
{
    // there are 235,886 words
    auto words = load_words();
    int table_size = 0.75 * words.size();
    DuoHashTable<string,int> *h = new DuoHashTable<string,int>(table_size);
//    unique_ptr<DuoHashTable<int,string>> h(new DuoHashTable<int,string>(101));
    auto start = clock();
    int n = 1000;
    for (auto w:words) {
        h->put(w, n);
        n++;
    }
    auto end = clock();
    printf("DuoHashTable average time taken: %lf ns\n",
           double(end - start) / CLOCKS_PER_SEC / words.size() * 1e9);
    cout << "Avg bucket len " << h->avgBucketLength() << " vs expected " << words.size()/((float)table_size) << "\n";
    delete h;
}

