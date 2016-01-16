#include<string.h>
#include<iostream.h>
#define L 1001
int main (int argc, char **argv)
	{
		char dividend[L]="", divisor[L]="",
		difference[L]="", a[L]="", b[L]="", char temp[L]="0",
		s[L]="", tempstring[L]=""; // a and b used to store dividend and divisor.
		int quotient, inta, intb, diff, tempint = 0;
		char d;

		quotient = 0;

		cout << "Enter the dividend?  ";      //larger number (on top)
		cin  >> a;
		cout << "Enter the divisor?  ";           //smaller number (on bottom)
		cin  >> b;

		//making the strings the same length by adding 0's to the beggining of string.

		while (strlen(a) < strlen(b))
		{
			strcat(temp,a);
			strcpy(a,temp);
			strcpy(temp,"0");
		}
				  // a has less digits than b add 0's
		strcpy(temp,"0");
		while (strlen(b) < strlen(a))
		{
			strcat(temp,b);
			strcpy(b,temp);
			strcpy(temp,"0");
		}          // b has less digits than a add 0's

		inta = a[0]-'0';                        // getting first digit in both strings
		intb = b[0]-'0';

		//if a<b print remainder out (a) and return 0
		if (inta < intb)
		{
			cout << "Quotient: 0 " << endl << "Remainder: " << a << endl;
		}
		else
		{
			strcpy(temp,"0");
			strcat(temp,a);
			strcpy(a,temp);

			//a = "0"+a;


			strcpy(temp,"0");
			strcat(temp,b);
			strcpy(b,temp);

			//b = "0"+b;


			diff = intb;
			//s = b;
		// while ( s >= b )
		 //{
			do
			{
				for (int i = strlen(a)-1; i>=0; i--)            // do subtraction until end of string
				{
				inta = a[i]-'0';                    // converting ascii to int, used for munipulation
				intb = b[i]-'0';
				if (inta < intb)                 // borrow if needed
				{
				  a[i-1]--;                         //borrow from next digit
				  a[i] += 10;
				}
				diff = a[i] - b[i];
			  char d = diff+'0';

				strcpy(temp,"0");
				strcat(temp,b);
				strcpy(b,temp);
//			   s = d + s;                           //this + is appending two strings, not performing addition.

				}
			 quotient++;
			 a = s;
			// strcpy (a, s);
			} while (s >= B); // fails after deviding 3 x's

		cout << "s string: " << s << endl;
		 cout << "a string: " << a << endl;
		 cout << "Quotient:  " << quotient << endl;
		 //cout << "Remainder: " << s << endl;

		}


		return 0;
	}