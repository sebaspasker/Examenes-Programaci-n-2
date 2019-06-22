#include <iostream>
#include "List.h"

using namespace std;

int main() {
List l("The best movies");
l.addMovie("Brian’s life, 4", Comedy);
l.addMovie("A New Hope, 5", SciFi);
l.addMovie("Sharknado, -10", SciFi); // Excepcion
l.addMovie("A New Hope, 5", SciFi); // Ya existe
l.addMovie("Monster’s Ball, 4",Drama);
cout << l << endl;
}