#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct node* Create(int);
struct node* RandomCreate();
struct node* ReverseListRecursive(struct node*);
void AddToHead(int);
void Insert(int, int);
void AddToTail(int);
void FillListRandomly(int);
void DeleteFromHead();
void DeleteFromGapWithPosition(int);
void DeleteFromGapWithValue(int);
void DeleteFromTail();
void DestroyList();
void DestroyListRecursive(struct node**);
void ReverseListIterative();
void PrintList();
void MenuPrint();
void ClearScreen();

struct node {
	int mNumber;
	struct node* next;
};

struct node* firstNode = NULL;

int main()
{
	int selection;
	int number;
	int position;
	int element;
	int elementNumber;
	srand(time(NULL));

	MenuPrint();
	do
	{
		printf("\n ----------------------------------------");
		printf("\n Yapmak istediginiz islemi secin: ");
		scanf("%d", &selection);
		printf(" ----------------------------------------\n");

		switch (selection)
		{
		case 0:
			printf(" Program basariyla sonlandirildi...");
			break;
		case 1:
			MenuPrint();
			break;
		case 2:
			PrintList();
			break;
		case 3:
			ClearScreen();
			break;
		case 4:
			printf(" Basa eklemek istediginiz degeri giriniz: ");
			scanf("%d", &number);
			AddToHead(number);
			break;
		case 5:
			printf(" Eleman eklemek istediginiz liste sirasini giriniz: ");
			scanf("%d", &position);
			printf(" Araya eklemek istediginiz degeri giriniz: ");
			scanf("%d", &number);
			Insert(position - 1, number);						// Fonksiyonda indis mantığı geçerli ancak kullanıcı pozisyon belirtirken ilk elemanın pozisyonunu 1 olarak kabul ediyor (position - 1)
			break;
		case 6:
			printf(" Sona eklemek istediginiz degeri giriniz: ");
			scanf("%d", &number);
			AddToTail(number);
			break;
		case 7:
			printf(" Listeye kac adet eleman ekleyeginizi girin: ");
			scanf("%d", &elementNumber);
			FillListRandomly(elementNumber);
			break;
		case 8:
			printf("Listenin ilk elemani siliniyor...\n");
			DeleteFromHead();
			break;
		case 9:
			printf("\n Silmek istediginiz elemanin liste sirasini giriniz: ");
			scanf("%d", &position);
			DeleteFromGapWithPosition(position - 1);
			break;
		case 10:
			printf("\n Silmek istediginiz elemani giriniz: ");
			scanf("%d", &element);
			DeleteFromGapWithValue(element);
			break;
		case 11:
			printf("Listenin son elemani siliniyor...\n");
			DeleteFromTail();
			break;
		case 12:
			if (firstNode != NULL)
			{
				printf("\n Liste tamamen siliniyor...");
				DestroyList(firstNode);
			}
			else
			{
				printf("\n Liste halihazirda bos, bu islemi yapabilmek icin eleman ekleyin\a");
			}
			break;
		case 13:
			DestroyListRecursive(&firstNode);
			break;
		case 14:
			ReverseListIterative();
			Sleep(2000);
			printf("\n Listeyi ters cevirme islemi tamamlandi...");
			break;
		case 15:
			ReverseListRecursive(firstNode);
			Sleep(2000);
			printf("\n Listeyi ters cevirme islemi tamamlandi...");
			break;
		default:
			printf(" Hatali tuslama yaptiniz, tekrar deneyin...\a");
			break;
		}
	} while (selection != 0);

	getch();
	return 0;
}

// Düğüm üreten fonksiyon
struct node* Create(int number)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->mNumber = number;																// Düğüm içerisindeki veri
	newNode->next = NULL;																	// Bir sonraki düğümün işaretçisi

	return newNode;
}

// Düğüm üreten fonksiyon - mNumber 1-100 arası rastgele sayıya sahiptir
struct node* RandomCreate()
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->mNumber = 1 + rand() % 101;
	newNode->next = NULL;

	return newNode;
}

// Liste başına eleman ekleme fonksiyonu
void AddToHead(int number)
{
	struct node* addedToHead = Create(number);												// Başa eklenecek eleman oluşturuluyor
	if (firstNode == NULL)                    												// Dizi boş ise yani başta eleman yoksa üretilen eleman direkt olarak başa ekleniyor
	{
		firstNode = addedToHead;
	}

	/*
	 * Başa eleman eklerken eğer başta bir eleman varsa swap işlemi yaparak baştaki elemanın yerine 
	 * kendi elemanımızı yerleştirip önceki ilk elemanı ikinci sıraya yerleştiririz. Aşağıdaki
	 * else yapısıda bu işlem gerçekleştirilmektedir.
	*/

	else
	{
		struct node* tempFirstNode = firstNode;
		firstNode = addedToHead;
		firstNode->next = tempFirstNode;
	}
}

