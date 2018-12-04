//
//  Template1.hpp
//  Online
//
//  Created by wzp on 2018/12/4.
//  Copyright © 2018 wzp. All rights reserved.
//

#ifndef Template1_hpp
#define Template1_hpp

#include <iostream>
using namespace std;

template <class Item>
class Array {
    friend ostream &operator<<(ostream &, const Array<Item> &);
    int m_size = 0;
    int m_capacity = 0;
    const int m_increment = 10;
    Item *m_data = NULL;
    
public:
    Array(int capacity);
    ~Array();
    void add(Item value);
    Item get(int index);
    int length();
    Item operator[](int index);
};


template <class Item>
Array<Item>::Array(int capacity) {
    if (capacity <= 0) {
        return;
    }
    this->m_data = new Item[capacity];
    memset(this->m_data, 0, sizeof(Item) * capacity);
    this->m_capacity = capacity;
}

template <class Item>
Array<Item>::~Array() {
    delete [] this->m_data;
    this->m_data = NULL;
}

template <class Item>
void Array<Item>::add(Item value) {
    this->m_size++;
    if (this->m_size >= this->m_capacity) {
        this->m_capacity += this->m_increment;
        Item *newData = new Item[this->m_capacity];
        memset(newData, 0, sizeof(Item) * this->m_capacity);
        for (int i = 0; i < this->m_size - 1; i++) {
            newData[i] = this->m_data[i];
        }
        delete [] this->m_data;
        this->m_data = newData;
    }
    this->m_data[this->m_size - 1] = value;
}

template <class Item>
Item Array<Item>::get(int index) {
    if (index < 0 || index >= this->m_size) {
        return this->m_data[0];
    }
    return this->m_data[index];
}

template <class Item>
int Array<Item>::length() {
    return this->m_size;
}

template <class Item>
Item Array<Item>::operator[](int index) {
    return get(index);
}

template <class Item>
ostream &operator<<(ostream &os, const Array<Item> &array) {
    os << "[";
    for (int i = 0; i < array.m_size; i++) {
        os << array.m_data[i];
        if (i != array.m_size - 1) {
            os << ", ";
        }
    }
    return os << "]";
}
#endif /* Template1_hpp */
