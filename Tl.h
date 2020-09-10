//
// Created by btnt51 on 25.07.2020.
//
#include <iostream>
#ifndef FUN_TL_H
#define FUN_TL_H


class Tl {
public:
    Tl(int up , int down);
    ~Tl();

private:
    int m_up;
    int m_down;

public:
    void print() const;
    void setUp(int up);
    void setDown(int down);
    Tl operator+(int value) const;
    Tl operator+(Tl b) const;
    Tl operator-(int value) const;
    Tl operator-(Tl b) const;
    Tl operator*(int value) const;
    Tl operator*(Tl b) const;
    Tl operator/(int value) const;
    Tl operator/(Tl b) const;
    void operator+=(int value);
    void operator+=(Tl b);
    void operator>>(int value);
    void operator>>(Tl b);
    void operator*=(int value);
    void operator*=(Tl b);
    void operator/=(int value);
    void operator/=(Tl b);
};
#endif //FUN_TL_H
