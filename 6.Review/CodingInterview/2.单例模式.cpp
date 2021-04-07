
class Singleton {
   private:
    Singleton() = default;
    ~Singleton() = default;

    Singleton(const Singleton&) = default;
    Singleton& operator=(const Singleton&) = default;

   public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};