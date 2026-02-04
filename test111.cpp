#include <iostream>
#ifndef LIMITVALUE_H
#define LIMITVALUE_H

using namespace std;

template <typename T>
class LimitValue {
private:
    T current_value;
    T min_value;
    T max_value;

public:
    LimitValue(T init, T min_val, T max_val) {
        min_value = min_val;
        max_value = max_val;
        current_value = init;

        if (current_value < min_value) {
            current_value = min_value;
            cout << "初始值太小 改成最小值\n";
        }
        if (current_value > max_value){
            current_value = max_value;
            cout << "初始值太大 已经改最大值\n";
        }
    }

    T val() const {
        return current_value;
    }

    LimitValue& operator=(T new_val) {
        current_value = new_val;

        if (current_value < min_value) current_value = min_value;
        else if (current_value > max_value) {
            current_value = max_value;
        }

        return *this;
    }

    LimitValue& operator+=(T delta) {
        current_value += delta;

        if (current_value < min_value) {
            current_value = min_value;
        }
        else if (current_value > max_value) {
            current_value = max_value;
        }

        return *this;
    }
};

#endif
