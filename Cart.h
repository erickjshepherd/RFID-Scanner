struct storeItem{
	char uid[5];
	char name[15];
	int price;
}; typedef struct storeItem StoreItem;

char* Get_Name(char* tag);

int Get_Price(char* tag);

void Data_Init(void);
