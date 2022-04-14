#pragma once
#include "Juego.h"

class Player1 : public Juego {
public:
	Player1() : Juego() {
		this->x = 10;
		this->y = 10;
		this->dy = 1;
		this->alto = 3;
		this->ancho = 2;
	};
	~Player1() {};
	void borrar() {
		Console::SetCursorPosition(x, y); cout << "  ";
		Console::SetCursorPosition(x, y + 1); cout << "  ";
		Console::SetCursorPosition(x, y + 2); cout << "  ";
	}

	void mover(char index) {
		switch (index)
		{
		case 'W':
			if (y > 6) y -= dy; break;
		case 'S':
			if (y + alto < 30) y += dy; break;
		}
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(x, y); cout << "||";
		Console::SetCursorPosition(x, y + 1); cout << "||";
		Console::SetCursorPosition(x, y + 2); cout << "||";
		Console::ForegroundColor = ConsoleColor::White;
	}

};
