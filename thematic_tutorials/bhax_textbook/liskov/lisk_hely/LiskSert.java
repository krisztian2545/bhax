public class LiskSert{

  void drive(Car c){
    c.go();
    //...
  }

  public static void main(String[] args){

    Car c = new Car();
    drive(c);

    Audi a = new Audi();
    drive(a);

    ToyBMW tbmw = new ToyBMW();
    drive(tbmw); // this is a problem, because you can't drive drive a toy car

  }

}

class Car{
  void go(){}
}

class Audi extends Car{
  // no problem, because you can drive a car
}

class ToyBMW extends Car{
  // but you can't drive a toy car
}
