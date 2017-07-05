#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <cmath>
using namespace std;
typedef struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
} City;

class Vehicle {
 public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const {
        return speed;
    }
    virtual ~Vehicle() {}

 private:
    double speed;
};
class BicycleStrategy: public Vehicle {
public:
  virtual void doTravel(const City& src, const City& dest);
  explicit BicycleStrategy(double speed): Vehicle(speed) {}
};
class TrainStrategy: public Vehicle {
public:
  explicit TrainStrategy(double speed): Vehicle(speed) {}
  virtual void doTravel(const City& src, const City& dest);  
};
class AirplaneStrategy: public Vehicle {
public:
  explicit AirplaneStrategy(double speed): Vehicle(speed) {}
  virtual void doTravel(const City& src, const City& dest);  
};
void print(const double &time, const string &vehicle, const City& src, const City& dest) {
  cout << "It takes ";
  cout << time;
  cout << " hours to Travel from " << src.name;
  cout << " to " << dest.name << " by " << vehicle << "." << endl;
}
void BicycleStrategy::doTravel(const City& src, const City& dest) {
  double dis = fabs(src.x - dest.x) + fabs(src.y - dest.y);
  print(dis / Vehicle::getSpeed(), string("Bicycle"), src, dest);
}
void TrainStrategy::doTravel(const City& src, const City& dest) {
  double dis = sqrt(pow(src.x - dest.x, 2.0) + pow(src.y - dest.y, 2.0));
    print(dis / Vehicle::getSpeed(), string("Train"), src, dest);
}
void AirplaneStrategy::doTravel(const City& src, const City& dest) {
  double dis = ((fabs(src.x - dest.x) > fabs(src.y - dest.y)) ? fabs(src.x - dest.x) : fabs(src.y - dest.y));
  print(dis / Vehicle::getSpeed(), string("Airplane"), src, dest);
}
#endif