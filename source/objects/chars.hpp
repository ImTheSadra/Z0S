namespace chars{
    int length(char* text){
        int len = 0;
        while(*text){len++;*text++;}
        return len;
    }
}