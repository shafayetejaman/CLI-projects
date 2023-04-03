#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("input error\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("input error\n");
        return 2;
    }

    unsigned char buffer[512];
    int i = 0;
    char* file_name = malloc(sizeof(char) * 8);
    FILE* output_file = NULL;

    while (fread(buffer, sizeof(char), 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (i > 0)
            {
                fclose(output_file);
            }

            sprintf(file_name, "%03i.jpg", i);
            output_file = fopen(file_name,"w");
            i++;
        }

        if (output_file != NULL)
        {
           fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    fclose(output_file);
    fclose(file);
    free(file_name);
    return 0;
}