#include <stdio.h>
#include <stdlib.h>

#define C_GRAY      "\033[37m"
#define BG_RED      "\033[41m"
#define C_RED       "\033[31m"
#define BG_BLACK    "\033[40m"
#define UNDERSCORE  "\033[4m"
#define NONE        "\033[0m"
#define C_CYAN      "\033[36m"

    char senha[10] = "**********";
    int i = 0;
    const char letra_min[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
      't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    const char letra_max[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                            'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1',
                             '2', '3', '4', '5', '6', '7', '8', '9'};
    
    const char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    void generator(int n, int min, int max, int q){
		//printf(NONE);
		printf(C_CYAN);
		if(i < q){
            printf("senha %d: ", i + 1);
            if(n == 1 && min == 0 && max == 0){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = number[rand() % 10];        
                }
                printf("%s\n", senha);
            }
            else if(n == 0 && min == 1 && max == 0){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = letra_min[rand() % 26];        
                }
                printf("%s\n", senha);
            }
            else if(n == 0 && min == 0 && max == 1){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = letra_max[rand() % 26];        
                }
                printf("%s\n", senha);
            }
            else if(n == 0 && min == 1 && max == 1){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = letra_max[rand() % 26];
                    senha[rand() % 10] = letra_min[rand() % 26];        
                }
                printf("%s\n", senha);
            }
            else if(n == 1 && min == 0 && max == 1){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = letra_max[rand() % 26];
                    senha[rand() % 10] = number[rand() % 10];        
                }
                printf("%s\n", senha);
            }
            else if(n == 1 && min == 1 && max == 0){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = letra_max[rand() % 26];
                    senha[rand() % 10] = number[rand() % 10];        
                }
                printf("%s\n", senha);
            }
            else if(n == 1 && min == 1 && max == 1){
                while(senha[0] == '*' || senha[1] == '*' || senha[2] == '*' || senha[3] == '*' || senha[4] == '*' || senha[5] == '*' || senha[6] == '*' || senha[7] == '*' || senha[8] == '*' || senha[9] == '*'){
                    senha[rand() % 10] = letra_max[rand() % 26];
                    senha[rand() % 10] = number[rand() % 10];   
                    senha[rand() % 10] = letra_min[rand() % 26];     
                }
                printf("%s\n", senha);
            }
            ++i;
            if(n != 1 && n != 0 || min != 1 && min != 0 && max != 1 && max != 0){
                system("clear");
                printf("\n\n\n-----------NÚMERO INCORRETO---------------------\n\n\n");
                return;
            }
            for(int j = 0; j < 10; j++){
                senha[j] = '*';
            }
            generator(n, min, max, q);
        }
		printf("\n");
    }
#define BOLD        "\033[1m"
    int main(){
        int n, min, max, q;
        system("clear");
		printf(BG_BLACK);
		printf(C_GRAY);
		printf(UNDERSCORE);
        printf("\n\n\n-----------WELCOME---------------------\n\n");
        printf("-----------QUANTAS SENHAS VOCÊ DESEJA?---------------------\n");
        scanf("%d", &q);
        system("clear");
		printf("\n\n-----------DIGITE (1) PARA SIM OU (0) PARA NÃO\n---------------------\n");
        while(n != 1 && n != 0){
        	system("clear");
			printf(C_GRAY "1. Senhas com números? \n       1 -> SIM\n       0 -> NÃO\n");
	    	scanf("%d", &n);
			if(n == 1 || n == 0) break;
			else printf("TENTE NOVAMENTE\n");
		}
        system("clear");
		while(max != 1 && max != 0){
	        system("clear");
			printf("2. Senhas com letras maiúsculas? \n       1 -> SIM\n       0 -> NÃO\n");
    	    scanf("%d", &max);
			if(max == 1 || max == 0) break;
			else printf("TENTE NOVAMENTE\n");
		}
        system("clear");
		while(min != 1 && min != 0){
			system("clear");
		    printf("2. Senhas com letras minúsculas? \n       1 -> SIM\n       0 -> NÃO\n");
	        scanf("%d", &min);
			if(min == 1 || min == 0) break;
			else printf("TENTE NOVAMENTE\n");
		}
        system("clear");
		printf("\n\n\n");
        generator(n, min, max, q);
    }
