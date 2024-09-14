#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Braille dictionary for English letters (lowercase)
char *braille_alpha[] = 
{
    "O.....", "O.O...", "OO....", "OO.O..", "O..O..", "OOO...", "OOOO..", "O.OO..", ".OO...", ".OOO..",
    "O...O.", "O.O.O.", "OO..O.", "OO.OO.", "O..OO.", "OOO.O.", "OOOOO.", "O.OOO.", ".OO.O.", ".OOOO.",
    "O...OO", "O.O.OO", "OO..OO", "OO.OOO", "O..OOO", "OOO.OO"  // a-z
};

// Braille dictionary for numbers (0-9)
char *braille_num[] = 
{
    ".O.OOO", "O.....", "O.O...", "OO....", "OO.O..", "O..O..", "OOO...", "OOOO..", "O.OO..", ".OO..." // 0-9
};

// Braille capital follow symbol
char *braille_cap = ".....O";

// Braille number follow symbol
char *braille_num_f = ".O.OOO";

// Function to convert English text to Braille
void english_to_braille(const char *input) 
{
    for (int i = 0; i < strlen(input); i++) 
    {
        if (isspace(input[i]))
        {
            printf("......");
        } 
        else if (isdigit(input[i])) 
        {
            // Print number follows symbol and the corresponding Braille number
            printf("%s%s", braille_num_f, braille_num[input[i] - '0']);
        } 
        else if (isupper(input[i])) 
        {
            // Print capital follows symbol and the corresponding lowercase letter Braille
            printf("%s%s", braille_cap, braille_alpha[tolower(input[i]) - 'a']);
        } 
        else if (islower(input[i])) 
        {
            // Print corresponding lowercase letter Braille
            printf("%s", braille_alpha[input[i] - 'a']);
        }
    }
    printf("\n");
}

// Function to convert Braille to English
void braille_to_english(const char *input) 
{
    int i = 0, capital = 0, numbers = 0;
    
    while (i < strlen(input)) 
    {
        if (strncmp(&input[i], "......", 6) == 0) 
        {
            printf(" ");
            i += 6;
        } 
        else if (strncmp(&input[i], braille_cap, 6) == 0) 
        {
            capital = 1;
            i += 6;
        } 
        else if (strncmp(&input[i], braille_num_f, 6) == 0) 
        {
            numbers = 1;
            i += 6;
        } 
        else 
        {
            int found = 0;
            if (numbers) 
            {
                for (int j = 0; j < 10; j++) 
                {
                    if (strncmp(&input[i], braille_num[j], 6) == 0) 
                    {
                        printf("%d", j);
                        i += 6;
                        found = 1;
                        break;
                    }
                }
                numbers = 0;
            }
            if (!found) 
            {
                for (int j = 0; j < 26; j++)
                {
                    if (strncmp(&input[i], braille_alpha[j], 6) == 0) 
                    {
                        if (capital) 
                        {
                            printf("%c", toupper('a' + j));
                            capital = 0;
                        } 
                        else 
                        {
                            printf("%c", 'a' + j);
                        }
                        i += 6;
                        break;
                    }
                }
            }
        }
    }
    printf("\n");
}

// Function to determine if input is Braille
int is_braille(const char *input) 
{
    for (int i = 0; i < strlen(input); i++) 
    {
        if (input[i] != 'O' && input[i] != '.' && !isspace(input[i])) 
        {
            return 0; // Not Braille
        }
    }
    return 1; // Braille
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s <string to translate>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];

    if (is_braille(input)) 
    {
        braille_to_english(input);
    } 
    else {
        english_to_braille(input);
    }

    return 0;
}
