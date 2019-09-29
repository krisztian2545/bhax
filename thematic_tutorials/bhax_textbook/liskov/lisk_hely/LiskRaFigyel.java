public class LiskRaFigyel{

  void drive(RealCar rc){
    rc.go();
    //...
  }

  public static void main(String[] args){

    Audi a = new Audi();
    drive(a);

    //ToyBMW tbmw = new ToyBMW();
    //drive(tbmw);  this is a problem, because you can't drive drive a toy car

  }

}

class Car{}

class RealCar extends Car{
  void go(){}
}

class Audi extends RealCar{
  // no problem, because you can drive a car
}

class ToyBMW extends Car{
  // but you can't drive a toy car
}
