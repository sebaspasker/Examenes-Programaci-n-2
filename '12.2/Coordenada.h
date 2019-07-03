#include <iostream>
#include <cmath>

using namespace std;

class Coordenada {
	private:
		static bool coordenadaError;
		double x;
		double y;

	public:
		Coordenada(double x=-1, double y=-1);
		Coordenada(const Coordenada &c);
		double distancia(const Coordenada &c) const;
		bool isError() const;
		double getX() const;
		double getY() const;
		void setX(double x);
		void setY(double y);

};