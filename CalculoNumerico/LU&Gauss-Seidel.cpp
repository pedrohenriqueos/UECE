#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f3f3f3f3f

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

Matrix A2,L1,R,D,X,b2,Inter,A1,b1,L,U,P,y,x;
vector<Matrix> It;
pair<long double,long double> equacao;
//          x = pontos  y = poluição
vector<pair<long double,long double>> Analise;
int N,M,itera;
long double eps;

bool cmp(pair<int,int> a, pair<int,int> b){ //ordem do vetor para o Pivotamento
	return a.first > b.first;
}
bool cmp2(pair<long double,long double> a,pair<long double,long double> b){ //ordem do rio
	return a.first<b.first;
}

void inputs(){
	scanf("%d %d %Lf %d",&N,&M,&eps,&itera);
	Matrix aux1(N,M),aux3(M,1),aux2(N,1),P1(N,N);
	A2 = aux1; A1 = aux1; // NxM
	b1 = aux2; b2 = aux2; y=aux2; // Nx1
	L = P1; P = P1; // NxN
	X = aux3; x = aux3; // Mx1
	for(int i=0;i<A1.N;i++)
		for(int j=0;j<A1.M;j++)
			scanf(" %Lf",&A1.Mat[i][j]);
	for(int i=0;i<b1.N;i++)
		scanf(" %Lf",&b1.Mat[i][0]); 
	for(int i=0;i< A2.N;i++)
		for(int j=0;j< A2.M;j++)
			scanf("%Lf",&A2.Mat[i][j]);
	for(int i=0;i< b2.N;i++)
		scanf("%Lf",&b2.Mat[i][0]);
}

void output2(){
	puts("--Fatoração LU--");
	A1 = P*A1;
	puts("Matriz A1 de entrada:");
	A1.printM();
	puts("");
	puts("vetor b1 de entrada:");
	b1.printM();
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
	puts("Matriz A1 pela multiplicação P*L*U:");
	Matrix AA= P*L*U;
	AA.printM();
	puts("");
	puts("vetor b1 pela multiplicação P*L*U*x:");
	Matrix bb = AA*x;
	bb.printM();
	puts("");
	puts("--Guass-Seidel--");
	puts("Iteracoes:");
	for(int i=0;i<(int)It.size();i++){
		It[i].printM();
		puts("");
	}
  	puts("Vetor final:");
	X.printM();
	puts("");
	puts("--Lagrange--");
	puts("Resultado da Interpolacao:");
	printf("Equação: %Lf*x ",equacao.first);
	if(equacao.second<0.0) printf("%Lf\n",equacao.second);
	else printf("+%Lf\n",equacao.second);
	puts("   x          y");
	for(int i=0;i<Inter.N;i++)
		printf("%Lf : %Lf\n",Inter.Mat[i][0],Inter.Mat[i][1]);
	puts("");
}

void output(){
	puts(" Pontos      Poluição");
	for(int i=0;i<(int)Analise.size();i++)
		printf("%Lf -> %Lf\n",Analise[i].first,Analise[i].second);
	puts("");
	puts("Resultado da Interpolacao:");
	printf("Equação: %Lf*x ",equacao.first);
	if(equacao.second<0.0) printf("%Lf\n",equacao.second);
	else printf("+%Lf\n",equacao.second);
	puts("");
	long double point = (Analise[0].first+Analise[(int)Analise.size()-1].first)/2.0;
	printf("Ponto da cidade: %Lf\nGrau de poluicao: %Lf\n",point,equacao.first*point+equacao.second);
}
/*Decomposição LU*/

void Gerar_P(){ //Faz o pivotamento
	vector<pair<long double,int>> escalonador;
	Matrix aux = A1;
	for(int i=0;i<N;i++)
		escalonador.push_back({A1.Mat[i][0],i});
	sort(escalonador.begin(),escalonador.end(),cmp);
	for(int i=0;i<N;i++){
		A1.Mat[i] = aux.Mat[escalonador[i].second];
		P.Mat[i][escalonador[i].second] = 1;
	}
}

