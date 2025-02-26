#include<iostream>

using namespace std;
/*---------------------------------------Single / Multilevel-------------------------------------*/

class Vehicle{

    private: // accessible inside this class only
        string privateVehicleData;

    protected: // accessible within this class and the derived class.
        double maxSpeed;
        string make;
        string model;
        int year;

    public: // accessible from outside the class.
        Vehicle(string mke, string mdl, int yr, double spd): make(mke), model(mdl), year(yr), maxSpeed(spd), privateVehicleData("Internal")
        {
            cout<<"Vehicle constructor called !"<<endl;
        }

        // when deleting the obj through base class ptr. The destructor of derived class will be called auto.
        // class B{ virtual ~B(){}}; 
        // class D:public B{ ~B(){} };
        // int main(){ 
        // Base* b = new Derived; 
        // delete b; // if we haven't declared ~B as virtual than deleting b will only call B's destr.
        // } // B constructor -> D constructor -> B destructor -> D destructor
        virtual ~Vehicle(){
            cout<<"Vehicle destructor called !"<<endl;
        }

        void displayInfo(){
            cout<< year << " " << make << " " << model <<endl;
        }

        //virtual function - enables (dynamic binding)runtime polymorphism (helps the base class ptr to call overridden fun in derived class depending on the actual object types)
        // if you want derived class to override the fun of the base class. virtual keyword is necessary for that method in the base class.
        // otherwise it will call the fun of the Base class and not the actual child class.
        virtual void startEngine(){
            cout<<"Vehicle engine started"<<endl;
        }

        //pure virtual function - makes Vehicle abstract class (non instantiable | act as an interface for Der classes).
        // all the derived class of this class must implement this if they want to be concrete else the derived class will be considered abstract
        // It is not important for the 2nd level derived class to implement the pure virtual fun if the 1st level has already implement it.
        // Car should implement it if it wants to be a concrete class but Sports car is not required to implement it unless it wants to.
        virtual void accelerate() = 0;

        //Final method - cannot be overriden by the derived class.
        virtual void registerVehicle()  final{
            cout<<"Vehicle registration completed"<<endl;
        }
};

// Public inheritance
class Car: public Vehicle{
    private:
        int numDoors;
    
    public:
        Car(string mke, string mdl, int yr, double spd, int doors): Vehicle(mke,mdl,yr,spd),numDoors(doors)
        {
            cout<<"Car constructor called !"<<endl;
        }

        ~Car() override{
            cout<<"Car destructor called !"<<endl;
        }

        // Override virtaul method.
        void startEngine() override{
            cout<<"Car engine started with key"<<endl;
        }

        //accelerate is pure virtual function 
        void accelerate() override{
           //maxspeed declared protected in public
            cout<<"Car accelerating to speed = "<<maxSpeed<<"mph"<<endl;
        }

        void honk(){
            cout<<"Car honking"<<endl;
        }
};

class Motorcycle: protected Vehicle{

    private:
        bool hasSidecar;
    
    public:
        Motorcycle(string mke, string mdl, int yr, double spd, bool sideCar): Vehicle(mke,mdl,yr,spd), hasSidecar(sideCar)
        {
            cout<<"Motorcycle constructor called !"<<endl;
        }
        ~Motorcycle() override{
        cout<<"Motorcycle destructor called !"<<endl;
        }

        //year,make,mode - protected members
        void showDetails(){
            cout<<"Motorcycle: "<<year<<" "<<make<<" "<<model<<endl;
            cout<<"Has sideCar: "<< (hasSidecar ? "Yes" : "No")<<endl;
        }

        //virtual method
        void startEngine() override{
            cout<<"Motorcycle engine started with button"<<endl;
        }

        //pure virtual method 
        void accelerate() override{
            //maxspeed is protected.
            cout<<"Motorcycle accelerating to speed = "<<maxSpeed<<"mph"<<endl;
        }

        void displayVehicleInfo(){
            displayInfo(); // Base class method - public.
        }
};

class Truck: private Vehicle{
    private:
        double cargoCapacity;
    
    public:
        Truck(string mke, string mdl, int yr, double spd, double cap): Vehicle(mke,mdl,yr,spd), cargoCapacity(cap)
        {
            cout<<"Truck constructor called !"<<endl;
        }

        ~Truck() override{
            cout<<"Truck destructor called !"<<endl;
        }
        void startEngine() override {
            cout << "Truck engine started with remote" << std::endl;
        }
        
        void accelerate() override {
            cout << "Truck accelerating slowly to " << maxSpeed << " mph" << std::endl;
        }

        void getTrcukInfo(){
            cout<<"Truck"<<endl;
            displayInfo();
            cout<<"Cargo capacity"<<cargoCapacity<<" tons"<<endl;
        }
};

/*---------------------------------------------------------------------------------------------------------*/


/*---------------------------------------Multiple-------------------------------------*/


class Engine{
    protected:
        int horsepower;
        string fueltype;
    
    public:
        
        Engine(int hp, string fltype): horsepower(hp), fueltype(fltype){
            cout<<"Engine construtor called !"<<endl;
        }

        // create virtual destructor so that when the base class ptr gets destroyed it also calls the destructor of the derived class ptr if the obj pointed is of type derived class.
        virtual ~Engine(){
            cout<<"Engine destructor called !"<<endl;
        }

