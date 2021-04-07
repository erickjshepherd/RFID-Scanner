#include "Cart.h"
#include "String.h"

StoreItem Data[3];

void Data_Init(){
	Data[0].uid[0] = 0xB6;
	Data[0].uid[1] = 0x4D;
	Data[0].uid[2] = 0x78;
	Data[0].uid[3] = 0x13;
	Data[0].uid[4] = '\0';
	strcpy(Data[0].name, "Object1");
	Data[0].price = 7;
	
	Data[1].uid[0] = 0x76;
	Data[1].uid[1] = 0x27;
	Data[1].uid[2] = 0xF3;
	Data[1].uid[3] = 0x12;
	Data[1].uid[4] = '\0';
	strcpy(Data[1].name, "Object2");
	Data[1].price = 11;
	
	Data[2].uid[0] = 0xE6;
	Data[2].uid[1] = 0x34;
	Data[2].uid[2] = 0x76;
	Data[2].uid[3] = 0x13;
	Data[2].uid[4] = '\0';
	strcpy(Data[2].name, "Object3");
	Data[2].price = 5;
}

int Get_Price(char* tag){
	
	int x;
	for(x = 0; x < 3; x++){
		if(strcmp(Data[x].uid, tag) == 0){
			return Data[x].price;
		}
	}
	return 0;
}

char* Get_Name(char* tag){
	
	int x;
	for(x = 0; x < 3; x++){
		if(strcmp(Data[x].uid, tag) == 0){
			return Data[x].name;
		}
	}
	
	return 0;
}
