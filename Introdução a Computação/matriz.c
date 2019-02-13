/************************************************
*               TRABALHO ICC                    *
*                                               *
*   Grupo: Pedro Henrique Oliveira Sousa        *
*          Érica Carneiro Araújo                *
*          Ricardo de Carvalho Oliveira Filho   *
*                                               *
//***********************************************/


//Arquivo com todas as funções da parte de matrizes
#include "matriz.h"

static matriz matl[6];//Variável para a entrada de dentro da struct, o tipo é static, pois é apenas um ponteiro de entrada

int soma_mat=0,sub_mat=0,mult_mat=0,transposta=0;//variáveis de controle para os menus
int memoriam[6];//Variáveis de controle para memória
double **cria_matriz(int n,int m){//cria a matriz com os parâmetros necessários
	double **vet;//variável para a criação da matriz
	int i;
	vet = (double **)malloc(n*sizeof(double *));//cria as linhas da matriz
	for(i=0;i<n;i++)
		vet[i]=(double *)malloc(m*sizeof(double));//cria as colunas da matriz
	return vet;//retorna a matriz com o tamanho solicitado
}

void ler_matriz(int x, int k){//lê qualquer matriz dentro da struct
   int i,a,j,y,control=0;
   soma_mat = sub_mat = mult_mat = transposta = 0;//reseta todas as variáveis de controle
      for(y=0;y<6;y++)                    
      memoriam[y]=0; 
   //Pois esta função, teoricamente, serve para lê as primeiras duas matrizes para progredir no menu
   if(x==0&&k==2){
      printf("\n");
   for(i=0;i<2;i++){
      do{
      control=0;
      printf("Digite o tamanho da matriz %s utilizando espaço(tipo: n m): ",matl[i].palavra);
      scanf("%lf %lf",&matl[i].linha,&matl[i].coluna);
      if(matl[i].linha<0.0||matl[i].coluna<0.0){
      control=1;
      printf("Tamanho de matriz impossível, por favor verifique se é inteiro positivo\n");
      }else if(((matl[i].linha/floor(matl[i].linha))!=1)||((matl[i].coluna/floor(matl[i].coluna))!=1)){
      control=1;
      printf("Tamanho de matriz impossível, por favor verifique se é inteiro\n");
      }else
      matl[i].mat = cria_matriz(matl[i].linha,matl[i].coluna);
      
      }while(control==1);
   }
   } 
   for(a=x;a<k;a++){//indica qual(is) matriz(es) deve(m) ser lida(s)   
      memoriam[a]=1; 
      for(i=0;i<matl[a].linha;i++)//indica o tamanho da linha, eixo x, da matriz
         for(j=0;j<matl[a].coluna;j++){//indica o tamanho da coluna, eixo y,da matriz
            if(i==0&&j==0)//Serve para apenas a primeira vez que entre nos for's quebre a linha
               printf("\n");
            printf("Digite o valor na posição [%d][%d] da matriz %s: ",i,j,matl[a].palavra);
            scanf("%lf",&matl[a].mat[i][j]);//recebe o valor digitado na matriz
         }
      printf("\n");
   }
}

void imprime_matriz(int x, int k){//imprime qualquer matriz dentro da struct
   int i,j,a;
   for(a=x;a<k;a++){//indica qual(is) matriz(es) deve(m) ser impressa(s) 
      memoriam[a]=1;
      for(i=0;i<matl[a].linha;i++)//indica o tamanho da linha, eixo x, da matriz
         for(j=0;j<matl[a].coluna;j++){//indica o tamanho da coluna, eixo y,da matriz
	 printf("\nO valor da matriz %s na posição[%d][%d] é: %lf",matl[a].palavra,i,j,matl[a].mat[i][j]);		
	 }
   printf("\n");
   }
}

void soma_matriz(int q,int w){//soma as duas matrizes digitadas inicialmente
int i,j;
   if(matl[q].linha==matl[w].linha && matl[q].coluna==matl[w].coluna){//Condição para que seja possivel a soma
      soma_mat++;//acrescenta uma unidade na variável de controle para saber que existe esta matriz,para os menus seguintes.
      matl[2].linha = matl[q].linha;
      matl[2].coluna = matl[q].coluna;
      matl[2].mat = cria_matriz(matl[2].linha,matl[2].coluna);
      for(i=0;i<matl[2].linha;i++){
         for(j=0;j<matl[2].coluna;j++){
            matl[2].mat[i][j] = matl[q].mat[i][j] + matl[w].mat[i][j];
         }
      }
   imprime_matriz(2,3);//imprime a matriz soma
   }else{
      printf("\nEstas matrizes não podem ser somadas,tamanho das matrizes incopatível\n");
   }
}

