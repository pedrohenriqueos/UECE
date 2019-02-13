/************************************************
*               TRABALHO ICC                    *
*                                               *
*   Grupo: Pedro Henrique Oliveira Sousa        *
*          Érica Carneiro Araújo                *
*          Ricardo de Carvalho Oliveira Filho   *
*                                               *
//***********************************************/

#include "matriz.h"
#include "vetor.h"

 int opc,opc2,esc,contm=0,contv=0, c, sub,aux;
   char arquivo[100],arquivo2[100];

void menu_entrada(){
   printf("\nMenu de entrada: \n");
   printf("***************************************************************\n");
   printf("\n (1)Operações com matrizes!!");
   printf("\n (2)Operações com vetores!!");
   printf("\n (3)Fechar programa!!");
   printf("\n\n***************************************************************");
   printf("\nDigite sua opção: ");
}

void menu_arquivo_matrizes(){
   printf("\nMenu de arquivo de matrizes: \n");
   printf("***************************************************************\n");
   printf("\n (1)Importar arquivo de matriz!!");
   printf("\n (2)Inicializar o programa de matrizes!!");
   printf("\n (3)Voltar para o menu anterior!!");
   printf("\n\n***************************************************************");
   printf("\nDigite sua opção: ");
   
}

void menu_matriz(){
            printf("\nMenu de operações:");
            printf("\n***************************************************************\n");
            printf("\n (1)Criar matrizes");
            printf("\n (2)Somar duas matrizes");
            printf("\n (3)Subtrair duas matrizes");
            printf("\n (4)Multiplicar duas matrizes");
            printf("\n (5)Calcular a transposta de uma matriz");
            printf("\n (6)Calcular o determinante de uma matriz");
            printf("\n (7)Verificar se uma matriz é simétrica");
            printf("\n (8)Salva as matrizes");
            printf("\n (9)Mostrar todas as matrizes salvas");
            printf("\n (10)Voltar ao menu anterior");
            printf("\n\n***************************************************************");
            printf("\nDigite a opção desejada: ");
            
}

void operar_matrizes(int esc){
   switch(esc){
               case 1:
                  printf("\nVamos criar 2 matrizes!!\n");
                  ler_matriz(0,2);//Chama a função ler_matriz()
                  contm=1;//Controle para checar se ja foi criada as matrizes
                  break;
               case 2:
                  if(contm==1)
                  soma_matriz(0,1);//Chama a função soma_matriz()
                  else
                     printf("\nInforme primeiramente as matrizes iniciais,opção (1)Criar matrizes\n");
                  break;
               case 3:
                  if(contm==1)
                     subtrai_matriz(0,1);//Chama a função subtrai_matriz()
                  else
                     printf("\nInforme primeiramente as matrizes iniciais,opção (1)Criar matrizes\n");
                  break;
               case 4:
                  if(contm==1)
                     multiplica_matriz();//Chama a função multiplica_matriz()
                  else
                     printf("\nInforme primeiramente as matrizes iniciais,opção (1)Criar matrizes\n");
                  break;
               case 5:
                  if(contm==1)
                     matriz_transposta();//Chama a função matriz_transposta()
                  else
                     printf("\nInforme primeiramente as matrizes iniciais,opção (1)Criar matrizes\n");
                  break;
               case 6:
                  if(contm==1)
                     determinante_matriz();//Chama a função determinante_matriz()
                  else
                     printf("\nInforme primeiramente as matrizes iniciais,opção (1)Criar matrizes\n");
                  break;
               case 7:
                  if(contm==1)
                     matriz_simetrica();//Chama a função matriz_simetrica()
                  else
                     printf("\nInforme primeiramente as matrizes iniciais,opção (1)Criar matrizes\n");
                  break;
               case 8:
                  printf("Digite o nome do arquivo(sem espaço ou .txt): ");
                  setbuf(stdin,NULL);
                  scanf("%s",arquivo);
                  setbuf(stdin,NULL);     
                  salva_arquivo_matriz(arquivo,100);//cria os arquivos com o nome passado pelo usuário
                  break;                            //O segundo argumento é o tamanho do char declarado, como na fgets é passado.
               case 9:
                  matrizes_salvas(0,6);//Imprime todas as matrizes na memoria do programa (em execução)
                  break;   
               case 10:
                  printf("\n");
                  break;
               default:         
                  printf("\nOpção inválida, digite novamente.\n");
            }
        //Desaloca da memória as matrizes criadas

}

void menu_arquivo_vetor(){
   printf("\n   Menu de arquivo de vetores: \n");
   printf("***************************************************************\n");
   printf("\n (1) Importar arquivo de vetores!!");
   printf("\n (2) Inicializar o programa de vetores!!");
   printf("\n (3) Sair!!");
   printf("\n\n***************************************************************");
   printf("\nDigite sua opção: ");
}

void menu_vetor(){
   printf("\nMenu de operações: \n");
   printf("***************************************************************\n");
   printf("\n (1) Criar vetores!!\n (2) Somar vetores!!\n (3) Subtrair vetores!!\n (4) Produto por um escalar!!\n (5) Produto de Vetores!!\n (6) Salvar vetores!!\n (7) Imprimir vetores!!\n (8) Voltar ao menu anterior!!");
   printf("\n\n***************************************************************");
   printf("\n Digite a sua opção: ");
}

