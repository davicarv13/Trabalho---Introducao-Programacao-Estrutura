#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void limparTela();
void jogadorUm(int quadro[][3]);
void jogadorDois(int quadro[][3]);
void imprimeQuadro(int quadro[][3]);
int verificaValidade(char resp);
int verificaPosicao(int jogador, char resp, int quadro[][3]);
int verificaQuadro(int quadro[][3]);
void imprimeArquivo(FILE *arqVelha, int jogada, int quadro[][3]);

int main(){
	limparTela();
	FILE *arqVelha=fopen("Velha.txt", "w");
	int quadro[3][3]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'}, result=0, i, j, jogada=0;
	imprimeArquivo(arqVelha, jogada, quadro);
	while(jogada<9){
		jogadorUm(quadro);
		jogada++;
		imprimeArquivo(arqVelha, jogada, quadro);
		result=verificaQuadro(quadro);
		if(result==1){
			break;
		}
		if(jogada==9){
			break;
		}
		jogadorDois(quadro);
		jogada++;
		result=verificaQuadro(quadro);
		imprimeArquivo(arqVelha, jogada, quadro);
		if(result==2){
			break;
		}
	}
	imprimeQuadro(quadro);
	if(result==1){
		printf("\nJogador 1 (O) Venceu!");
	}
	else if(result==2){
		printf("\nJogador 2 (X) Venceu!");
	}
	else{
		printf("\nEmpate!");
	}
	printf("\n\n");
	fclose(arqVelha);
}
void imprimeQuadro(int quadro[][3]){
	int i, j;
	printf("Quadro:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(j!=0){
				printf(" | ");
			}
			printf("%c ", quadro[i][j]);
		}
		printf("\n");
		if(i!=2){
			for(j=0; j<12; j++){
				printf("-");
			}
			printf("\n");	
		}
		
	}
}
void jogadorUm(int quadro[][3]){
	char resp;
	imprimeQuadro(quadro);
	printf("\nJogador 1 (O):\n");
	printf("\nInforme uma posicao:");
	scanf("%c", &resp);
	getchar();
	resp=toupper(resp);
	while(verificaValidade(resp)==1){
		printf("Resposta invalida!");
		printf("\nInforme uma posicao:");
		scanf("%c", &resp);
		getchar();
		resp=toupper(resp);
	}
	while(verificaPosicao(1, resp, quadro)==1){
		printf("Posicao se encontra preenchida!\n");
		printf("\nInforme uma posicao:");
		scanf("%c", &resp);
		getchar();
		resp=toupper(resp);
	}
	limparTela();
} 
void jogadorDois(int quadro[][3]){
	char resp;
	imprimeQuadro(quadro);
	printf("\nJogador 2 (X):\n");
	printf("\nInforme uma posicao:");
	scanf("%c", &resp);
	getchar();
	resp=toupper(resp);
	while(verificaValidade(resp)==1){
		printf("Resposta invalida!");
		printf("\nInforme uma posicao:");
		scanf("%c", &resp);
		getchar();
		resp=toupper(resp);
	}
	while(verificaPosicao(2, resp, quadro)==1){
		printf("Posicao se encontra preenchida!\n");
		printf("\nInforme uma posicao:");
		scanf("%c", &resp);
		getchar();
		resp=toupper(resp);
	}
	limparTela();
}
int verificaQuadro(int quadro[][3]){
	int i, j, cont=0, teste1=0, teste2=0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(quadro[i][j]=='O'){
				teste1++;
			}
			if(quadro[i][j]=='X'){
				teste2++;
			}
		}
		if(teste1==3){
			return 1;
		}
		if(teste2==3){
			return 2;
		}
		teste1=0;
		teste2=0;
	}
	for(j=0; j<3; j++){
		for(i=0; i<3; i++){
			if(quadro[i][j]=='O'){
				teste1++;
			}
			if(quadro[i][j]=='X'){
				teste2++;
			}
		}
		if(teste1==3){
			return 1;
		}
		if(teste2==3){
			return 2;
		}
		teste1=0;
		teste2=0;
	}
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(i==j){
				if(quadro[i][j]=='O'){
					teste1++;
				}
				if(quadro[i][j]=='X'){
					teste2++;
				}
			}
		}
		if(teste1==3){
			return 1;
		}
		if(teste2==3){
			return 2;
		}
	}
	teste1=0; 
	teste2=0;
	j=2;
	for(i=0; i<3; i++){
		if(quadro[i][j]=='O'){
				teste1++;
		}
		if(quadro[i][j]=='X'){
				teste2++;
		}
		j--;
		if(teste1==3){
			return 1;
		}
		if(teste2==3){
			return 2;
		}
	}
	return 0;
}
int verificaPosicao(int jogador, char resp, int quadro[][3]){
	if(resp=='A'){
		if(quadro[0][0]=='A'){
			if(jogador==1){
				quadro[0][0]='O';		
			}
			else{
				quadro[0][0]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	if(resp=='B'){
		if(quadro[0][1]=='B'){
			if(jogador==1){
				quadro[0][1]='O';		
			}
			else{
				quadro[0][1]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='C'){
		if(quadro[0][2]=='C'){
			if(jogador==1){
				quadro[0][2]='O';		
			}
			else{
				quadro[0][2]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='D'){
		if(quadro[1][0]=='D'){
			if(jogador==1){
				quadro[1][0]='O';		
			}
			else{
				quadro[1][0]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='E'){
		if(quadro[1][1]=='E'){
			if(jogador==1){
				quadro[1][1]='O';		
			}
			else{
				quadro[1][1]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='F'){
		if(quadro[1][2]=='F'){
			if(jogador==1){
				quadro[1][2]='O';		
			}
			else{
				quadro[1][2]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='G'){
		if(quadro[2][0]=='G'){
			if(jogador==1){
				quadro[2][0]='O';		
			}
			else{
				quadro[2][0]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='H'){
		if(quadro[2][1]=='H'){
			if(jogador==1){
				quadro[2][1]='O';		
			}
			else{
				quadro[2][1]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(resp=='I'){
		if(quadro[2][2]=='I'){
			if(jogador==1){
				quadro[2][2]='O';		
			}
			else{
				quadro[2][2]='X';
			}
			return 0;
		}
		else{
			return 1;
		}
	}
}
void imprimeArquivo(FILE *arqVelha, int jogada, int quadro[][3]){
	int i, j;
	if(jogada==0){
		fprintf(arqVelha, "Estado Inicial\n");
	}
	else{
		fprintf(arqVelha, "Jogada %d\n", jogada);
	}
	fprintf(arqVelha, "Quadro:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(j!=0){
				fprintf(arqVelha, " | ");
			}
			fprintf(arqVelha, "%c ", quadro[i][j]);
		}
		fprintf(arqVelha, "\n");
		if(i!=2){
			for(j=0; j<12; j++){
				fprintf(arqVelha, "-");
			}
			fprintf(arqVelha, "\n");	
		}
		
	}
	fprintf(arqVelha, "\n\n");
}
int verificaValidade(char resp){
	toupper(resp);
	if(resp!='A' && resp!='B' && resp!='C' && resp!='D' && resp!='E' && resp!='F' && resp!='G' && resp!='H' && resp!='I'){
		return  1;
	}
	return 0; 
}

void limparTela(){
	system("clear || cls");
}
