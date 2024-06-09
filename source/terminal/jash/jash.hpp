#include "commands.hpp"
#include "terminal.hpp"

namespace Jash
{
    void useCommand(char* cmd){
        char* function;
        int len = 0;
        while(*cmd){len++;*cmd++;}
        for(int i = 0; i < len; i++){
            if (cmd[i] == ' '){break;}
            function[i] = cmd[i];
        }

        if(function == "clear" or function == "cls"){
            VGA::clearConsole();
        }
    }
    
    void loop(){
        char* cmd = Terminal::input("Z0S$ ");
        Jash::useCommand(cmd);
    }   
}
