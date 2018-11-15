// Nikolaj Vorobiev

#include "proj2.h"

void chyba(char *str)
{
	FILE *file = fopen("proj2.out", "w");
	fprintf(file, "Error: %s\n", str);	
	fclose(file);
	exit(1);
}
void kontrola_argv( int pocet_riders, int kapacita, int doba_rider, int doba_bus )
{
	if( pocet_riders <= 0 || kapacita <= 0 || doba_rider < 0 || doba_rider > 1000 || doba_bus < 0 || doba_bus > 1000 )
	{
		chyba("Mate spatne zadane argumenty");
	}
}
void init_res()
{
	if((sem1 = sem_open(SEM_NAME_1, O_CREAT | O_EXCL , 0666, OPENED )) == SEM_FAILED)
	{
		chyba("Semaphor se nepodarilo otevrit");	
	}

	if((sem2 = sem_open(SEM_NAME_2, O_CREAT | O_EXCL , 0666, OPENED )) == SEM_FAILED)
	{
		chyba("Semaphor se nepodarilo otevrit");	
	}
	if((sem3 = sem_open(SEM_NAME_3, O_CREAT | O_EXCL , 0666, LOCKED )) == SEM_FAILED)
	{
		chyba("Semaphor se nepodarilo otevrit");	
	}

	if((sem4 = sem_open(SEM_NAME_4, O_CREAT | O_EXCL , 0666, LOCKED )) == SEM_FAILED)
	{
		chyba("Semaphor se nepodarilo otevrit");	
	}

	if((sem5 = sem_open(SEM_NAME_5, O_CREAT | O_EXCL , 0666, OPENED )) == SEM_FAILED)
	{
		chyba("Semaphor se nepodarilo otevrit");	
	}
	if((sem6 = sem_open(SEM_NAME_6, O_CREAT | O_EXCL , 0666, LOCKED )) == SEM_FAILED)
	{
		chyba("Semaphor se nepodarilo otevrit");	
	}
	if((mem_id_1 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_1 = shmat(mem_id_1, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_1 = 1;

	if((mem_id_2 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_2 = shmat(mem_id_2, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_2 = 0;

	if((mem_id_3 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_3 = shmat(mem_id_3, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_3 = 1;

	if((mem_id_4 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_4 = shmat(mem_id_4, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_4 = 0;

	if((mem_id_5 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_5 = shmat(mem_id_5, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_5 = 0;

	if((mem_id_6 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_6 = shmat(mem_id_6, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_6 = 1;

	if((mem_id_7 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_7 = shmat(mem_id_7, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_7 = 0;

	if((mem_id_8 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_8 = shmat(mem_id_8, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_8 = 0;

	if((mem_id_9 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_9 = shmat(mem_id_9, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_9 = 0;

	if((mem_id_10 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	if((mem_10 = shmat(mem_id_10, NULL, 0)) == NULL)
	{
		chyba("Pamet se nepodarilo vytvorit");	
	}
	*mem_10 = 0;
}
void clean_res()
{
	shmctl(mem_id_1, IPC_RMID, NULL);
	shmctl(mem_id_2, IPC_RMID, NULL);
	shmctl(mem_id_3, IPC_RMID, NULL);
	shmctl(mem_id_4, IPC_RMID, NULL);
	shmctl(mem_id_5, IPC_RMID, NULL);
	shmctl(mem_id_6, IPC_RMID, NULL);
	shmctl(mem_id_7, IPC_RMID, NULL);
	shmctl(mem_id_8, IPC_RMID, NULL);
	shmctl(mem_id_9, IPC_RMID, NULL);
	shmctl(mem_id_10, IPC_RMID, NULL);
	sem_close(sem1);	
	sem_close(sem2);
	sem_close(sem3);
	sem_close(sem4);
	sem_close(sem5);
	sem_close(sem6);
	sem_unlink(SEM_NAME_1);
	sem_unlink(SEM_NAME_2);
	sem_unlink(SEM_NAME_3);
	sem_unlink(SEM_NAME_4);
	sem_unlink(SEM_NAME_5);
	sem_unlink(SEM_NAME_6);

}
void bus_f(char *str, char *akce, FILE *file)
{
	if((strcmp(str, "BUS") == 0))
	{
		if(strcmp(akce, "start boarding") == 0 || strcmp(akce, "end boarding") == 0)
		{
			sem_wait(sem5);
			fprintf( file,"%-10d: %-14s : %s: %d\n", (*mem_1)++, str, akce, *mem_2);			
			sem_post(sem5);
		}
		else
		{
			sem_wait(sem5);
			fprintf(file, "%-10d: %-14s : %s\n", (*mem_1)++, str, akce);	
			sem_post(sem5);
		}
	}
}
void rid_f(char *str, char *akce, int arg, FILE *file)
{
	if(strcmp(str, "RID") == 0)
	{
		if(strcmp(akce, "enter") == 0)
		{
			sem_wait(sem5);
			fprintf(file, "%-10d: %s %-10d : %s: %d\n", (*mem_1)++, str, arg, akce, (*mem_2));
			sem_post(sem5);
		}
		else if(strcmp(akce, "boarding") == 0 || strcmp(akce, "finish") == 0)
		{
			sem_wait(sem5);
			fprintf(file ,"%-10d: %s %-10d : %s\n", (*mem_1)++, str, arg, akce);
			sem_post(sem5);
		}
		else
		{
			sem_wait(sem5);
			fprintf(file, "%-10d: %s %-10d : %s\n", (*mem_1)++, str, (*mem_3)++, akce);
			sem_post(sem5);
		}
	}
}
void ms_sleep(int sec)
{
	if(sec != 0)
	{
		unsigned randi = (rand() % sec) * 1000;
		usleep(randi);
	}
	else if (sec ==0)
		usleep(0);
}
int main(int argc, char **argv)
{
	pid_t bus;
	pid_t tvorec;
	pid_t rider;
	int pocet_riders, kapacita,  doba_rider, doba_bus;
	if(argc == 5)
	{
		pocet_riders = strtol(argv[1] , NULL, 10);
		kapacita = strtol(argv[2] , NULL, 10);
		doba_rider = strtol(argv[3] , NULL, 10);
		doba_bus = strtol(argv[4] , NULL, 10) ; 
		kontrola_argv( pocet_riders, kapacita, doba_rider, doba_bus);
	}
	else
	{
		chyba("Mate spatne zadane argumenty");	
	}
	init_res();
	FILE *file = fopen("proj2.out", "w");
	setbuf(file, NULL);
	bus = fork();
	if(bus == 0) //bus
	{
		bus_f("BUS" ,"start", file);
		while(1)
		{
			bus_f("BUS" ,"arrival", file);
			sem_wait(sem1);
			if(*mem_2 > 0 )
			{
				bus_f("BUS" ,"start boarding", file);
				sem_post(sem3);
				int prom = *mem_2;
				(*mem_5) = prom;
				sem_wait(sem4);
				if(*mem_9 == 1)
				{
					sem_post(sem2);
					*mem_9 =0;
				}
				else if(*mem_9 == 0)
				{
					sem_wait(sem3);
				}
				bus_f("BUS", "end boarding", file);
			}
			bus_f("BUS" ,"depart", file);
			sem_post(sem1);
			ms_sleep(doba_bus);
			bus_f("BUS" ,"end", file);
			for( ; *mem_8 > 0; (*mem_8)--)
			{
				sem_post(sem6);
			}
			if(*mem_4 == 1)
			{
				break;
			}
		}
		bus_f("BUS","finish", file);
		exit(EXIT_SUCCESS);
	}
	else if(bus > 0) //main
	{
		tvorec = fork();
		if(tvorec == 0) //tvorec
		{
			for(int i = 0; i < pocet_riders ; i++)
			{
				ms_sleep(doba_rider);
				rider = fork();	
				if(rider == 0)
				{
					break;	
				}
			}
			if(rider == 0)
			{
				rid_f("RID", "start", 0, file);
				sem_wait(sem1);  //enter
				(*mem_2)++;
				int arg = (*mem_6)++;
				rid_f("RID", "enter", arg, file);
				sem_post(sem1);
				sem_wait(sem2);
				sem_wait(sem3);
				rid_f("RID", "boarding", arg, file);
				(*mem_7)++;
				if(*mem_7 == kapacita)
				{
					*mem_7 = 0;
					(*mem_2)--;
					*mem_9 = 1;
					sem_post(sem4);
				}
				else
				{
					(*mem_2)--;
					sem_post(sem2);
					sem_post(sem3);
				}
				if(*mem_5 == *mem_7)
				{
					*mem_7 = 0;
					sem_post(sem4);
				}
				(*mem_10)++;
				if(*mem_10 == pocet_riders)
				{
					*mem_4 = 1;
				}
				(*mem_8)++;
				sem_wait(sem6);
				rid_f("RID", "finish", arg, file);
				exit(EXIT_SUCCESS);
			}
			waitpid(rider, NULL, 0);	
			exit(EXIT_SUCCESS);
		}
		else if (tvorec > 0) //main
		{
		}
		else 
		{
			chyba("Nepodarilo se vytvorit process tvorec");	
		}
	}
	else
	{
		chyba("Nepodarilo se vytvorit process bus");	
	}
	clean_res();
	waitpid(tvorec, NULL, 0);	
	waitpid(bus, NULL, 0);	
	fclose(file);
	return 0;
}
