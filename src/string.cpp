#include <iostream>

#include "string.hpp"

int String::strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    for ( ; src[i] != '\0' && i < n; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src) {
    int dest_len = strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        ++i;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n) {
    int dest_len = strlen(dest);
    int i = 0;
    while (src[i] != '\0' && i < n) {
        dest[dest_len + i] = src[i];
        ++i;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while (left[i] != '\0' && right[i] != '\0') {
        if (left[i] != right[i]) {
            return left[i] - right[i];
        }
        ++i;
    }
    return left[i] - right[i];
}

int String::strncmp(const char *left, const char *right, int n) {
    if (n <= 0) return 0;
    int i = 0;
    while (i < n && left[i] != '\0' && right[i] != '\0') {
        if (left[i] != right[i]) {
            return left[i] - right[i];
        }
        ++i;
    }
    if (i == n) {
        return 0;
    }
    return left[i] - right[i];
}

void String::reverse_cpy(char *dest, const char *src) {
    int src_len = strlen(src);
    int src_index = src_len - 1;
    int dest_index = 0;
    for (; dest_index < src_len; ++dest_index, --src_index) {
        dest[dest_index] = src[src_index];
    }
    dest[dest_index] = '\0';
}

const char *String::strchr(const char *str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return &str[i];
        }
        ++i;
    }
    if (c == '\0') {
        return &str[i];
    }
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle) {
    int len = strlen(needle);
    if (len == 0) return haystack;
    for (const char *p = haystack; (p = strchr(p, needle[0])) != nullptr; ++p) {
        if (strncmp(p, needle, len) == 0) {
            return p;
        }
    }
    return nullptr;
}

bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}

String::String(const char *s){
	strncpy(buf, s, MAXLEN - 1);
}

String::String(const String &s){
	strcpy(buf, s.buf);
}

String &String::operator=(const String &s){
	if(this != &s){
		strcpy(buf, s.buf);
	}
	return *this;
}

String String::operator+(const String &s) const {
    String R;
    strcpy(R.buf, buf);

    int current_len = strlen(buf);
    int other_len = strlen(s.buf);

    if (current_len + other_len >= MAXLEN) {
        std::cout << "ERROR: String Capacity Exceeded" << std::endl;
        strncat(R.buf, s.buf, MAXLEN - 1 - current_len);
    } else {
        strcat(R.buf, s.buf);
    }
    return R;
}

String &String::operator+=(const String &s) {
    int current_len = strlen(buf);
    int other_len = strlen(s.buf);

    if (current_len + other_len >= MAXLEN) {
        std::cout << "ERROR: String Capacity Exceeded" << std::endl;
        strncat(buf, s.buf, MAXLEN - 1 - current_len);
    } else {
        strcat(buf, s.buf);
    }
    return *this;
}

int String::size() const {
    return strlen(buf);
}

char &String::operator[](int i) {
    if (i < 0 || i >= size()) {
        std::cout << "ERROR: Index Out Of Bounds" << std::endl;
        return buf[0];
    }
    return buf[i];
}

int String::indexOf(char c) const {
    const char *p = strchr(buf, c);
    if (p != nullptr) {
        return p - buf;
    }
    return -1;
}

int String::indexOf(const String &s) const {
    const char *p = strstr(buf, s.buf);
    if (p != nullptr) {
        return p - buf;
    }
    return -1;
}

String String::reverse() const {
    String temp;
    reverse_cpy(temp.buf, this->buf);
    return temp;
}

String::~String() {
}

void String::print(std::ostream &out) const {
    out << buf;
}

void String::read(std::istream &in) {
    in >> buf;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}
