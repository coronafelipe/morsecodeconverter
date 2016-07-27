#include<stdio.h>
#include<string.h>
int peek(FILE *file);
int peek(FILE *file)
{
        int c;
        c = getchar();
        ungetc(c,file);
        return c;
}
void alphaToMorse(char*, char*);
void morseToAlpha(char*, char*);


void morseToAlpha(char *infilename, char* outfilename)
{
	FILE *file, *outfile;
	file = fopen(infilename, "r");
	outfile = fopen(outfilename, "w");
	char *alpha[] ={ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	char *morse[] = {".-", "-...",  "-.-.", "-..",  ".", "..-.","--.", "....",  "..", ".---", "-.-",  ".-..", "--", "-.", "---",  ".--.", "--.-", ".-.", "...",   "-",
			"..-",  "...-", ".--",  "-..-","-.--",  "--..",  ".--.-",".-.-", "---." };
	int i;
	char c;
	c = fgetc(file);

	int counter = 0;
	char tempA[16];
	char *temp;
	temp = tempA;

	int space_counter = 0;
	while(c != EOF)
	{
		if (c != ' ')
		{
			*(temp + counter) = c;
			counter++;
		}
		else if(counter != 0)
		{	
			*(temp + counter) = '\0';
			counter = 0;
			for(i = 0; i < 26; i++)
			{
				if(strcmp(temp, morse[i])== 0)
				{
					fputs(alpha[i], outfile);
				}
			}
			strcpy(temp, "");
		}
		else
		{
			space_counter++;
			space_counter = space_counter % 7;
			if(space_counter == 0)
			{
				fputs(" ", outfile);
			}	
		}
		c = fgetc(file);
	}

	 *(temp + (counter - 1)) = '\0';
         counter = 0;
         for(i = 0; i < 26; i++)
         {
                 if(strcmp(temp, morse[i])== 0)
                 {       
                         fputs(alpha[i], outfile);
                 }
         }

         strcpy(temp, "");

	fclose(file);
    	fclose(outfile);	


}

void alphaToMorse(char* infilename, char* outfilename)
{
    FILE* inputfile = fopen(infilename, "r");
    FILE* outputfile = fopen(outfilename, "w");

    int read_c;
    char temp[10000];
    do 
    {
        read_c = fgetc(inputfile);
	switch(read_c)
        {
            case 'a':
            case 'A':
                strcat(temp, ".- ");
                break;

            case 'b':
            case 'B':
                strcat(temp, "-... ");
                break;

            case 'c':
            case 'C':
                strcat(temp, "-.-. ");
                break;

            case 'd':
            case 'D':
                strcat(temp, "-.. ");
                break;

            case 'e':
            case 'E':
                strcat(temp, ". ");
                break;

            case 'f':
            case 'F':
                strcat(temp, "..-. ");
                break;
            
            case 'g':
            case 'G':
                strcat(temp, "--. ");
                break;
            
            case 'h':
            case 'H':
                strcat(temp, ".... ");
                break;

            case 'i':
            case 'I':
                strcat(temp, ".. ");
                break;

            case 'j':
            case 'J':
                strcat(temp, ".--- ");
                break;

            case 'k':
            case 'K':
                strcat(temp, "-.- ");
                break;

            case 'l':
            case 'L':
                strcat(temp, ".-.. ");
                break;

            case 'm':
            case 'M':
                strcat(temp, "-- ");
                break;
            
            case 'n':
            case 'N':
                strcat(temp, "-. ");
                break;

            case 'o':
            case 'O':
                strcat(temp, "--- ");
                break;

            case 'p':
            case 'P':
                strcat(temp, ".--. ");
                break;

            case 'q':
            case 'Q':
                strcat(temp, "--.- ");
                break;

            case 'r':
            case 'R':
                strcat(temp, ".-. ");
                break;

            case 's':
            case 'S':
                strcat(temp, "... ");
                break;

            case 't':
            case 'T':
                strcat(temp, "- ");
                break;

            case 'u':
            case 'U':
                strcat(temp, "..- ");
                break;

            case 'v':
            case 'V':
                strcat(temp, "...- ");
                break;

            case 'w':
            case 'W':
                strcat(temp, ".-- ");
                break;
            
            case 'x':
            case 'X':
                strcat(temp, "-..- ");
                break;
            
            case 'y':
            case 'Y':
                strcat(temp, "--.- ");
                break;
            
            case 'z':
            case 'Z':
                strcat(temp, "--.. ");
                break;

            case '1':
                strcat(temp, ".---- ");
                break;
            
            case '2':
                strcat(temp, "..--- " );
                break;

            case '3':
                strcat(temp, "...-- ");
                break;

            case '4':
                strcat(temp, "....- ");
                break;

            case '5':
                strcat(temp, "..... ");
                break;

            case '6':
                strcat(temp, "-.... ");
                break;

            case '7':
                strcat(temp, "--... ");
                break;

            case '8':
                strcat(temp, "---.. ");
                break;

            case '9':
                strcat(temp, "----. ");
                break;

            case '0':
                strcat(temp, "----- ");
                break;
            
            case ' ':
                strcat(temp, "       ");
                break;

            case '\n':
                strcat(temp, "\n");
                break;
        }
    }while(read_c != EOF);
    fputs(temp, outputfile);
    fclose(inputfile);
    fclose(outputfile);
}

int main(int argc, char* argv[])
{
	alphaToMorse(argv[1], argv[2]);
	morseToAlpha(argv[2], "finalconversion.txt");
	return 0;
}
