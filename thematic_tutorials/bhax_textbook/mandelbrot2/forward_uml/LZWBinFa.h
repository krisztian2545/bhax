
#ifndef LZWBINFA_H
#define LZWBINFA_H

#include string

/**
  * class LZWBinFa
  * osztályon belűl csak prototípusok legyenek,<<operátor kiiktatása,szeggyük külön
  * a programot 3 részre
  */

class LZWBinFa
{
public:

 // Constructors/Destructors
 //  


 /**
  * Empty Constructor
  */
 LZWBinFa ();

 /**
  * Empty Destructor
  */
 virtual ~LZWBinFa ();

 // Static Public attributes
 //  

 // Public attributes
 //  


 // Public attribute accessor methods
 //  


 // Public attribute accessor methods
 //  



 /**
  * @param  b
  */
 void operator_ (char b)
 {
 }


 /**
  */
 void kiir ()
 {
 }


 /**
  * A változatosság kedvéért ezeket az osztálydefiníció (class LZWBinFa {...};) után
  * definiáljuk,
  * hogy kénytelen légy az LZWBinFa és a :: hatókör operátorral minősítve definiálni
  * :) l. lentebb
  * @return int
  */
 int getMelyseg ()
 {
 }


 /**
  * @return double
  */
 double getAtlag ()
 {
 }


 /**
  * @return double
  */
 double getSzoras ()
 {
 }


 /**
  * @return std::ostream&
  * @param  os
  * @param  bf
  */
 std::ostream& operator_ (std::ostream& os, LZWBinFa& bf)
 {
 }


 /**
  * @param  os
  */
 void kiir (std::ostream& os)
 {
 }


 /**
  */
 void ki ()
 {
 }


 /**
  * @param  elem
  */
 void szabadit (Csomopont* elem)
 {
 }

protected:

 // Static Protected attributes
 //  

 // Protected attributes
 //  

 // A fában tagként benne van egy csomópont, ez erősen ki van tüntetve, Ő a gyökér: 
 Csomopont* gyoker;
 int maxMelyseg;
 double atlag;
 double szoras;
public:


 // Protected attribute accessor methods
 //  

protected:

public:


 // Protected attribute accessor methods
 //  


 /**
  * Set the value of gyoker
  * A fában tagként benne van egy csomópont, ez erősen ki van tüntetve, Ő a gyökér:
  * @param new_var the new value of gyoker
  */
 void setGyoker (Csomopont* new_var)  {
   gyoker = new_var;
 }

 /**
  * Get the value of gyoker
  * A fában tagként benne van egy csomópont, ez erősen ki van tüntetve, Ő a gyökér:
  * @return the value of gyoker
  */
 Csomopont* getGyoker ()  {
  return gyoker;
 }

 /**
  * Set the value of maxMelyseg
  * @param new_var the new value of maxMelyseg
  */
 void setMaxMelyseg (int new_var)  {
   maxMelyseg = new_var;
 }

 /**
  * Get the value of maxMelyseg
  * @return the value of maxMelyseg
  */
 int getMaxMelyseg ()  {
  return maxMelyseg;
 }

 /**
  * Set the value of atlag
  * @param new_var the new value of atlag
  */
 void setAtlag (double new_var)  {
   atlag = new_var;
 }

 /**
  * Get the value of atlag
  * @return the value of atlag
  */
 double getAtlag ()  {
  return atlag;
 }

 /**
  * Set the value of szoras
  * @param new_var the new value of szoras
  */
 void setSzoras (double new_var)  {
   szoras = new_var;
 }

 /**
  * Get the value of szoras
  * @return the value of szoras
  */
 double getSzoras ()  {
  return szoras;
 }
protected:



 /**
  * @param  elem
  */
 void rmelyseg (Csomopont* elem)
 {
 }


 /**
  * @param  elem
  */
 void ratlag (Csomopont* elem)
 {
 }


 /**
  * @param  elem
  */
 void rszoras (Csomopont* elem)
 {
 }

private:

 // Static Private attributes
 //  

 // Private attributes
 //  

