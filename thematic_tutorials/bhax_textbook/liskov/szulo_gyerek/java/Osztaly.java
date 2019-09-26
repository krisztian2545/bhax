public class Osztaly{

  public static void main(String[] args){
    Szulo sz = new Gyerek();
    sz.kiir();
  }
}

class Szulo{}

class Gyerek extends Szulo{
  public void kiir(){
    System.out.println("Gyerek");
  }
}
