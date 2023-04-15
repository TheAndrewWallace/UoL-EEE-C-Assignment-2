#include <stdio.h>

#define TELEPHONE_CHARGE 0.05
#define INTERNET_CHARGE 0.02
#define TELEVISION_BASIC 0.01
#define TELEVISION_PREMIUM 0.02

void details(unsigned int *account_number, char *code, unsigned int *mins);
double	telephone(unsigned int a);
double	internet(unsigned int b);
double television(unsigned int c, char d);
char info(char get_pack);
void print_data(unsigned account_number, double charge);


void main(void)
{
	unsigned int account_number, mins;									//Unsigned because it should not be a minus value
	char code, pack;
	double charge;

	details(&account_number, &code, &mins);

	switch(code)
	{
		case 'p':
		case 'P':
			charge = telephone(mins);
			break;
		case 'i':
		case 'I':
			charge = internet(mins);
			break;
		case 't':
		case 'T':
			pack = info(pack);
			charge = television(mins, pack);
			break;
		default:
			printf("\nERROR: The option entered is invalid");
	}
	
	print_data(account_number, charge);
	
}


void details(unsigned int *account_number, char *code, unsigned int *mins)
{	
	/*Get account number*/
	printf("Enter account number: ");
	fflush(stdin);
	scanf("%u", *&account_number);
	
	/*Get option*/
	printf("\nP: Telephone\nI: Internet\nT: Television\nEnter service code option: ");
	fflush(stdin);
	scanf("%c", *&code);
	
	/*Get minutes*/
	printf("\nEnter how many minutes: ");
	fflush(stdin);
	scanf("%u", *&mins);
	
}


double	telephone(unsigned int a)
{
	double due = 15.0;
	due = due + (a * TELEPHONE_CHARGE);
	return due;
}

double	internet(unsigned int b)
{
	double due = 0.0;
	if(b > 0);
	{
		due = 20.0;
	}
	
	if(b > 1000)
	{
		b = b - 1000;
		due = due + (b * INTERNET_CHARGE);
	}
	
	return due;
}


char info(char get_pack)
{
	printf("\nPack types:\nB:	Basic\nP:	Premium\nEnter 'B' or 'P' to select pack: ");
	fflush(stdin);
	scanf("%c", &get_pack);
	return get_pack;
}


double television(unsigned int c, char d)
{
	double due = 0.0;
	
	switch(d)
	{
		case 'b':
		case 'B':
			if(c > 0);
			{
				due = 5.0;
			}
	
			if(c > 60)
			{
				c = c - 60;
				due = due + (c * TELEVISION_BASIC);
			}
			break;
		case 'p':
		case 'P':
			if(c > 0);
			{
				due = 10.0;
			}
	
			if(c > 60)
			{
				c = c - 60;
				due = due + (c * TELEVISION_PREMIUM);
			}
			break;
		default:
			printf("\nERROR: The pack entered is invalid");
	}
	
	return due;
}

void print_data(unsigned int account_number, double charge)
{
	printf("\nAccount Number:		%u", account_number);
	printf("\nAmmount Due:		%.2f GBP", charge);
}
