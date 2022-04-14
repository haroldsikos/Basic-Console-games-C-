#pragma once
#include "Pelota.h"
#include "PlayerAuto.h"
#include "Player1.h"
#include <vector>

class Controller {
private:
	vector<Pelota*> bola;
	PlayerAuto* PAuto;
	Player1* Player;
	int cont1;
	int cont2;
	int nBolas;

public:
	Controller() {
		PAuto = new PlayerAuto();
		Player = new Player1();
		cont1 = 0;
		cont2 = 0;
		nBolas = 1;
	}
	void addBola() {
		bola.push_back(new Pelota());
	}
	void BorrarTodo() {
		Console::SetCursorPosition(1, 1); cout << "         ";
		Console::SetCursorPosition(1, 2); cout << "         ";
		for (int i = 0; i < bola.size(); i++)
		{
			bola[i]->borrar();
		}

		PAuto->borrar();
		Player->borrar();
	}

	void MoverTodo() {
		for (int i = 0; i < bola.size(); i++)
		{
			bola[i]->mover();
		}
		PAuto->mover();
	}

	void DibujarTodo() {

		Console::SetCursorPosition(5, 5);
		for (int i = 0; i < 86; i++)
		{
			cout << "#";
		}
		Console::SetCursorPosition(5, 30);
		for (int i = 0; i < 85; i++)
		{
			cout << "#";
		}
		int k = 6;
		for (int i = 0; i < 25; i++)
		{
			Console::SetCursorPosition(5, k++);
			cout << "#\n";
		}
		int j = 6;
		for (int i = 0; i < 25; i++)
		{
			Console::SetCursorPosition(90, j++);
			cout << "#\n";
		}
		int l = 10;
		for (int i = 0; i < 15; i++)
		{
			Console::SetCursorPosition(50, l++);
			cout << "o\n";
		}



		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(5, 32); cout << "PUNTOS P1: " << cont1;
		Console::SetCursorPosition(80, 32); cout << "PUNTOS P2: " << cont2;
		Console::SetCursorPosition(80, 33); cout << "Cant bolas: " << bola.size() << "  " << nBolas;
		for (int i = 0; i < bola.size(); i++)
		{
			bola[i]->dibujar();
		}
		PAuto->dibujar();
		Player->dibujar();

	}
	void colision() {
		colisionPared();
		colisionPauto();
		colisionP1();
	}
	void colisionPared() {
		for (int i = 0; i < bola.size(); i++)
		{
			if (bola[i]->Get_x() >= 89)
			{
				bola[i]->Set_x(50);
				bola[i]->Set_y(17);
				cont1++;
			}
			if (bola[i]->Get_x() <= 6)
			{
				bola[i]->Set_x(50);
				bola[i]->Set_y(17);
				cont2++;
			}
		}
	}
	void colisionPauto() {

		for (int i = 0; i < bola.size(); i++)
		{
			if (bola[i]->getRectangle().IntersectsWith(Player->getRectangle()))
			{
				bola[i]->rebote();
				cont1++;
			}
		}
	}
	void colisionP1() {

		for (int i = 0; i < bola.size(); i++)
		{
			if (bola[i]->getRectangle().IntersectsWith(PAuto->getRectangle()))
			{
				bola[i]->rebote();
				cont2++;
			}
		}
	}
	void finJuego() {
		if (cont1 == 10 || cont2 == 10)
		{
			Console::Clear();
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(40, 12); cout << "FIN DEL JUEGO";
			Console::SetCursorPosition(40, 14); cout << "Ganador: ";
			if (cont1 == 10)
			{
				Console::SetCursorPosition(50, 14); cout << "PLAYER 1";
			}
			if (cont2 == 10)
			{
				Console::SetCursorPosition(50, 14); cout << "PLAYER 2";
			}
			Console::SetCursorPosition(40, 16); cout << "PUNTOS: ";
			Console::SetCursorPosition(40, 17); cout << "Player 1 - " << cont1 << " pts";
			Console::SetCursorPosition(40, 18); cout << "Player 2 - " << cont2 << " pts";
			_getch();
			exit(0);
		}
	
	}
	void validacionBolas_Pantalla() {
		if (cont1 == 0 && cont2 == 0)
		{
			addBola();
		}
		if (cont1 >= 5 && cont2 >=5)
		{
			addBola();
			addBola();
		}
		
	}

	Player1* getPlayer() { return Player; }
	vector<Pelota*> getBola() { return bola; }
	int getCont1() { return cont1; }
	void setCont1(int v) { cont1 = v; }

	int getCont2() { return cont2; }
	void setCont2(int v) { cont2 = v; }

};
