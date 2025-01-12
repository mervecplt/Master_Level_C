#include <stdlib.h>
#include <time.h>


int game(char you,char computer){
    if(you == 'T' &&  computer == 'K'){
        return 0;
    }
    else if(you ==  'K'  && computer =='T'){
        return 1;
    }
    else if(you == 'T'   && computer =='M'){
        return 1;
    }
    else if(you == 'M' && computer =='T'){
        return 0;
    }
     else if(you == 'K' && computer =='M'){
        return 0;
    }
    else if(you == 'M' && computer =='K'){
        return 1;
    }
    else{
        return -1;
    }
}

// Driver Code
int main()
{

    int n,result;
    char you,computer;

    srand(time(NULL));
    n=rand() % 100;



        if(n < 33){
                computer='T';
        }

        else if(n >=33 && n <66){
              computer='K';
        }
        else{
              computer='M';
        }

        printf("\n\n\n\n\n\n\n\n\t\t\t\t    Tas Kagit Makas Oyunu\n\n\n\n\n\n\n\n");
        printf("\t\t\tTas Icin T Kagit Icin K Makas Icin M Giriniz");

        scanf("%c",&you);

        result=game(you,computer);

        //1 se ben kazandim
        //0 sa bilgisayar kazandi
        //-1 se berabere

        if(result == -1){
            printf("\n\n\t\t\tBerabere! Kimse kazanmadi!\n");
        }
        else if(result == 1){
            printf("\n\n\t\t\tBravo! Oyunu kazandin!\n");
        }
        else{
             printf("\n\n\t\t\tMalesef ! Oyunu kaybettin!\n");
        }

        printf("\t\t\tSenin secimin: %c Bilgisayarin secimi: %c",you,computer);



	return 0;
}