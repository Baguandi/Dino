#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //Sleep()
#include <conio.h> //kbhit()
#include <time.h> //srand(time(null))
#define L 3
#define C 50
#define dorme 1000

//essa fun��o serve para posicionar o cursor antes da escrita
//ela serve para dar a impress�o de movimento
void movexy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void puladino(){
              // FUN��O PARA FAZER O DINOSSAURO PULAR

    /*movexy(4,8);
    printf(" ");
    movexy(4,6);
    printf("0");
    //move_obstaculo();
    //imprime ();


    Sleep(1000);

    movexy(4,7);
    printf(" ");
    movexy(4,5);
    printf("0");
    Sleep(dorme);

    movexy(4,4);
    printf(" ");
    movexy(4,6);
    printf("0");
    Sleep(dorme);

    movexy(4,4);
    printf(" ");
    movexy(4,6);
    printf("0");
    Sleep(dorme);

    movexy(4,5);
    printf(" ");
    movexy(4,7);
    printf("0");
    Sleep(dorme);

    movexy(4,6);
    printf(" ");
    movexy(4,8);
    printf("0");
    Sleep(dorme);*/


}

void deitadino(char e0[C], char e1[C], char e2[C]){// FUN��O PARA FAZER O DINOSSAURO DEITAR

    movexy(4,7);
    printf(" ");
    movexy(6,8);
    printf("0");
    Sleep(dorme);

    movexy(4,7);
    printf(" ");
    movexy(6,8);
    printf("0");
    Sleep(dorme);

    /*movexy(4,7);
    printf(" ");
    movexy(6,8);
    printf("0");
    Sleep(dorme);

    movexy(4,7);
    printf(" ");
    movexy(6,8);
    printf("0");
    Sleep(dorme);*/

    movexy(6,8);
    printf(" ");
    movexy(4,7);
    printf("0");
}

void inicia (char e0[C], char e1[C], char e2[C]){
    for (int j=0;j<C;j++){
        e0[j]=' ';
        e1[j]=' ';
        e2[j]=' ';
    }
}

//escreve os elementos mais a direita uma posi��o mais a esquerda
//de forma cont�nua, assim os obst�culos ter�o se movido uma posi��o
//na dire��o do dinossauro
void move_obstaculo (char e0[C], char e1[C], char e2[C]){

    for (int j=1;j<C;j++){

       e0[j-1]=e0[j];
       e1[j-1]=e1[j];
       e2[j-1]=e2[j];
    }
}

//essa fun��o serve para criar novos obst�culos
//voc�s precisam definir as condi��es para aparecer
//novos obst�culos, por exemplo, a frequencia e em condi��es
//em que seja poss�vel desviar-se
void novo_obstaculo (char e0[C], char e1[C], char e2[C]){
	//O trecho, a seguir, n�o est� criando novos obst�culos, apenas gerando espa�os vazios
    static int x=0;
    int r;
    x++;
    if(x%4==0){
        srand(time(NULL));
        r=rand()%5;
    }
    else {
        r=0;
    }

    switch(r)
    {
        case 0:
            e0[49]=' ';
            e1[49]=' ';
            e2[49]=' ';
        break;

        case 1:
            e0[49]=' ';
            e1[49]=' ';
            e2[49]='@';
        break;

        case 2:
            e0[49]=' ';
            e1[49]='@';
            e2[49]='@';
        break;

        case 3:
            e0[49]='@';
            e1[49]='@';
            e2[49]=' ';
        break;

        case 4:
            e0[49]=' ';
            e1[49]='@';
            e2[49]=' ';
        break;
    }

}

//aqui voc�s precisam colocar o dinossauro na �ltima posi��o e permitir que ela se mova
// usar a fun��o kbhit (para detectar que uma tecla foi pressionada) e getch (para saber que tecla foi essa)
//n�o d� de usar a printf, pois ele necessita que o enter seja digitado para reconhecer o comando
//ao pressionar uma tecla v�lida o movimento deve ser executado.
//lembre-se que s� � poss�vel pular ou se abaixar quando o dinossauro estiver em contato com o ch�o.
void move_dinossauro(char e0[C], char e1[C], char e2[C]){
    char tecla;
    if(kbhit()){
        getch();
        tecla=getch();
    }
    if(tecla=='H')
        puladino();
    if(tecla=='P')
        deitadino();
}

//Essa fun��o imprime cada linha do cen�rio cada vez que for chamada
void imprime (char e0[C], char e1[C], char e2[C]){
    for (int i=0;i<L;i++){
        for (int j=0;j<C;j++){
            if (i==0){
                printf("%c",e0[j]);
            }
            else if (i==1){
                printf("%c",e1[j]);
            }
            else {
                printf("%c",e2[j]);
            }
        }
        printf("\n");
    }
    movexy(4,7);
    printf("0");
    movexy(4,8);
    printf("0");
    movexy(0,9);
}




int main()
{
    char cenario0[C],
         cenario1[C],
         cenario2[C];

    inicia(cenario0, cenario1, cenario2);

    movexy(0,9);
    printf("==================================================");

    while(1){
        //serve para resposicionar a escrita para posi��o inicial
        //assim quando imprimir o cen�rio ele vai imprimir por cima do antigo
        movexy(0,6);

        //imprime o cen�rio do jogo
        imprime (cenario0, cenario1, cenario2);

        //espera por mil milissegundos
        Sleep(1000);

        //escreve todas as posi��es do cen�rio uma posi��o para esquerda
        //isso da a impress�o de movimento
        move_obstaculo(cenario0, cenario1, cenario2);

        //coloca novos obst�culos ou obst�culo nenhum na posi��o inicial
        //ou seja nas posi��es mais a direita do cen�rio
        novo_obstaculo(cenario0, cenario1, cenario2);

        //serve para interpretar os movimentos do dinossauro
        move_dinossauro(cenario0, cenario1, cenario2);

        //Al�m das fun��es j� criadas � necess�rio criar fun��es para verificar
        //se o dinossauro esbarrou e para exibir o placar na tela

    }
    return 0;
}
