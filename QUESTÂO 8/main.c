#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //Sleep()
#include <conio.h> //kbhit()
#include <time.h> //srand(time(null))
#define L 3
#define C 50
#define dorme 1000

//essa função serve para posicionar o cursor antes da escrita
//ela serve para dar a impressão de movimento
void movexy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void puladino(){
              // FUNÇÃO PARA FAZER O DINOSSAURO PULAR

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

void deitadino(char e0[C], char e1[C], char e2[C]){// FUNÇÃO PARA FAZER O DINOSSAURO DEITAR

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

//escreve os elementos mais a direita uma posição mais a esquerda
//de forma contínua, assim os obstáculos terão se movido uma posição
//na direção do dinossauro
void move_obstaculo (char e0[C], char e1[C], char e2[C]){

    for (int j=1;j<C;j++){

       e0[j-1]=e0[j];
       e1[j-1]=e1[j];
       e2[j-1]=e2[j];
    }
}

//essa função serve para criar novos obstáculos
//vocês precisam definir as condições para aparecer
//novos obstáculos, por exemplo, a frequencia e em condições
//em que seja possível desviar-se
void novo_obstaculo (char e0[C], char e1[C], char e2[C]){
	//O trecho, a seguir, não está criando novos obstáculos, apenas gerando espaços vazios
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

//aqui vocês precisam colocar o dinossauro na última posição e permitir que ela se mova
// usar a função kbhit (para detectar que uma tecla foi pressionada) e getch (para saber que tecla foi essa)
//não dá de usar a printf, pois ele necessita que o enter seja digitado para reconhecer o comando
//ao pressionar uma tecla válida o movimento deve ser executado.
//lembre-se que só é possível pular ou se abaixar quando o dinossauro estiver em contato com o chão.
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

//Essa função imprime cada linha do cenário cada vez que for chamada
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
        //serve para resposicionar a escrita para posição inicial
        //assim quando imprimir o cenário ele vai imprimir por cima do antigo
        movexy(0,6);

        //imprime o cenário do jogo
        imprime (cenario0, cenario1, cenario2);

        //espera por mil milissegundos
        Sleep(1000);

        //escreve todas as posições do cenário uma posição para esquerda
        //isso da a impressão de movimento
        move_obstaculo(cenario0, cenario1, cenario2);

        //coloca novos obstáculos ou obstáculo nenhum na posição inicial
        //ou seja nas posições mais a direita do cenário
        novo_obstaculo(cenario0, cenario1, cenario2);

        //serve para interpretar os movimentos do dinossauro
        move_dinossauro(cenario0, cenario1, cenario2);

        //Além das funções já criadas é necessário criar funções para verificar
        //se o dinossauro esbarrou e para exibir o placar na tela

    }
    return 0;
}
