#include "Vehicle.hpp"

template<typename Derived>
class AbstractVehicleBuilder {
    public:
    virtual  Derived* buildEngine(const std::string& engine) = 0;
    virtual  Derived* setColor(const std::string& color) = 0;
    virtual  Derived* setTransmisison(const std::string& transmisisonType) = 0;
    virtual  Derived* setGps(bool gps) = 0;
};

class CarBuilder : public AbstractVehicleBuilder<CarBuilder>{
    private:

    Car* car = new Car();
    public:
    CarBuilder* buildEngine(const std::string& engine){
        // std::cout << "";
        this->car->Engine = engine;
        return this;
    }

    CarBuilder* setColor(const std::string& color){
        this->car->Color = color;
        return this;
    }

    CarBuilder* setTransmisison(const std::string& transmissionType){
        this->car->TranmissionType = transmissionType;
        return this;
    }
    
    CarBuilder* setGps(bool gps){
        this->car->Gps = gps;
        return this;
    }

    CarBuilder* setDriveType(bool driveType){
        this->car->AllWheelDrive = driveType;
        return this;
    }

    void printCar() {
        std::cout << "Car(engine=" << this->car->Engine << ", color=" << this->car->Color << ", transmission=" << this->car->TranmissionType
                  << ", gps=" << std::boolalpha << this->car->Gps << ", Drive Type= " << this->car->AllWheelDrive << ")" << std::endl;
    }
    
};

class BikeBuilder : public AbstractVehicleBuilder<BikeBuilder>{
    private:
    std::unique_ptr<Bike> bike = std::make_unique<Bike>();
    
    public:
    BikeBuilder* buildEngine(const std::string& engine){
        // std::cout << "";
        this->bike->Engine = engine;
        return this;
    }

    BikeBuilder* setColor(const std::string& color){
        this->bike->Color = color;
        return this;
    }

    BikeBuilder* setTransmisison(const std::string& transmissionType){
        this->bike->TranmissionType = transmissionType;
        return this;
    }
    
    BikeBuilder* setGps(bool gps){
        this->bike->Gps = gps;
        return this;
    }

    BikeBuilder* setEngineCC(int cc){
        this->bike->EngineCC = cc;
        return this;
    }
};

int main(){

    std::unique_ptr<CarBuilder> buildCar = std::make_unique<CarBuilder>();

    buildCar->buildEngine("V8")
            ->setColor("Red")
            ->setDriveType("2 wheel drive")
            ->setGps(true)
            ->setTransmisison("Manual")
            ->printCar();

    return 0;
}