//
// Created by btnt51 on 25.07.2020.
//

#include "Tl.h"

Tl::Tl(int up, int down) {
        m_up = up;
        m_down = down;
}

Tl::~Tl() {

}

void Tl::print() const{
    std::cout << this->m_up << "/" << this->m_down;
    std::cout << std::endl;
}

void Tl::setUp(int up) {
    this->m_up = up;
}

void Tl::setDown(int down) {
    this->m_down = down;
}

Tl Tl::operator+(int value) const{
    Tl c(0,0);
    int downVal = 1;
    if(this->m_down== 0 && this->m_up == 0) {
        c.setUp(this->m_up + value);
        c.setDown(this->m_down + downVal);
        return c;
    } else {
        if (this->m_down == downVal) {
            c.setUp(this->m_up + value);
            c.setDown(this->m_down);
            return c;
        } else {
            value = value * this->m_down;
            c.setUp(this->m_up + value);
            c.setDown(this->m_down);
            return c;
        }
    }
}

Tl Tl::operator+(Tl b) const{
    Tl c(0,0);
    if(this->m_down== 0 && this->m_up == 0) {
        c.m_up += b.m_up ;
        c.m_down = b.m_down;
        return c;
    } else {
        if (this->m_down == b.m_down) {
            c.m_up = this->m_up + b.m_up;
            c.setDown(this->m_down);
            return c;
        } else {
            int l = this->m_up;
            int k = b.m_up;
            int g = this->m_down;
            int o = b.m_down;
            l *= o;
            k *= g;
            c.setUp(l + k);
            c.setDown(g * o);
            return c;
        }
    }
}

Tl Tl::operator-(int value) const{
    Tl c(0,0);
    int downVal = 1;
    if(this->m_down== 0 && this->m_up == 0) {
        c.setUp(this->m_up + value);
        c.setDown(this->m_down + downVal);
        return c;
    } else {
        if (this->m_down == downVal) {
            c.setUp(this->m_up - value);
            c.setDown(this->m_down);
            return c;
        } else {
            value = value * this->m_down;
            c.setUp(this->m_up - value);
            c.setDown(this->m_down);
            return c;
        }
    }
}

Tl Tl::operator-(Tl b) const{
    Tl c(0,0);
    if(this->m_down== 0 && this->m_up == 0) {
        c.m_up -= b.m_up ;
        c.m_down = b.m_down;
        return c;
    } else {
        if (this->m_down == b.m_down) {
            c.m_up = this->m_up - b.m_up;
            c.setDown(this->m_down);
            return c;
        } else {
            int l = this->m_up;
            int k = b.m_up;
            int g = this->m_down;
            int o = b.m_down;
            l *= o;
            k *= g;
            c.m_up = l - k;
            c.m_down = g * o;
            return c;
        }
    }
}

void Tl::operator+=(int value) {
    int downVal = 1;
    if(this->m_down== 0 && this->m_up == 0)
    {
        this->m_up += value;
        this->m_down = downVal;
    } else {
        if (this->m_down == downVal) {
            this->m_up += value;

        } else {
            value = value * this->m_down;
            this->m_up += value;
        }
    }
}

void Tl::operator+=(Tl b) {
    if(this->m_down== 0 && this->m_up == 0) {
        this->m_up = b.m_up;
        this->m_down = b.m_down;
    } else {
        if (this->m_down == b.m_down) {
            this->m_up += b.m_up;
        } else {
            int l = this->m_up;
            int k = b.m_up;
            int g = this->m_down;
            int o = b.m_down;
            l *= o;
            k *= g;
            this->setUp(l + k);
            this->setDown(g * o);
        }
    }
}

Tl Tl::operator*(int value) const{
    Tl c(0,0);
    c.setUp(this->m_up * value);
    c.setDown(this->m_down * 1);
    return c;
}

Tl Tl::operator*(Tl b) const{
    Tl c(0,0);
    c.setUp(this->m_up * b.m_up);
    c.setDown(this->m_down * b.m_down);
    return c;
}

Tl Tl::operator/(int value) const{
    Tl c(0,0);
    int downVal = 1;
    c.setUp(this->m_up * downVal);
    c.setDown(this->m_down * value);
    return c;
}

Tl Tl::operator/(Tl b) const {
    Tl c(0,0);
    c.setUp(this->m_up * b.m_down);
    c.setDown(this->m_down * b.m_up);
    return c;
}

void Tl::operator>>(int value) {
    this->setUp(value);
    this->setDown(1);
}

void Tl::operator>>(Tl a) {
    this->setDown(a.m_down);
    this->setUp(a.m_up);
}

void Tl::operator*=(int value) {
    this->setUp(this->m_up * value);
}

void Tl::operator*=(Tl b) {
    this->setUp(this->m_up*b.m_up);
    this->setDown(this->m_down*b.m_down);
}

void Tl::operator/=(int value) {
    this->setUp(this->m_up *1);
    this->setDown(this->m_down * value);
}

void Tl::operator/=(Tl b) {
    this->setUp(this->m_up * b.m_down);
    this->setDown(this->m_down * b.m_up);
}