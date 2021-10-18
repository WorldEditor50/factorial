#include "largeint.h"
#include <iostream>

LargeInt LargeInt::operator +(const LargeInt &x)
{
    size_t s = x.size() > data.size() ? x.size() : data.size();
    std::string data1;
    std::string data2;
    if (x.size() > data.size()) {
        data1 = x.data;
        data2 = std::string(x.size() - data.size(), '0') + data;
    } else {
        data1 = data;
        data2 = std::string(data.size() - x.size(), '0') + x.data;
    }
    int n = 0;
    std::string y(s + 1, '0');
    for (int i = s - 1; i >= 0; i--) {
        int value = data1[i] - '0' + data2[i] - '0';
        y[i + 1] += (value + n) % 10;
        n = (value + n) / 10;
    }
    y[0] += n;
    if (y[0] == '0') {
        y = y.substr(1, y.size() - 1);
    }
    return y;
}

LargeInt LargeInt::operator -(const LargeInt &x)
{
    size_t s = x.size() > data.size() ? x.size() : data.size();
    std::string data1;
    std::string data2;
    if (x.size() > data.size()) {
        data1 = x.data;
        data2 = std::string(x.size() - data.size(), '0') + data;
        symbol = false;
    } else {
        data1 = data;
        data2 = std::string(data.size() - x.size(), '0') + x.data;
        symbol = true;
    }
    int n = 0;
    std::string y(s, '0');
    for (int i = s - 1; i >= 0; i--) {
        int value = data1[i] - data2[i];
        if (value >= 0) {
            y[i] += value % 10 + n;
            n = 0;
        } else {
            y[i] += 10 + value + n;
            n--;
        }
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
    const std::string &data1 = *p1;
    const std::string &data2 = *p2;
    std::vector<std::string> r;
    int h = 0;
    for (int i = data2.size() - 1; i >= 0; i--) {
        std::string u(data1.size() + 1, '0');
        for (int j = data1.size() - 1; j >= 0; j--) {
            int value = (data1[j] - '0') * (data2[i] - '0');
            u[j + 1] += (value + h) % 10;
            h = (value + h) / 10;
        }
        r.push_back(u);
    }
    for (size_t i = 0; i < r.size(); i++) {
        r[i] = std::string(r.size() - i - 1, '0') + r[i] + std::string(i, '0');
    }
    size_t s = r[0].size();
    std::string y(s + 1, '0');
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

std::string LargeInt::removeZeros(const std::string &x)
{
    size_t pos = 0;
    for (size_t i = 0; i < x.size(); i++) {
        if (x[i] != '0') {
            break;
        } else {
            pos++;
        }
    }
    return x.substr(pos, x.size() - pos);
}

int LargeInt::compare(const std::string &s1, const std::string &s2)
{
    std::string data1 = removeZeros(s1);
    std::string data2 = removeZeros(s2);
    int r = 0;
    if (data1.size() > data2.size()) {
        r = 1;
    } else if (data1.size() < data2.size()) {
        r = -1;
    } else {
        for (size_t i = 0; i < data1.size(); i++) {
            if (data1[i] > data2[i]) {
                r = 1;
                break;
            } else if (data1[i] < data2[i]) {
                r = -1;
                break;
            }
        }
    }
    return r;
}
