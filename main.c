#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");

    struct people {
        char name[30];
        char surname[30];
        char dname[30];
        short birth;
    };

    FILE *f, *fw;
    f = fopen("names.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла для чтения");
        return -1;
    }
    fw = fopen("result.txt", "w");
    if (fw == NULL) {
        printf("Ошибка открытия файла для записи");
        fclose(f);
        return -2;
    }

    short n = 0;
    while (!feof(f)) if (fgetc(f) == '\n') n++;
    n++;
    struct people humans[n];

    fseek(f,0,SEEK_SET);

    for (short i = 0; i < n; i++) {
        fscanf(f, "%s%s%s%hd", humans[i].surname, humans[i].name, humans[i].dname, &humans[i].birth);
        printf("%s %s %s %hd\n", humans[i].surname, humans[i].name, humans[i].dname, humans[i].birth);
        if (humans[i].birth > 1979) fprintf(fw,"%s %s %s %hd\n", humans[i].name, humans[i].surname, humans[i].dname, humans[i].birth);
    }
    /*while (fscanf(f, "%s%s%s%hd", humans[n].name, humans[n].surname, humans[n].dname, &humans[n].birth) != EOF) {
        if (humans[n].birth > 1979) fprintf(fw,"%s %s %s %hd\n", humans[n].name, humans[n].surname, humans[n].dname, humans[n].birth);
        n++;
    }*/

    ///printf("%hd", n);
    fclose(fw);
    fclose(f);
    return 0;
}