// Araya eleman ekleme fonksiyonu
void Insert(int position, int number)
{
	/*
	 * number parametresi, belirtilen pozisyona eklenmek üzere oluşturulan düğüme veri olarak aktarılır ve yerine yerleştirilir.
	 * Diyelim ki düğüm verilerimiz şunlar => 3 5 7 9 11 15 ve biz 11-15 arasına 13 verisine sahip düğümü eklemek istiyoruz.
	 * Bu düğümü eklemek için kullanıcının girmesi gereken pozisyon değeri "5" olmalıdır.
	 * Kullanıcının girdiği pozisyon değeri fonksiyona 4 olarak gelir çünkü dizi aritmetiğini baz alıyoruz
	 * Bu işlemlerin ardından 15 yerine 13 gelir ve 11->next = 13 olurken 13->next 15 olur. Böylece araya eleman eklenir
	 */

	/*
	 * Diyelim ki listenin ikinci sırasına bir eleman ekleyeceğiz, o halde listenin birinci elemanını bulmalı ve bu elemanın "next" işaretçisini
	 * eklemek istediğimiz elemanın struct'ına eşitlemeli ardından eklediğimiz elemanın "next" işaretçisini daha önce listenin ikinci sırasında
	 * bulunan liste elemanına eşitlemeliyiz. Böylece bağlı liste yapısını bozmadan araya eleman ekleyebiliriz.
	 */

	int counter = 0;                             											// Sayaç
	struct node* insertedMember = Create(number);										    // Araya eklenecek eleman oluşturuluyor
	struct node* temp = firstNode;              											// Geçici değişkene listenin ilk elemanı atanıyor

	if (temp == NULL)																		// Listede eleman olup olmadığının kontrolü
	{
		printf(" Liste bos, bu islemi yapmak icin listeye eleman ekleyin...\a");
		return;
	}

	if (temp->next == NULL)																	// Listede en az iki eleman olup olmadığının kontrolü
	{
		printf(" Araya eleman eklemek icin listede en az iki adet eleman olmasi gerekmektedir, yeni eleman ekleyiniz...\a");
		return;
	}

	if (position == 0)																		// Eleman eklemek istediğimiz pozisyonun listenin başı olup olmadığının kontrolü
	{
		printf(" Bu islem icin lutfen \"Basa Eleman Ekle\" secenegini kullanin...\a");
		return;
	}

	if (position < 0)
	{
		printf(" Belirttiginiz pozisyon listede mevcut degildir...\a");
		return;
	}

	while (temp != NULL)
	{
		if (counter == position - 1)														// Hangi konuma eleman ekleyeceksek o koundan önceki önceki elemanı bulduğumuzu doğrulayan kontrol yapısı
		{
			break;
		}														
		temp = temp->next;
		counter++;																			// Hangi konuma eleman ekleyeceksek o konumdan önceki elemanı bulmamızı sağlayan sayaç değişkeni
	}

	if (counter + 1 != position)															// Belirtilen pozisyonun listede olup olmadığı kontrol edilir
	{
		printf("\n Belirttiginiz pozisyon listede mevcut degildir\a\n");
		return;
	}

	// Swap işlemi yapılıyor
	struct node* nextTemp = temp->next;
	temp->next = insertedMember;
	insertedMember->next = nextTemp;
}

// Liste sonuna eleman ekleme fonksiyonu
void AddToTail(int number)
{
	struct node* addedToTail = Create(number);												// Sona eklenecek eleman oluşturuluyor
	if (firstNode == NULL)                    												// Listede eleman olup olmadığının kontrolü yapılıyor
	{
		printf(" Listede eleman bulunmamaktadir, lutfen eleman ekleyin...\a");
		return;
	}

	else
	{
		struct node* temp = firstNode;
		while (temp->next != NULL)															// Listenin son düğümüne ulaşan döngü yapısı
		{
			temp = temp->next;
		}
		temp->next = addedToTail;															// number verisine sahip düğüm listenin sonuna ekleniyor
	}
}

