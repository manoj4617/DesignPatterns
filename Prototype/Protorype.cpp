#include <iostream>

class Prototype{
    public:
    virtual Prototype* clone() const = 0;
    virtual void SetAttribute(const std::string& attrs) = 0;
    virtual void PrintInfo() const = 0;     
};

class ConcretePrototype : Prototype{
    private:
    std::string attributes;

    public:
    Prototype* clone() const override{
        return new ConcretePrototype(*this);
    }

    void SetAttribute(const std::string& attr) override {
        this->attributes = attr;
    }

    void PrintInfo() const override {
        std::cout << "Attributes : " << this->attributes << "\n";
    }

};

int main(){
    ConcretePrototype pro;
    pro.SetAttribute("First Attribute");

    Prototype* clone = pro.clone();
    clone->SetAttribute("Custom Attribute");

    pro.PrintInfo();
    clone->PrintInfo();

    
    return 0;
}