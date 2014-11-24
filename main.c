//The function "diasassemble" should be a const char and return ud_insn_asm.
//Then in main you print diasassemble(...).
//The same with hexdump.

#include <udis86.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


void diasassemble( FILE *file )
{
    ud_t ud_obj;

    ud_init(&ud_obj);
    ud_set_input_file(&ud_obj, file);
    ud_set_mode(&ud_obj, 32);
    ud_set_syntax(&ud_obj, UD_SYN_INTEL);

    while (ud_disassemble(&ud_obj))
    {
        printf("\t%s\n", ud_insn_asm(&ud_obj));
    }
}

void hexdump( FILE *file )
{

}

void showhelp()
{
    printf(
           "\n\tFunctions:\n%s%s%s%s",
           "\t\tHelp: -h or --help\n",
           "\t\tDisassemble: -d or --disass - file\n",
           "\t\tHexdump: -hd or --hexdump - file ( Coming soon )\n",
           "\t\tBytes to ASM: -ba or --bytestoasm\n",
           "\n"
           );
}

int main(int argc, char* argv[])
{
    char* argument = argv[1];
    char* filename;

    if ( argc > 1 && argc <= 3 )
    {
        filename = argv[2];
        FILE *file = fopen(filename, "rw++");

        if ( strcmp("-h", argument) == 0 || strcmp("--help", argument) == 0 )
        {
            showhelp();
        }
        else if ( strcmp("-d", argument) == 0 || strcmp("--disass", argument) == 0 )
        {
            diasassemble( file );
        }
        else if ( strcmp("-hd", argument) == 0 || strcmp("--hexdump", argument) == 0 )
        {
            hexdump( file );
        }
        else if ( strcmp("-ba", argument) == 0 || strcmp("--bytestoasm", argument) == 0 )
        {
            diasassemble( stdin );
        }
        else
        {
            showhelp();
        }
    }
    else
    {
        showhelp();
    }

    return 0;
}
