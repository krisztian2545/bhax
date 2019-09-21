public class Osztaly{

  public static void main(String[] args){
    Szulo sz = new Gyerek();
    sz.kiir();
  }
}

class Szulo{

}

class Gyerek extends Szulo{
  void kiir(){
    System.out.println("Gyerek");
  }
}
