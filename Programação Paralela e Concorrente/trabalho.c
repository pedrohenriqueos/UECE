//Descrição do Trabalho: http://marcial.larces.uece.br/cursos/programacao-concorrente-e-paralela-2018-2/problema-do-jantar-dos-canibais

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdbool.h>

const double limit = 120.0;
volatile int Caldeirao=0,cont_cozi=0,cont_cani[3]={0,0,0};
volatile bool preparando =false;
struct timespec start,finish;
volatile double time_p;

pthread_cond_t dormi_cozi = PTHREAD_COND_INITIALIZER,
                dormi_cani= PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_zone = PTHREAD_MUTEX_INITIALIZER,
                mutex_cani = PTHREAD_MUTEX_INITIALIZER, 
                mutex_cozi = PTHREAD_MUTEX_INITIALIZER;
pthread_t canibal[3],cozinheiro;

void servir(int id){
	printf("(Canibal  %d)Servindo\n",id);
	sleep(1);
	cont_cani[id]++;
	Caldeirao--;
}
void comer(int id){
	printf("(Canibal  %d)Comendo\n",id);
    sleep(3);
    printf("(Canibal  %d)Terminou de comer\n",id);
}
void *thread_canibal(void *v){
    pthread_mutex_lock(&mutex_cani);
    int id = * (int *)v;
    pthread_mutex_unlock(&mutex_cani);
    while(time_p<limit){
        pthread_mutex_lock(&mutex_cani);
        if(preparando){
            printf("(Canibal  %d)Dorme\n",id);
            pthread_cond_wait(&dormi_cani,&mutex_cani);
        }
        pthread_mutex_unlock(&mutex_cani);
        pthread_mutex_lock(&mutex_zone);
        if(Caldeirao==0){
            printf("(Canibal  %d)Acorda Cozinheiro\n",id);
            pthread_cond_signal(&dormi_cozi);
            printf("(Canibal  %d)Dorme\n",id);
            pthread_cond_wait(&dormi_cani,&mutex_zone);
            pthread_mutex_unlock(&mutex_zone);
        }else{
            servir(id);
            pthread_mutex_unlock(&mutex_zone);
        	comer(id);
            clock_gettime(CLOCK_MONOTONIC,&finish);
            time_p = (finish.tv_sec - start.tv_sec);
        }
    }
    printf("(Canibal  %d)Parou\n",id);
    pthread_cond_signal(&dormi_cozi);
}

void prepara_jantar(){
    printf("(Cozinheiro)Cozinhando\n");
    preparando = true;
    sleep(5);
    cont_cozi++;
    Caldeirao=5;
}

void *thread_cozinheiro(void *v){
    pthread_mutex_lock(&mutex_cozi);
    pthread_cond_wait(&dormi_cozi,&mutex_cozi);
    pthread_mutex_unlock(&mutex_cozi);
    while(time_p<limit){
        printf("(Cozinheiro)Acordado\n");
        pthread_mutex_lock(&mutex_zone);
        prepara_jantar();
        preparando = false;
        printf("(Cozinheiro)Acorda Canibais e Dorme\n");
        pthread_cond_broadcast(&dormi_cani);
        pthread_cond_wait(&dormi_cozi,&mutex_zone);
        pthread_mutex_unlock(&mutex_zone);
    }
    printf("(Cozinheiro)Parou\n");
}
int main(void){
    pthread_create(&cozinheiro,NULL,&thread_cozinheiro,NULL);
    int id[3]={0,1,2};
    for(int i=0;i<3;i++)
        pthread_create(&canibal[i],NULL,&thread_canibal,(void *) &id[i]);
    clock_gettime(CLOCK_MONOTONIC,&start);
    pthread_join(cozinheiro,NULL);
    for(int i=0;i<3;i++)
        pthread_join(canibal[i],NULL);
    printf("\n\n");
    for(int i=0;i<3;i++)
        printf("(Canibal  %d) %d Vezes\n",i,cont_cani[i]);
    printf("(Cozinheiro) %d Vezes\n",cont_cozi);
}
