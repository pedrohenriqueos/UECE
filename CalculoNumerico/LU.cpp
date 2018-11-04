#include<bits/stdc++.h>
using namespace std;

const long double EPS =1e-9;

struct Matrix{
	vector<vector<long double>> Mat;
	int N,M;
	Matrix(int _N,int _M){
		N=_N;
		M=_M;
		Mat.assign(_N,vector<long double>(_M,0.0));
	}
	Matrix(){}
	Matrix friend operator*(const Matrix &m1,const Matrix &m2){
		if(m1.M!=m2.N){
			printf("Multiplicação de matrizes invalida!\n");
			exit(1);
		}
		Matrix result(m1.N,m2.M);
		for(int i=0;i< m1.N;i++)
			for(int j=0;j<m2.M;j++)
				for(int k=0;k<m1.M;k++)
					result.Mat[i][j] +=m1.Mat[i][k]*m2.Mat[k][j];
		return result;
	}
	Matrix friend operator+(const Matrix &m1,const Matrix &m2){
		if(m1.N!=m2.N or m1.M!=m2.M){
			printf("Soma de matrizes inválida!\n");
			exit(1);
		}
		Matrix result(m1.N,m1.M);
		for(int i=0;i< m1.N;i++)
			for(int j=0;j< m1.M;j++)
				result.Mat[i][j] = m1.Mat[i][j]+m2.Mat[i][j];
		return result;
	}
	Matrix friend operator-(const Matrix &m1,const Matrix &m2){
		if(m1.N!=m2.N or m1.M!=m2.M){
			printf("Subtração de matrizes inválida!\n");
			exit(1);
		}
		Matrix result(m1.N,m1.M);
		for(int i=0;i< m1.N;i++)
			for(int j=0;j< m1.M;j++)
				result.Mat[i][j] = m1.Mat[i][j]-m2.Mat[i][j];
		return result;
	}
	void printM(){ //imprimi a matriz
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				printf("%Lf ",Mat[i][j]);
			puts("");
		}
	}
};
Matrix A,P,L,U,b,y,x,Inter;
pair<long double,long double> equacao;
int N,M;
bool cmp(pair<int,int> a, pair<int,int> b){ //ordem do vetor para o Pivotamento
	return a.first > b.first;
}
void inputs(){
	scanf(" %d %d",&N,&M);
	Matrix A1(N,M),b1(N,1),x1(M,1),P1(N,N);
	A = A1; // NxM 
	b = b1; y=b1; // Nx1
	L = P1; P = P1; // NxN
	x = x1; // Mx1
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf(" %Lf",&A.Mat[i][j]);
	for(int i=0;i<N;i++)
		scanf(" %Lf",&b.Mat[i][0]);
}
void Gerar_P(){ //Faz o pivotamento
	vector<pair<long double,int>> escalonador;
	Matrix aux = A;
	for(int i=0;i<N;i++)
		escalonador.push_back({A.Mat[i][0],i});
	sort(escalonador.begin(),escalonador.end(),cmp);
	for(int i=0;i<N;i++){
		A.Mat[i] = aux.Mat[escalonador[i].second];
		P.Mat[i][escalonador[i].second] = 1;
	}
}
void Decomposicao_LU(){
	U = A;
	for(int i=0;i < U.N;i++){
		vector<long double> parc(A.M,0.0);
		for(int j = 0;j < i;j++)
			if(fabs(U.Mat[i][j])>EPS){
				parc[j] = (U.Mat[i][j]/U.Mat[j][j]);
				for(int k = 0; k < U.M;k++)
					U.Mat[i][k] -= U.Mat[j][k]*parc[j];
			}
		L.Mat[i] = parc;
		L.Mat[i][i] = 1;
	}
}
void Ly_Pb(){
	b= P*b;
	for(int i = 0;i < L.N ;i++){
		double sum = 0.0;
		for(int j=0 ;j < i;j++)
			sum += y.Mat[j][0]*L.Mat[i][j];
		y.Mat[i][0] = (b.Mat[i][0] - sum);
	}
}
void Ux_y(){
	for(int i = U.N-1;i >=0 ; i--){
			double sum =0.0;
			for(int j = U.M - 1; j> i; j--)
				sum+= x.Mat[j][0]*U.Mat[i][j];
			x.Mat[i][0] = (y.Mat[i][0] - sum) / U.Mat[i][i];
	}
}
void Lagrange(){
	b= P*b;
	Matrix result(x.N,2);
	result.Mat[0][0] = x.Mat[0][0], result.Mat[0][1] = b.Mat[0][0];
	result.Mat[1][0] = x.Mat[1][0], result.Mat[1][1] = b.Mat[1][0];
	equacao.first = (b.Mat[0][0]/(x.Mat[0][0]- x.Mat[1][0])) + (b.Mat[1][0]/(x.Mat[1][0] - x.Mat[0][0]));
	equacao.second = ((-b.Mat[0][0]*x.Mat[1][0])/(x.Mat[0][0] - x.Mat[1][0]))+((-b.Mat[1][0]*x.Mat[0][0])/(x.Mat[1][0] - x.Mat[0][0]));
    for(int i=2;i<x.N;i++){ //Calculo dos demais valores aproximados pela reta feita.
		long double p=b.Mat[0][0]*(x.Mat[i][0]-x.Mat[1][0])/(x.Mat[0][0] - x.Mat[1][0]);
		p+=b.Mat[1][0]*(x.Mat[i][0]-x.Mat[0][0])/(x.Mat[1][0] - x.Mat[0][0]);
		result.Mat[i][0] = x.Mat[i][0], result.Mat[i][1] = p;
  	}
	Inter = result;
}
void outputs(){
	A = P*A;
	puts("Matriz A de entrada:");
	A.printM();
	puts("");
	puts("vetor b de entrada:");
	b.printM();
	puts("");
	puts("Matriz P:");
	P.printM();
	puts("");
	puts("Matriz L:");
	L.printM();
	puts("");
	puts("Matriz U:");
	U.printM();
	puts("");
	puts("Vetor y:");
	y.printM();
	puts("");
	puts("Vetor x:");
	x.printM();
	puts("");
	puts("Resultado da Interpolacao:");
	printf("Equação: %Lf*x ",equacao.first);
	if(equacao.second<0.0)
		printf("%Lf\n",equacao.second);
	else
		printf("+%Lf\n",equacao.second);
	puts("   x          y");
	for(int i=0;i<Inter.N;i++)
		printf("%Lf : %Lf\n",Inter.Mat[i][0],Inter.Mat[i][1]);
	puts("");
	puts("Matriz A pela multiplicação P*L*U:");
	Matrix AA= P*L*U;
	AA.printM();
	puts("");
	puts("vetor b pela multiplicação P*L*U*x:");
	Matrix bb = AA*x;
	bb.printM();
}
int main(){
	inputs();
	Gerar_P();
	Decomposicao_LU();
	Ly_Pb();
	Ux_y();
	Lagrange();
	outputs();
}

/* Exemplos de input (livro do thelmo)
2 2
3 4
-2 1
-2 5

3 3
1 2 3
1 4 7
-2 2 5
1 -1 -7
 
3 3
1 -2 1
2 -1 4
3 -3 2
1 7 5
  
3 3
8 4 2
4 3 1
-8 -2 0
8 3 -6

4 4
1 2 -5 4
2 5 12 7
3 5 17 8
1 1 27 4
6 14 16 6  
  
*/
