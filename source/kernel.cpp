#include "terminal/jash/jash.hpp"
#include "display/screen.hpp"

void init(){
    
}

extern "C" void kernel_main(){
    init();
    VGA::clearConsole();

    VGA::changeColor(ForeColors::magenta, BackColors::black);
    VGA::clearConsole();
    VGA::printText("welcome to Z0S\npress any key then type something");

    Keyboard::readKey();

    for(int _ = 0; _ < 35000000; _++){}

    VGA::changeColor(ForeColors::black, BackColors::white);
    VGA::clearConsole();

    while(true){
        char* text = Terminal::input(">> ");
        VGA::printText(text);
        for(int i = 0; i < 100000000; i++){}
        VGA::clearConsole();
    }
}