// Boş listeyi, belirlenen eleman sayısı adedince rastgele sayılara sahip düğümlerle dolduran fonksiyon
void FillListRandomly(int elementNumber)
{
	if (elementNumber <= 0)
	{
		printf("\n Eleman sayisi sifira esit ya da sifirdan kucuk olamaz, yeniden deneyin\a ");
		return;
	}

	if (firstNode != NULL)
	{
		printf("\n Bu islem yalnizca bos listelerde calismaktadir.");
		printf(" Listede halihazirda eleman bulunmaktadir, diger ekleme yontemlerini deneyiniz\a");
		return;
	}

	if (firstNode == NULL)
	{
		firstNode = RandomCreate();															// İlk elemanı ekledik
		struct node* tempNode = firstNode;
		for (int i = 0; i < (elementNumber - 1); i++)										// İlk elemanı ekledimiz için döngü eleman sayısının bir eksiği kadar döner
		{
			tempNode->next = RandomCreate();
			tempNode = tempNode->next;
		}
		Sleep(2000);
		printf(" Liste rastgele sayilarla dolduruldu...");
	}
}

// Listenin başından eleman silme fonksiyonu
void DeleteFromHead()
{
	if (firstNode == NULL)
	{
		printf("Listede eleman bulunmamaktadir...\a");
		return;
	}

	else if (firstNode->next == NULL)
	{
		firstNode = NULL;
		printf("Listenin ilk elemani silindi...");
		return;
	}

	// Swap işlemi ile listenin ilk elemanını silip listenin ikinci elemanını birinci eleman olarak güncelliyoruz.
	else
	{
		struct node* secondNode = firstNode->next;
		free(firstNode);
		firstNode = secondNode;
	}
}

// Verilen liste konumunu kullanarak aradan eleman silen fonksiyon
void DeleteFromGapWithPosition(int position)
{
	struct node* temp = firstNode;
	int counter = 0;

	if (firstNode == NULL)
	{
		printf("\n Listede halihazirda eleman bulunmamaktadir...\a");
		return;
	}

	if (position == 0)
	{
		printf("En bastaki elemani silmek icin \"Bastan Eleman Sil\" secenegini kullaniniz...\a");
		return;
	}

	if (position < 0)
	{
		printf("\n Belirttiginiz pozisyon listede mevcut degildir\a\n");
		return;
	}

	while (temp != NULL)
	{
		if (counter == position - 1)// Belirtilen pozisyona gidiyoruz
			break;
		temp = temp->next;
		counter++;
	}

	// Verilen pozisyonun listenin son elemenını işaret edip etmediğinin kontrolü yapılıyor
	if (temp->next->next == NULL)
	{
		printf("En sondaki elemani silmek icin \"Sondan Eleman Sil\" secenegini kullaniniz...\a");
		return;
	}

	if (counter + 1 != position)
	{
		printf("\n Belirttiginiz pozisyon listede mevcut degildir\a\n");
		return;
	}

	// Swap işlemi
	struct node* newTemp = temp->next->next;
	free(temp->next);
	temp->next = newTemp;
}

// Verilen değerin bulunduğu liste elemanını listeden silen fonksiyon
void DeleteFromGapWithValue(int element)
{
	if (firstNode == NULL)
	{
		printf("\n Listede halihazirda eleman bulunmamaktadir...\a");
		return;
	}

	if (firstNode->mNumber == element)
	{
		printf("Girdiginiz sayi listenin ilk elemanidir, lutfen \"Bastan Eleman Sil\" secenegini kullanin...\a");
		return;
	}

	struct node* temp = firstNode;
	int flag = 0;
	while (temp->next != NULL)
	{
		if (temp->next->mNumber == element)// Aradığımız değer bulunursa bu yapının içine girer
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}

	// Aradıgımız değerin bulunup bulunmadığını kontrol eder
	if (flag != 1)
	{
		printf("\n Aradiginiz deger bulunamadi...\a");
		return;
	}

	// Verilen değerin listenin son elemanına ait olup olmadığını kontrol eden yapı
	if (temp->next->next->mNumber == element)
	{
		printf("En sondaki elemani silmek icin \"Sondan Eleman Sil\" secenegini kullaniniz...\a");
		return;
	}

	struct node* newTemp = temp->next->next;
	free(temp->next);
	temp->next = newTemp;
}

