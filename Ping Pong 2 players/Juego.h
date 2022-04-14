#pragma once
#pragma once
#include <iostream>

using namespace System::Drawing;
using namespace std;
using namespace System;

class Juego {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int alto;
	int ancho;
public:
	Juego() {
		this->x = 0;
		this->y = 0;
		this->dx = 0;
		this->dy = 0;
		this->alto = 0;
		this->ancho = 0;
	}
	~Juego() {}

	//Set y Gets
	void Set_x(int x) { this->x = x; }
	int Get_x() { return this->x; }

	void Set_y(int y) { this->y = y; }
	int Get_y() { return this->y; }

	void Set_alto(int alto) { this->alto = alto; }
	int Get_alto() { return this->alto; }

	void Set_ancho(int ancho) { this->ancho = ancho; }
	int Get_ancho() { return this->ancho; }

	void Set_dx(int dx) { this->dx = dx; }
	int Get_dx() { return this->dx; }

	void Set_dy(int dy) { this->dy = dy; }
	int Get_dy() { return this->dy; }

	virtual void borrar() {};
	void mover() {};
	virtual void dibujar() {};


	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
