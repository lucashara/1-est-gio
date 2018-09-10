#include <stdio.h>
#include <stdlib.h> //para o system("clear")
#include <math.h> // usar pow

typedef enum{False = 0, True} Boolean;

void QuemSouEu(){
	printf("Aluno: Lucas Hara Lima Santos de Souza\n");
	printf("Matricula: 1810022341\n");
	printf("Matricula Hexa: %X\n", 1810022341);
}
Boolean AnoBissexto(int ano){
	if(!(ano%4))
		return True;
	return False;
}
Boolean Primo(int numero){
	int i;
	for(i=2;i<numero;i++){ 
		if(!(numero%i)){
			return False;
		}
	}
	return True;
}
void Fatorial(int numero){
	int i;
	long unsigned int result;
	for(i = numero-1, result = numero; i>0; i--)
		result*=i;
	printf("%lu\n", result);
}
void Primos(int numero){
	int i;
	for(i=2;i<=numero;i++){
		if (Primo(i)){
			printf("%d Eh primo\n", i);
		}
		else{
			printf("%d Nao eh primo\n", i);
		}
	}
}
void CalculaMedia(float nota1, float nota2){
	float result;
	if(((nota1>=0)&&(nota1<=10)) && ((nota2>=0)&&(nota2<=10))){
		result = (nota1+nota2)/2;
		printf("%f\n", result);
	}
	else{
		printf("Valor Invalido\n");
	}
}
void CalculaMediaPonderada(float nota1, float nota2, float nota3){
	float result;
	if(((nota1>=0)&&(nota1<=10)) && ((nota2>=0)&&(nota2<=10)) && ((nota3>=0)&&(nota3<=10))){
		result = (nota1+nota2+(nota3*2))/4;
		printf("%f\n", result);
		if(result >= 60){
			printf("Aprovado\n");
		}
		else{
			printf("Reprovado\n");
		}
	}
	else{
		printf("Valor Invalido\n");
	}
}
void FloatRaizInt(float fNumero, int iNumero){
	printf("Resposta = %e", pow(fNumero,1/iNumero));
}
void FloatElevadoInt(float fNumero, int iNumero){
	printf("Resposta = %e", pow(fNumero,iNumero));
}
void PerguntaTresNumerosF(float *numero1, float *numero2, float *numero3){
	printf("Digite primeira nota\n");
	scanf(" %f", numero1);
	printf("Digite segunda nota\n");
	scanf(" %f", numero2);
	printf("Digite terceira nota\n");
	scanf(" %f", numero2);
}
void PerguntaDoisNumerosF(float *numero1, float *numero2){
	printf("Digite primeira nota\n");
	scanf(" %f", numero1);
	printf("Digite segunda nota\n");
	scanf(" %f", numero2);
}
void PerguntaUmNumeroF(float *numero){
	printf("Digite um numero Float\n");
	scanf(" %f", numero);
}
void PerguntaUmNumero(int *numero){
	printf("Digite um numero Inteiro\n");
	scanf(" %d", numero);
}
int main(int argc, char const *argv[])
{
	int op, iNumero1;
	float fNumero, fNumero2, fNumero3;
	do
		{
			printf("Fatorial 1 \t Primo 2 \n");
			printf("Primos 3 \t Elevado 4 \n");
			printf("Raiz 5    \t Biseexto 6 \n");
			printf("Media 7 \t Ponderada 8 \n");
			printf("Criador 9 \t Sair 0 \n");
			scanf(" %d", &op);
			if (op){
				switch (op){
					case 1:
						PerguntaUmNumero(&iNumero1);
						Fatorial(iNumero1);
						break;
					case 2:
						PerguntaUmNumero(&iNumero1);
						if (Primo(iNumero1)){
							printf("%d Eh primo\n", iNumero1);
						}
						else{
							printf("%d Nao eh primo\n", iNumero1);
						}
						break;
					case 3:
						PerguntaUmNumero(&iNumero1);
						Primos(iNumero1);
						break;
					case 4:
						PerguntaUmNumero(&iNumero1);
						PerguntaUmNumeroF(&fNumero);
						FloatElevadoInt(fNumero,iNumero1);
						break;
					case 5:
						PerguntaUmNumero(&iNumero1);
						PerguntaUmNumeroF(&fNumero);
						FloatRaizInt(fNumero,iNumero1);
						break;
					case 6: 
						PerguntaUmNumero(&iNumero1);
						if(AnoBissexto(iNumero1)){
							printf("Eh bissexto\n");
						}
						else{
							printf("Nao eh bissexto\n");
						}
						break;
					case 7:
						PerguntaDoisNumerosF(&fNumero, &fNumero2);
						CalculaMedia(fNumero ,fNumero2);
						break;
					case 8:
						PerguntaTresNumerosF(&fNumero,&fNumero2,&fNumero3);
						CalculaMediaPonderada(fNumero,fNumero2,fNumero3);
						break;
					case 9:
						QuemSouEu();
						break;
					default:
						printf("Opcao Invalida\n");
				}
			}
			else{
				printf("Digitou 0 - Tchau\n");
			}

		  getchar();
		  getchar(); //em windows nao funciona	
		  system("clear"); //em windows nao funciona	
		} while (op);	
	return 0;
}