void Decomposicao_LU(){
	U = A1;
	for(int i=0;i < U.N;i++){
		vector<long double> parc(U.N,0.0);
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
	b1= P*b1;
	for(int i = 0;i < L.N ;i++){
		double sum = 0.0;
		for(int j=0 ;j < i;j++)
			sum += y.Mat[j][0]*L.Mat[i][j];
		y.Mat[i][0] = (b1.Mat[i][0] - sum);
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

/*Gauss-Seidel*/
void Gerar_RLD(){//Gera as matrizes apartir da Matriz A2, para os calculos
	L1 = A2.L();
	R = A2.R();
	D = A2.D();
	L1.negativa();
	R.negativa();
}
void CriterioLinhas(){
    for(int i=0;i<A2.N;i++){
        double sum =0.0;
        for(int j=0;j<A2.M;j++)
            if(j!=i)
                sum+=fabs(A2.Mat[i][j]);
        sum/=fabs(A2.Mat[i][i]);
        if(sum>=1.0){
            puts("Nao respeita o Criterio de Convergencia das Linhas");
            exit(1);
        }
    }
}
void CriteriodeSassenfeld(){
    Matrix v(A2.N,1);
    for(int i=0;i<A2.N;i++){
        double sum =0.0;
        for(int j=0;j<i;j++)
            sum+=fabs(A2.Mat[i][j])*v.Mat[j][0];
        for(int j=i+1;j<A2.M;j++)
            sum+=fabs(A2.Mat[i][j]);
        sum/=fabs(A2.Mat[i][i]);
        v.Mat[i][0]=sum;
        if(sum>=1.0){
            puts("Nao respeita o Criterio de Convergencia de Sassenfeld");
            exit(1);
        }
    }
}

void GaussSeidel(){
	for(int i=0;i< b2.N;i++)
		for(int j=0;j< b2.M;j++)
			X.Mat[i][j] = b2.Mat[i][j]/A2.Mat[i][i];//vetor X inicial
	while(itera--){
		It.push_back(X);
		Matrix result(X.N,X.M);
		for(int i=0;i<X.N;i++){
			long double sum=0;
			for(int j=0;j<i;j++)
				sum+= L1.Mat[i][j]*result.Mat[j][0];
			for(int j=i+1;j<X.N;j++)
				sum+= R.Mat[i][j]*X.Mat[j][0];
			result.Mat[i][0] = (b2.Mat[i][0]+sum)/D.Mat[i][i];
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
	for(int i=0;i<x.N;i++)
		Analise.push_back({x.Mat[i][0],X.Mat[i][0]});
	sort(Analise.begin(),Analise.end(),cmp2);
	Matrix result(X.N,2);
	result.Mat[0][0] = Analise[0].first, result.Mat[0][1] = Analise[0].second;
	result.Mat[1][0] = Analise[x.N-1].first, result.Mat[1][1] = Analise[x.N-1].second;
	equacao.first = (Analise[0].second/(Analise[0].first- Analise[x.N-1].first)) + (Analise[x.N-1].second/(Analise[x.N-1].first - Analise[0].first));
	equacao.second = ((-Analise[0].second*Analise[x.N-1].first)/(Analise[0].first - Analise[x.N-1].first))+((-Analise[x.N-1].second*Analise[0].first)/(Analise[x.N-1].first - Analise[0].first));
	int cont=2;
	for(int i=1;i<(X.N-1);i++){ //Calculo dos demais valores aproximados pela reta feita.
		long double p=Analise[0].second*(Analise[i].first-Analise[x.N-1].first)/(Analise[0].first - Analise[x.N-1].first);
		p+=Analise[x.N-1].second*(Analise[i].first-Analise[0].first)/(Analise[x.N-1].first - Analise[0].first);
		result.Mat[cont][0] = Analise[i].first, result.Mat[cont][1] = p;
		cont++;
  	}
	Inter = result;
}
int main(){
	inputs();
	/*Decomposição LU*/
	Gerar_P();
	Decomposicao_LU();
	Ly_Pb();
	Ux_y();
	/*Metodo de Guass-Seidel*/
	CriteriodeSassenfeld();
	CriterioLinhas();
	Gerar_RLD();
	GaussSeidel();
	/*Lagrange*/
	Lagrange();
	/*Outputs*/
	output();
}
/* 
Exemplo input:
3 3 0.01 10
1 2 3
1 4 7
-2 2 5
1 -1 -7
10 2 2
1 10 2
2 -7 -10
28 7 -17

5 5 0.0001 10
21 3 -4 2 -3
5 3 0 3 2
0 2 13 5 1
2 36 1 -5 3
1 2 -5 5 5
320 -38 142 542 -423
4 0 2 0 -1
2 9 0 0 -1
0 2 7 -1 0
0 2 0 5 -2
0 3 1 0 9
95 163 543 -21 657

*/
