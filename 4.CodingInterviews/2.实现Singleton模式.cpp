/**
    题目：实现C++的单例模式
 */
#include <mutex>

using namespace std;

// method 1 double-check
class Singleton1 {
public:
    Singleton1 *getInstance()
    {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mu);
            if (instance == nullptr) {
                instance = new Singleton1();
            }
        }
        return instance;
    }

private:
    Singleton1() = default;
    
    Singleton1(const Singleton1 &rhs) = default;;
    
    Singleton1 &operator=(const Singleton1 &rhs) = default;

private:
    static mutex mu;
    static Singleton1 *instance;
};

mutex Singleton1::mu;
Singleton1 *Singleton1::instance = nullptr;


// singleton2 local static variables
class Singleton2 {
private:
    Singleton2() = default;;
    
    ~Singleton2() = default;;
    
    Singleton2(const Singleton2 &) = delete;
    
    Singleton2 &operator=(const Singleton2 &) = delete;

public:
    static Singleton2 &getInstance()
    {
        static Singleton2 instance;
        return instance;
    }
};

int main()
{
    return 0;
}
