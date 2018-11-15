#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<semaphore.h>

#define SEM_NAME_1 "/sem1"
#define SEM_NAME_2 "/sem2"
#define SEM_NAME_3 "/sem3"
#define SEM_NAME_4 "/sem4"
#define SEM_NAME_5 "/sem5"
#define SEM_NAME_6 "/sem6"
#define LOCKED 0
#define OPENED 1

sem_t *sem1 = NULL;
sem_t *sem2 = NULL;
sem_t *sem3 = NULL;
sem_t *sem4 = NULL;
sem_t *sem5 = NULL;
sem_t *sem6 = NULL;
int mem_id_1 = 0;
int *mem_1 = NULL; 	//cislo operaci
int mem_id_2 = 0;	
int *mem_2 = NULL;	//pocet lidi na zastavce
int mem_id_3 = 0;	
int *mem_3 = NULL;	//cislo ridera
int mem_id_4 = 0;	
int *mem_4 = NULL;	//kontrola bus
int mem_id_5 = 0;	
int *mem_5 = NULL;	//pocet lidi, ktere by meli nastoupit
int mem_id_6 = 0;	
int *mem_6 = NULL;	//cislo rid na zastavce
int mem_id_7 = 0;	
int *mem_7 = NULL;	//test na kapacitu
int mem_id_8 = 0;	
int *mem_8 = NULL;	//pocet rid ktere by meli finish
int mem_id_9 = 0;	
int *mem_9 = NULL;	//pomocna prom pro test na kapacitu
int mem_id_10 = 0;	
int *mem_10 = NULL;	//promena pro jizdu autobusu

//funkce pro vypis chyb
void chyba(char *str);

//funkce pro kontrolu argumentu
void kontrola_argv( int pocet_riders, int kapacita, int doba_rider, int doba_bus );

//funkce inicializaci 
void init_res();

//funkce uvolneni
void clean_res();

//funkce pro vypis autobusovych akci
void bus_f(char *str, char *akce, FILE *file);

//funcke pro vypis riderovych akci
void rid_f(char *str, char *akce, int arg, FILE *file);

//funkce pro cas v ms
void ms_sleep(int sec);