void operar_vetores(int c){
   switch (c){
	       case 1:
	          printf("\nVamos criar 2 vetores!!!\n");
   	          alimenta_struct_vetor();
                  printf("\nOperar 2 vetores!!!\n");
                  contv=1;		
	          break;
	       case 2:
                  if(contv==1){
                  printf("\n");
	          soma_vetor();	
                  }else
                  printf("\nInforme primeiramente os vetores iniciais,opção (1)Criar vetores\n");		
	          break;
   	       case 3:
                  if(contv==1){
                  do{
	          printf("\nSUBTRAÇÃO DE VETORES: \n Escolha a ordem da substração: \n(1)V1 - V2\n(2)V2 - V1\n   Digite sua opcao: ");
	          scanf("%d", &sub);
                  if((sub!=1)&&(sub!=2))
                  printf("Erro!Digite uma opção válida!!\n");
                  else{
                  aux=1;
	          subtracao_vetor(sub);
                  }
                  }while(aux!=1);
                  }else
                  printf("\nInforme primeiramente os vetores iniciais,opção (1)Criar vetores\n");
	          break;
	       case 4:	
                  if(contv==1){
                  printf("\n");
   	          produto_escalar();
                  }else
                  printf("\nInforme primeiramente os vetores iniciais,opção (1)Criar vetores\n");
	          break;
	       case 5:
                  if(contv==1){
                  printf("\n");
	          produto_de_vetores();
                  }else
                  printf("\nInforme primeiramente os vetores iniciais,opção (1)Criar vetores\n");
                  break;
               case 6:
                  if(contv==1){
                  printf("Digite o nome do arquivo(sem .txt): ");
                  setbuf(stdin,NULL);
                  scanf("%s",arquivo2);
                  setbuf(stdin,NULL);
                  salva_arquivo_vetor(arquivo2,100);
                  }else
                  printf("\nInforme primeiramente os vetores iniciais,opção (1)Criar vetores\n");
                  break;
               case 7:
                  if(contv==1)
                  vetores_salvos();
                  else
                     printf("\nInforme primeiramente os vetores iniciais,opção (1)Criar vetores!!\n");
                  break;
               case 8:
                  printf("Sair de Vetores!!\n\n"); 
                  break;
               default:
                  printf("\nOpção inválida, digite novamente.\n");
            }
}
int main(void){
   do{
   menu_entrada();
   scanf("%d",&opc);
   printf("\n_______________________________________________________________\n\n");
   switch(opc){
      case 1:
         opc2=0;
         inicio_matriz();//Inicializa o nome das matrizes
         do{//Opção do usuário de selecionar algo ja salvo
            menu_arquivo_matrizes();
            scanf("%d",&opc2);
            printf("\n_______________________________________________________________\n\n");
            switch(opc2){
               case 1:
                     printf("Digite o nome do arquivo (sem espaço ou .txt): ");
                     setbuf(stdin,NULL);
                     scanf("%s",arquivo);
                     setbuf(stdin,NULL);
                     importa_arquivo_matriz(arquivo,100);//Importa os arquivos
                     contm=1;  
               case 2:
                  printf("\n[Matrizes]\n");
                  do{//Menu principal da parte de matrizes
                  menu_matriz();
                  scanf("%d",&esc);
                  printf("\n_______________________________________________________________\n\n");
                  operar_matrizes(esc);
                  }while(esc!=10);
                  contm=0;
                  limpa_matriz();//Desaloca da memória as matrizes criadas
                  break;
               case 3:
                  printf("Voltar ao menu anterior!!\n\n");
                  break;
               default:
                  printf("\nOpção inválida, digite novamente!\n");
            }}while(opc2!=3);
         break;

      case 2:
         opc2=0;
         inicio_vetor();//Inicializa o nome dos vetores
         do{//Opção para o usuário de selecionar algo ja salvo
            menu_arquivo_vetor();
            scanf("%d",&opc2);
            printf("\n_______________________________________________________________\n\n");
            switch(opc2){
               case 1:
                     printf("Digite o nome do arquivo (sem .txt): ");
                     setbuf(stdin,NULL);
                     scanf("%s",arquivo2);
                     setbuf(stdin,NULL);
                     importar_arquivo_vetor(arquivo2,100,1);
                     contv=1; 
               case 2:
                  printf("\n[Vetores]\n");
                  do{//Menu de vetores
	          menu_vetor();
	          scanf("%d",&c);
                  printf("\n_______________________________________________________________\n\n");
	          operar_vetores(c);	
                  }while(c!=8);
                  contv=0;
                  limpa_vetor();
                  break;
               case 3:
                  printf("Voltar ao menu anterior!!\n\n");
                  printf("\n_______________________________________________________________\n\n");
                  break;
               default:
                  printf("\nOpção inválida, digite novamente!\n");
            }}while(opc2!=3);
	 
         break;

      case 3:
         printf("\n\nSair!!\n***************************************************************\nEquipe Dragonfly agradece a preferência!!\n");
         break;
      default:
         printf("\nOpção inválida, digite novamente.\n");
   }}while(opc!=3);
   return 0;
}
