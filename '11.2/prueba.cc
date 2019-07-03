#include "Ciudad.h"
int main()
{
Ciudad c("Villa arriba");
c.leerVotos("elecciones.txt");
c.imprimirResultados();
cout << "Ganador: " << c.getGanador() << endl;
}