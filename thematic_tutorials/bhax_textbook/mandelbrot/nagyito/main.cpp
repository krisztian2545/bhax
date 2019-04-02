// main.cpp
//
// Mandelbrot halmaz rajzol�
// Programoz� P�ternoszter
//
// Copyright (C) 2011, B�tfai Norbert, nbatfai@inf.unideb.hu, nbatfai@gmail.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// B�r a Nokia Qt SDK �ppen tartalmaz egy Mandelbrotos p�ld�t, de
// ezt nem tartottam megfelel�nek els� Qt programk�nt aj�nlani, mert el�g
// bonyolult: haszn�l k�lcs�n�s kiz�r�st stb. Ez�rt "from scratch" meg�rtam
// egy saj�tot a Jav�t tan�tokhoz �rt dallam�ra:
// http://www.tankonyvtar.hu/informatika/javat-tanitok-2-2-080904-1
//

#include <QApplication>
#include "frakablak.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Tov�bbi adatokat olvashatsz le innen:
    // http://www.tankonyvtar.hu/informatika/javat-tanitok-2-3-080904
    FrakAblak w1;
    w1.show();

    /*
    FrakAblak w1,
    w2(-.08292191725019529, -.082921917244591272,
       -.9662079988595939, -.9662079988551173, 600, 3000),
    w3(-.08292191724880625, -.0829219172470933,
       -.9662079988581493, -.9662079988563615, 600, 4000),
    w4(.14388310361318304, .14388310362702217,
       .6523089200729396, .6523089200854384, 600, 38655);
    w1.show();
    w2.show();
    w3.show();
    w4.show();
*/
    return a.exec();
}
