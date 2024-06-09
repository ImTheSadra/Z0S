enum KEYS
{
    A = 0x1E,
    B = 0x30,
    C = 0x2E,
    D = 0x20,
    E = 0x12,
    F = 0x21,
    G = 0x22,
    H = 0x23,
    I = 0x17,
    J = 0x24,
    K = 0x25,
    L = 0x26,
    M = 0x32,
    N = 0x31,
    O = 0x18,
    P = 0x19,
    Q = 0x10,
    R = 0x13,
    S = 0x1F,
    T = 0x14,
    U = 0x16,
    V = 0x2F,
    W = 0x11,
    X = 0x2D,
    Y = 0x15,
    Z = 0x2C,
    _1 = 0x02,
    _2 = 0x03,
    _3 = 0x04,
    _4 = 0x05,
    _5 = 0x06,
    _6 = 0x07,
    _7 = 0x08,
    _8 = 0x09,
    _9 = 0x0A,
    _0 = 0x0B,
    SPACE = 0x39,
    OPEN_BRACKET = 0x1A,
    CLOSE_BRACKET = 0x1B,
    COMMA = 0x33,
    DOT = 0x34,
    BACKSPACE = 0x0E,
    SEMICOLON = 0x27,
    FORWARD_SLASH = 0x35,
    SLASH = 0x2B,
    ESC = 0x01,
    ENTER = 0x1C,
    UPARROW = 0x48,
    DOWNARROW = 0x34,
    RIGHTARROW = 0x4D,
    LEFTARROW = 0x4B,
    _EQ = 0x2F
};

char getKey(char code){
    switch(code)
    {
        case KEYS::A: return 'A';
        case KEYS::B: return 'B';
        case KEYS::C: return 'C';
        case KEYS::D: return 'D';
        case KEYS::E: return 'E';
        case KEYS::F: return 'F';
        case KEYS::G: return 'G';
        case KEYS::H: return 'H';
        case KEYS::I: return 'I';
        case KEYS::J: return 'J';
        case KEYS::K: return 'K';
        case KEYS::L: return 'L';
        case KEYS::M: return 'M';
        case KEYS::N: return 'N';
        case KEYS::O: return 'O';
        case KEYS::P: return 'P';
        case KEYS::Q: return 'Q';
        case KEYS::R: return 'R';
        case KEYS::S: return 'S';
        case KEYS::T: return 'T';
        case KEYS::U: return 'U';
        case KEYS::V: return 'V';
        case KEYS::W: return 'W';
        case KEYS::X: return 'X';
        case KEYS::Y: return 'Y';
        case KEYS::Z: return 'Z';
        case KEYS::_1: return '1';
        case KEYS::_2: return '2';
        case KEYS::_3: return '3';
        case KEYS::_4: return '4';
        case KEYS::_5: return '5';
        case KEYS::_6: return '6';
        case KEYS::_7: return '7';
        case KEYS::_8: return '8';
        case KEYS::_9: return '9';
        case KEYS::_0:         return '0';   case KEYS::SPACE: return ' ';
        case KEYS::OPEN_BRACKET: return '['; case KEYS::CLOSE_BRACKET: return ']';
        case KEYS::COMMA:        return ',';   case KEYS::DOT: return '.';
        case KEYS::SEMICOLON:    return ';';   case KEYS::FORWARD_SLASH: return '/';
        case KEYS::SLASH:        return '\\';  case KEYS::LEFTARROW: return 1;
        case KEYS::RIGHTARROW:   return 2;     case KEYS::UPARROW: return 3;
        case KEYS::BACKSPACE:    return -1;

        default: return 0;
    }
}

namespace Keyboard
{
    char inputChar(){
        char key = 0;

        asm volatile("inb %1, %0" : "=a" (key) : "d" (0x60));

        if (key == KEYS::ENTER){return '\n';}
        else if (key == 0){return 0;}
        else {return getKey(key);}
    }

    int readKey(){
        char key = 0;
        
        while (true){
            asm volatile("inb %1, %0" : "=a" (key) : "d" (0x60));
            if (key != 0 && getKey(key) != 0){break;}
        }
        return (int)key;
    }
}