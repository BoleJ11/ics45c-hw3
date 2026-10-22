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
