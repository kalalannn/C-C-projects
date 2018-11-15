#include <stdio.h>
#include <unistd.h>
#include <thread>
#include <queue>
#include <mutex>
#include <vector>
#include <iostream>
#include <string.h>

// #include <string>

std::mutex locks1 ;
std::mutex locks2 ;

char *line;
int num =0;

char *to_cstr(std::string a) {
// prevede retezec v c++ do retezce v "c" (char *)
	char *str;
	str = (char *) malloc(sizeof(char)*(a.length() + 1));
	strcpy(str, a.c_str());
	return str;
}

char *read_line(int *res) {
	std::string line;
	char *str;

	if (std::getline(std::cin, line)) {
		str = to_cstr(line);
		*res = 1;
		return str;
	} else {
		*res = 0;
		return NULL;
	}

}

// ID - thread identification 
// RE - regular expression

void f(int ID, char *RE, char *REPL) {
/* funkce implementujici thread */
	locks1.lock();
	if(ID == num ){
	    printf("I am %d\n", ID);
        num++;
	}
	locks2.unlock();
}

int main(int argc, char *argv[]) {
/*******************************
 * Inicializace threadu a zamku
 * *****************************/

	std::vector <std::thread *> threads; /* pole threadu promenne velikosti */
	int num_thds = (argc - 1) / 2;
	locks1.lock();
	locks2.lock();



/* vytvorime thready */
	threads.resize(num_thds); /* nastavime si velikost pole threads */
	for (int i = 0; i < num_thds; i++){	
		std::thread *new_thread = 
				new std::thread (f, i, argv[2*i + 1], argv[2*i + 2]);
		threads[i] = new_thread;
	}

/**********************************
 * Vlastni vypocet psed
 * ********************************/
	int res;

	while (1) {
		line = read_line(&res);
		if(res){
			while(1){
				locks1.unlock();
				locks2.lock();
				if(num = (argc - 1)/2){
					num =0;
					break;
				}

			}
		}
		// mutex.lock
		
		// mutex.unlock

		free(line); /* uvolnim pamet */
	}


/**********************************
 * Uvolneni pameti
 * ********************************/

/* provedeme join a uvolnime pamet threads */
	for(int i = 0; i < num_thds; i++) {
		(*(threads[i])).join();
		delete threads[i];
	}
/* uvolnime pamet zamku */
	//for(int i = 0; i < num_locks; i++){
		//delete locks1;
		//delete locks2;
	//}

}
