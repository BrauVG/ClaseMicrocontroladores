#include <iostream>
#include <string>

using namespace std;
int main()
{
   int portb;
   int salida;
   int ddrb;
   int dato;

   int DDRB =255;
   int DATO =1;
   while (1)
   {
      int SALIDA =1;
      DATO =SALIDA;
      while (1)
      {
         int PORTB;
		 PORTB=DATO;
         delay_ms(0.5);
         DATO =2 ** SALIDA;
         cout<<DATO<<endl;
         SALIDA =SALIDA+1;
         if (SALIDA>9)) break;
      }
      if (SALIDA==255)) break;
   }

   return 0;
}
