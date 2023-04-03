#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
  string text = get_string("Text: ");
  int n_l = count_letters(text);
  int n_w = count_words(text);
  int n_s = count_sentences(text);

  float L = (float)n_l / (float)n_w * 100;
  float S = (float)n_s / (float)n_w * 100;

  float index = 0.0588 * L - 0.296 * S - 15.8;


     if((int) round(index) < 1)
     {
        printf("Before Grade 1\n");
     }
     else if((int) round(index)  > 16)
     {
        printf("Grade 16+\n");
     }
     else
     {
        printf("Grade %i\n",(int) round(index));
     }

}

int count_letters(string text)
{   int letter=0;
    for(int i=0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
           letter++;
        }
    }
    return letter;
}

int count_words(string text)
{
    int word=0;
    for(int i=0; i < strlen(text); i++)
    {
        if(isspace(text[i]))
        {
           word++;
        }
    }
    return word + 1;
}

int count_sentences(string text)
{
    int sentences=0;
    for(int i=0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
          sentences++;
        }
    }
    return sentences;
}