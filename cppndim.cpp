#include <iostream>
using namespace std;

class Artikel {
private:
   int artno;
   int preis;
   int staffel[2][5];
   
   int getRabatt(int kt) {
      // Normalerweise kein Rabatt
      int r = 0;
      for (int i=0; i<5; i++) {
         // Falls in der ersten Zeile 
		 // der Kundentyp uebereinstimmt
         if (staffel[0][i]==kt) {
            // dann wird aus der zweiten Zeile
			// der Rabattsatz gelesen
            r = staffel[1][i];
         }
      }
      return r;
   }
   
public:
   // Konstruktoren
   Artikel () {}
   Artikel (int n, int p) {
      artno = n;
      preis = p;
      
      staffel[0][0] = 1;
      staffel[0][1] = 2;
      staffel[0][2] = 3;
      staffel[0][3] = 4;
      staffel[0][4] = 42;

      staffel[1][0] = 1;
      staffel[1][1] = 3;
      staffel[1][2] = 5;
      staffel[1][3] = 10;
      staffel[1][4] = 20;
   }

   // Getter
   int getPreis() {
      // Ohne Rabatt
      return preis;
   }
   int getPreis(int kt) {
      // Mit Rabatt
      return preis * (100 - getRabatt(kt)) / 100;
   }
};

int main(int argc, char* argv[])
{
   Artikel artikel(1, 100);
   
   cout << artikel.getPreis() << "\n";
   cout << artikel.getPreis(1) << "\n";
   cout << artikel.getPreis(2) << "\n";
   cout << artikel.getPreis(3) << "\n";
   cout << artikel.getPreis(4) << "\n";
   cout << artikel.getPreis(5) << "\n";
   cout << artikel.getPreis(42) << "\n";
   
   return 0;
}
