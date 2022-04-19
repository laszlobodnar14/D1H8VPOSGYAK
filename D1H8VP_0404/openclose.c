#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FILE "D1H8VP.txt"

int main(){
    int fileHandle = open(FILE, O_RDWR);
    if(fileHandle == -1){
        perror("Nem nyil meg a file");
        return 1;
    }
    else{
        printf("Fajl megnyilt");
    }
    char szov[120];

    int olvasott = read(fileHandle, szov, sizeof(szov));
    printf("A szoveg: \"%s\" osszesen: \"%i\" byte.\n",szov,olvasott);

    lseek(fileHandle, 0, SEEK_SET);

    char probaszoveg[] = "teszt";
    int irott = write(fileHandle, probaszoveg,sizeof(probaszoveg));
    printf("A fajlba bekerult a \"%s\" szoveg. osszesen: \"%i\"byte.\n",probaszoveg,irott);
    close(fileHandle);
    return 0;
}