class CMyString {
   public:
    CMyString(char* pData = nullptr);

    CMyString(const CMyString& str);

    ~CMyString(void);

    CMyString& operator=(const CMyString& rhs) {
        // 对象是否相等检查
        if (this == &rhs) {
            return *this;
        }
        CMyString tmp(rhs);
        // swap tmp and this
        char* tmp_ptr = this->m_pData;
        this->m_pData = tmp.m_pData;
        tmp.m_pData = tmp_ptr;
        return *this;
    }

   private:
    char* m_pData;
}