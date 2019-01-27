//Davi.T2.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 10
#define ALFABETO 28

//Declaração dos protótipos de função
void limpaTela();
void imprimeBoneco(int boneco, FILE *arqForca);
void preenchePalavra(char *palavra);
void imprimeSequencia(char *sequencia);
int pegaPalavra(char *palavra, FILE *arqForca);
int pegaLetra(char *palavra, char *sequencia, int tamPalavra, char *alfabeto, int *posAlfabeto, FILE *arqForca);
void preencheSequencia(char *sequencia, int tamPalavra);
int verificaSequencia(char *sequencia, int tamPalavra);
void preencheAlfabeto(char *alfabeto);

//Função principal
int main(){
	limpaTela();
	char palavra[TAM], alfabeto[ALFABETO];
	int tamPalavra=0, i=1, boneco=0, teste=0, result=0, posAlfabeto=0;
	FILE *arqForca=fopen("Forca.txt", "w");

	preenchePalavra(palavra);
	tamPalavra=strlen(palavra);
	char sequencia[tamPalavra+1];		//sequencia foi preenchida com tamPalavra+1 para que haja espaço para o caracter finalizador '\0'
	preencheSequencia(sequencia, tamPalavra);

	preencheAlfabeto(alfabeto);
	fprintf(arqForca, "Primeiro Jogador: \n");
	fprintf(arqForca, "Palavra oculta: %s\n\n", palavra);
	limpaTela();

	while(teste==0){

		fprintf(arqForca, "Tentativa numero %d:\n", i++);
		imprimeSequencia(sequencia);
		result=pegaPalavra(palavra, arqForca);

		if(result==1){

			teste=1;
			break;
		}

		else if(result==2){

			boneco++;
		}
		imprimeBoneco(boneco, arqForca);
		result=pegaLetra(palavra, sequencia, tamPalavra, alfabeto, &posAlfabeto, arqForca);
		limpaTela();

		if(result==0){

			boneco++;
		}
		else if(result==2){

			printf("Letra ja informada!\n\n");
		}

		if(boneco==6){

			teste=2;
			break;
		}

		if(verificaSequencia(sequencia, tamPalavra)==0){

			teste=1;
			break;
		}
		
	}

	limpaTela();
	printf("Palavra oculta: %s\n", palavra); 
	imprimeBoneco(boneco, arqForca);

	if(teste==1){

		printf("Parabens! Voce ganhou!\n");
	}

	else{

		printf("Voce perdeu!\n");
	}
	fclose(arqForca);
}

/*Esta função será responsável por imprimir as etapas do homem palito durante o jogo na tela e
no arquivo. A variavel boneco podera variar de 0 a 5, sendo que, quando for 0, será impresso
na tela que nenhuma parte do boneco esta formada (O jogador 2 nao errou nenhuma vez)*/ 
void imprimeBoneco(int boneco, FILE *arqForca){
	int i;
	printf("\n\n");

	if(boneco==0){
		printf("Boneco:Nenhuma parte formada\n");
		fprintf(arqForca, "Boneco:Nenhuma parte formada\n");		
	}

	else{

		printf("Boneco:\n");
		fprintf(arqForca, "Boneco:\n");

		for(i=0; i<boneco; i++){

			if(i==0){

				printf("\t O \n");
				fprintf(arqForca, "\t O \n");
			}

			if(i==1){

				printf("\t/");
				fprintf(arqForca, "\t/");
			}

			if(i==2){

				printf("|");
				fprintf(arqForca, "|");
			}

			if(i==3){

				printf("\\ \n");
				fprintf(arqForca, "\\ \n");
			}

			if(i==4){

				printf("\t/");
				fprintf(arqForca, "\t/");
			}

			if(i==5){

				printf(" \\ \n");
				fprintf(arqForca, " \\ \n");
			}
		}
	}

	printf("\n\n");
	fprintf(arqForca, "\n\n");
}

/*Esta função imprimirá a sequencia oculta de caracteres formada por '_' (Underline), e será acrescida das letras
correspondentes a palavra a medida que o jogador dois informar letras*/

void imprimeSequencia(char *sequencia){

	printf("%s\n", sequencia);
}

/*Esta função pegará a palavra oculta que deverá ser descoberta durante o jogo. Alem disso, ela convertera
todos os caraceteres da palavra para caixa baixa, para que futuras comparações com letras informadas em caixa
alta ou baixa possam ser realizadas*/ 

void preenchePalavra(char *palavra){

	int i;
	printf("Jogador 1:\n");
	printf("Informe uma palavra de no maximo 10 letras:");
	scanf(" %s", palavra);
	getchar();

	while(strlen(palavra)>TAM){

		printf("Tamanho ultrapassa o limite de 10 caracteres!\n");
		printf("Informe uma palavra de no maximo 10 letras:");
		scanf(" %s", palavra);
		getchar();
	}

	for(i=0; i<strlen(palavra); i++){

		palavra[i]=tolower(palavra[i]);
	}
}

