#pragma once
#include "Juego.h"
class PlayerAuto : public Juego {
public:
	PlayerAuto() : Juego() {
		this->x = 80;
		this->y = 10;
		this->dy = 1;
		this->dx = 0;
		this->alto = 3;
		this->ancho = 2;
	};
	~PlayerAuto() {};
	void borrar() {
		Console::SetCursorPosition(x, y); cout << "  ";
		Console::SetCursorPosition(x, y + 1); cout << "  ";
		Console::SetCursorPosition(x, y + 2); cout << "  ";
	}

	void mover() {
		if (y <= 6 || y + alto + dy > 30)
		{
			dy *= -1;
		}
		y += dy;
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y); cout << "||";
		Console::SetCursorPosition(x, y + 1); cout << "||";
		Console::SetCursorPosition(x, y + 2); cout << "||";
		Console::ForegroundColor = ConsoleColor::White;
	}

};
