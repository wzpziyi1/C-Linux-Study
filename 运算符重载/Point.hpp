//
//  Point.hpp
//  Online
//
//  Created by wzp on 2018/11/19.
//  Copyright © 2018 wzp. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Point {
    float m_x;
    float m_y;
    
public:
    Point(float x = 0, float y = 0) : m_x(x), m_y(y) {}
    
    Point &operator+(const Point &);
    Point &operator-(const Point &);
    const Point operator-() const;
    Point &operator+=(const Point &);
    Point &operator-=(const Point &);
    
    bool operator==(const Point &);
    bool operator!=(const Point &);
    
    //前++
    Point &operator++();
    //后++
    const Point operator++(int);
};

#endif /* Point_hpp */
