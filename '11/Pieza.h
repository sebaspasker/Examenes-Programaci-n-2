#include <iostream>

using namespace std;

class Pieza {
	private:
		char tipo;
		bool color;

	public:
		Pieza(char tipo = ' ', bool color=false);
		char getTipo() const;
		bool getColor() const;
		bool IsVacia() const;
		void SetVacia();	
};