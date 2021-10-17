#ifndef LARGEINT_H
#define LARGEINT_H

#include <string>
#include <cmath>
#include <vector>

class LargeInt
{
public:
    LargeInt():symbol(true){}
    LargeInt(const LargeInt& x):symbol(true),data(x.data){}
    LargeInt(const std::string& x):symbol(true),data(x){}
    LargeInt(int x):symbol(true),data(std::to_string(x)){}
    LargeInt(size_t N):symbol(true),data(std::string(N, 48)){}
    ~LargeInt(){}
    inline size_t size() const {return data.size();}
    inline char& operator[](size_t i) {return data[i];}
    inline std::string toString() const
    {
        return data;
    }
    LargeInt &operator =(const LargeInt &x)
    {
        if (this == &x) {
            return *this;
        }
        data = x.data;
        return *this;
    }

    LargeInt &operator =(const std::string &x)
    {
        data = x;
        return *this;
    }

    LargeInt &operator =(const char *r)
    {
        data = r;
        return *this;
    }

    LargeInt &operator =(int r)
    {
        data = std::to_string(r);
        return *this;
    }
    LargeInt operator + (const LargeInt& x);
    LargeInt operator - (const LargeInt& x);
    LargeInt operator * (const LargeInt& x);
    LargeInt operator / (const LargeInt& x);
    LargeInt operator + (const std::string& r);
    LargeInt operator - (const std::string& r);
    LargeInt operator * (const std::string& r);
    LargeInt operator / (const std::string& r);
    LargeInt operator + (const char* r);
    LargeInt operator - (const char* r);
    LargeInt operator * (const char* r);
    LargeInt operator / (const char* r);
    LargeInt operator + (int r);
    LargeInt operator - (int r);
    LargeInt operator * (int r);
    LargeInt operator / (int r);

    LargeInt &operator += (const LargeInt &r);
    LargeInt &operator -= (const LargeInt &r);
    LargeInt operator *= (const LargeInt &r);
    LargeInt &operator /= (const LargeInt &r);
    LargeInt &operator += (const std::string &r);
    LargeInt &operator -= (const std::string &r);
    LargeInt &operator *= (const std::string &r);
    LargeInt &operator /= (const std::string &r);
    LargeInt &operator += (const char *r);
    LargeInt &operator -= (const char *r);
    LargeInt &operator *= (const char *r);
    LargeInt &operator /= (const char *r);
    LargeInt &operator += (int r);
    LargeInt &operator -= (int r);
    LargeInt &operator *= (int r);
    LargeInt &operator /= (int r);
private:
    bool symbol;
    std::string data;
};

#endif // LARGEINT_H