 // van nulla
 int vann;
 // nincs nulla
 int nincsn;
 // van egy
 int vane;
 // nincs egy
 int nincse;
 // Mindig a fa "LZW algoritmus logikája szerinti aktuális" csomópontjára mutat 
 Csomopont* fa;
 // technikai
 int melyseg;
 int atlagosszeg;
 int atlagdb;
 double szorasosszeg;
public:


 // Private attribute accessor methods
 //  

private:

public:


 // Private attribute accessor methods
 //  


 /**
  * Set the value of vann
  * van nulla
  * @param new_var the new value of vann
  */
 void setVann (int new_var)  {
   vann = new_var;
 }

 /**
  * Get the value of vann
  * van nulla
  * @return the value of vann
  */
 int getVann ()  {
  return vann;
 }

 /**
  * Set the value of nincsn
  * nincs nulla
  * @param new_var the new value of nincsn
  */
 void setNincsn (int new_var)  {
   nincsn = new_var;
 }

 /**
  * Get the value of nincsn
  * nincs nulla
  * @return the value of nincsn
  */
 int getNincsn ()  {
  return nincsn;
 }

 /**
  * Set the value of vane
  * van egy
  * @param new_var the new value of vane
  */
 void setVane (int new_var)  {
   vane = new_var;
 }

 /**
  * Get the value of vane
  * van egy
  * @return the value of vane
  */
 int getVane ()  {
  return vane;
 }

 /**
  * Set the value of nincse
  * nincs egy
  * @param new_var the new value of nincse
  */
 void setNincse (int new_var)  {
   nincse = new_var;
 }

 /**
  * Get the value of nincse
  * nincs egy
  * @return the value of nincse
  */
 int getNincse ()  {
  return nincse;
 }

 /**
  * Set the value of fa
  * Mindig a fa "LZW algoritmus logikája szerinti aktuális" csomópontjára mutat
  * @param new_var the new value of fa
  */
 void setFa (Csomopont* new_var)  {
   fa = new_var;
 }

 /**
  * Get the value of fa
  * Mindig a fa "LZW algoritmus logikája szerinti aktuális" csomópontjára mutat
  * @return the value of fa
  */
 Csomopont* getFa ()  {
  return fa;
 }

 /**
  * Set the value of melyseg
  * technikai
  * @param new_var the new value of melyseg
  */
 void setMelyseg (int new_var)  {
   melyseg = new_var;
 }

 /**
  * Get the value of melyseg
  * technikai
  * @return the value of melyseg
  */
 int getMelyseg ()  {
  return melyseg;
 }

 /**
  * Set the value of atlagosszeg
  * @param new_var the new value of atlagosszeg
  */
 void setAtlagosszeg (int new_var)  {
   atlagosszeg = new_var;
 }

 /**
  * Get the value of atlagosszeg
  * @return the value of atlagosszeg
  */
 int getAtlagosszeg ()  {
  return atlagosszeg;
 }

 /**
  * Set the value of atlagdb
  * @param new_var the new value of atlagdb
  */
 void setAtlagdb (int new_var)  {
   atlagdb = new_var;
 }

 /**
  * Get the value of atlagdb
  * @return the value of atlagdb
  */
 int getAtlagdb ()  {
  return atlagdb;
 }

 /**
  * Set the value of szorasosszeg
  * @param new_var the new value of szorasosszeg
  */
 void setSzorasosszeg (double new_var)  {
   szorasosszeg = new_var;
 }

 /**
  * Get the value of szorasosszeg
  * @return the value of szorasosszeg
  */
 double getSzorasosszeg ()  {
  return szorasosszeg;
 }
private:



 /**
  * @param
  */
  LZWBinFa (const LZWBinFa& )
 {
 }


 /**
  * szokásosan: nocopyable
  * @return LZWBinFa&
  * @param
  */
 LZWBinFa& operator_ (const LZWBinFa& )
 {
 }


 /**
  * @param  elem
  * @param  os
  */
 void kiir (Csomopont* elem, std::ostream& os)
 {
 }

 void initAttributes () ;

};

#endif // LZWBINFA_H
