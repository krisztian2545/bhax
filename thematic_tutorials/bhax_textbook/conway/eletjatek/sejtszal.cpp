// sejtszal.cpp
//
// letjtk rajzol
// Programoz Pternoszter
//
// Copyright (C) 2011, Btfai Norbert, nbatfai@inf.unideb.hu, nbatfai@gmail.com
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
// Ez a program szabad szoftver; terjeszthet illetve mdosthat a
// Free Software Foundation ltal kiadott GNU General Public License
// dokumentumban lertak; akr a licenc 3-as, akr (tetszleges) ksbbi
// vltozata szerint.
//
// Ez a program abban a remnyben kerl kzreadsra, hogy hasznos lesz,
// de minden egyb GARANCIA NLKL, az ELADHATSGRA vagy VALAMELY CLRA
// VAL ALKALMAZHATSGRA val szrmaztatott garancit is belertve.
// Tovbbi rszleteket a GNU General Public License tartalmaz.
//
// A felhasznlnak a programmal egytt meg kell kapnia a GNU General
// Public License egy pldnyt; ha mgsem kapta meg, akkor
// tekintse meg a <http://www.gnu.org/licenses/> oldalon.
//
//
// Version history:
//
// 0.0.1    A kt osztly tervezsnek f szempontja az volt, hogy
// ne vagy alig klnbzzn az els C++-os pldtl, a Mandelostl:
// http://progpater.blog.hu/2011/02/26/tan_csodallak_amde_nem_ertelek_de_kepzetem_hegyvolgyedet_bejarja
// ezrt az olyan knyesebb dolgokkal, hogy kezeljk a racsIndex-et a
// kt osztlyra bontott C++ megoldsban, amikor rjuk t a Javsbl, nem foglalkoztunk
// a kiindul Javs: http://www.tankonyvtar.hu/informatika/javat-tanitok-1-2-080904-1
// (a bazr eszme: Release Early, Release Often" rjuk ki a posztra)
//

#include "sejtszal.h"

SejtSzal::SejtSzal(bool ***racsok, int szelesseg, int magassag, int varakozas, SejtAblak *sejtAblak)
{
    this->racsok = racsok;
    this->szelesseg = szelesseg;
    this->magassag = magassag;
    this->varakozas = varakozas;
    this->sejtAblak = sejtAblak;

    racsIndex = 0;
}

/**
   * Az krdezett llapotban lv nyolcszomszdok szma.
   *
   * @param   rcs    a sejttr rcs
   * @param   sor     a rcs vizsglt sora
   * @param   oszlop  a rcs vizsglt oszlopa
   * @param   llapor a nyolcszomszdok vizsglt llapota
   * @return int a krdezett llapotbeli nyolcszomszdok szma.
   */
int SejtSzal::szomszedokSzama(bool **racs,
                              int sor, int oszlop, bool allapot) {
    int allapotuSzomszed = 0;
    // A nyolcszomszdok vgigzongorzsa:
    for(int i=-1; i<2; ++i)
        for(int j=-1; j<2; ++j)
            // A vizsglt sejtet magt kihagyva:
            if(!((i==0) && (j==0))) {
        // A sejttrbl szlnek szomszdai
        // a szembe oldalakon ("peridikus hatrfelttel")
        int o = oszlop + j;
        if(o < 0)
            o = szelesseg-1;
        else if(o >= szelesseg)
            o = 0;

        int s = sor + i;
        if(s < 0)
            s = magassag-1;
        else if(s >= magassag)
            s = 0;

        if(racs[s][o] == allapot)
            ++allapotuSzomszed;
    }

    return allapotuSzomszed;
}

/**
 * A sejttr idbeli fejldse a John H. Conway fle
 * letjtk sejtautomata szablyai alapjn trtnik.
 * A szablyok rszletes ismertetst lsd pldul a
 * [MATEK JTK] hivatkozsban (Cskny Bla: Diszkrt
 * matematikai jtkok. Polygon, Szeged 1998. 171. oldal.)
 */
void SejtSzal::idoFejlodes() {

    bool **racsElotte = racsok[racsIndex];
    bool **racsUtana = racsok[(racsIndex+1)%2];

    for(int i=0; i<magassag; ++i) { // sorok
        for(int j=0; j<szelesseg; ++j) { // oszlopok

            int elok = szomszedokSzama(racsElotte, i, j, SejtAblak::ELO);

            if(racsElotte[i][j] == SejtAblak::ELO) {
                /* l l marad, ha kett vagy hrom l
             szomszedja van, klnben halott lesz. */
                if(elok==2 || elok==3)
                    racsUtana[i][j] = SejtAblak::ELO;
                else
                    racsUtana[i][j] = SejtAblak::HALOTT;
            }  else {
                /* Halott halott marad, ha hrom l
             szomszedja van, klnben l lesz. */
                if(elok==3)
                    racsUtana[i][j] = SejtAblak::ELO;
                else
                    racsUtana[i][j] = SejtAblak::HALOTT;
            }
        }
    }
    racsIndex = (racsIndex+1)%2;
}


/** A sejttr idbeli fejldse. */
void SejtSzal::run()
{
    while(true) {
        QThread::msleep(varakozas);
        idoFejlodes();
        sejtAblak->vissza(racsIndex);
    }

}

SejtSzal::~SejtSzal()
{
}
