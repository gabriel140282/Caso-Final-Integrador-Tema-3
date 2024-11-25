#include "carga_scripts.h"
#include <iostream>
#include <string>

using namespace std;

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;

/* El usuario o bien coloca la ruta absoluta o bien a través de la ruta relativa colocando el archivo dentro del proyecto
referencia al nombre con su extensión */

const char* base_path = "../";

void load_script(const char* filename, bool show_script)
{
    string script;
    FILE* f = nullptr;
    try
    {
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "error de apertura de " << filename << endl;
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
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (...)
    {
        cerr << "error durante la lectura del archivo" << endl;
        if(f)
            fclose(f);
    }
}

void load_script()
{
    char filename[500];
    printf("Introduce el nombre del archivo (sin ruta absoluta): ");
    scanf("%499s", filename);

    string full_path = string(base_path) + filename;

    load_script(full_path.c_str(), true);
}