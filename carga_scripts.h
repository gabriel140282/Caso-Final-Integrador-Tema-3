#ifndef CARGA_SCRIPTS_H
#define CARGA_SCRIPTS_H

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

void load_script(const char* filename, bool show_script = false);
void load_script();

#endif //CARGA_SCRIPTS_H