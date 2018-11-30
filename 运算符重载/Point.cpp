//
//  Point.cpp
//  Online
//
//  Created by wzp on 2018/11/19.
//  Copyright © 2018 wzp. All rights reserved.
//

#include "Point.hpp"

Point &Point::operator+(const Point &p) {
    this->m_x += p.m_x;
    this->m_y += p.m_y;
    return *this;
}

Point &Point::operator-(const Point &p) {
    this->m_x -= p.m_x;
    this->m_y -= p.m_y;
    return *this;
}
const Point Point::operator-() const {
    return Point(-this->m_x, -this->m_y);
}
Point &Point::operator+=(const Point &p) {
    this->m_x += p.m_x;
    this->m_y += p.m_y;
    return *this;
}
Point &Point::operator-=(const Point &p) {
    this->m_x -= p.m_x;
    this->m_y -= p.m_y;
    return *this;
}

bool Point::operator==(const Point &p) {
    return (this->m_x == p.m_x && this->m_y == p.m_y);
}
bool Point::operator!=(const Point &p) {
    return !(*this == p);
}

//前++
Point &Point::operator++() {
    this->m_x++;
    this->m_y++;
    return *this;
}
//后++
const Point Point::operator++(int) {
    Point tmpPoint(*this);
    this->m_x++;
    this->m_y++;
    return tmpPoint;
}