void subtrai_matriz(int q,int w){//Subtrai as duas matrizes digitadas inicialmente
int i,j;
   if(matl[q].linha==matl[w].linha && matl[q].coluna==matl[w].coluna){//Condição para que seja possível a subtração
      sub_mat++;//acrescenta uma unidade na variável de controle para saber que existe esta matriz,para os menus seguintes.
      matl[3].linha = matl[q].linha;
      matl[3].coluna = matl[q].coluna;
      matl[3].mat = cria_matriz(matl[3].linha,matl[3].coluna);
      for(i=0;i<matl[3].linha;i++){
         for(j=0;j<matl[3].coluna;j++){
            matl[3].mat[i][j] = matl[q].mat[i][j] - matl[w].mat[i][j];
         }
      }
   imprime_matriz(3,4);//imprime a matriz subtração
   }else{
      printf("\nEstas matrizes não podem ser subtraidas,tamanho das matrizes incopatível\n");
   }

}

void multiplica_matriz(){//multiplica duas matrizes na escolha do usuário, se possivel
   int q,w,a,esc1,esc2;
   do{
   printf("\nOpções para fazer a multiplicação de matrizes");
   printf("\n(1)Primeira matriz lida");
   printf("\n(2)Segunda matriz lida");
   printf("\n(3)Matriz soma");
   printf("\n(4)Matriz diferença");
   printf("\nDigite quais matrizes devem ser multiplicadas(tipo: x y): ");
   scanf("%d %d",&esc1,&esc2);
   if(soma_mat==0&&(esc1==3||esc2==3)||sub_mat==0&&(esc1==4||esc2==4)){//Condição que indica uma opção ainda não foi gerada
      if(esc1==3||esc2==3)
         soma_matriz(0,1);
      if(esc1==4||esc2==4)
         subtrai_matriz(0,1);
       
   }
   if((esc1!=1&&esc1!=2&&esc1!=3&&esc1!=4)||(esc2!=1&&esc2!=2&&esc2!=3&&esc2!=4))
      printf(ERRO_MAT);
   }while((esc1!=1&&esc1!=2&&esc1!=3&&esc1!=4)||(esc2!=1&&esc2!=2&&esc2!=3&&esc2!=4));
   if((matl[esc1-1].coluna==matl[esc2-1].linha)!=0){
      mult_mat++;//acrescenta uma unidade na variável de controle para saber que existe esta matriz,para os menus seguintes.
      matl[4].mat = cria_matriz(matl[esc1-1].linha,matl[esc2-1].coluna);
      matl[4].linha = matl[esc1-1].linha;
      matl[4].coluna = matl[esc2-1].coluna;
      for(q=0;q<matl[esc1-1].linha;q++)//indica a linha da matriz multiplica, criada. 
         for(w=0;w<matl[esc2-1].coluna;w++)//indica a coluna da matriz multiplica, criada.
            for(a=0;a<matl[esc1-1].coluna;a++)//for auxiliar para manipular a multiplicação de matrizes
               matl[4].mat[q][w] = matl[4].mat[q][w] + (matl[esc1-1].mat[q][a]*matl[esc2-1].mat[a][w]);
      imprime_matriz(4,5);//imprime a matriz produto
   }else
      printf("\nNão é possivel fazer esta multiplicação!\n");
     
}

