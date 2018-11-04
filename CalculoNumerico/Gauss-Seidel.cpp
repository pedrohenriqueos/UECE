#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f3f3f3f3f

const long double EPS =1e-9;
int N,M,itera;
long double eps;

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
	void negativa(){ //Inverte o sinal da matriz
		for(int i=0;i< N;i++)
			for(int j=0;j< M;j++)
				Mat[i][j] = (fabs(Mat[i][j])>EPS)?-Mat[i][j]:Mat[i][j];
	}
	Matrix L(){ //retorna a Matriz L, da matriz que chama a função
		Matrix result(N,M);
		for(int i=0;i< N;i++)
			for(int j=0;j< i;j++)
				result.Mat[i][j] = Mat[i][j];
		return result;
	}
	Matrix R(){ //retorna a Matriz R, da matriz que chama a função
		Matrix result(N,M);
		for(int i=0;i< N;i++)
			for(int j=i+1;j< M;j++)
				result.Mat[i][j] = Mat[i][j];
		return result;
	}
	Matrix D(){ //retorna a Matriz D, da matriz que chama a função
		Matrix result(N,M);
		for(int i=0;i< N;i++)
			result.Mat[i][i] = Mat[i][i];
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

Matrix A,L,R,D,X,b,Inter;
vector<Matrix> It;
pair<long double,long double> equacao;

void inputs(){
	scanf("%d %d %Lf %d",&N,&M,&eps,&itera);
	Matrix aux1(N,M),aux3(M,1),aux2(N,1);
	A = aux1;
	X = aux3;
	b = aux2;
	for(int i=0;i< A.N;i++)
		for(int j=0;j< A.M;j++)
			scanf("%Lf",&A.Mat[i][j]);
	for(int i=0;i< b.N;i++)
		for(int j=0;j< b.M;j++)
			scanf("%Lf",&b.Mat[i][j]);
}

void output(){
	puts("Iteracoes:");
	for(int i=0;i<(int)It.size();i++){
		It[i].printM();
		puts("");
	}
  	puts("Vetor final:");
	X.printM();
	puts("");
	puts("Resultado da Interpolacao:");
	printf("Equação: %Lf*x ",equacao.first);
	if(equacao.second<0.0)
		printf("%Lf\n",equacao.second);
	else
		printf("+%Lf\n",equacao.second);
	cout << "   x          y\n";
	for(int i=0;i<Inter.N;i++)
		printf("%Lf : %Lf\n",Inter.Mat[i][0],Inter.Mat[i][1]);
}

void Gerar_RLD(){//Gera as matrizes apartir da Matriz A, para os calculos
	L = A.L();
	R = A.R();
	D = A.D();
	L.negativa();
	R.negativa();
}
void CriterioLinhas(){
    for(int i=0;i<A.N;i++){
        double sum =0.0;
        for(int j=0;j<A.M;j++)
            if(j!=i)
                sum+=fabs(A.Mat[i][j]);
        sum/=fabs(A.Mat[i][i]);
        if(sum>=1.0){
            puts("Nao respeita o Criterio de Convergencia das Linhas");
            exit(1);
        }
    }
}
void CriteriodeSassenfeld(){
    Matrix v(A.N,1);
    for(int i=0;i<A.N;i++){
        double sum =0.0;
        for(int j=0;j<i;j++)
            sum+=fabs(A.Mat[i][j])*v.Mat[j][0];
        for(int j=i+1;j<A.M;j++)
            sum+=fabs(A.Mat[i][j]);
        sum/=fabs(A.Mat[i][i]);
        if(sum>=1.0){
            puts("Nao respeita o Criterio de Convergencia de Sassenfeld");
            exit(1);
        }
    }
}

void GaussSeidel(){
	for(int i=0;i< b.N;i++)
		for(int j=0;j< b.M;j++)
			X.Mat[i][j] = b.Mat[i][j]/A.Mat[i][i];//vetor X inicial
	while(itera--){
		It.push_back(X);
		Matrix result(X.N,X.M);
		for(int i=0;i<X.N;i++){
			long double sum=0;
			for(int j=0;j<i;j++)
				sum+= L.Mat[i][j]*result.Mat[j][0];
			for(int j=i+1;j<X.N;j++)
				sum+= R.Mat[i][j]*X.Mat[j][0];
			result.Mat[i][0] = (b.Mat[i][0]+sum)/D.Mat[i][i];
		}
		long double mX = -inf,m = -inf;
		for(int i=0;i<X.N;i++){ //Erro relativo
			m = max(m,fabs(result.Mat[i][0] - X.Mat[i][0]));
			mX = max(mX,fabs(result.Mat[i][0]));
		}
		X = result;
		if((m/mX)<eps)
			break;
		
	}

}

void Lagrange(){
	Matrix result(X.N,2);
	result.Mat[0][0] = X.Mat[0][0], result.Mat[0][1] = b.Mat[0][0];
	result.Mat[1][0] = X.Mat[1][0], result.Mat[1][1] = b.Mat[1][0];
	equacao.first = (b.Mat[0][0]/(X.Mat[0][0]- X.Mat[1][0])) + (b.Mat[1][0]/(X.Mat[1][0] - X.Mat[0][0]));
	equacao.second = ((-b.Mat[0][0]*X.Mat[1][0])/(X.Mat[0][0] - X.Mat[1][0]))+((-b.Mat[1][0]*X.Mat[0][0])/(X.Mat[1][0] - X.Mat[0][0]));
    for(int i=2;i<X.N;i++){ //Calculo dos demais valores aproximados pela reta feita.
		long double p=b.Mat[0][0]*(X.Mat[i][0]-X.Mat[1][0])/(X.Mat[0][0] - X.Mat[1][0]);
		p+=b.Mat[1][0]*(X.Mat[i][0]-X.Mat[0][0])/(X.Mat[1][0] - X.Mat[0][0]);
		result.Mat[i][0] = X.Mat[i][0], result.Mat[i][1] = p;
  	}
	Inter = result;
}
int main(){
	inputs();
	CriteriodeSassenfeld();
    CriterioLinhas();
	Gerar_RLD();
	GaussSeidel();
    Lagrange();
	output();
}
/* 
Exemplo input:
3 3 0.01 10
10 2 2
1 10 2
2 -7 -10
28 7 -17

2 2 0.01 5 
5 2
1 4
1 2

*/