        void startEngine() {
            cout<<"Engine started horsepower  = "<< horsepower<< " fuel type = "<<fueltype<<endl;
        }
};

// Multiple inheritance. [Base classes - Car, Engine] 
class SportsCar : public Car, public Engine{

    private:
        bool convertible;
    
    public:
        SportsCar(string make, string model, int year, double maxspeed, 
        int doors, int horsepower, string fuel, bool isconvertible) : Car(make, model, year, maxspeed,doors),
        Engine(horsepower,fuel), convertible(convertible)
        {
            cout<<"Sports car constructor called"<<endl;
        }

        ~SportsCar() override{
            cout<<"Sports car destructor called"<<endl;
        }

        // Sports car is following multiple inheritance (Car and Engine).
        // Car and Engine both has this startEngine()
        // if we delete below impl of startEngine() and call sportscar.startEng() 
        // than compiler would get confused which startEngine() to call. [Car or Engine since both has the impl]
        void startEngine(){
            cout<<"Sports car starting process"<<endl;
            Car::startEngine(); // Call Car's version
            Engine::startEngine(); // Call Engine's version    
        }

};

/*---------------------------------------------------------------------------------------------------------*/

int main(){
    cout<<"=======Public Inheritance ==========="<<endl;
    /*
    Car car("Land Rover","Range Rover", 2025, 100, 4);
    // 1. Vehicle constructor
    // 2. Car constructor
    
    cout<<"---------------"<<endl;
    
    car.displayInfo(); // Base class method.
    // 3. Base class method
    // 4. Car Destructor
    // 5. Vehicle Destructor

    cout<<"---------------"<<endl;

    car.startEngine(); // declared virtual in base and overriden in derived 
    // 6. Car engine started with key.
    // 7. Car Destructor
    // 8. Vehicle Destructor

    cout<<"---------------"<<endl;

    car.accelerate(); // pure virtual in base and overriden in derived
    // 9. method
    // 10. Car Desturcor
    // 11. Vehicle Destructor

    cout<<"---------------"<<endl;

    car.honk();
    //12. method
    //13. Car Destructor
    //14. Vehicle Destructor

    cout<<"---------------"<<endl;

    car.registerVehicle(); // virtual final method in the base class
    //15. method
    //16. Car Destructor
    //17. Vehicle Destructor

    */
   /*
    cout<<"=======Protected Inheritance ==========="<<endl;
    
    Motorcycle motorcycle("Royal-Enfield", "Thunderbird", 2016, 180, false);
    //1. Vehicle Constructor
    //2. Motorcycle Constructor

    cout<<"---------------"<<endl;

//  motorcycle.displayInfo(); Motorcycle is protected inheritance and so public displayInfo() in Vehicle becomes protected in motocycle.
    // error
    cout<<"---------------"<<endl;

    motorcycle.showDetails(); //motorcycle specific method that uses protected members from base class.
    //3. method
    //4. Motorcycle destructor
    //5. Vehicle destructor

    cout<<"---------------"<<endl;

    motorcycle.displayVehicleInfo(); //internally calls the displayInfo() which is protected and inaccessible from the main.

    */
    /*
    cout<<"=======Private Inheritance ==========="<<endl;

    Truck truck("Ford", "F-150", 2023, 100.0, 3.5);
    // 1. Vehicle constructor
    // 2. Truck constructor

    // truck.displayInfo(); private in Truck
    
    cout<<"---------------"<<endl;
    
    truck.getTrcukInfo(); // internally calls the displayInfo() of Vehicle (class) which is private in the Derived class.
    // 3. Vehicle constructor
    // 4. Truck constructor
    // 5. method
    // 6. Truck destructor
    // 7. Vehicle destructor
*/

    cout<<"=======Multiple Inheritance ==========="<<endl;
/*
    SportsCar sportscar("Land Rover","Range Rover", 2025, 200, 4, 2000, "premium", true);
    //1. Vehicle constructor
    //2. Car constructor
    //3. Engine constructor
    //4. Sports car constructor
    //5. Sports car destructor
    //6. Engine destructor
    //7. Car destructor
    //8. Vehicle destructor

    cout<<"---------------"<<endl;

    sportscar.startEngine();
    // 9. method
    // 10. Sports car destructor
    // 11. Engine destructor
    // 12. Car destructor
    // 13. Vehicle destructor

    cout<<"---------------"<<endl;

    // Will call the accelrate() of Car class as the impl doesn't exist in the Sports Car class.
    sportscar.accelerate();
    // 14. method
    // 15. SportsCar destructor
    // 16. Engine destructor
    // 17. Car destructor
    // 18. Vehicle destructor

    */

    cout<<"=======Polymorphism ==========="<<endl;


    Vehicle* vehicle[1];

    vehicle[0] = new Car("Audi","Q4",2023,130.0,4);
    // 1. Vehicle Constructor
    // 2. Car Constructor
    // This will not call any destructor
    
    delete vehicle[0];
    // 1. Car Destructor // automatically called because Car inherits the Vehicle and destructor in the Vehicle is virtual which is overriden
    // 2. Vehicle Destructor

    // not allowed because Motorcycle is following protected inheritance.
    // and we are doing upcasting to vehicle which is only possible when there is public inheritance
    // vehicle[1] = new Motorcycle("flowerbird","mountain",2023,130.0,4);
    
    //Similar reason as above.
    // vehicle[0] = new Truck("Volvo", "VNL", 2023, 85.0, 33.5);

}