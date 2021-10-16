#include "largeint.h"
#include <iostream>

LargeInt LargeInt::operator +(const LargeInt &x)
{
    size_t s = x.size() > data.size() ? x.size() : data.size();
    std::string data_;
    if (x.size() > data.size()) {
        data = std::string(x.size() - data.size(), '0') + data;
    } else {
        data_ = std::string(data.size() - x.size(), '0') + x.data;
    }
    std::string y(s + 1, '0');
    for (int i = s - 1; i >= 0; i--) {
        char value = data[i] - '0' + data_[i] - '0';
        y[i + 1] += value % 10;
        y[i] += value / 10;
    }
    if (y[0] == '0') {
        y = std::string(y, 1, y.size() - 1);
    }
    return y;
}

LargeInt LargeInt::operator *(const LargeInt &x)
{ 
    const std::string *p1 = nullptr;
    const std::string *p2 = nullptr;
    if (x.size() > data.size()) {
        p1 = &x.data;
        p2 = &data;
    } else {
        p1 = &data;
        p2 = &x.data;
    }
    const std::string &data1 = (*p1);
    const std::string &data2 = (*p2);
    std::vector<std::string> r;
    for (int i = data2.size() - 1; i >= 0; i--) {
        std::string u(data1.size() + 1, '0');
        for (int j = data1.size() - 1; j >= 0; j--) {
            char value = (data1[j] - '0') * (data2[i] - '0');
            u[j + 1] += value % 10;
            u[j] += value / 10;
        }
        r.push_back(u);
    }
    for (size_t i = 0; i < r.size(); i++) {
        r[i] = std::string(r.size() - i - 1, '0') + r[i] + std::string(i, '0');
    }
    size_t s = r[0].size();
    std::string y(s, '0');
    int n = 0;
    for (int j = r[0].size() - 1; j >= 0; j--) {
        int value = 0;
        for (size_t i = 0; i < r.size(); i++) {
            value += r[i][j] - '0';
        }
        y[j] += (value + n) % 10;
        n = (value + n) / 10;
    }
    return y;
}
