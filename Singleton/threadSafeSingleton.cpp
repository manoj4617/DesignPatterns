#include <iostream>
#include <mutex>


class Singleton {
    private:
    static Singleton* singleton;
    static std::mutex mutex;
    Singleton(){}

    public:
    static Singleton* getInstance(){
        if(singleton == nullptr){
            std::lock_guard<std::mutex> lock(mutex);
            if(singleton == nullptr){
                singleton = new Singleton();
            }
        }
        return singleton;
    }
};

Singleton* Singleton::singleton = nullptr;
std::mutex Singleton::mutex;

int main(){
    Singleton* single = Singleton::getInstance();
    single->getInstance();

}