void determinante_matriz(){//Calcula o determinante das matrizes
   int esc3,a,b=2,c=1,d=1,cont=0;
   double det,aux,auxc,aux1=1.0,aux2=1.0,aux3=1.0;
   do{
   printf("\nOpções para calcular o determinante de uma matriz");
   printf("\n(1)Primeira matriz lida");
   printf("\n(2)Segunda matriz lida");
   printf("\n(3)Matriz soma");
   printf("\n(4)Matriz diferença");
   printf("\n(5)Matriz produto");
   printf("\nDigite qual das matrizes deve ser calculado o determinante: ");
   scanf("%d",&esc3);
   if((soma_mat==0&&esc3==3)||(mult_mat==0&&esc3==5)||(sub_mat==0&&esc3==4)){//Condição que indica uma opção impossivel
                                                                       //Digitada pelo usuário
      cont=1;
      switch(esc3){
         case 3:
            soma_matriz(0,1);
            break;
         case 4:
            subtrai_matriz(0,1);
            break;
         case 5:
            printf("\nA matriz Produto não existe.");
            multiplica_matriz();
            break;
      }      
      }
   if(esc3!=1&&esc3!=2&&esc3!=3&&esc3!=4&&esc3!=5)
      printf(ERRO_MAT);
   }while(esc3!=1&&esc3!=2&&esc3!=3&&esc3!=4&&esc3!=5);
   if(cont==0)
      imprime_matriz(esc3-1,esc3);
   if(matl[esc3-1].linha==matl[esc3-1].coluna && matl[esc3-1].linha<=3){//Condição em que é possível calcular o determinante
                                                                        //Por este programa
      switch((int)matl[esc3-1].linha){
         case 1://Calcula o determinante de uma matriz 1x1
            det = matl[esc3-1].mat[0][0];   
            break;
         case 2://Calcula o determinante de uma matriz 2x2
            for(a=0;a<=1;a++){
               aux1 = aux1*matl[esc3-1].mat[a][a];
               b = a;
               if(a==1)
                  c = 0;
               aux2 = aux2*matl[esc3-1].mat[b][c];
               }
            det = aux1 - aux2;
            break;
         case 3://Calcula o determinante de uma matriz 3x3
            for(a=0;a<=2;a++){
               aux1 = aux1*matl[esc3-1].mat[a][a];
               if(a==2)
                  c=0;
               aux2 = aux2*matl[esc3-1].mat[a][c];
               c++;
               aux3 = aux3*matl[esc3-1].mat[a][b];
               b = 0;
               if(a==1)
                  b++;
            }
            aux = aux1+aux2+aux3;
            aux1 = aux2 = aux3 = 1.0;
            b = 2;
            c = 0;
            for(a=0;a<=2;a++){
               aux1 = aux1*matl[esc3-1].mat[a][b];
               b--;
               aux2 = aux2*matl[esc3-1].mat[a][c];
               c +=2;
               if(a==1)
                  c = 1;
               aux3 = aux3*matl[esc3-1].mat[a][d];
               if(a==1)
                  d = 3;
               d--;
            }
            auxc = aux1+aux2+aux3;
            det = aux - auxc;
            break;            
      }
   printf("\nO determinante da matriz %s é: %lf\n",matl[esc3-1].palavra,det);
   }else 
      printf("\nEste programa não calcula o determinante desta matriz\nMotivo: Matriz de dimensões diferente de 1x1, 2x2 ou 3x3");
}

void matriz_transposta(){//Mostra a transposta da matriz
   int esc,i,j,k,aux=0;

   do{
      printf("\nOpções para demonstrar a transposta de uma matriz");
      printf("\n(1)Primeira matriz lida");
      printf("\n(2)Segunda matriz lida");
      printf("\n(3)Matriz soma");
      printf("\n(4)Matriz diferença");
      printf("\n(5)Matriz produto");
      printf("\nDigite qual matriz deve ser demonstrada a transposta: ");
      scanf("%d",&esc);
      if((soma_mat==0&&esc==3)||(mult_mat==0&&esc==5)||(sub_mat==0&&esc==4)){//Condição que indica uma opção ainda não gerada
         aux =1;
         switch(esc){
            case 3:
               soma_matriz(0,1);
               break;
            case 4:
               subtrai_matriz(0,1);
               break;
            case 5:
               printf("\nA matriz Produto não existe.");
               multiplica_matriz();
               break;
         }
      }
      if(esc!=1&&esc!=2&&esc!=3&&esc!=4&&esc!=5)
         printf(ERRO_MAT);
   }while(esc!=1&&esc!=2&&esc!=3&&esc!=4&&esc!=5);
   if(aux==0)
      imprime_matriz(esc-1,esc);
   transposta++;//acrescenta uma unidade na variável de controle para saber que existe esta matriz,para os menus seguintes.
   matl[5].mat = cria_matriz(matl[esc-1].coluna,matl[esc-1].linha);
   matl[5].coluna = matl[esc-1].linha;
   matl[5].linha = matl[esc-1].coluna;
   for(i=0;i<matl[esc-1].linha;i++)
      for(j=0;j<matl[esc-1].coluna;j++)
         matl[5].mat[j][i] = matl[esc-1].mat[i][j]; 
   imprime_matriz(5,6);//Imprime a matriz transposta  
  
}

