#include "carga_scripts.h"
#include <iostream>
#include <string>



struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const std::string &text) { std::cout << text << std::endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;

/* El usuario o bien coloca la ruta absoluta o bien a través de la ruta relativa colocando el archivo dentro del proyecto
referencia al nombre con su extensión */

const char* base_path = "../";

void load_script(const char* filename, bool show_script)
{
    std::string full_path = std::string(base_path) + filename; //Se añade el directorio principal en el que nos encontramos más el archivo que buscamos

    std::string script;
    FILE* f = nullptr;
    try
    {
        f = fopen(full_path.c_str(), "rb"); //Se cambia con el nuevo puntero transformando de string a cadena puntero
        if (!f)
        {
            std::cerr << "error de apertura de " << full_path.c_str() << std::endl; //Se cambia con el nuevo puntero transformando de string a cadena puntero
            return;
        }

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script)
        {
            std::cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            std::cout << script << std::endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (...)
    {
        std::cerr << "error durante la lectura del archivo" << std::endl;
        if(f)
            fclose(f);
    }
}

void load_script()
{
    char filename[500];
    printf("Introduce el nombre del archivo (sin ruta absoluta): ");
    scanf("%499s", filename);
    /*Se elimina la parte de concatenacion con la ruta principal más el archivo que se desea abrir
     y se lo implementa directamente en la funcion load_script(const char* filename, bool show_script)*/

    load_script(filename, true);
}