#include <iostream>
using namespace std;

class Artikel {
private:
   int artno;
   int preis;
   int staffel[5] = {1, 3, 5, 10, 20};

public:
   // Konstruktoren
   Artikel () {}
   Artikel (int n, int p) {
      artno = n;
      preis = p;
   }

   // Getter
   int getPreis() {
      // Ohne Rabatt
      return preis;
   }
   int getPreis(int kt) {
      // Mit Rabatt
      return preis * (100 - staffel[kt-1]) / 100;
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

   return 0;
}
