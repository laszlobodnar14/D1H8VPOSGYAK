#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>



int main(){
	int szulo, szulomasik;

	int elsoszulogyerek1, elsoszulogyerek2, elsoszulogyerek3, masodikszulogyerek1, masodikszulogyerek2, masodikszulogyerek3;
	int statusz;
	int st;
	szulo=fork();
	szulomasik=fork();
	if(szulo==0)
	{
		printf("Elso szulo gyerekek %d\n",getpid());

		elsoszulogyerek1=fork();

		elsoszulogyerek2=fork();

		elsoszulogyerek3=fork();
        
		if(elsoszulogyerek1==0)
		{
			printf("Varunk 3 mpt %d \n", getpid());
			sleep(3);
		}
		if(elsoszulogyerek2==0)
		{
			printf("Megint varunk 3 mpt%d\n", getpid());
			sleep(3);
		}
		if(elsoszulogyerek3==0)
		{
			printf("Megint varunk 3 mpt%d\n",getpid());
			sleep(3);
		}

	}
	else{
		wait(&st);

		wait(&st);

		wait(&st);

	}
	if(szulomasik==0)
	{
		printf("Masodik szulo gyerekei %d\n", getpid());

		masodikszulogyerek1=fork();

		masodikszulogyerek2=fork();

		masodikszulogyerek3=fork();

		if(masodikszulogyerek1==0)
		{
			printf("Varunk 3 mpt %d\n", getpid());
			sleep(3);
		}

		if(masodikszulogyerek2==0)
		{
			printf("Megint varunk 3 mpt %d\n ", getpid());
			sleep(3);
		}

		if(masodikszulogyerek3==0)
		{
			printf("Megint varunk 3 mpt %d\n", getpid());
			sleep(3);
		}

	}
	else{
		wait(&st);

		wait(&st);

		wait(&st);
	}
	
	return 0;
}
