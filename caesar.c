#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // check for the command line argument
    if (argc == 2)
    {
        // convert key to int
        int key = atoi(argv[1]);  // "10" -> 10 ... atoi from stdlib.h

        // store key validity
        bool check_valid_key = false;

        // check validity of the key
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                check_valid_key = true;
            }
            else //Usage and terminate the program
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // check for upper and lower case letters and apply the formula
        if (check_valid_key == true)
        {
            string c = get_string("plaintext: "); // User plaintext text input

            for (int i = 0; i < strlen(c); i++)
            {
                if (isupper(c[i]))
                {
                    c[i] = ((c[i] - 65 + key) % 26) + 65; // formula
                }
                else if (islower(c[i]))
                {
                    c[i] = ((c[i] - 97 + key) % 26) + 97; // formula
                }
            }
            printf("ciphertext: %s\n", c); //output the ciphertext!!
        }
    }
    else //Usage and terminate the program
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
