public class Osztaly{

  public static void main(String[] args){
    Szulo sz = new Gyerek();
    sz.kiir();
    //sz.ujKiir();
  }
}

class Szulo{
  public static void kiir(){
    System.out.println("Szulo");
  }
}

class Gyerek extends Szulo{

  public static void kiir(){
    System.out.println("Gyerek");
  }

  public void ujKiir(){
    System.out.println("uj");
  }

}
