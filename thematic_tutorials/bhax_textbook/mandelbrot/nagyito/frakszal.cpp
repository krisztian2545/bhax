// frakszal.cpp
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

#include "frakszal.h"

FrakSzal::FrakSzal(double a, double b, double c, double d,
                   int szelesseg, int magassag, int iteraciosHatar, FrakAblak *frakAblak)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->szelesseg = szelesseg;
    this->iteraciosHatar = iteraciosHatar;
    this->frakAblak = frakAblak;
    this->magassag = magassag;

    egySor = new int[szelesseg];
}

FrakSzal::~FrakSzal()
{
    delete[] egySor;
}

// A sz�l k�dj�t a Jav�t tan�tokhoz �rt Java k�domb�l vettem �t
// http://www.tankonyvtar.hu/informatika/javat-tanitok-2-2-080904-1
// mivel itt az algoritmust is le�rtam/lerajzoltam, �gy meghagytam
// a kommenteket, hogy a hallgat� k�nnyen hozz�olvashassa az "elm�letet",
// ha �rdekli.
void FrakSzal::run()
{
    // A [a,b]x[c,d] tartom�nyon milyen s�r� a
    // megadott sz�less�g, magass�g h�l�:
    double dx = (b-a)/szelesseg;
    double dy = (d-c)/magassag;
    double reC, imC, reZ, imZ, ujreZ, ujimZ;
    // H�ny iter�ci�t csin�ltunk?
    int iteracio = 0;
    // V�gigzongor�zzuk a sz�less�g x magass�g h�l�t:
    for(int j=0; j<magassag; ++j) {
        //sor = j;
        for(int k=0; k<szelesseg; ++k) {
            // c = (reC, imC) a h�l� r�cspontjainak
            // megfelel� komplex sz�m
            reC = a+k*dx;
            imC = d-j*dy;
            // z_0 = 0 = (reZ, imZ)
	    std::complex<double> c(reC, imC);
	    
            reZ = 0;
            imZ = 0;	    
	    std::complex<double> z_n(reZ, imZ);
            iteracio = 0;
            // z_{n+1} = z_n * z_n + c iter�ci�k
            // sz�m�t�sa, am�g |z_n| < 2 vagy m�g
            // nem �rt�k el a 255 iter�ci�t, ha
            // viszont el�rt�k, akkor �gy vessz�k,
            // hogy a kiindul�ci c komplex sz�mra
            // az iter�ci� konvergens, azaz a c a
            // Mandelbrot halmaz eleme
	    /*
            while(reZ*reZ + imZ*imZ < 4 && iteracio < iteraciosHatar) {
                // z_{n+1} = z_n * z_n + c

	      ujreZ = reZ*reZ+ std::atan(reZ*reZ - imZ*imZ) + std::sqrt(reC);
	      ujimZ = 2*reZ*imZ+std::atan(2*reZ*imZ) + imC;

                reZ = ujreZ;
                imZ = ujimZ;

                ++iteracio;

            }
            */
	    while( std::abs(z_n) < 4 && iteracio < iteraciosHatar) {
     
	      z_n = std::cos(z_n*z_n)*std::pow(z_n, 5) + c*c;	      
	      
	      ++iteracio;
	    }  
	      
            // ha a < 4 felt�tel nem teljes�lt �s a
            // iter�ci� < iter�ci�sHat�r s�r�l�s�vel l�pett ki, azaz
            // feltessz�k a c-r�l, hogy itt a z_{n+1} = z_n * z_n + c
            // sorozat konvergens, azaz iter�ci� = iter�ci�sHat�r
            // ekkor az iter�ci� %= 256 egyenl� 255, mert az esetleges
            // nagy�tasok sor�n az iter�ci� = valah�ny * 256 + 255

            //iteracio /= 2;
            //double oo = iteracio / iteraciosHatar;
            //iteracio = oo*255;

	    
            //a sz�nez�st viszont m�r majd a FrakAblak oszt�lyban lesz
            egySor[k] = iteracio;
        }
        // �br�zol�sra �tadjuk a kisz�molt sort a FrakAblak-nak.
        frakAblak->vissza(j, egySor, szelesseg);
    }
    frakAblak->vissza();

}
