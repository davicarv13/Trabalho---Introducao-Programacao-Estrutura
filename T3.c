#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6

void lp();
void imprimeCampo1(int campo1[][TAM]);
void imprimeCampo2(int campo2[][TAM]);
void geraCampos(int campo1[][TAM], int campo2[][TAM]);
void jogador1(int campo2[][TAM]);
void jogador2(int campo1[][TAM]);
int verificaCampos(int campo1[][TAM], int campo2[][TAM], int jogador);

int main(){
	lp();
	int campo1[TAM][TAM], campo2[TAM][TAM], vencedor=0;
	srand((unsigned)time(NULL));
	geraCampos(campo1, campo2); 
	while(vencedor==0){
		jogador1(campo2);
		if(verificaCampos(campo1, campo2, 1)==1){
			vencedor=1;
			break;
		}
		jogador2(campo1);
		if(verificaCampos(campo1, campo2, 2)==2){
			vencedor=2;
			break;
		}
	}

	lp();

	imprimeCampo1(campo1);
	imprimeCampo2(campo2);

	if(vencedor==1){
		printf("Jogador 1 Venceu!");
	}
	else{
		printf("Jogador 2 Venceu!");
	}
	printf("\n\n");
}
void geraCampos(int campo1[][TAM], int campo2[][TAM]){

	int i, j;

	for(i=0; i<TAM; i++){

		for(j=0; j<TAM; j++){

			campo1[i][j]='~';
			campo2[i][j]='~';
		}
	}

	for(i=0; i<4; i++){
		campo1[rand()%TAM][rand()%TAM]='o';
		campo2[rand()%TAM][rand()%TAM]='o';
	}
}

void jogador1(int campo2[][TAM]){
	int i, j;
	imprimeCampo2(campo2);
	printf("Jogador 1:\n");
	printf("Informe a linha:");
	scanf("%d", &i);
	while(i>5 || i<0){
		printf("Valor invalido!\n");
		printf("Informe a linha (Valor inteiro menor 6 e maior ou igual a 0):");
		scanf("%d", &i);
	}
	printf("Informe a coluna:");
	scanf("%d", &j);
	while(j>5 || j<0){
		printf("Valor invalido!\n");
		printf("Informe a coluna (Valor inteiro menor 6 e maior ou igual a 0):");
		scanf("%d", &j);
	}

	if(campo2[i][j]=='o'){
		lp();
		printf("Parabens! Voce afundou um navio\n\n");
		campo2[i][j]='O';
	}
	else if(campo2[i][j]=='O' || campo2[i][j]=='X'){
		printf("Desculpe, essa posicao ja foi jogada!\n\n");
		printf("Escolha outra:\n");
		lp();
		jogador1(campo2);
	}
	else{
		lp();
		printf("\nTiro na agua!\n\n");
		campo2[i][j]='X';
	}
}

void jogador2(int campo1[][TAM]){
	int i, j;
	imprimeCampo1(campo1);
	printf("Jogador 2:\n");
	printf("Informe a linha:");
	scanf("%d", &i);
	while(i>5 || i<0){
		printf("Valor invalido!\n");
		printf("Informe a linha (Valor inteiro menor 6 e maior ou igual a 0):");
		scanf("%d", &i);
	}
	printf("Informe a coluna:");
	scanf("%d", &j);
	while(j>5 || j<0){
		printf("Valor invalido!\n");
		printf("Informe a coluna (Valor inteiro menor 6 e maior ou igual a 0):");
		scanf("%d", &j);
	}

	if(campo1[i][j]=='o'){
		lp();
		printf("Parabens! Voce afundou um navio\n\n");
		campo1[i][j]='O';
	}
	else if(campo1[i][j]=='O' || campo1[i][j]=='X'){
		printf("Desculpe, essa posicao ja foi jogada!\n\n");
		printf("Escolha outra:\n");
		lp();
		jogador2(campo1);
	}
	else{
		lp();
		printf("\nTiro na agua!\n\n");
		campo1[i][j]='X';
	}
}
int verificaCampos(int campo1[][TAM], int campo2[][TAM], int jogador){
	int i, j, jog1=0, jog2=0;

	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			if(jogador==1){
				if(campo2[i][j]=='O'){
					jog1++;
				}
			}
			else{
				if(campo1[i][j]=='O'){
					jog2++;
				}
			}
		}
	}
	if(jog1==4){
		return 1;
	}
	else if(jog2==4){
		return 2;
	}
	else{
		return 0;
	}
}

void imprimeCampo1(int campo1[][TAM]){
	int i, j, k;
	printf("%8s", "Campo 1:\n");
	for(i=0; i<TAM; i++){
		if(i==0){
			for(k=0; k<(TAM+2); k++){
				printf("_");
			}
			printf("\n");	
		}
		printf("|");
		for(j=0; j<TAM; j++){
			if(campo1[i][j]=='o'){
				printf("~");
			}
			else{
				printf("%c", campo1[i][j]);
			}
		}
		printf("|");
		printf("\n");
		if(i==(TAM-1)){
			for(k=0; k<(TAM+2); k++){
				printf("_");
			}	
		}
	}
	printf("\n\n");
}

void imprimeCampo2(int campo2[][TAM]){
	int i, j, k;
	printf("%8s", "Campo 2:\n");
	for(i=0; i<TAM; i++){
		if(i==0){
			for(k=0; k<(TAM+2); k++){
				printf("_");
			}	
			printf("\n");
		}
		printf("|");
		for(j=0; j<TAM; j++){
			if(campo2[i][j]=='o'){
				printf("~");
			}
			else{
				printf("%c", campo2[i][j]);
			}
		}
		printf("|");
		printf("\n");
		if(i==(TAM-1)){
			for(k=0; k<(TAM+2); k++){
				printf("_");
			}	
		}
	}
	printf("\n\n");
}
void lp(){
	system("clear || cls");
}
