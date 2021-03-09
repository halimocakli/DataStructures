#include <stdbool.h>
#include <stdio.h>
#define SIZE 10

int array[SIZE];
int top = -1;// Stack konusu içerisinde dizilerle işlem yaparken top değişkeni indis olarak değerlendirildiği için "-1" ile başlattık ki sonraki eleman 0. indis olarak görünsün

bool FullControl()
{
  if (top == (SIZE - 1))
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool EmptinessControl()
{
  if (top == -1)
  {
    return true;
  }

  else
  {
    return false;
  }
}

void Push(int number)
{
  bool full = FullControl();
  if (full == true)
  {
    printf("\n !!!Stackoverflow!!!\a\n");
    return;
  }
  top++;
  array[top] = number;
}

int Pop()
{
  bool empty = EmptinessControl();
  if (empty == true)
  {
    printf("\n Stack halihazirda bos...\a");
    return 0;
  }
  int prevTop = array[top];
  top--;

  return prevTop;
}

int Peek()
{
  return array[top];
}

void Print()
{
  printf("\n");
  for (int i = top; i >= 0; i--)
  {
    printf("\n %d", array[i]);
  }
  printf("\n");
}

int main()
{
  /*
   * STACK (YIĞIN) VERİ YAPISI
   *
   * Soyut bir veri yapısıdır (Abstract Data Type)
   * En son giren elemanın ilk olarak çıktığı bir yapıya sahiptir (Last In First Out - LIFO)
   * Sıklıkla kullanılan bir veri yapısıdır.
   * Yapılan işlemlerin daha sonra tekrar lazım olacağı durumlarda çokça kullanılır.
   * Örnek olarak "Ctrl+Z" komutunun işleyişinde Stack mantığı hakimdir.
   * Stack için hafızadan yer ayırılır. Alana aşımı olması halinde "Stackoverflow" hatası alınır.
   *
   * Push => Eleman ekleme işlemi
   * Pop  => Eleman çıkarma işlemi
   * Peek => Listenin en tepesindeki elemanı kontrol etmemizi sağlar
   *
   * Listenin en üzerindeki eleman Top eleman olarak isimlendirilir.
   * Listeye her eleman eklenmesinde eklenen eleman Top eleman olur.
   * Listeden her eleman silindiğinde bir gerideki eleman Top eleman haline gelir.
   *
   *
   */

  int selection;
  int number;
  int minuend;
  int topElement;

  do {
    printf("\n 0- End Programme");
    printf("\n 1- Push");
    printf("\n 2- Pop");
    printf("\n 3- Peek");
    printf("\n 4- Print");
    printf("\n Make a selection: ");
    scanf("%d", &selection);

    switch (selection)
    {
    case 0:
      printf("\n Programme ended successfully!\a");
      break;
    case 1:
      printf("\n Insert a number that you wanna add: ");
      scanf("%d", &number);
      Push(number);
      break;
    case 2:
      minuend = Pop();
      printf("\n %d has removed from stack...\n", minuend);
      break;
    case 3:
      topElement = Peek();
      printf("\n Top element of array is: %d\n", topElement);
      break;
    case 4:
      Print();
      break;
    }
  } while (selection != 0);
  
  return 0;
}
