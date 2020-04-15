#include<stdlib.h>
#include<stdio.h>

int main (){
	
	int Matriz[3][5];// Na regra de Sarrus, você precissa duplicar as duas primeiras colunas, sendo num total de 5 colunas;
	int ContColuna = 0;//Conta em qual coluna esta.
	int ContLinha = 0;//Conta em qual linha esta.
	int A = 1, B = 1, C = 1;// Estas variaveis irao armazenar as mutiplicações positivas da regra de Sarrus.
	int A1 = 1, B1 = 1, C1 = 1;// Estas variaveis irao armazenar as mutiplicações negativas da regra de Sarrus.
	int LinhaInversa = 2;//Ajudara na contagem das mutiplicações negativas.
	int Resolucao = 0;//Resultado final.

	// Este for e utilizado na leitura, sendo ela linha por linha.	
	for(ContLinha = 0; ContLinha <= 2; ContLinha++){
		for(ContColuna = 0; ContColuna <= 2; ContColuna++){
			scanf("%i",&Matriz[ContLinha][ContColuna]);
			
			if(ContColuna == 0){
				Matriz[ContLinha][3] = Matriz[ContLinha][ContColuna];// O indice 3 se refere a coluna 4.
			}
			else if(ContColuna == 1){
				Matriz[ContLinha][4] = Matriz[ContLinha][ContColuna];//O indice 4 se refere a coluna 5.
			}
		}
	}
	//Este for e utilizado na mutiplicações da regra de Sarrus.
	for(ContColuna = 0; ContColuna <= 2; ContColuna++){
		//Variaveis positivas
		A *= Matriz[ContColuna][ContColuna];
		B *= Matriz[ContColuna][(ContColuna + 1)];
		C *= Matriz[ContColuna][(ContColuna + 2)];
		
		//Variaveis negativas	
		A1 *= Matriz[LinhaInversa][(ContColuna)];
		B1 *= Matriz[LinhaInversa][(ContColuna + 1)];
		C1 *= Matriz[LinhaInversa][(ContColuna + 2)];

		LinhaInversa--;
	}
	
	Resolucao = (A + B + C) + ((-1)*(A1 + B1 + C1));
	printf("%i", Resolucao);

	return 0;
}
