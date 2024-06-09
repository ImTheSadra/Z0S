#ifndef VGAID 
#define VGAID 0xb8000
#endif

namespace ForeColors{
    const int black = 0;
    const int blue  = 1;
    const int green = 2;
    const int cyan  = 3;
    const int red   = 4;
    const int magenta = 5;
    const int brown = 6;
    const int white = 7;
}

namespace BackColors{
    const int black = 0;
    const int blue  = 1;
    const int green = 2;
    const int cyan  = 3;
    const int red   = 4;
    const int magenta = 5;
    const int brown = 6;
    const int white = 7;
}

namespace VGA
{
    const int width = 80;
    const int height = 25;
    int color = (ForeColors::black & 0x0F) | (BackColors::white << 4);
    int line = 0;

    void changeColor(int fore, int back){
        VGA::color = (fore & 0x0F) | (back << 4);
    }

    void setChar(char c, int x, int y){
        if (x < 0 or x > VGA::width &&
            y < 0 or y > VGA::height
        ){return;}
        char* vga = (char*)VGAID;
        vga[(y*VGA::width)+x];
    }

    void clearConsole()
    {
        char *vga = (char*)VGAID;
        unsigned int i=0;
        while(i < ((VGA::width)*(VGA::height)*2))
        {
            vga[i]=' ';
            i++;
            vga[i]=VGA::color;
            i++;
        };

        line = 0;
    };

    void printText(char *message, bool newLine = true)
    {
        char *vga = (char *)VGAID;
        unsigned int i=0;

        i=(line*VGA::width*2);

        while(*message!=0)
        {
            if(*message=='\n')
            {
                line++;
                i=(line*80*2);
                *message++;
            } else {
                vga[i]=*message;
                *message++;
                i++;
                vga[i]=VGA::color;
                i++;
            };
        };

        if(newLine){line++;}
    }
}