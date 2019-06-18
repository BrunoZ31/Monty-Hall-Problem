#include "stdio.h"
#include "stdlib.h"
#include "random.h"
#include "genlib.h"
#include "time.h"

int RandomInteger(int low, int high)
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}

int main()
{   
	//SETAR UM NUMERO (PORTA) QUE É O NUMERO VENCEDOR
	//FAZER O TIPO QUE TROCA O NUMERO (A PORTA) E O QUE NÃO TROCA
	//COMPARAR OS RESULTADOS  
	//
	long long int n=100000;
	long long int ESCOLHA[n];
	long double somaTROCA=0,somaNAOTROCA=0;

//TROCA DE PORTA
	for (int i = 0; i < n; ++i)
	{
//		printf("%d ",i); 

		ESCOLHA[i]=RandomInteger(1,3);
		
//		printf("ESCOLHA: %ld ",ESCOLHA[i]);

		if(ESCOLHA[i]==1)
		{
		}
		if(ESCOLHA[i]==2)
		{

					somaTROCA++;
					//printf(" +");
		}

			/*SE ESCOLHER 1 O JOGADOR GANHOU*/
		
		if(ESCOLHA[i]==3)
		{
		
			somaTROCA++;
	//		printf(" +");
		}
//		printf("\n");
	}

		printf("\n\n");
//NÃO TROCA DE PORTA
    
	for (int i = 0; i < n; ++i)
	{


		ESCOLHA[i]=RandomInteger(1,3);
		
		//printf("\nESCOLHA: %lld ",ESCOLHA[i]);

		if(ESCOLHA[i]==1)
		{
			somaNAOTROCA++;
		
		}
		if(ESCOLHA[i]==2)
		{
		}
		if(ESCOLHA[i]==3)
		{
		}

	}
	printf("\n\n");
	printf("Numero de vezes ganhado quando TROCA de porta: %Lf \n", somaTROCA);
	printf("Numero de vezes ganhado quando NAO TROCA de porta: %Lf \n",somaNAOTROCA);
	printf("\n");

	double fracao= 0;
	fracao= (double)somaTROCA/(double)somaNAOTROCA;
	printf("fração entre eles: %lf\n", fracao);

    return 0;
}
