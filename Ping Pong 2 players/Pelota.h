#pragma once
#include "Juego.h"

class Pelota : public Juego {
public:
	Pelota() :Juego() {
		Random r;
		this->x = 50;
		this->y = r.Next(10,20);
		this->dx = rand() % 2 + 1;
		this->dy = rand() % 2 + 1;
		this->alto = 1;
		this->ancho = 1;
	};
	~Pelota() {}
	void borrar() {
		Console::SetCursorPosition(x, y);
		cout << " ";
	};
	void mover() {
		if (x <= 6 || x + ancho >= 90) {
			dx *= -1;
		}

		if (y <= 6 || y + alto >= 30)
		{
			dy *= -1;
		}

		y += dy;
		x += dx;
	};
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);
		cout << "O";
		Console::ForegroundColor = ConsoleColor::White;
	}
	void rebote() {
		dx *= -1;
		dy *= -1;
	}


};
