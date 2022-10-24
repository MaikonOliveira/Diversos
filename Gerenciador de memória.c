// Trabalho de gerenciador de memória
// Desenvolvido por Maikon Oliveira

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bold(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[!!status]);
}

int main(){
    int T=0, OP, vet2[10];
    //Realiza a leitura do algoritmo a ser utilizado.
    printf("\n===== Gerenciador de memoria por particoes dinamicas =====\n");
    do{
        printf("Escolha um dos algoritmos:\n");
        printf(" 0 - First-fit\n 1 - Best-fit\n 2 - Worst-fit\n 3 - Circular-fit\n");
        scanf("%d", &OP);
    }while(OP!=0 && OP!=1 && OP!=2 && OP!=3);
    srand((unsigned)time(NULL) );
    T=8+rand()%(15-8+1);
    int vet[T];
    printf("Regioes: %d\n",T);
    //Gera um valor aleatório para cada região e imprime no terminal as regiões originais.
    for(int i=0;i<T;i++){
        vet[i]=1+rand()%(100);
    }for(int i=0;i<T;i++){
        if(i==0) printf("Original [%d - ",vet[i]);
        else if(i<T-1) printf("%d - ",vet[i]);
        else printf("%d]\n",vet[i]);
    }
    //Gera 10 solicitações de memórias aleatoriamente.
    for(int i=0;i<10;i++){
        vet2[i]=1+rand()%(99);
    }
    //Chama o algoritmo escolhido.
    switch(OP){
        case 0:
            first_fit(T, vet, vet2);
            printf("\n");
            break;
        case 1:
            best_fit(T, vet, vet2);
            printf("\n");
            break;
        case 2:
            worst_fit(T, vet, vet2);
            printf("\n");
            break;
        case 3:
            circular_fit(T, vet, vet2);
            printf("\n");
            break;
    }
}
//Algoritmo que gera o first-fit;
void first_fit(int reg, int x[], int y[]){
    int flag=0, flag2=0, aux;
    for(int i=0; i<10;i++){
        for(int k=0; k<reg;k++){
            if(x[k]/y[i] >= 1){
                x[k]=x[k]-y[i];
                aux=k;
                if(x[k]==0) flag2=1;
                k=reg;
            }else if(k==(reg-1)){
                flag=1;
            }
        }
        printf("[%d - %d]", i, y[i]);
        if(flag==0){
            for(int j=0;j<reg;j++){
                if(x[j] == 0);
                else if(j==0 && aux==0){
                    bold(2);
                    printf(" [%d - ",x[j]);
                }else if(j==0){
                    bold(0);
                    printf(" [%d - ",x[j]);
                }else if(j<reg-1 && aux==j){
                    bold(2);
                    printf("%d - ",x[j]);
                }else if(j<reg-1){
                    bold(0);
                    printf("%d - ",x[j]);
                }else if(aux==reg-1){
                    bold(2);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(1);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }else{
                    bold(0);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(2);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }
            }
        }else{
            bold(2);
            printf(" Solicitacao nao pode ser atendida\n");
            flag=0;
        }
    }
}
//Algoritmo que gera o best-fit;
void best_fit(int reg, int x[], int y[]){
    int flag=0, flag2=0, aux, valor=100, indice=0;
    for(int i=0;i<10;i++){
        for(int k=0;k<reg;k++){
            if(x[k]-y[i] < valor){
                if(x[k]-y[i] >= 0){
                    valor=x[k]-y[i];
                    indice=k;
                }
            }
            if(k==reg-1 && valor!=100){
                x[indice]=x[indice]-y[i];
                aux=indice;
                if(x[indice]==0) flag2=1;
                indice=0;
                valor=100;
            }else if(k==reg-1) flag=1;
        }
        printf("[%d - %d]", i, y[i]);
        if(flag==0){
            for(int j=0;j<reg;j++){
                if(x[j] == 0);
                else if(j==0 && aux==0){
                    bold(2);
                    printf(" [%d - ",x[j]);
                }else if(j==0){
                    bold(0);
                    printf(" [%d - ",x[j]);
                }else if(j<reg-1 && aux==j){
                    bold(2);
                    printf("%d - ",x[j]);
                }else if(j<reg-1){
                    bold(0);
                    printf("%d - ",x[j]);
                }else if(aux==reg-1){
                    bold(2);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(1);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }else{
                    bold(0);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(2);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }
            }
        }else{
            bold(2);
            printf(" Solicitacao nao pode ser atendida\n");
            flag=0;
        }
    }
}
//Algoritmo que gera o worst-fit;
void worst_fit(int reg, int x[], int y[]){
    int flag=0, flag2=0, aux, valor=0, indice=0;
    for(int i=0;i<10;i++){
        for(int k=0;k<reg;k++){
            if(x[k]-y[i] > valor){
                if(x[k]-y[i] >= 0){
                    valor=x[k]-y[i];
                    indice=k;
                }
            }
            if(k==reg-1 && valor!=0){
                x[indice]=x[indice]-y[i];
                aux=indice;
                if(x[indice]==0) flag2=1;
                indice=0;
                valor=0;
            }else if(k==reg-1) flag=1;
        }
        printf("[%d - %d]", i, y[i]);
        if(flag==0){
            for(int j=0;j<reg;j++){
                if(x[j] == 0);
                else if(j==0 && aux==0){
                    bold(2);
                    printf(" [%d - ",x[j]);
                }else if(j==0){
                    bold(0);
                    printf(" [%d - ",x[j]);
                }else if(j<reg-1 && aux==j){
                    bold(2);
                    printf("%d - ",x[j]);
                }else if(j<reg-1){
                    bold(0);
                    printf("%d - ",x[j]);
                }else if(aux==reg-1){
                    bold(2);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(1);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }else{
                    bold(0);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(2);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }
            }
        }else{
            bold(2);
            printf(" Solicitacao nao pode ser atendida\n");
            flag=0;
        }
    }
}
//Algoritmo que gera o circular-fit ou next-fit;
void circular_fit(int reg, int x[], int y[]){
    int flag=0, flag2=0, aux, indice=0, cont=1;
    for(int i=0; i<10;i++){
        cont=1;
        for(int k=indice; k<reg;k++){
            if(x[k]/y[i] >= 1){
                x[k]=x[k]-y[i];
                indice=k+1;
                if(indice==reg) indice=0;
                aux=k;
                if(x[k]==0) flag2=1;
                k=reg;
            }else if(cont==reg){
                flag=1;
                k=reg;
            }else if(k==(reg-1)){
                k=0; 
            }
            cont++;
        }
        printf("[%d - %d]", i, y[i]);
        if(flag==0){
            for(int j=0;j<reg;j++){
                if(x[j] == 0);
                else if(j==0 && aux==0){
                    bold(2);
                    printf(" [%d - ",x[j]);
                }else if(j==0){
                    bold(0);
                    printf(" [%d - ",x[j]);
                }else if(j<reg-1 && aux==j){
                    bold(2);
                    printf("%d - ",x[j]);
                }else if(j<reg-1){
                    bold(0);
                    printf("%d - ",x[j]);
                }else if(aux==reg-1){
                    bold(2);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(1);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }else{
                    bold(0);
                    printf("%d] ",x[j]);
                    if(flag2==1){
                        bold(2);
                        printf("Encaixe perfeito\n");
                        flag2=0;
                    }else printf("\n");
                }
            }
        }else{
            bold(2);
            printf(" Solicitacao nao pode ser atendida\n");
            flag=0;
        }
    }
}
