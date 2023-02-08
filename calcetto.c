#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct Pl{
	char Nome[N];
	int Peso;
	struct Pl * next;
} Player;

typedef Player * PlayerList;

void ViewList(PlayerList lista);
PlayerList InsInFondoStringa(PlayerList lista,char elem[]);
PlayerList Players();
PlayerList BubbleSort(PlayerList list);
PlayerList Neri();
PlayerList Bianchi();


int main(){
	PlayerList Black=Neri();
	PlayerList White=Bianchi();
	
	White=BubbleSort(White);
	Black=BubbleSort(Black);
	
	PlayerList Giocatori =Players();
	Giocatori=BubbleSort(Giocatori);
	
	printf("GIOCATORI\n\n");
	ViewList(Giocatori);
	printf("\nSQUADRE\n");
	printf("Bianchi: ");
	ViewList(White);
	printf("Neri: ");
	ViewList(Black);
}




PlayerList BubbleSort(PlayerList list){
	char temp[N];
	PlayerList aux=list;
	int flag=0;
	while(1){
		flag=0;
		while(aux->next!=NULL){
			if(strcmp(aux->next->Nome,aux->Nome)<0){
				strcpy(temp,aux->next->Nome);
				strcpy(aux->next->Nome,aux->Nome);
				strcpy(aux->Nome,temp);
				flag=1;
			}
			aux=aux->next;
			
		}
		if(!flag)
			break;
		aux=list;
	}
	
	return list;
}

PlayerList Players(){
	PlayerList lis=NULL;
	lis=InsInFondoStringa(lis,"Leraj Kevin");lis=InsInFondoStringa(lis,"Angelone Samuele");lis=InsInFondoStringa(lis,"Russica Daniele");
	lis=InsInFondoStringa(lis,"Angelone Davide");lis=InsInFondoStringa(lis,"Pagliari Marco");lis=InsInFondoStringa(lis,"Castoldi Jacopo");
	lis=InsInFondoStringa(lis,"Vianello Luca");lis=InsInFondoStringa(lis,"Pennone Dario");lis=InsInFondoStringa(lis,"Pagliari Matteo");
	lis=InsInFondoStringa(lis,"Patcas Sebastian");
	
	return lis;
}

PlayerList Bianchi(){
	PlayerList lis=NULL;
	lis=InsInFondoStringa(lis,"Angelone Davide");lis=InsInFondoStringa(lis,"Pagliari Marco");lis=InsInFondoStringa(lis,"Castoldi Jacopo");
	lis=InsInFondoStringa(lis,"Pennone Dario");lis=InsInFondoStringa(lis,"Pagliari Matteo");
	
	return lis;
}

PlayerList Neri(){
	PlayerList lis=NULL;
	lis=InsInFondoStringa(lis,"Leraj Kevin");lis=InsInFondoStringa(lis,"Angelone Samuele");lis=InsInFondoStringa(lis,"Russica Daniele");
	lis=InsInFondoStringa(lis,"Vianello Luca");	lis=InsInFondoStringa(lis,"Patcas Sebastian");
	
	return lis;
}
PlayerList InsInFondoStringa(PlayerList lista,char elem[]) {
    PlayerList punt;
    if(lista==NULL) { punt = malloc( sizeof(Player) );
                     punt->next = NULL; strcpy(punt->Nome,elem); return  punt;
    }else{lista->next = InsInFondoStringa(lista->next,elem); return lista;}
}

void ViewList(PlayerList lista) {
    if (lista==NULL) printf(" --| \n");
    else{printf("%s --> ", lista->Nome); ViewList( lista->next );}
}
