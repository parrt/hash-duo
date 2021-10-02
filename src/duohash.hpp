#include <iostream>
using namespace std;

template <class K, class V>
class Node {
public:
    size_t hashcode;
    K key;
    V value;
    Node *next;
    Node(size_t hashcode, K key, V value) {
        this->hashcode = hashcode;
        this->key = key;
        this->value = value;
    }
};

template <class K, class V>
class DuoHashTable {
protected:
    int nbuckets;
    Node<K,V> **buckets;

public:
    DuoHashTable(int nbuckets = 101) {
        this->nbuckets = nbuckets;
//        this->buckets = new Node<K,V>*[nbuckets]; // DOES NOT INIT THE POINTERS
        this->buckets = new Node<K,V>*[nbuckets](); // WOW. new syntax with ()
    }

    ~DuoHashTable() {
        for (auto i=0; i<nbuckets; i++) {
            Node<K,V> *p = this->buckets[i];
            while ( p!=NULL ) {
                auto next = p->next;
                delete p;
                p = next;
            }
        }
        delete this->buckets;
    }

    Node<K,V> *index(Node<K,V> *head, K key) {
        hash<K> khash;
        size_t h = khash(key);
        Node<K,V> *p = head;
        while ( p!=NULL ) {
            if ( p->hashcode == h && p->key == key ) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    int bucketLength(Node<K,V> *head) {
        auto n = 0;
        Node<K,V> *p = head;
        while ( p!=NULL ) {
            n += 1;
            p = p->next;
        }
        return n;
    }

    void put(K key, V value) {
        hash<K> khash;
        size_t h = khash(key);
        int i = h % this->nbuckets;
        cout << "key" << key << "," << h << "," << i << "blen"
            << this->bucketLength(this->buckets[i]) << "\n";
        Node<K,V> *p = index(this->buckets[i], key);
        if ( p!=NULL ) { // replace existing value
            p->value = value;
        }
        else { // insert at head
            auto *head = new Node<K,V>(h, key, value);
            head->next = this->buckets[i];
            this->buckets[i] = head;
        }
    }

    V get(K key) {
        hash<K> khash;
        size_t h = khash(key);
        int i = h % this->nbuckets;
        Node<K,V> *p = index(this->buckets[i], key);
        if ( p!=NULL ) {
            return p->value;
        }
        return NULL;
    }
};
