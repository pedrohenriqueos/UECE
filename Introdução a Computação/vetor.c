/************************************************
*               TRABALHO ICC                    *
*                                               *
*   Grupo: Pedro Henrique Oliveira Sousa        *
*          Érica Carneiro Araújo                *
*          Ricardo de Carvalho Oliveira Filho   *
*                                               *
//***********************************************/

#include "vetor.h"  // importa biblioteca de vetores.



struct vetor vet[6];


//Variáveis para entrada na struct, o tipo é static, pois é apenas um ponteiro de entrada.

int memoriav[6]; // guarda a posiçao na memória de vetores e matrizes.
// variaveis de apoio estão declaradas em vetor.h.





double *recebe_coord(int op)
{
	int i,j;
	double *aux;
	do
	{
	printf("Insira a quantidade de coordenadas a serem trabalhadas: \n");
	scanf("%lf", &vet[op].coor);
	if(vet[op].coor<=0)
	printf("Erro! Insira valores inteiros positivos e maiores do que '0' !!\n\n");
	else if((vet[op].coor/floor(vet[op].coor))!=1)
	printf("Erro! Insira valores inteiros positivos!!\n\n");
	else	
	j=1;
	}while(j!=1);
	
	aux = (double *)malloc(vet[op].coor*sizeof(double));
		for(i=0; i<vet[op].coor; i++)
		{
		printf("\n Vetor -> insira a %d coordenada:  \n", i+1);
		scanf("%lf", &aux[i]);
		
		}
	
	

	return aux;

}

double cria_modulo(double *vete,int a)
{
	int i;	
	double modulo;
	for(i=0; i< vet[a].coor; i++)
	{
		
		modulo = modulo + pow(vete[i],2);
	}
	
	modulo = sqrt(modulo);
	

	return modulo;


} 



double	*cria_vetor(double tam)   
{
	
	double *vetor;
	vetor = (double *)malloc(tam*sizeof(double));
	return vetor;
}


void alimenta_struct_vetor()
{
		int i,j,op;
		for(i=0; i<2; i++)
		{
		printf("\nCriar %d vetor: \n", i+1);	
		op=i;
		vet[i].coordenadas = recebe_coord(op);
		vet[i].modulo = cria_modulo(vet[i].coordenadas,i);
		vet[i].pont = cria_vetor(vet[i].modulo);
		memoriav[i]=1;
		printf("Vetor de norma = %.2lf\n", vet[i].modulo);	
		
			for(j=0; j<vet[i].coor; j++)
			{
				printf("Coordenadas: %.2lf\n", vet[i].coordenadas[j]);

			}	
			
		} 
	
}


double *soma_vetor()

{
		int i,j;
		if(vet[0].coor==vet[1].coor)
		{
			memoriav[2]=1;
			vet[2].coordenadas = (double *)malloc(vet[0].coor*sizeof(double));
			vet[2].coor=vet[0].coor;
			for (i=0; i< vet[2].coor; i++)
			{
				vet[2].coordenadas[i]=vet[0].coordenadas[i] + vet[1]. coordenadas[i];
			
			}
			vet[2].modulo = cria_modulo(vet[2].coordenadas,2);
			vet[2].pont = cria_vetor(vet[2].modulo);
			printf("Vetor de norma = %.2lf\n", vet[2].modulo);	
			for(j=0; j<vet[2].coor; j++)
			{
				printf("Coordenadas: %.2lf\n", vet[2].coordenadas[j]);

			}	
		}
		else 
		printf("Vetores de tamanhos incompativeis!!\n\n");
return vet[2].pont;

}


double *subtracao_vetor(int sub)

{
		int i,j;
		if((vet[0].coor==vet[1].coor)&&(sub==1))
		{
			memoriav[3]=1;	
			vet[3].coordenadas = (double *)malloc(vet[0].coor*sizeof(double));
			vet[3].coor = vet[0].coor;
			for (i=0; i< vet[3].coor; i++)
			{
				vet[3].coordenadas[i]=vet[0].coordenadas[i] - vet[1].coordenadas[i];
			
			}
			vet[3].modulo = cria_modulo(vet[3].coordenadas,3);
			vet[3].pont = cria_vetor(vet[3].modulo);
			printf("Vetor de norma = %.2lf\n", vet[3].modulo);	
			for(j=0; j<vet[3].coor; j++)
			{
				printf("Coordenadas: %.2lf\n", vet[3].coordenadas[j]);

			}	
		}

		else 
		{
		if((vet[0].coor==vet[1].coor)&&(sub == 2))
		{
			memoriav[3]=1;
			vet[3].coordenadas = (double *)malloc(vet[0].coor*sizeof(double));
			vet[3].coor = vet[0].coor;
			for (i=0; i< vet[3].coor; i++)
			{
				vet[3].coordenadas[i]=vet[1].coordenadas[i] - vet[0]. coordenadas[i];
			
			}
			vet[3].modulo = cria_modulo(vet[3].coordenadas,3);
			vet[3].pont = cria_vetor(vet[3].modulo);
			printf("Vetor de norma = %.2lf\n", vet[3].modulo);	
			for(j=0; j<vet[3].coor; j++)
			{
				printf("Coordenadas: %.2lf\n", vet[3].coordenadas[j]);

			}	
		}
		else 
		printf("Vetores possuem tamanhos incompativeis!\n\n");
		
		}
	return vet[3].pont;

}