void matriz_simetrica(){//Verifica se a matriz é simétrica
   int i,j,opc2,max,cont=0,aux=0;

   do{
   printf("\nOpções para verificar se a matriz é simétrica");
   printf("\n(1)Primeira matriz lida");
   printf("\n(2)Segunda matriz lida");
   printf("\n(3)Matriz soma");
   printf("\n(4)Matriz diferença");
   printf("\n(5)Matriz produto");
   printf("\nDigite qual matriz deve ser feito o teste de simetria: ");
   scanf("%d",&opc2);
   if((soma_mat==0&&opc2==3)||(mult_mat==0&&opc2==5)||(sub_mat==0&&opc2==4)){//Condição que indica uma opção impossivel
                                                                       //Digitada pelo usuário
      aux=1;
      switch(opc2){
         case 3:
            soma_matriz(0,1);
            break;
         case 4:
            subtrai_matriz(0,1);
            break;
         case 5:
            multiplica_matriz();
            break;
      }
   }
   if(opc2!=1&&opc2!=2&&opc2!=3&&opc2!=4&&opc2!=5)
      printf(ERRO_MAT);
   }while(opc2!=1&&opc2!=2&&opc2!=3&&opc2!=4&&opc2!=5);
   if(aux==0)
      imprime_matriz(opc2-1,opc2);
   if(matl[opc2-1].linha==matl[opc2-1].coluna && matl[opc2-1].linha>=2){
      max=(matl[opc2-1].linha*matl[opc2-1].coluna)-matl[opc2-1].linha;
      for(i=0;i<matl[opc2-1].linha;i++)
         for(j=0;j<matl[opc2-1].coluna;j++)
            if(i!=j)
            if(matl[opc2-1].mat[i][j] == matl[opc2-1].mat[j][i])
               cont++;//Contador para indicar quantos números são iguais
      if(cont==max)
         printf("\nEsta matriz é simétrica.\n");
      else
         printf("\nEsta matriz não é simetrica.\n");
   }else
      printf("\nEsta matriz não é simetrica.\n");
   

}

void salva_arquivo_matriz(char *arquivo,int tam){
   char aux[tam+20];
   strcpy(aux,arquivo);
   strcat(arquivo,"_matriz.txt");
   strcat(aux,"_matriz_control.txt");
   salvar_matriz(arquivo);//Salva as matrizes no "memoria.txt"
   tamsave_matriz(aux);//Salva as informações das matrizes no "tam.txt"
}

void importa_arquivo_matriz(char *arquivo,int tam){
   char aux[tam+20];
   int esc2,iniciot=1;
   do{
      esc2=0;
      if(iniciot==0){
      printf("Digite novamente o nome do arquivo (sem espaço ou .txt): ");
      setbuf(stdin,NULL);
      scanf("%s",arquivo);
      setbuf(stdin,NULL);
      }
      iniciot=0;
      strcpy(aux,arquivo);
      strcat(arquivo,"_matriz.txt");
      strcat(aux,"_matriz_control.txt");
      if((access(arquivo, F_OK)==0)&&(access(aux, F_OK)==0)){
         tamler_matriz(aux);
         importar_matriz(arquivo);
      }else{
         printf("\nArquivo de memoria não encontrado!");
      do{
         printf("\nDigite se deseja tentar novamente");
         printf("\n(1)Digitar novamente o nome do arquivo para importar");
         printf("\n(2)Inicializar o programa sem importar dados");
         printf("\nDigite sua opção: ");
         scanf("%d",&esc2);
         if(esc2!=1&&esc2!=2)
         printf("\nOpção inválida, digite novamente!\n");
      }while(esc2!=1&&esc2!=2);
   }
   }while(esc2==1);
}

void salvar_matriz(char *nome){//Salva dentro do arquivo todas as matrizes q estavam na memória interna do programa
   FILE *f;
   int a,i,j;
  

   f = fopen(nome,"wr");//Abre o arquivo
   if(f==NULL){//Checa se foi possivel abri-lo
      printf("O arquivo não pode ser aberto");
      exit(0);
   }
   for(a=0;a<6;a++){
      if(matl[a].linha==0)//Se não houver um valor na linha da matriz, ela não existe
         memoriam[a]=0;//Só pra garantir que não  
      if(memoriam[a]==0)//Verifica se é uma matriz existem para salva-la
         printf("\nA matriz %s não pode ser salva",matl[a].palavra);/* matriz não existe */
      else{/* matriz existe */
         printf("\n A matriz %s foi salva com sucesso!",matl[a].palavra);
         for(i=0;i<matl[a].linha;i++)
            for(j=0;j<matl[a].coluna;j++){
               fprintf(f,"%lf",matl[a].mat[i][j]);//escreve no arquivo as matrizes
               fprintf(f," ");
            }
         fprintf(f,"\n");
      }
   }
   printf("\n");
   fclose(f);//Fecha o arquivo
}

