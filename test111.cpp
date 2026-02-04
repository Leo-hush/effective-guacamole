#include <iostream>
using namespace std;

#ifndef LIMITVALUE_H
#define LIMITVALUE_H

template <typename T>
class LimitValue {
    T current_value;
    T min_value;
    T max_value;

public:
    LimitValue(T a, T b, T c) {
        current_value = a;
        min_value = b;
        max_value = c;
        if (current_value < min_value) 
            current_value = min_value;
        if (current_value > max_value) 
            current_value = max_value;
    }

    T val() { 
        return current_value; 
    }

    LimitValue& operator=(T x) {
        current_value = x;
        if (current_value < min_value) 
            current_value = min_value;
        if (current_value > max_value) 
            current_value = max_value;
        return *this;
    }

    LimitValue& operator+=(T y) {
        current_value += y;
        if (current_value < min_value) 
            current_value = min_value;
        if (current_value > max_value) 
            current_value = max_value;
        return *this;
    }

    LimitValue& operator++() {
        current_value++;
        if (current_value < min_value) 
            current_value = min_value;
        if (current_value > max_value) 
            current_value = max_value;
        return *this;
    }

    friend ostream& operator<<(ostream& out, LimitValue lv) {
        out << lv.current_value;
        return out;
    }
};

#endif
}