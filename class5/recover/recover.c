#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Enter the name of image you want to recover\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *image = fopen(infile, "r");
    if (image == NULL)
    {
        printf("Can not open the image file\n");
        return 2;
    }

    int count = 0;
    BYTE *buffer = malloc(512 * sizeof(BYTE));
    FILE *JPEG = NULL;
    char filename[8];

    while (fread(buffer, 512 * sizeof(BYTE), 1, image) == 1)
    // continue to read image next time
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (count > 0)
            {
                fclose(JPEG);
            }
            // not close only before the first file
            sprintf(filename, "%03i.jpg", count);
            JPEG = fopen(filename, "w");
            // the file needs a name
            fwrite(buffer, 512 * sizeof(BYTE), 1, JPEG);

            count++;
        }
        else if(count != 0)
        //this can not run first (before the last if)
        {
            fwrite(buffer, 512 * sizeof(BYTE), 1, JPEG);
            // continue to write in JPEG next time
        }
    }

    fclose(image);
    fclose(JPEG);
    free(buffer);
    return 0;
}