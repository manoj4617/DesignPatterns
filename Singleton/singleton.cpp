#include <iostream>

class Singleton {
    private:
    static Singleton* singleton;

    Singleton(){}

    public:
    static Singleton* getInstance(){
        if(singleton == NULL){
            singleton = new Singleton();
        }
        return singleton;
    }
};

int main(){
    Singleton* single = Singleton::getInstance();
    single->getInstance();

}