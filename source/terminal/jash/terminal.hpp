#include "../../display/vga.hpp"
#include "../../keyboard/keyboard.hpp"
#include "../../objects/chars.hpp"

namespace Terminal
{
    char* input(char* promp){
        char* result;
        int vgai = chars::length(promp)*2;
        VGA::printText(promp, false);
        int i = 0;
        char* vga = (char*)VGAID;
        while (true)
        {
            char c = Keyboard::inputChar();
            if(c == 0){continue;}
            else if (c == '\n'){for(int _ = 0; _ < 35000000; _++){};break;}
            else if (c == -1){
                i -= 1; vgai -= 2;
                result[i] = ' ';
                vga[vgai] = ' ';
                i -= 1; vgai -= 2;
                continue;
            }
            vga[(VGA::line*VGA::width)+vgai] = c;
            result[i] = c;
            i += 1; vgai += 2;
            for(int _ = 0; _ < 35000000; _++){}
        }
        VGA::line++;
        return result;
    }

    
} 