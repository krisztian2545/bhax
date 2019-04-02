// frakablak.cpp
//
// Mandelbrot halmaz nagy�t�
// Programoz� P�ternoszter
//
// Copyright (C) 2011, B�tfai Norbert, nbatfai@inf.unideb.hu, nbatfai@gmail.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Ez a program szabad szoftver; terjeszthet� illetve m�dos�that� a
// Free Software Foundation �ltal kiadott GNU General Public License
// dokumentum�ban le�rtak; ak�r a licenc 3-as, ak�r (tetsz�leges) k�s�bbi
// v�ltozata szerint.
//
// Ez a program abban a rem�nyben ker�l k�zread�sra, hogy hasznos lesz,
// de minden egy�b GARANCIA N�LK�L, az ELADHAT�S�GRA vagy VALAMELY C�LRA
// VAL� ALKALMAZHAT�S�GRA val� sz�rmaztatott garanci�t is bele�rtve.
// Tov�bbi r�szleteket a GNU General Public License tartalmaz.
//
// A felhaszn�l�nak a programmal egy�tt meg kell kapnia a GNU General
// Public License egy p�ld�ny�t; ha m�gsem kapta meg, akkor
// tekintse meg a <http://www.gnu.org/licenses/> oldalon.
//
//
// Version history:
//
// 0.0.1    B�r a Nokia Qt SDK �ppen tartalmaz egy Mandelbrotos p�ld�t, de
// ezt nem tartottam megfelel�nek els� Qt programk�nt aj�nlani, mert el�g
// bonyolult: haszn�l k�lcs�n�s kiz�r�st stb. Ez�rt "from scratch" meg�rtam
// egy saj�tot a Jav�t tan�tokhoz �rt dallam�ra:
// http://www.tankonyvtar.hu/informatika/javat-tanitok-2-2-080904-1
//

#include "frakablak.h"

FrakAblak::FrakAblak(double a, double b, double c, double d,
                     int szelesseg, int iteraciosHatar, QWidget *parent)
                         : QMainWindow(parent)
{
    setWindowTitle("Biomorfok");

    szamitasFut = true;
    x = y = mx = my = 0;
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->szelesseg = szelesseg;
    this->iteraciosHatar = iteraciosHatar;
    magassag = (int)(szelesseg * ((d-c)/(b-a)));

    setFixedSize(QSize(szelesseg, magassag));
    fraktal= new QImage(szelesseg, magassag, QImage::Format_RGB32);

    savec = 0;
    
    mandelbrot = new FrakSzal(a, b, c, d, szelesseg, magassag, iteraciosHatar, this);
    mandelbrot->start();
}

FrakAblak::~FrakAblak()
{
    delete fraktal;
    delete mandelbrot;
}

void FrakAblak::paintEvent(QPaintEvent*) {
    QPainter qpainter(this);
    qpainter.drawImage(0, 0, *fraktal);
    if(!szamitasFut) {
        qpainter.setPen(QPen(Qt::white, 1));
        qpainter.drawRect(x, y, mx, my);

    }
    qpainter.end();
}

void FrakAblak::mousePressEvent(QMouseEvent* event) {

    // A nagy�tand� kijel�lt ter�letet bal fels� sarka:
    x = event->x();
    y = event->y();
    mx = 0;
    my = 0;

    update();
}

void FrakAblak::mouseMoveEvent(QMouseEvent* event) {

    // A nagy�tand� kijel�lt ter�let sz�less�ge �s magass�ga:
    mx = event->x() - x;
    my = mx; // n�gyzet alak�

    update();
}

void FrakAblak::mouseReleaseEvent(QMouseEvent* event) {

    if(szamitasFut)
        return;

    szamitasFut = true;

    double dx = (b-a)/szelesseg;
    double dy = (d-c)/magassag;

    double a = this->a+x*dx;
    double b = this->a+x*dx+mx*dx;
    double c = this->d-y*dy-my*dy;
    double d = this->d-y*dy;

    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;

    delete mandelbrot;
    mandelbrot = new FrakSzal(a, b, c, d, szelesseg, magassag, iteraciosHatar, this);
    mandelbrot->start();

    update();
}

void FrakAblak::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_N)
  {
    if(szamitasFut)
        return;

        iteraciosHatar *= 2;
    szamitasFut = true;

    delete mandelbrot;
    mandelbrot = new FrakSzal(a, b, c, d, szelesseg, magassag, iteraciosHatar, this);
    mandelbrot->start();
  }
  else if (event->key() == Qt::Key_S)
  {
    fraktal->save("mandel_"+QString::number(savec++)+".png");
  }
}


void FrakAblak::vissza(int magassag, int *sor, int meret)
{
    for(int i=0; i<meret; ++i) {
      QRgb szin = qRgb(255-(sor[i]/16)%256, (sor[i]%256), (sor[i]%32));
        fraktal->setPixel(i, magassag, szin);
    }
    update();
}

void FrakAblak::vissza(void)
{
    szamitasFut = false;
    x = y = mx = my = 0;
}