/*Esta função preencherá a sequencia oculta que será mostrada ao usuário com caracteres underline ('_')*/

void preencheSequencia(char *sequencia, int tamPalavra){

	int i;

	for(i=0; i<tamPalavra; i++){

		sequencia[i]='_';
	}

	sequencia[tamPalavra]='\0';
}

/*Esta função pegará letras a cada tentativa. Elas serão convertidas para caixa baixa e imprimirá a letra que foi chutada 
no arquivo Forca.txt. Além disso, ela checará se a letra já foi informada anteriormente através de uma consulta a uma
string 'alfabeto' formada pelas letras que já foram chutadas, usando um contador acessado através de ponteiros*/
 
int pegaLetra(char *palavra, char *sequencia, int tamPalavra, char *alfabeto, int *posAlfabeto, FILE *arqForca){
	char letra;
	int i, teste=0;
	printf("Jogador 2:");
	printf("Informe uma letra:");
	scanf("%c", &letra);
	getchar();
	__wur(stdin);
	letra=tolower(letra);
	fprintf(arqForca, "Letra:%c\n\n", letra);

	for(i=0; i<(*posAlfabeto); i++){

		if(alfabeto[i]==letra){

			return 2;
		}
	}

	if(teste!=1){

		alfabeto[*posAlfabeto]=letra;
		(*posAlfabeto)++;
	}

	if(teste==0){

		for(i=0; i<tamPalavra; i++){

			if(palavra[i]==letra){

				sequencia[i]=palavra[i];
				teste=2;
			}
		}
	}

	if(teste==0){

		return 0;
	}

	else{

		return 1;
	}
}

/*Esta função pegará uma palavra que será chutada pelo usuário a cada tentativa, se ele quiser tentar informar uma palavra
Se a palavra for igual a oculta ela retorn 1 e jogo acaba, se não, retorna 2 para que uma incrementação ocorra no homem palito.
Ela também imprimirá no arquivo Forca.txt a palavra informada, ou se nenhuma palavra foi informada*/

int pegaPalavra(char *palavra, FILE *arqForca){

	char palavraAux[TAM], resp;
	int i;
	printf("Jogador 2:\n");
	printf("Ja sabe qual e a palavra? [S/N]:");
	scanf("%c", &resp);
	getchar();
	resp=tolower(resp);

	while(resp!='s' && resp!='n'){

		printf("Invalido!\n");
		printf("Ja sabe qual e a palavra? [S/N]:");
		scanf("%c", &resp);
		getchar();
		resp=tolower(resp);
	}

	if(resp=='s'){

		printf("Informe uma palavra de no maximo 10 caracteres:");
		scanf(" %s", palavraAux);
		getchar();

		while(strlen(palavraAux)>10){

			printf("Tamanho excede o limite de carateres!\n");
			printf("Informe uma palavra de no maximo 10 caracteres:");
			scanf(" %s\n", palavraAux);			
			getchar();
		}

		fprintf(arqForca, "Palavra:%s\n", palavraAux);

		for(i=0; i<strlen(palavraAux); i++){

			palavraAux[i]=tolower(palavraAux[i]);
			palavra[i]=tolower(palavra[i]);
		}

		if(strcmp(palavraAux, palavra)==0){

			return 1;
		}

		else{

			printf("Incorreto!\n");
			return 2;
		}
	}
	else{

		fprintf(arqForca, "Palavra:%s", "Nenhuma palavra informada nesta jogada\n");
		return 0;	
	}
	
}

/*Esta função preencherá o 'alfabeto' (String de caracteres repetidos) com carateres '-' (Traço), para que nenhum caratere
da função pegaLetra() que não tenha sido informado seja comparado a um eventual lixo que possa ser igual a ele (Seja informado 
um caractere inédito já foi informado)
*/ 

void preencheAlfabeto(char *alfabeto){

	int i;

	for(i=0; i<ALFABETO; i++){

		alfabeto[i]='-';
	}
	alfabeto[ALFABETO]='\0';
}

/*Esta função verifica se a sequencia oculta foi totalmente descoberta (Se nao existem caracteres underline nela mais). Se existirem,
retorn 1 e o jogo continua. Se nao, retorna 0 e jogo termina
*/
int verificaSequencia(char *sequencia, int tamPalavra){
	
	int i, teste=0;

	for(i=0; i<tamPalavra; i++){

		if(sequencia[i]=='_'){
			teste=1;
		}
	}

	if(teste==1){

		return 1;
	}

	else{

		return 0;
	}
}

/*Função para limpar a tela do terminal*/

void limpaTela(){

	system("clear || cls");	
}
