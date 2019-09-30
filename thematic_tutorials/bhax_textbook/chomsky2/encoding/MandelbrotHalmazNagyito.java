/*
 * MandelbrotHalmazNagyito.java
 *
 * DIGIT 2005, Javat tanítok
 * Bátfai Norbert, nbatfai@inf.unideb.hu
 *
 */
/**
 * A Mandelbrot halmazt nagyító és kirajzoló osztály.
 *
 * @author Bátfai Norbert, nbatfai@inf.unideb.hu
 * @version 0.0.2
 */
public class MandelbrotHalmazNagyito extends MandelbrotHalmaz {
    /** A nagyítandó kijelölt területet bal felső sarka. */
    private int x, y;
    /** A nagyítandó kijelölt terület szélessége és magassága. */
    private int mx, my;
    /**
     * Létrehoz egy a Mandelbrot halmazt a komplex sík
     * [a,b]x[c,d] tartománya felett kiszámoló és nygítani tudó
     * <code>MandelbrotHalmazNagyito</code> objektumot.
     *
     * @param      a              a [a,b]x[c,d] tartomány a koordinátája.
     * @param      b              a [a,b]x[c,d] tartomány b koordinátája.
     * @param      c              a [a,b]x[c,d] tartomány c koordinátája.
     * @param      d              a [a,b]x[c,d] tartomány d koordinátája.
     * @param      szelesseg      a halmazt tartalmazó tömb szélessége.
     * @param      iteraciosHatar a számítás pontossága.
     */
    public MandelbrotHalmazNagyito(double a, double b, double c, double d,
            int szelesseg, int iteraciosHatar) {
        // Az ős osztály konstruktorának hívása
        super(a, b, c, d, szelesseg, iteraciosHatar);
        setTitle("A Mandelbrot halmaz nagyításai");
        // Egér kattintó események feldolgozása:
        addMouseListener(new java.awt.event.MouseAdapter() {
            // Egér kattintással jelöljük ki a nagyítandó területet
            // bal felső sarkát vagy ugyancsak egér kattintással
            // vizsgáljuk egy adott pont iterációit:
            public void mousePressed(java.awt.event.MouseEvent m) {
                // Az egérmutató pozíciója
                x = m.getX();
                y = m.getY();
                // Az 1. egér gombbal a nagyítandó terület kijelölését
                // végezzük:
                if(m.getButton() == java.awt.event.MouseEvent.BUTTON1 ) {
                    // A nagyítandó kijelölt területet bal felső sarka: (x,y)
                    // és szelessege (majd a vonszolás növeli)
                    mx = 0;
                    my = 0;
                    repaint();
                } else {
                    // Nem az 1. egér gombbal az egérmutató mutatta c
                    // komplex számból indított iterációkat vizsgálhatjuk
                    MandelbrotIteraciok iteraciok =
                            new MandelbrotIteraciok(
                            MandelbrotHalmazNagyito.this, 50);
                    new Thread(iteraciok).start();
                }
            }
            // Vonszolva kijelölünk egy területet...
            // Ha felengedjük, akkor a kijelölt terület
            // újraszámítása indul:
            public void mouseReleased(java.awt.event.MouseEvent m) {
                if(m.getButton() == java.awt.event.MouseEvent.BUTTON1 ) {
                    double dx = (MandelbrotHalmazNagyito.this.b
                            - MandelbrotHalmazNagyito.this.a)
                            /MandelbrotHalmazNagyito.this.szelesseg;
                    double dy = (MandelbrotHalmazNagyito.this.d
                            - MandelbrotHalmazNagyito.this.c)
                            /MandelbrotHalmazNagyito.this.magassag;
                    // Az új Mandelbrot nagyító objektum elkészítése:
                    new MandelbrotHalmazNagyito(
                            MandelbrotHalmazNagyito.this.a+x*dx,
                            MandelbrotHalmazNagyito.this.a+x*dx+mx*dx,
                            MandelbrotHalmazNagyito.this.d-y*dy-my*dy,
                            MandelbrotHalmazNagyito.this.d-y*dy,
                            600,
                            MandelbrotHalmazNagyito.this.iteraciosHatar);
                }
            }
        });
        // Egér mozgás események feldolgozása:
        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            // Vonszolással jelöljük ki a négyzetet:
            public void mouseDragged(java.awt.event.MouseEvent m) {
                // A nagyítandó kijelölt terület szélessége és magassága:
                mx = m.getX() - x;
                my = m.getY() - y;
                repaint();
            }
        });
    }
    /**
     * Pillanatfelvételek készítése.
     */
    public void pillanatfelvetel() {
        // Az elmentendő kép elkészítése:
        java.awt.image.BufferedImage mentKep =
                new java.awt.image.BufferedImage(szelesseg, magassag,
                java.awt.image.BufferedImage.TYPE_INT_RGB);
        java.awt.Graphics g = mentKep.getGraphics();
        g.drawImage(kep, 0, 0, this);
        g.setColor(java.awt.Color.BLACK);
        g.drawString("a=" + a, 10, 15);
        g.drawString("b=" + b, 10, 30);
        g.drawString("c=" + c, 10, 45);
        g.drawString("d=" + d, 10, 60);
        g.drawString("n=" + iteraciosHatar, 10, 75);
        if(szamitasFut) {
            g.setColor(java.awt.Color.RED);
            g.drawLine(0, sor, getWidth(), sor);
        }
        g.setColor(java.awt.Color.GREEN);
        g.drawRect(x, y, mx, my);
        g.dispose();
        // A pillanatfelvetel képfájl nevének képzése:
        StringBuffer sb = new StringBuffer();
        sb = sb.delete(0, sb.length());
        sb.append("MandelbrotHalmazNagyitas_");
        sb.append(++pillanatfelvetelSzamlalo);
        sb.append("_");
        // A fájl nevébe belevesszük, hogy melyik tartományban
        // találtuk a halmazt:
        sb.append(a);
        sb.append("_");
        sb.append(b);
        sb.append("_");
        sb.append(c);
        sb.append("_");
        sb.append(d);
        sb.append(".png");
        // png formátumú kepet mentünk
        try {
            javax.imageio.ImageIO.write(mentKep, "png",
                    new java.io.File(sb.toString()));
        } catch(java.io.IOException e) {
            e.printStackTrace();
        }
    }
    /**
     * A nagyítandó kijelölt területet jelző négyzet kirajzolása.
     */
    public void paint(java.awt.Graphics g) {
        // A Mandelbrot halmaz kirajzolása
        g.drawImage(kep, 0, 0, this);
        // Ha éppen fut a számítás, akkor egy vörös
        // vonallal jelöljük, hogy melyik sorban tart:
        if(szamitasFut) {
            g.setColor(java.awt.Color.RED);
            g.drawLine(0, sor, getWidth(), sor);
        }
        // A jelző négyzet kirajzolása:
        g.setColor(java.awt.Color.GREEN);
        g.drawRect(x, y, mx, my);
    }
    /**
     * Hol áll az egérmutató?
     * @return int a kijelölt pont oszlop pozíciója.
     */
    public int getX() {
        return x;
    }
    /**
     * Hol áll az egérmutató?
     * @return int a kijelölt pont sor pozíciója.
     */
    public int getY() {
        return y;
    }
    /**
     * Példányosít egy Mandelbrot halmazt nagyító obektumot.
     */
    public static void main(String[] args) {
        // A kiinduló halmazt a komplex sík [-2.0, .7]x[-1.35, 1.35]
        // tartományában keressük egy 600x600-as hálóval és az
        // aktuális nagyítási pontossággal:
        new MandelbrotHalmazNagyito(-2.0, .7, -1.35, 1.35, 600, 255);
    }
}
