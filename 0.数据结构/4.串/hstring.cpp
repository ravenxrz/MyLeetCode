/**
 * Created by raven on 2020/9/11.
 * 字符串
 */
#include "../common.h"
#include <cstring>

using namespace std;

class hstring;

class hstring {
public:
    hstring(const char *str);

    hstring(const hstring &other);

    ~hstring();

    /* 字符串支持的最小操作集合 */
    size_t length() const;

    int compare(const hstring &str) const;

    hstring concat(const hstring &other) const;

    hstring substring(int pos, int len) const;

    friend ostream &operator<<(ostream &out, const hstring &string);


private:
    char *ch;
    size_t len;
};

hstring::hstring(const char *str) {
    if (!str) {
        cerr << "str can't be null\n";
        exit(ERROR);
    }

    const size_t str_len = strlen(str);
    /* 为hstring分配内存 */
    ch = new char[str_len + 1];       /* 1 for \0 */
    ch[0] = '\0';
    len = str_len;
    memcpy(this->ch, str, str_len + 1);
}

hstring::hstring(const hstring &other) {
    if (ch) delete ch;

    const int str_len = other.len;
    ch = new char[str_len + 1];
    ch[0] = '\0';
    len = str_len;
    memcpy(ch, other.ch, str_len + 1);
}

hstring::~hstring() {
    delete ch;
}

size_t hstring::length() const {
    return len;
}

int hstring::compare(const hstring &str) const {
    const int str_len = str.len;
    for (int i = 0; i < len && i < str_len; i++) {
        if (ch[i] != str.ch[i]) {
            return ch[i] - str.ch[i];
        }
    }
    return len - str_len;
}

hstring hstring::concat(const hstring &other) const {
    const int new_len = other.len + len;
    char *new_ch = new char[new_len + 1];
    /* copy string 1 */
    int i;
    for (i = 0; i < len; i++) {
        new_ch[i] = ch[i];
    }
    /* copy string 2 */
    for (; i < len + other.len; i++) {
        new_ch[i] = other.ch[i - len];
    }
    new_ch[i] = '\0';
    return hstring(new_ch);
}

hstring hstring::substring(int pos, int sub_len) const {
    /* boundary check */
    if (pos < 0 || pos >= len - sub_len + 1) {
        cerr << "pos is too low or too hight\n";
        exit(ERROR);
    }
    char *new_ch = new char[sub_len + 1];
    int i;
    for (i = pos; i < pos + sub_len; i++) {
        new_ch[i - pos] = ch[i];
    }
    new_ch[i] = '\0';
    return hstring(new_ch);
}

ostream &operator<<(ostream &out, const hstring &string) {
    out << string.ch ;
    return out;
}


