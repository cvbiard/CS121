#include "header.h"

int main()
{

	//Problem 1
	char str[100], revstr[100];
    int l = 0;

	//// Declaring variable i=to iterate loop, l=length
	//int i = 0, j = 0, l = 0;

	//printf("Enter whatever you'd like to be reversed: ");
	//gets(str); //stores the value...like a cleaner scanf()....why don't always use gets()? Does gets have to be used for strings?

	//while (str[l] != '\0') //value of length starts at zero, value of l is used as array position. 
	//{					   //l++ increase length afer each round until length hits null character which indicates end of string
	//	l++;
	//}
	//// Reversing string

	//for (i = l - 1; i >= 0; i--)
	//{
	//	revstr[j] = str[i];
	//	j++;
	//}
	//revstr[j] = '\0';

	//// Printing string and reversed string
	//printf("String : %s\n", str);
	//printf("Reversed string : %s", revstr);



    //Problem 1b

    //char* strptr = str; // strptr - holds the first position address of str
    //char* revptr = revstr; // revptr - holds the first position address of revstr
    //int i = -1;

    //// Inputting string
    //printf("Enter any string : ");
    //gets(str);

    //// strptr is pointed to the last position address
    //while (*strptr)
    //{
    //    strptr++;
    //    i++;
    //}

    //// string stored in str is copied to revstr
    //while (i >= 0)
    //{
    //    strptr--;
    //    *revptr = *strptr;
    //    revptr++;
    //    --i;
    //}

    //*revptr = '\0';

    /*printf("Reverse of string is : %s", revstr);*/


    //Problem 2d    int my_strlen (const char *s)
    printf("enter a string and I'll count it for ya\n");
    gets(str);
    while (str[l] != '\0')
    {
        l++;
    }
    printf("Length of string is: %d", l);


	return 0;
}