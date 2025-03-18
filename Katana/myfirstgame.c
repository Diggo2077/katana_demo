#include "headers.h"

int main (/*int argc, char const *argv[]*/)
{
    setlocale (LC_ALL, "pt_BR.UTF-8");
    
    c = loadConfigs ();
    mainMenu (&c, &p);
}