double *produto_escalar()
{
	int j, i,mult;
	double prodesc;
	//aplicar um switch nos casos de erro
	do{
	printf("\nProduto escalar:\nEscolha o vetor a ser multiplicado:\n 1 - V1\n 2 - V2\n");
	scanf("%d", &mult);
	if(mult!=2&&mult!=1)
	printf("Erro! Digite uma opcao valida!!\n\n");	
	}while(mult!=2&&mult!=1);
	
	
	printf("Digite o escalar: \n");
	scanf("%lf", &prodesc);
	vet[4].coordenadas = (double *)malloc(vet[mult-1].coor*sizeof(double));
	vet[4].coor = vet[mult-1].coor;
	memoriav[4]=1;
	for(i=0; i<vet[4].coor; i++)	
	{
		vet[4].coordenadas[i] = vet[mult-1].coordenadas[i]*prodesc;
	}
	
	vet[4].modulo = cria_modulo(vet[4].coordenadas,4);
	vet[4].pont = cria_vetor(vet[4].modulo);
	printf("Vetor de norma = %.2lf\n", vet[4].modulo);	
	for(j=0; j<vet[4].coor; j++)
		{
		printf("Coordenadas: %.2lf\n\n", vet[4].coordenadas[j]);

		}		
	
return vet[4].pont;

}

double produto_de_vetores()
{
	int i;
	double prodvet;
	printf("Produto de Vetores: \n\n");
	if(vet[0].coor==vet[1].coor)
	vet[5].coordenadas = (double *)malloc(vet[0].coor*sizeof(double));
	vet[5].coor = vet[0].coor;
	 memoriav[5]=1;
	
	for(i=0; i<vet[5].coor; i++)
	{
		vet[5].coordenadas[i]=vet[0].coordenadas[i]*vet[1].coordenadas[i];
		prodvet = prodvet + vet[5].coordenadas[i];
	}
	printf("Resultado do produto: %.2lf\n\n", prodvet );

return prodvet;
}



void inicio_vetor(){//Função que inicializa a main, dizendo para o programa o nome das matrizes 
   int i; 
   vet[0].palavra = "inicial1"; 
   vet[1].palavra = "inicial2"; 
   vet[2].palavra = "soma"; 
   vet[3].palavra = "diferenca"; 
   vet[4].palavra = "produto_escalar"; 
   vet[5].palavra = "produto"; 
   for(i=0;i<6;i++) 
 {
   memoriav[i]=0; 
 }   
} 
 
void limpa_vetor(){ 
   int i; 
   for(i=0;i<6;i++){ 
      free((void *)vet[i].coordenadas); 
      free((void *)vet[i].pont); 
   } 
} 
 
void vetores_salvos(){ 
   int i,a; 
   printf("\n"); 
   for(a=0;a<6;a++){ 
      if(memoriav[a]==1){ 
      printf("Vetor %s\n",vet[a].palavra);
      printf("Vetor de norma = %.2lf\n", vet[a].modulo);     
      for(i=0; i<vet[a].coor; i++) 
        { 
        printf("Coordenadas: %.2lf\n", vet[a].coordenadas[i]); 
        } 
     printf("\n"); 
     } 
   } 
} 
 
void importar_arquivo_vetor(char *arquivo2,int tam,int iniciov){ 
   char aux2[tam+20]; 
   int esc2,inicio = iniciov; 
   do{ 
      esc2=0; 
      if(inicio==0){ 
      printf("Digite novamente o nome do arquivo (sem espaco ou .txt): "); 
      setbuf(stdin,NULL); 
      scanf("%s",arquivo2); 
      setbuf(stdin,NULL); 
      } 
      inicio = 0; 
      strcpy(aux2,arquivo2); 
      strcat(arquivo2,"_vetor.txt"); 
      strcat(aux2,"_vetor_control.txt"); 
      if((access(arquivo2, F_OK)==0)&&(access(aux2, F_OK)==0)){ 
         tamler_vetor(aux2); 
         importar_vetor(arquivo2); 
      }else{ 
         printf("\nArquivo de memoria não encontrado!"); 
         do{ 
            printf("\nDigite se deseja tentar novamente"); 
            printf("\n(1)Digitar novamente o nome do arquivo para importar"); 
            printf("\n(2)Inicializar o programa sem importar dados"); 
            printf("\nDigite sua opcao: "); 
            scanf("%d",&esc2); 
            if(esc2!=1&&esc2!=2) 
               printf("\nOpcao invalida, digite novamente!\n"); 
         }while(esc2!=1&&esc2!=2); 
      }   
   }while(esc2==1); 
 
} 
 
