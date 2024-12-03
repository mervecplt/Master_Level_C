#include <ctype.h>
#include <stdio.h>
#define max 20
#include <string.h>

struct employee{
  char name[20];
  int code;
  char job[20];
  int  exp;
  int  age;
};

struct employee emp[20];
int num;

void build(){
    int i;
    printf("Maksimum calisan sayisi: %d\n",max);
    printf("Lutfen calisan sayisini giriniz\n");
    scanf("%d",&num);

    if(num>20){
        printf("Maksimum calisan sayisini astiniz.Calisan sayisi maksimum %d olabilir\n",max);
        num=max;
    }

    printf("Lutfen calisan bilgilerini giriniz\n");
    for(i=0;i<num;i++){
        printf("%d. calisan bilgilerini giriniz\n",i+1);
        printf("Ad:");
        scanf("%s",&emp[i].name);
        printf("Calisan Id:");
        scanf("%d",&emp[i].code);
        printf("Meslek:");
        scanf("%s",&emp[i].job);
        printf("Tecrube:");
        scanf("%d",&emp[i].exp);
        printf("Yas:");
        scanf("%d",&emp[i].age);
        printf("\n");
    }

    showMenu();


}
void insert(){

    if(num < max){
                printf("Ad:");
                scanf("%s",&emp[num].name);
                printf("Calisan Id:");
                scanf("%d",&emp[num].code);
                printf("Meslek:");
                scanf("%s",&emp[num].job);
                printf("Tecrube:");
                scanf("%d",&emp[num].exp);
                printf("Yas:");
                scanf("%d",&emp[num].age);
                num++;
    }
    else{
        printf("Maksimum calisan sayisini astiniz\n");
    }

    showMenu();
}

void searchRecord(){
    int code,i;
    printf("Calisan bilgilerine ulasmak icin calisan Id sini giriniz\n");
    scanf("%d",&code);

    for(i=0;i<num;i++){
        if(emp[i].code == code){

            printf("Ad : %s\n",emp[i].name);
            printf("Meslek : %s\n",emp[i].job);
            printf("Tecrube : %d\n",emp[i].exp);
            printf("Yas : %d\n",emp[i].age);
            break;
        }
    }

    showMenu();


}

void showNumber(){

    printf("Calisan sayisi: %d\n",num);

    showMenu();

}
void deleteIndex(int i){
    int j;
    for(j=i;j<(num-1);j++){
        strcpy(emp[j].name,emp[j+1].name);
        emp[j].code=emp[j+1].code;
        strcpy(emp[j].job,emp[j+1].job);
        emp[j].exp=emp[j+1].exp;
        emp[j].age=emp[j+1].age;
    }
    return;

}

void deleteRecord(){
   int code,i;
    printf("Calisani silmek icin calisan Id sini giriniz\n");
    scanf("%d",&code);

    for(i=0;i<num;i++){
        if(emp[i].code == code){
            deleteIndex(i);
            num--;
            printf("Basarili bir sekilde calisani sildiniz");
            break;
        }
    }

    showMenu();

}


void showMenu(){

    int option;

    printf("\n\n-----------------------Calisan Yonetim Sistemi-------------\n\n");
    printf("Islem seciniz\n");
    printf("Calisan tablosu olusturunuz(1)\n");
    printf("Yeni calisan ekleyiniz(2)\n");
    printf("Calisan siliniz(3)\n");
    printf("Calisan bilgilerini getiriniz (4)\n");
    printf("Calisan sayisini gosteriniz (5)\n");
    printf("Cikis yapiniz(6)\n");
    scanf("%d",&option);

    if(option == 1){
        build();
    }
    else if(option == 2){
        insert();
    }
    else if(option == 3){
        deleteRecord();
    }
    else if(option == 4){
        searchRecord();
    }
    else if(option == 5){
        showNumber();
    }
    else if(option == 6){
        return;
    }
    else{
        printf("Yanlis bir secim yaptiniz");
        showMenu();
    }





}


int main()
{


	showMenu();
	return  0;

}
