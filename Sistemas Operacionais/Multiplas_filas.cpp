//Multiplas_filas
#include <pthread.h>
#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;
#define N_cliente (int)1e2   //Quantidade de clientes
#define N_resposta (int)1e4  //soma máxima
#define inf 0x3f3f3f3f       //vez do escalonador

volatile int buffer[N_cliente+2],idx=0;
//buffer de comunição cliente -> servidor
volatile int valores_clientes[N_cliente+2],vc=0;
//Dados que seram utilizados para determinar a prioridade do clientes
volatile int retorno[N_resposta+2],check[N_resposta+2],v=0,vez;
//Resposta do servidor para o cliente
pthread_mutex_t mutex_zone=PTHREAD_MUTEX_INITIALIZER,mutex_clients=PTHREAD_MUTEX_INITIALIZER;
pthread_t server,cliente[N_cliente],escalonador;

void * thread_servidor(void * v){
	int resposta[N_resposta+2],count=0;
	resposta[1]=1;
	for(int i=2;i<=N_resposta;i++)
		resposta[i]=resposta[i-1]+i;
	while(true){
		if(count==N_cliente) break;
		while(idx==0);
		pthread_mutex_lock(&mutex_zone);
		count++;
		int num_cliente=buffer[--idx];
		retorno[num_cliente]=resposta[num_cliente];
		pthread_mutex_unlock(&mutex_zone);
	}
}
void * thread_cliente(void * v){
	int valor_cliente;
	pthread_mutex_lock(&mutex_clients);
	int k=rand()%N_resposta+1;
	while(check[k])
		k=rand()%N_resposta+1;
	check[k]=1;
	valores_clientes[vc++]=k;
	valor_cliente=k;
	if(vc==N_cliente) vez=inf;
	pthread_mutex_unlock(&mutex_clients);
	while(vez!=valor_cliente);
	pthread_mutex_lock(&mutex_zone);
	buffer[idx++]=valor_cliente;
	pthread_mutex_unlock(&mutex_zone);
	while(retorno[valor_cliente]==0);
	printf("Thread: %d\n",valor_cliente);
	printf("Resposta: %d\n\n",retorno[valor_cliente]);
	vez=inf;
}
void * thread_escalonador(void *args){
	while(vez!=inf);
	queue<int> q[4];
	for(int s=0;s<N_cliente;s++){
		int mod=valores_clientes[s]%4;
		q[mod].push((int)valores_clientes[s]);
	}
	for(int qu=3;qu>=0;qu--){
		while(!q[qu].empty()){
			while(vez!=inf);
			vez=q[qu].front();
			//printf("%d\n",vez%4);//teste da multifila
			q[qu].pop();

		}
	}
}

int main(){
	srand(time(NULL));
	int x;
	vez=-inf;
	pthread_create(&server,NULL,&thread_servidor,NULL);
	pthread_create(&escalonador,NULL,&thread_escalonador,NULL);
	for(x=0;x<N_cliente;x++)
		pthread_create(&cliente[x],NULL,&thread_cliente,NULL);
	pthread_join(server, NULL);
	for(x=0;x<N_cliente;x++)
		pthread_join(cliente[x], NULL);
	pthread_join(escalonador, NULL);
}
