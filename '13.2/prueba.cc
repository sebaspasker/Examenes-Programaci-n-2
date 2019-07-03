#include <iostream>
#include <stdlib.h>
#include "Partida.h"
using namespace std;
int main()
{
srand(2);
Partida p(2);
p.jugar();
cout << p << endl;
// Creamos una partida para 2 jugadores
// Los jugadores introducen palabras hasta terminar la partida con "q"
// Se imprimen las puntuaciones finales
}