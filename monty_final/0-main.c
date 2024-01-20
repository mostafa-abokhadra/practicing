#define  _GNU_SOURCE
#include "monty.h"
/**
 *
 *
 *
 *
 */
int main(int argc, char *argv[])
{
                unsigned int line_num = 0;
                size_t size = 0;
                FILE *fily;
                char *line = NULL;

                if (argc < 2)
                        less_than_two();
                fily = fopen(argv[1], "r");
                if (!fily)
                        not_found(argv[1]);
                for(; getline(&line, &size, fily) != -1 ;)
                {
                        line_num++;
                        if (execution(line, line_num, &fily))
                                continue;
                }
		free(line);
		fclose(fily);
                return (0);
}