void salva_arquivo_vetor(char *arquivo2,int tam){ 
   char aux2[tam+20]; 
   strcpy(aux2,arquivo2); 
   strcat(arquivo2,"_vetor.txt"); 
   strcat(aux2,"_vetor_control.txt"); 
   salvar_vetor(arquivo2);//Salva os vetores 
   tamsave_vetor(aux2);//Salva as informações dos vetores 
} 
 
void salvar_vetor(char *nome){//Salva todas as matrizes q estavam na memória interna do programa 
   FILE *f; 
   int a,i; 
 
   f = fopen(nome,"wr");//Abre o arquivo 
   if(f==NULL){//Checa se foi possivel abri-lo 
      printf("O arquivo nao pode ser aberto"); 
      exit(0); 
   } 
   for(a=0;a<6;a++){ 
      if(vet[a].coor==0)//Se não houver um valor na linha da matriz, ela não existe 
         memoriav[a]=0;//Só pra garantir que não   
      if(memoriav[a]==0)//Verifica se é uma matriz existem para salva-la 
         printf("\nO vetor %s nao pode ser salvo!",vet[a].palavra);/* matriz não existe */ 
      else{/* matriz existe */ 
         printf("\nO vetor %s foi salvo com sucesso!",vet[a].palavra);
         for(i=0;i<vet[a].coor;i++){ 
               fprintf(f,"%lf",vet[a].coordenadas[i]);//escreve no arquivo as matrizes 
               fprintf(f," "); 
            } 
         fprintf(f,"\n"); 
      } 
   } 
   printf("\n"); 
   fclose(f);//Fecha o arquivo 
} 
 
void tamsave_vetor(char *nome){//Salva quais matrizes foram salvas e seus tamanhos 
   FILE *f; 
   int a,i; 
 
   f = fopen(nome,"wr");//Abre o arquivo 
   if(f==NULL){ 
      printf("O arquivo não pode ser aberto"); 
      exit(0); 
   } 
   for(a=0;a<6;a++)//Escreve no programa as matrizes que foram salvas 
      fprintf(f,"%d\n",memoriav[a]); 
   fprintf(f,"%lf\n",vet[0].coor);//Escreve o tamanho do vetor 
   fprintf(f,"%lf\n",vet[1].coor);//Escreve o tamanho do vetor 
   for(i=0;i<6;i++){ 
   if(memoriav[i]==1) 
   fprintf(f,"%lf\n",vet[i].modulo); 
   } 
   if(memoriav[5]==1)//Verifica se o vetor produto foi salva 
      fprintf(f,"%lf\n",vet[5].coor);//Escreve o tamanho do vetor produto 
   fclose(f);   
} 
 
void tamler_vetor(char *nome){//Lê o arquivo com as informações das matrizes 
   FILE *f; 
   int a,i; 
  
   f = fopen(nome,"rt"); 
   if(f==NULL){ 
      printf("O arquivo nao pode ser aberto"); 
      exit(0); 
   } 
   for(a=0;a<6;a++)//Lê quais matrizes foram salvas 
      fscanf(f,"%d\n",&memoriav[a]); 
   fscanf(f,"%lf\n",&vet[0].coor);//lê o tamanho da primeira matriz 
   fscanf(f,"%lf\n",&vet[1].coor);//lê o tamanho da segunda matriz 
   for(i=0;i<6;i++){ 
   if(memoriav[i]==1) 
   fscanf(f,"%lf\n",&vet[i].modulo); 
   } 
   if(memoriav[5]==1) 
      fscanf(f,"%lf\n",&vet[5].coor);//Lê o tamanho do vetor produto, se ela existir 
   fclose(f);//Fecha o arquivo 
} 
 
void importar_vetor(char *nome){//Lê o arquivo com as matrizes 
   FILE *f; 
   int a,i,x; 
 
   f = fopen(nome,"rt");//Abre o arquivo 
   if(f==NULL){ 
      printf("O arquivo nao pode ser aberto"); 
      exit(0); 
   } 
   for(x=2;x<5;x++)//Passa para o programa o tamanho das matrizes 
      if(memoriav[x]==1){ 
            vet[x].coor = vet[0].coor; 
      } 
       
         
  
   for(a=0;a<6;a++) 
      if(memoriav[a]==1){//Cria as matrizes e inicializa seus valores 
         vet[a].coordenadas=cria_vetor(vet[a].coor);/* Cria */ 
         for(i=0;i<vet[a].coor;i++){ 
               fscanf(f,"%lf",&vet[a].coordenadas[i]);/* Inicializa */ 
               if(i!=(vet[a].coor-1)) 
                  fscanf(f," "); 
               else 
                  fscanf(f,"\n"); 
            }     
      } 
   fclose(f);//Fecha o arquivo 
} 
 



