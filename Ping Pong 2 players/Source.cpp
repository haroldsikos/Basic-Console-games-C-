#include <iostream>
#include <conio.h>
#include "Controller.h"

int main() {
  
    Console::SetWindowSize(100, 35);
    Console::CursorVisible = false;
    srand(time(NULL));

    Controller* control = new Controller();

    char tecla;
    //Validacion añadir 3 pelotas (2 pelotas adicionales)

    control->validacionBolas_Pantalla();

    while (true)
    {
        control->BorrarTodo();
        control->colision();

        if (_kbhit())
        {
            tecla = _getch();
            tecla = toupper(tecla);
            control->getPlayer()->mover(tecla);
        }
        control->MoverTodo();
        control->DibujarTodo();
        control->finJuego();

        _sleep(50);
    }
    return 0;

}

