class Car{
public:
  virtual void go(){};
};

class Audi : public Car{};

class ToyBMW : public Car{};

class Program{
  void drive(Car& c){
    c.go();
    //...
  };
};

int main(){

  Car c;
  Program p;
  p.drive(c);

  Audi a;
  p.drive(a);

  ToyBMW tbmw;
  p.drive(tbmw); // this is impossible, because you can't drive a toy car

}