void tamsave_matriz(char *nome){//Salva quais matrizes foram salvas e seus tamanhos
   FILE *f;
   int a;

   f = fopen(nome,"wr");//Abre o arquivo
   if(f==NULL){
      printf("O arquivo não pode ser aberto");
      exit(0);
   }
   for(a=0;a<6;a++)//Escreve no programa as matrizes que foram salvas
      fprintf(f,"%d\n",memoriam[a]);
   fprintf(f,"%lf %lf\n",matl[0].linha,matl[0].coluna);//Escreve o tamanho da matriz
   fprintf(f,"%lf %lf\n",matl[1].linha,matl[1].coluna);//Escreve o tamanho da matriz
   if(memoriam[5]==1)//Verifica se a matriz transposta foi salva
      fprintf(f,"%lf %lf\n",matl[5].linha,matl[5].coluna);//Escreve o tamanho da matriz transposta
   fclose(f);  
}

void tamler_matriz(char *nome){//Lê o arquivo com as informações das matrizes
   FILE *f;
   int a;

   f = fopen(nome,"rt");
   if(f==NULL){
      printf("O arquivo não pode ser aberto");
      exit(0);
   }
   for(a=0;a<6;a++)//Lê quais matrizes foram salvas
      fscanf(f,"%d\n",&memoriam[a]);
   fscanf(f,"%lf %lf\n",&matl[0].linha,&matl[0].coluna);//lê o tamanho da primeira matriz
   fscanf(f,"%lf %lf\n",&matl[1].linha,&matl[1].coluna);//lê o tamanho da segunda matriz
   if(memoriam[5]==1)
      fscanf(f,"%lf %lf\n",&matl[5].linha,&matl[5].coluna);//Lê o tamanho da matriz transposta, se ela existir
   fclose(f);//Fecha o arquivo
}

void importar_matriz(char *nome){//Lê o arquivo com as matrizes
   FILE *f;
   int a,i,j,x;

   f = fopen(nome,"rt");//Abre o arquivo
   if(f==NULL){
      printf("O arquivo não pode ser aberto");
      exit(0);
   }
   for(x=2;x<5;x++)//Passa para o programa o tamanho das matrizes
      if(memoriam[x]==1){
            matl[x].linha = matl[0].linha;
            matl[x].coluna = matl[1].coluna;
      }  
 
   for(a=0;a<6;a++)
      if(memoriam[a]==1){//Cria as matrizes e inicializa seus valores
         matl[a].mat=cria_matriz(matl[a].linha,matl[a].coluna);/* Cria */
         for(i=0;i<matl[a].linha;i++)
            for(j=0;j<matl[a].coluna;j++){
               fscanf(f,"%lf",&matl[a].mat[i][j]);/* Inicializa */
               if(i!=(matl[a].linha-1)&&j!=(matl[a].coluna-1))
                  fscanf(f," ");
               else
                  fscanf(f,"\n");
            }    
      }
   fclose(f);//Fecha o arquivo
}

void matrizes_salvas(int x,int k){//Imprime de uma forma mais legivel as matrizes
   int i,j,a;
   
   for(a=x;a<k;a++){
      if(memoriam[a]==1)
         printf("\nMatriz %s\n",matl[a].palavra);
      for(i=0;i<matl[a].linha;i++)
         for(j=0;j<matl[a].coluna;j++){
            if(j==0)
               printf("| ");
            printf("%lf",matl[a].mat[i][j]);  
            if(j==(matl[a].coluna-1))
               printf(" |\n");
            else
               printf("  ");
         }
   }
}

void inicio_matriz(){//Função que inicializa a main, dizendo para o programa o nome das matrizes
   matl[0].palavra = "inicial1";
   matl[1].palavra = "inicial2";
   matl[2].palavra = "soma";
   matl[3].palavra = "diferença";
   matl[4].palavra = "produto";
   matl[5].palavra = "transposta";
}

void limpa_matriz(){//Desloca da memória todas as matrizes criadas
   int a,i;
   for(a=0;a<6;a++)
   for(i=0;i<matl[a].linha;i++)
   free((void *)matl[a].mat[i]);
   for(i=0;i<6;i++)
   free((void *)matl[i].mat);
}

