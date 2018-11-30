//
//  String.hpp
//  Online
//
//  Created by wzp on 2018/11/30.
//  Copyright © 2018 wzp. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <iostream>
using namespace std;

class String {
    friend ostream &operator<<(ostream &, const String &);
    
public:
    String(const char *cstr = "");
    String(const String &str);
    ~String();
    size_t length();
    String &operator=(const char *cstr);
    String &operator=(const String &str);
    String operator+(const char *cstr);
    String operator+(const String &str);
    String &operator+=(const char *cstr);
    String &operator+=(const String &str);
    bool operator>(const char *cstr);
    bool operator>(const String &str);
    char operator[](int index);
    
private:
    char *m_cstr = NULL;
    String &assign(const char *cstr);
    char *join(const char *cstr1, const char *cstr2);
};

#endif /* String_hpp */
