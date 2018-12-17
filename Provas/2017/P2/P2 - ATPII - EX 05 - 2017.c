#include <stdlib.h>
#include <stdio.h>
#define MAX 50
void main(){
    char string[MAX] = "Se voce esta lendo perdeu o jogo";

    //Inicia pri e ult com -1 para garantir exatidão na posição
    //Se for 0 e não houver match, vai informar que a posição 0 é a primeira
    //E última a dar match
    int pri=-1, ult=-1, count=0;

    //Chama a função de contagem
    countChar(string, 'x', &pri, &ult, &count);
    
    printf("Na string \" %s \":\nA primera ocorrencia e na posicao: %d\nA ultima ocorrencia na posicao: %d\nTotal de ocorrencias: %d\n\n", string, pri, ult, count);    

    system("pause");

    return 0;
}

void countChar(char *str, char ch, int *pri, int *ult, int *count){
    //Varre a string
    for(int i = 0; *(str + i) != '\0'; i++){
        //Houve um match e é o primeiro
        if(ch == *(str + i) && *pri == -1){            
            *pri = i;            
            *ult = i;
            *count += 1;
        }
        //Houve um match e não é o primeiro
        else if(ch == *(str + i)){
            *ult = i;
            *count += 1;
        }        
    }
}