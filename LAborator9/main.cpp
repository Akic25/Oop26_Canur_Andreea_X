#include <iostream>
#include <cstdio>
#include <tuple>
using namespace std;

template <typename K, typename V>
class Map {
    struct Entry {
        K key;
        V value;
    };

    Entry* data;
    int size;
    int capacity;

    void resize() {
        capacity++;
        Entry* data2 = new Entry[capacity];
        for (int i = 0; i < size; i++)
            data2[i] = data[i]; 
        delete[] data;
        data = data2; 
    }

public:
    Map() {
        capacity = 4;
        size = 0;
        data = new Entry[capacity];
    }

    ~Map() {
        delete[] data;
    }


    V& operator[](const K& key) {
        for (int i = 0; i < size; ++i)
            if (data[i].key == key)
                return data[i].value;

        if (size == capacity)
            resize();

        data[size].key = key;
        data[size].value = V();
        ++size;
        return data[size - 1].value;
    }

    void Set(const K& key, const V& value) {
        for (int i = 0; i < size; i++)
            if (data[i].key == key) {
                data[i].value = value;
                return;
            }
        if (size == capacity)
            resize();
        data[size].key = key;
        data[size].value = value;
        ++size;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < size; i++) {
            if (data[i].key == key) {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        delete[] data;
        size = 0;
        capacity = 4;
        data = new Entry[capacity];
    }

    bool Delete(const K& key) {
        for (int i = 0; i < size; i++) {
            if (data[i].key == key) {
                for (int j = i; j < size - 1; ++j)
                    data[j] = data[j + 1];
                --size;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const {
        if (this->size > map.size)
            return false;
        int ok = 0;
        for (int i = 0; i < this->size; i++)
            for (int j = 0; j < map.size; j++)
                if (this->data[i].key == map.data[j].key)
                    ok++;
        return ok == this->size;
    }
    class Iterator {
        Entry* data;
        int index;

    public:
        Iterator(Entry* data, int index) : data(data), index(index) {}
        auto operator*()const {
            return std::tuple<K, V, int>(data[index].key, data[index].value, index);
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data, size);
    }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
