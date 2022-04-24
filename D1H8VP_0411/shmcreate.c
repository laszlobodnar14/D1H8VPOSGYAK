#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 123456L



main()
{
	int hallgato;		
	key_t key;		
	int size=512;		
	int shmflg;		

	key = KEY;
	
	shmflg = 0;
	if ((hallgato=shmget( key, size, shmflg)) < 0) {
	   printf("\n Nincs szegmens! ");
	   shmflg = 00666 | IPC_CREAT;
	   if ((hallgato=shmget( key, size, shmflg)) < 0) {
	      perror("\n Az shmget system call sikertelen!");
	      exit(-1);
	   }
	} else printf("\n Van  szegmens!");

	printf("A hallgato azonositoja a kovetkezo %d: \n", hallagato);

	exit (0);
}