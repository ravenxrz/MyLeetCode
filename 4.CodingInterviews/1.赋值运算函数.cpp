/**
 * 题目：如下为类型 CMyString的声明，请为该类型添加赋值运算符函数」
 *
class CMyString {
public:
    CMyString(char *pData = nullptr);
    
    CMyString(const CMyString &str);
    
    ~CMyString(void);
private:
    char *m_pData;
};
 */


class CMyString {
public:
    CMyString(char *pData = nullptr);
    
    CMyString(const CMyString &str);
    
    ~CMyString(void);
    
    CMyString &operator+(const CMyString &rhs)
    {
        // 自赋值检查
        if (this != &rhs) {
            CMyString tmp(rhs);    // copy
            swap(*this, tmp);    // swap
        }
        return *this;
    }
    
    void swap(CMyString &str1, CMyString &str2)
    {
        char *tmp = str1.m_pData;
        str1.m_pData = str2.m_pData;
        str2.m_pData = tmp;
    }

private:
    char *m_pData;
};


int main()
{
    return 0;
}
