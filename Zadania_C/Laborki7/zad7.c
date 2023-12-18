#include <stdio.h>
#include <stdlib.h>

int main(){

    const char *dict_name = "temp";
    char command[100];


    snprintf(command,sizeof(command), "tar -cf %s.tar %s", dict_name, dict_name);
    system(command);


}