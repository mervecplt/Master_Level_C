#include <stdio.h>
#include <string.h>


struct Hospital{
    char name[50];
    char city[50];
    int beds;
    float price;
    float rating;
    int reviews;
};

struct Patient{
    char name[50];
    int age;
};
void printHospital(struct Hospital hospital){
    printf("Hastane: %s\n",hospital.name);
    printf("Sehir: %s\n",hospital.city);
    printf("Toplam Yatak Kapasitesi: %d\n",hospital.beds);
    printf("Gunluk Kalma Ucreti: %.2f\n",hospital.price);
    printf("Puani: %.2f\n",hospital.rating);
    printf("Yorum Sayisi: %d\n",hospital.reviews);
    printf("\n");
}
void printPatient(struct Patient patient){
    printf("Hastanin adi %s\n",patient.name);
    printf("Hastanin yasi %d\n",patient.age);
    printf("\n");

}
void sortByPrice(struct Hospital hospitals[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
             if(hospitals[j].price>hospitals[j+1].price){
                struct Hospital temp = hospitals[j];
                hospitals[j]=hospitals[j+1];
                hospitals[j+1]=temp;
             }
        }
    }

}
void sortByBeds(struct Hospital hospitals[],int n){
  int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
             if(hospitals[j].beds < hospitals[j+1].beds){
                struct Hospital temp = hospitals[j];
                hospitals[j]=hospitals[j+1];
                hospitals[j+1]=temp;
             }
        }
    }

}
void sortByName(struct Hospital hospitals[],int n){
     int i,j;
      for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
             if(strcmp(hospitals[j].name,hospitals[j+1].name)>0){
                struct Hospital temp = hospitals[j];
                hospitals[j]=hospitals[j+1];
                hospitals[j+1]=temp;
             }
        }
    }
}
void sortByRating(struct Hospital hospitals[],int n){
   int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
             if(hospitals[j].rating>hospitals[j+1].rating){
                struct Hospital temp = hospitals[j];
                hospitals[j]=hospitals[j+1];
                hospitals[j+1]=temp;
             }
        }
    }
}

void printHospitalInCity(struct Hospital hospitals[]){
     char city[50];
     int i;
     printf("Lutfen sehir giriniz(Ankara Istanbul Izmir)\n");
     scanf("%s",&city);

     printf("%s'deki hasataneler :\n",city);

     for(i=0;i<5;i++){
        if(strcasecmp(hospitals[i].city,city)== 0){
                printf("Hastane: %s\n",hospitals[i].name);
                printf("Sehir: %s\n",hospitals[i].city);
                printf("Toplam Yatak Kapasitesi: %d\n",hospitals[i].beds);
                printf("Gunluk Kalma Ucreti: %.2f\n",hospitals[i].price);
                printf("Puani: %.2f\n",hospitals[i].rating);
                printf("Yorum Sayisi: %d\n",hospitals[i].reviews);
                printf("\n");
        }
     }


}

int main()
{
    int choice,n=5,i,j;
    struct Hospital hospitals[5]= { { "Can", "Istanbul", 100, 250.0, 4.5, 100 },
			{ "Balkan", "Ankara", 150, 200.0, 4.2, 80 },
			{ "Balbadem", "Istanbul", 200, 180.0, 4.0, 120 },
			{ "Edikol", "Izmir", 80, 300.0, 4.8, 90 },
			{ "Mekol", "Ankara", 120, 220.0, 4.6, 110 } };

    //Hasatanelerdeki hastalarimiz
    struct Patient patients[5][3] = { { { "Osman", 35 },{ "Hakan", 45 },{ "Elif", 28 } },
									{ { "Can", 62 },{ "Kerem", 18 },{ "Mazlum", 55 } },
									{ { "Zafer", 50 },{ "Melis", 30 },{ "Fulya", 40 } },
									{ { "Mert", 22 },{ "Asli", 38 },{ "Beyza", 60 } },
									{ { "Ada", 28 },{ "Celil", 48 },{ "Ozan", 33 } } };

    do {
            printf("\n\n\n***********Hastane Yonetim Sistemi *********\n\n\n");
            printf("1. Hastane Bilgilerini Bastir\n");
            printf("2. Hasta Bilgilerini Bastir\n");
            printf("3. Hastaneleri Gunluk Kalma Ucretine Gore Sirala\n");
            printf("4. Hastaneleri Yatak Sayisina Gore Sirala(Azalan)\n");
            printf("5. Hastaneleri Adina Gore Sirala\n");
            printf("6. Hastaneleri Puanina Gore Sirala\n");
            printf("7. Girilen Sehirdeki Hastaneleri Bastir\n");
            printf("8  Cikis Yap\n");

            printf("Seciminizi Yapiniz\n");
            scanf("%d",&choice);

            switch(choice){

            case 1:
                    for(i=0;i<n;i++){
                        printf("%d. Hastanem\n",i+1);
                        printHospital(hospitals[i]);
                    }

                 break;
            case 2:
                    for(i=0;i<n;i++){
                        printf("%s Hastanesi\n",hospitals[i].name);
                        for(j=0;j<3;j++){
                            printf("%d. Hastam:\n",j+1);
                            printPatient(patients[i][j]);
                        }
                    }
                 break;
            case 3:
                sortByPrice(hospitals,n);
                 for(i=0;i<n;i++){
                        printf("%d. Hastanem\n",i+1);
                        printHospital(hospitals[i]);
                 }
                 break;
            case 4:
                sortByBeds(hospitals,n);
                 for(i=0;i<n;i++){
                        printf("%d. Hastanem\n",i+1);
                        printHospital(hospitals[i]);
                 }
                 break;
            case 5:
                sortByName(hospitals,n);
                 for(i=0;i<n;i++){
                        printf("%d. Hastanem\n",i+1);
                        printHospital(hospitals[i]);
                 }

                 break;
            case 6:
                 sortByRating(hospitals,n);
                  for(i=0;i<n;i++){
                        printf("%d. Hastanem\n",i+1);
                        printHospital(hospitals[i]);
                 }
                 break;
            case 7:
                printHospitalInCity(hospitals); break;
            case 8:
                printf("Programimiz sonlandi");
                break;



            }
    }while(choice != 8);





	return 0;
}
