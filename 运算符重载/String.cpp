//
//  String.cpp
//  Online
//
//  Created by wzp on 2018/11/30.
//  Copyright © 2018 wzp. All rights reserved.
//

#include "String.hpp"
String::String(const char *cstr) {
    assign(cstr);
}
String::String(const String &str) {
    assign(str.m_cstr);
}
String::~String() {
    assign(NULL);
}
size_t String::length() {
    return strlen(this->m_cstr);
}
String &String::operator=(const char *cstr) {
    return assign(cstr);
}
String &String::operator=(const String &str) {
    return assign(str.m_cstr);
}
String String::operator+(const char *cstr) {
    String tmpStr;
    char *newCStr = join(this->m_cstr, cstr);
    if (newCStr) {
        tmpStr.assign(NULL);
        tmpStr.m_cstr = newCStr;
    }
    return tmpStr;
}
String String::operator+(const String &str) {
    return operator+(str.m_cstr);
}

String &String::operator+=(const char *cstr) {
    char *newCStr = join(this->m_cstr, cstr);
    if (newCStr) {
        this->assign(NULL);
        this->m_cstr = newCStr;
    }
    return *this;
}

String &String::operator+=(const String &str) {
    return operator+=(str.m_cstr);
}
bool String::operator>(const char *cstr) {
    if (!this->m_cstr || !cstr) {
        return 0;
    }
    return strcmp(this->m_cstr, cstr);
}
bool String::operator>(const String &str) {
    return operator>(str.m_cstr);
}
char String::operator[](int index) {
    if (!this->m_cstr || index < 0) {
        return '\0';
    }
    return this->m_cstr[index];
}

ostream &operator<<(ostream &os, const String &str) {
    if (!str.m_cstr) {
        return os;
    }
    return os << str.m_cstr;
}
String &String::assign(const char *cstr) {
    if (this->m_cstr == cstr) {
        return *this;
    }
    if (this->m_cstr) {
        delete [] this->m_cstr;
        this->m_cstr = NULL;
    }
    if (cstr) {
        size_t len = strlen(cstr) + 1;
        this->m_cstr = new char[len]{};
        strcpy(this->m_cstr, cstr);
        this->m_cstr[len] = '\0';
    }
    return *this;
}

char *String::join(const char *cstr1, const char *cstr2) {
    if (!cstr1 || !cstr2) {
        return NULL;
    }
    size_t len = strlen(cstr1) + strlen(cstr2) + 1;
    char *newCStr = new char[len]{};
    strcat(newCStr, cstr1);
    strcat(newCStr, cstr2);
    newCStr[len] = '\0';
    return newCStr;
}
