#include <stdio.h>
#include <stdlib.h>
#define COMP 50

void removeChar(char *str, char cH);

void main(){
    //Inicia 'string' generica
    char string[COMP] = "Barriguinha de breja.";

    //Chama a função para remoção de caractere (EX: r);
    removeChar(string, 'a');

    //Imprime a nova string
    printf("%s \n\n", string);

    system("pause");
    return 0;
}

void removeChar(char *str, char cH){
    //Varre o array de caracteres    
    for(int i = 0; *(str+i) != '\0'; i++)   
        //Houve um match
        if(cH == *(str+i)){
            //Move todas as caracteres seguintes uma posição para tras
            for(int j = i; *(str+j) != '\0'; j++)
                *(str+j) = *(str+(j + 1));
            //Retorna I para a caractere que ele havia parado
            i--;
        }            
}