// Sondan eleman silen fonksiyon
void DeleteFromTail()
{
	// Listelerde eleman silmek dizilerden farklıdır, listelerde eleman silerken bellekten alan sileriz
	// Silinecek elemandan bir önceki elemana ulaşmalıyız çünkü sondan önceki elemanın gösterdiği değeri NULL olarak işaretlemeliyiz

	struct node* temp = firstNode;
	if (temp->next == NULL)
	{
		printf("Listede yalnica bir eleman var. Silmek icin \"Bastan Eleman Sil\" secenegini kullaniniz...");
		return;
	}

	if (temp == NULL)
	{
		printf("Listede halihazirda eleman bulunmamaktadir...");
		return;
	}

	while (temp->next->next != NULL)// Bu ifadeyi sileceğimiz elemandan bir önceki elemanı bulmak için oluşturduk
	{
		temp = temp->next;
	}

	free(temp->next);
	temp->next = NULL;
}

// Listeyi yok eden fonksiyon
void DestroyList()
{
	struct node* temp;
	while (firstNode != NULL)
	{
		temp = firstNode;
		firstNode = firstNode->next;
		free(temp);
		temp = NULL;
	}
}

void DestroyListRecursive(struct node** head)
{
	if (*head == NULL)
	{
		return;
	}
	DestroyListRecursive(&((*head)->next));
	free(*head);
	*head = NULL;
}


// Listeyi ters çeviren fonksiyon
void ReverseListIterative()
{
	struct node* existingNode = firstNode;
	struct node* previousNode = NULL;
	struct node* nextNode = NULL;

	// Aşağıdaki algoritmada geniş bir swap yapısıdır. existingNode->next ve firstNode = previousNode ifadeleri kilit rol üstlenir
	// Bir kağıt-kalem kullanarak ya da debug yaparak algoritmanın mantığını ortaya çıkarabilirsiniz
	while (existingNode != NULL)
	{
		nextNode = existingNode->next;
		existingNode->next = previousNode;
		previousNode = existingNode;
		existingNode = nextNode;
	}
	firstNode = previousNode;
}

// Listeyi ters çeviren fonskiyon- Recursive
struct node* ReverseListRecursive(struct node* existingNode)
{
	if (existingNode == NULL)// Listenin halihazırda boş olup olmadığının kontrolü
	{
		printf("\n Liste bos, eleman ekleyiniz...\a");
		return NULL;
	}

	if (existingNode->next == NULL)// BaseCase
	{
		firstNode = existingNode;
		return existingNode;
	}

	struct node* tempNode = ReverseListRecursive(existingNode->next);
	tempNode->next = existingNode;
	existingNode->next = NULL;

	return existingNode;
}

// Liste yazdıran fonksiyon
void PrintList()
{
	printf("\n");

	struct node* temp = firstNode;
	printf(" *************************************************************\n");

	if (temp == NULL)
	{
		printf(" Liste Bos\a");
		printf("\n *************************************************************\n");
		return;
	}

	while (temp != NULL)
	{
		printf(" %d =>", temp->mNumber);
		temp = temp->next;
	}
	printf(" NULL");
	printf("\n *************************************************************");
	printf("\n");
}

// Menu yazdıran fonksiyon
void MenuPrint()
{
	printf("\n ***************** MENU *****************");
	printf("\n ****************************************");
	printf("\n 0- Programi Sonlandir");
	printf("\n 1- Menu Yazdir");
	printf("\n 2- Liste Yazdir");
	printf("\n 3- Ekrani Temizle");
	printf("\n ----------------------------------------");
	printf("\n ELEMAN EKLEME ISLEMLERI");
	printf("\n 4- Basa Eleman Ekle");
	printf("\n 5- Araya Eleman Ekle");
	printf("\n 6- Sona Eleman Ekle");
	printf("\n 7- Listeyi Rastgele Doldur");
	printf("\n ----------------------------------------");
	printf("\n ELEMAN SILME ISLEMLERI");
	printf("\n 8- Bastan Eleman Sil");
	printf("\n 9- Aradan Eleman Sil [REFERANS : INDEKS]");
	printf("\n 10- Aradan Eleman Sil [REFERANS : DEGER]");
	printf("\n 11- Sondan Elemen Sil");
	printf("\n 12- Listeyi Tamamen Sil");
	printf("\n 13- Listeyi Tamamen Sil - Recursive");
	printf("\n ----------------------------------------");
	printf("\n LISTE TERS CEVIRME ISLEMLERI");
	printf("\n 14- Listeyi Ters Cevir [ITERATIVE]");
	printf("\n 15- Listeyi Ters Cevir [RECURSIVE]");
}

// Ekranı temizleyen fonksiyon
void ClearScreen()
{
	system("CLS");
	printf("\n Ekran temizlendi, menu yazdiriliyor...");
	Sleep(1000);
	system("CLS");
	Sleep(1000);
	MenuPrint();
}