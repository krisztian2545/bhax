/*
 * MandelbrotIteraciok.java
 *
 * DIGIT 2005, Javat tanítok
 * Bátfai Norbert, nbatfai@inf.unideb.hu
 *
 */
/**
 * A nagyított Mandelbrot halmazok adott pontjában képes
 * nyomonkövetni az z_{n+1} = z_n * z_n + c iterációt.
 *
 * @author Bátfai Norbert, nbatfai@inf.unideb.hu
 * @version 0.0.1
 */
public class MandelbrotIteraciok implements Runnable{
    /** Mennyi időt várakozzunk két iteráció bemutatása között? */
    private int varakozas;
    // Kissé igaz redundánsan, s nem szépen, de kényelmesen:
    private MandelbrotHalmazNagyito nagyito;
    private int j, k;
    private double a, b, c, d;
    private  int szelesseg, magassag;
    private java.awt.image.BufferedImage kep;
    /**
     * Létrehoz egy iterációkat vizsgáló <code>MandelbrotIteraciok</code>
     * szál objektumot egy adott <code>MandelbrotHalmazNagyito</code>
     * objektumhoz.
     *
     * @param      nagyito      egy <code>MandelbrotHalmazNagyito</code> objektum
     * @param      varakozas    várakozási idő
     */
    public MandelbrotIteraciok(MandelbrotHalmazNagyito nagyito, int varakozas) {
        this.nagyito = nagyito;
        this.varakozas = varakozas;
        j = nagyito.getY();
        k = nagyito.getX();
        a = nagyito.getA();
        b = nagyito.getB();
        c = nagyito.getC();
        d = nagyito.getD();
        kep = nagyito.kep();
        szelesseg  = nagyito.getSz();
        magassag = nagyito.getM();
    }
    /** Az vizsgált pontból induló iterációk bemutatása. */
    public void run() {
        /* Az alábbi kód javarészt a MandelbrotHalmaz.java számolást
         végző run() módszeréből származik, hiszen ugyanazt csináljuk,
         csak most nem a hálón megyünk végig, hanem a háló adott a
         példányosításunkkor az egérmutató mutatta csomópontjában (ennek
         felel meg a c kompelx szám) számolunk, tehát a két külső for
         ciklus nem kell. */
        // A [a,b]x[c,d] tartományon milyen sűrű a
        // megadott szélesség, magasság háló:
        double dx = (b-a)/szelesseg;
        double dy = (d-c)/magassag;
        double reC, imC, reZ, imZ, ujreZ, ujimZ;
        // Hány iterációt csináltunk?
        int iteracio = 0;
        // c = (reC, imC) a háló rácspontjainak
        // megfelelő komplex szám
        reC = a+k*dx;
        imC = d-j*dy;
        // z_0 = 0 = (reZ, imZ)
        reZ = 0;
        imZ = 0;
        iteracio = 0;
        // z_{n+1} = z_n * z_n + c iterációk
        // számítása, amíg |z_n| < 2 vagy még
        // nem értük el a 255 iterációt, ha
        // viszont elértük, akkor úgy vesszük,
        // hogy a kiinduláci c komplex számra
        // az iteráció konvergens, azaz a c a
        // Mandelbrot halmaz eleme
        while(reZ*reZ + imZ*imZ < 4 && iteracio < 255) {
            // z_{n+1} = z_n * z_n + c
            ujreZ = reZ*reZ - imZ*imZ + reC;
            ujimZ = 2*reZ*imZ + imC;

            // az iteráció (reZ, imZ) -> (ujreZ, ujimZ)
            // ezt az egyenest kell kirajzolnunk, de most
            // a komplex számokat vissza kell transzformálnunk
            // a rács oszlop, sor koordinátájává:
            java.awt.Graphics g = kep.getGraphics();
            g.setColor(java.awt.Color.WHITE);
            g.drawLine(
                    (int)((reZ - a)/dx),
                    (int)((d - imZ)/dy),
                    (int)((ujreZ - a)/dx),
                    (int)((d - ujimZ)/dy)
                    );
            g.dispose();
            nagyito.repaint();

            reZ = ujreZ;
            imZ = ujimZ;

            ++iteracio;
            // Várakozunk, hogy közben csodálhassuk az iteráció
            // látványát:
            try {
                Thread.sleep(varakozas);
            } catch (InterruptedException e) {}
        }
    }
}
