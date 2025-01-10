#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library{
    char book_name[20];
    char   author[20];
    int  pages;
    float   price;
};

int main()
{
    char author[20];
	struct library lib[100];
	int i=0 , j ,input=0;


	while(input != 5){
        printf("\n\n*******#####Kutuphane Yonetim Sistemi#####******\n\n\n");
        printf("1. Kitap Bilgisi Ekleyiniz\n");
        printf("2. Kitap Bilgilerini Goster\n");
        printf("3. Yazara Ait Tum Kitaplari Listele\n");
        printf("4. Kutuphanedki Toplam Kitap Sayisini Goster\n");
        printf("5. Cikis");

        printf("\nLutfen seciminizi yapiniz ");
        scanf("%d",  &input);

        switch(input){
        case 1:
            printf("Kitabin adini giriniz = ");
            scanf("%s",&lib[i].book_name);
            printf("Kitabin yazarini giriniz = ");
            scanf("%s", &lib[i].author);
            printf("Kitabin sayfa sayisini giriniz = ");
            scanf("%d",&lib[i].pages);
            printf("Kitabin fiyati giriniz = ");
            scanf("%f", &lib[i].price);
            i++;
            break;

        case 2:
            printf("Kitap Bilgileri\n");
            for(j=0;j<i;j++){
                printf("%d. kitabim:\n",j+1);
                printf("Kitap ismi : %s\n",lib[j].book_name);
                printf("Kitabin yazari : %s\n",lib[j].author);
                printf("Kitabin sayfa sayisini : %d\n",lib[j].pages);
                printf("Kitap fiyati : %f\n",lib[j].price);
                printf("\n");
            }
            break;

        case 3:
            printf("Yazari giriniz\n");
            scanf("%s",&author);
            for(j=0;j<i;j++){
                if(strcmp(author,lib[j].author)==0){
                    printf("%s yazarina ait kitaplar:\n",author);
                    printf("Kitap ismi : %s\n",lib[j].book_name);
                    printf("Kitabin yazari : %s\n",lib[j].author);
                    printf("Kitabin sayfa sayisini : %d\n",lib[j].pages);
                    printf("Kitap fiyati : %f\n",lib[j].price);
                    printf("\n");
                }
            }
            break;

        case 4:
            printf("\n Toplam Kitap Sayisi: %d",i);
            break;

        case 5:
            exit(0);

        }
	}




	return 0;
}