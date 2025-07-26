#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int letters_count(string text);
int spaces_count(string text);
int sentences_count(string text);


int main(void)
{
        string text = get_string("text: ");
        int letters = letters_count(text);
        int words = spaces_count(text) + 1;
        int sentences = sentences_count(text);
        float L = ((float) letters / words) * 100;
        float S = ((float) sentences / words) * 100;
        float index = 0.0588 * L - 0.296 * S - 15.8;


       if(index < 1)
       {
        printf("Before Grade 1\n");
       }
       else if(index > 16)
       {
        printf("Grade 16+\n");
       }
       else
       {
        printf("Grade %.0f\n", index);
       }


}



int letters_count(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
        {

        if(isalpha(text[i]))
        {
            letters++;

        }
    }
    return letters;
}



int spaces_count(string text)
{
    int spaces = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
        {

        if(isspace(text[i]))
        {
            spaces++;

        }
    }
    return spaces;
}




int sentences_count(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
        {

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;

        }
    }
    return sentences;
}
