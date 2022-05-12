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
	
	if(szulo==0)
	{
		printf("Szulő %d\n",getpid());

		elsoszulogyerek1=fork();

		
	}
		if(elsoszulogyerek1==0)
		{
			printf("Gyerek %d \n", getpid());
			sleep(3);
		}
		
	
	else{
		wait(&st);	

	}
	szulomasik=fork();
	
	if(szulomasik==0)
	{
		printf(" Gyerek %d\n", getpid());

		masodikszulogyerek1=fork();

		
	}

		if(masodikszulogyerek1==0)
		{
			printf("Gyerek %d\n", getpid());
			sleep(3);
		}

		

	
	else{
		wait(&st);

		
	}
	
	return 0;
}
