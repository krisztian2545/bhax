class Car{
};

class RealCar : public Car{
  virtual void go(){};
};

class Audi : public RealCar{};

class ToyBMW : public Car{};

class Program{
  void drive(RealCar& rc){
    rc.go();
    //...
  };
};

int main(){

  Program p;
  Audi a;
  p.drive(a);

  //ToyBMW tbmw;
  //p.drive(tbmw); // this is impossible, because you can't drive a toy car

}
