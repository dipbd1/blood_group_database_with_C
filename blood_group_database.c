#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<time.h>

#define speed 5

FILE *bldt;
char wait[1000], dialog[1000];
char art=176;
char artp;
char lo;
char xtra[5];
char search[3];
int i,j;
int m, n;
int people;
int notation=10;
input_blood();
search_blood();
logo();
print_load();
logo_static();
print_load_slow();
date();
print_slow(char per[1000]);
struct group
{
    char name[20];
    char sign[5];
    char num[15];
    char given[10];
};
struct group g[60];
struct group g2[59];
main()
{
    while(1)
    {
        system("mode 1000");
        print_load_slow();
        Sleep(1000);
        for(i=0; i<3; i++)
        {
            system("cls");
            printf("Loading core files......\n\n\n");
            Sleep(500);
            print_load();
            Sleep(500);

        }
        system("mode 1000");
        system("cls");

        date();
        logo();
        print_slow("01. To input detail of donor, press'1'\n");
        printf("\n");
        //printf("02. Search for blood group with detail, press '2'\n");
        print_slow("02. Search for blood group with detail, press '2'");
        printf("\n\n");
        //printf("03. Exit\n\n");
        print_slow("03. Exit");
        printf("\n\n");
        printf("Press Key: ");

        lo=getch();
        //printf("%c %d\n", lo, notation);
        if(lo=='1')
        {
            notation = 1;
        }
        else if(lo=='2')
        {
            notation = 2;
        }
        else if (lo=='3')
        {
            notation =3;
        }
        else if (lo=='4')
        {
            notation =4;
        }

        //scanf("%d", &notation);
        if(notation==1)
        {
            input_blood();
            return 0;
        }
        if(notation==2)
        {
            search_blood();
            return 0;
        }
        if(notation==3)
        {
            return 0;
        }
        system("cls");
        print_slow("You have pressed a Wrong key!!\n\n\n\nPress any key to restart the program!");
        //printf("%c %d\n", lo, notation);
        gets(xtra);



    }
}
input_blood()
{
    system("cls");
    logo_static();
    print_slow("How many People detail do you want to give: ");
    scanf("%d", &people);
    bldt=fopen("database.txt","r");
    for(i=0; i<=60; i++)
    {
        g2[i].name[0]='\0';
        g2[i].sign[0]='\0';
        g2[i].num[0]='\0';
        g2[i].given[0]='\0';
    }
    for(i=0; i<=60; i++)
    {
        fscanf(bldt,"%s",g2[i].name);
        fscanf(bldt,"%s",g2[i].sign);
        fscanf(bldt,"%s",g2[i].num);
        fscanf(bldt,"%s",g2[i].given);
    }
    fclose(bldt);
    bldt=fopen("database.txt","w");
    for(i=0; i<people; i++)
    {
        system("cls");
        date();
        logo_static();
        print_slow("Taking Detail of case: ");
        printf("%d\n\n", i+1);
        print_slow("Give the name: ");
        scanf("%s", &g[i].name );
        print_slow("Give the blood group: ");
        scanf("%s", &g[i].sign );
        print_slow("Give the contact Number: ");
        scanf("%s", &g[i].num);
        print_slow("Last Blood Given Date(DD/MM/YY): ");
        scanf("%s", g[i].given);
        fprintf(bldt,"%-20s",g[i].name);
        fprintf(bldt,"%-20s",g[i].sign);
        fprintf(bldt,"%-20s",g[i].num);
        fprintf(bldt,"%-20s\n",g[i].given);
    }
    for(i=0; i<60; i++)
    {
        fprintf(bldt,"%-20s",g2[i].name);
        fprintf(bldt,"%-20s",g2[i].sign);
        fprintf(bldt,"%-20s",g2[i].num);
        fprintf(bldt,"%-20s\n",g2[i].given);
    }
    fclose(bldt);
    print_slow("\n\n\n\nPress any key to Terminate the program!");
    scanf("%c",&xtra);
    scanf("%c",&xtra);
}
search_blood()
{
    system("cls");
    for(i=0; i<3; i++)
    {
        search[i]='\0';
    }
    date();
    printf("\n\n");
    print_slow("Enter the group for which you are searching: ");
    scanf("%s",search);
    print_slow("Name__          ___Group___              ___ContNo__   ___ Last Given Date\n\n");
    bldt=fopen("database.txt","r");
    for(i=0; i<60; i++)
    {
        fscanf(bldt,"%s",g[i].name);
        fscanf(bldt,"%s",g[i].sign);
        fscanf(bldt,"%s",g[i].num);
        fscanf(bldt,"%s",g[i].given);
        if(g[i].sign[0]==search[0] && g[i].sign[1]==search[1] && g[i].sign[2]==search[2])
        {
            printf("%-20s %-20s %-20s %-20s\n",g[i].name,g[i].sign,g[i].num, g[i].given);
        }
    }
    fclose(bldt);
    print_slow("\n\n\n\nPress any key to Terminate the program!");
    gets(xtra);
    return 0;

}

logo()
{
    printf("\n\n\n");
    printf("\t\t      ");
    //print_slow("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art);
    for(i=0; i<39; i++)
    {
        printf("%c", art);
        Sleep(speed);
    }
    printf("\n");
    //printf("\n\n\n");
    //printf("\t      ");
    //printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art);

    //printf("\t      %c                                     %c\n",art, art);
    printf("\t\t      ");
    Sleep(speed);
    printf("%c", art);
    for(i=0; i<37; i++)
    {
        printf(" ");
    }
    printf("%c",art);

    printf("\n");
    //printf("\t      %c Welcome to 'SEC' Database of Blood. %c\n", art, art);
    printf("\t\t      ");
    Sleep(speed);
    printf("%c",art);
    strcpy(wait,"  Welcome to SEC Database of Blood.");
    i=strlen(wait);

    for(j=0; j<i; j++)
    {
        Sleep(speed);
        printf("%c",wait[j]);
    }
    Sleep(speed);
    printf("  %c\n", art);
    Sleep(speed);
    //printf("\t      %c 21/Shukrabad, Dhanmondi, Dhaka.     %c\n", art, art);
    printf("\t\t");
    strcpy(wait,"   21/Shukrabad, Dhanmondi, Dhaka.");
    j=strlen(wait);
    printf("      %c",art);
    for(i=0; i<j; i++)
    {
        Sleep(speed);
        printf("%c", wait[i]);
    }
    printf("   ");
    printf("%c\n", art);
    //printf("\t      %c                                     %c\n",art,art);
    printf("\t\t      ");
    Sleep(speed);
    printf("%c",art);
    Sleep(speed);
    printf("                                     ");
    printf("%c\n",art);
    printf("\t\t      ");
    //printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art);
    for(i=0; i<39; i++)
    {
        printf("%c", art);
        Sleep(speed);
    }
    printf("\n\n\n");
}

logo_static()
{
    printf("\n\n\n");
    printf("\t\t      ");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art);
    printf("\t\t      %c                                     %c\n",art, art);
    printf("\t\t      %c Welcome to 'SEC' Database of Blood. %c\n", art, art);
    printf("\t\t      %c 21/Shukrabad, Dhanmondi, Dhaka.     %c\n", art, art);
    printf("\t\t      %c                                     %c\n",art,art);
    printf("\t\t      ");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art,art);
}
print_slow(char per[1000])
{
    n=strlen(per);
    for(m=0; m<n; m++)
    {
        if(per[m]==' ')
        {
            printf("%c", per[m]);
            continue;
        }
        else
        {
            Sleep(speed);
            printf("%c", per[m]);
        }
    }
}

print_load()
{


    printf("                                                                      dddddddd                                                \n");
    printf("LLLLLLLLLLL                                                           d::::::d  iiii                                          \n");
    printf("L:::::::::L                                                           d::::::d i::::i                                              \n");
    printf("L:::::::::L                                                           d::::::d  iiii                                                    \n");
    printf("LL:::::::LL                                                           d:::::d                                                                \n");
    printf("  L:::::L                  ooooooooooo     aaaaaaaaaaaaa      ddddddddd:::::d iiiiiiinnnn  nnnnnnnn       ggggggggg   ggggg                       \n");
    printf("  L:::::L                oo:::::::::::oo   a::::::::::::a   dd::::::::::::::d i:::::in:::nn::::::::nn    g:::::::::ggg::::g                            \n");
    printf("  L:::::L               o:::::::::::::::o  aaaaaaaaa:::::a d::::::::::::::::d  i::::in::::::::::::::nn  g:::::::::::::::::g                                 \n");
    printf("  L:::::L               o:::::ooooo:::::o           a::::ad:::::::ddddd:::::d  i::::inn:::::::::::::::ng::::::ggggg::::::gg                                      \n");
    printf("  L:::::L               o::::o     o::::o    aaaaaaa:::::ad::::::d    d:::::d  i::::i  n:::::nnnn:::::ng:::::g     g:::::g                                        \n");
    printf("  L:::::L               o::::o     o::::o  aa::::::::::::ad:::::d     d:::::d  i::::i  n::::n    n::::ng:::::g     g:::::g                                        \n");
    printf("  L:::::L               o::::o     o::::o a::::aaaa::::::ad:::::d     d:::::d  i::::i  n::::n    n::::ng:::::g     g:::::g                                        \n");
    printf("  L:::::L         LLLLLLo::::o     o::::oa::::a    a:::::ad:::::d     d:::::d  i::::i  n::::n    n::::ng::::::g    g:::::g                                        \n");
    printf("LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::oa::::a    a:::::ad::::::ddddd::::::ddi::::::i n::::n    n::::ng:::::::ggggg:::::g                                        \n");
    printf("L::::::::::::::::::::::Lo:::::::::::::::oa:::::aaaa::::::a d:::::::::::::::::di::::::i n::::n    n::::n g::::::::::::::::g       ......       ......       ...... \n");
    printf("L::::::::::::::::::::::L oo:::::::::::oo  a::::::::::aa:::a d:::::::::ddd::::di::::::i n::::n    n::::n  gg::::::::::::::g       .::::.       .::::.       .::::. \n");
    printf("LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo     aaaaaaaaaa  aaaa  ddddddddd   dddddiiiiiiii nnnnnn    nnnnnn    gggggggg::::::g       ......       ......       ...... \n");
    printf("                                                                                                                   g:::::g                                        \n");
    printf("                                                                                                       gggggg      g:::::g                                        \n");
    printf("                                                                                                       g:::::gg   gg:::::g                                        \n");
    printf("                                                                                                        g::::::ggg:::::::g                                        \n");
    printf("                                                                                                         gg:::::::::::::g                                         \n");
    printf("                                                                                                           ggg::::::ggg                                           \n");
    printf("                                                                                                              gggggg    \n");

}

print_load_slow()
{
    print_slow("Loading core files......\n\n\n");



    print_slow("                                                                      dddddddd                                                \n");
    print_slow("LLLLLLLLLLL                                                           d::::::d  iiii                                          \n");
    print_slow("L:::::::::L                                                           d::::::d i::::i                                              \n");
    print_slow("L:::::::::L                                                           d::::::d  iiii                                                    \n");
    print_slow("LL:::::::LL                                                           d:::::d                                                                \n");
    print_slow("  L:::::L                  ooooooooooo     aaaaaaaaaaaaa      ddddddddd:::::d iiiiiiinnnn  nnnnnnnn       ggggggggg   ggggg                       \n");
    print_slow("  L:::::L                oo:::::::::::oo   a::::::::::::a   dd::::::::::::::d i:::::in:::nn::::::::nn    g:::::::::ggg::::g                            \n");
    print_slow("  L:::::L               o:::::::::::::::o  aaaaaaaaa:::::a d::::::::::::::::d  i::::in::::::::::::::nn  g:::::::::::::::::g                                 \n");
    print_slow("  L:::::L               o:::::ooooo:::::o           a::::ad:::::::ddddd:::::d  i::::inn:::::::::::::::ng::::::ggggg::::::gg                                      \n");
    print_slow("  L:::::L               o::::o     o::::o    aaaaaaa:::::ad::::::d    d:::::d  i::::i  n:::::nnnn:::::ng:::::g     g:::::g                                        \n");
    print_slow("  L:::::L               o::::o     o::::o  aa::::::::::::ad:::::d     d:::::d  i::::i  n::::n    n::::ng:::::g     g:::::g                                        \n");
    print_slow("  L:::::L               o::::o     o::::o a::::aaaa::::::ad:::::d     d:::::d  i::::i  n::::n    n::::ng:::::g     g:::::g                                        \n");
    print_slow("  L:::::L         LLLLLLo::::o     o::::oa::::a    a:::::ad:::::d     d:::::d  i::::i  n::::n    n::::ng::::::g    g:::::g                                        \n");
    print_slow("LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::oa::::a    a:::::ad::::::ddddd::::::ddi::::::i n::::n    n::::ng:::::::ggggg:::::g                                        \n");
    print_slow("L::::::::::::::::::::::Lo:::::::::::::::oa:::::aaaa::::::a d:::::::::::::::::di::::::i n::::n    n::::n g::::::::::::::::g       ......       ......       ...... \n");
    print_slow("L::::::::::::::::::::::L oo:::::::::::oo  a::::::::::aa:::a d:::::::::ddd::::di::::::i n::::n    n::::n  gg::::::::::::::g       .::::.       .::::.       .::::. \n");
    print_slow("LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo     aaaaaaaaaa  aaaa  ddddddddd   dddddiiiiiiii nnnnnn    nnnnnn    gggggggg::::::g       ......       ......       ...... \n");
    print_slow("                                                                                                                   g:::::g                                        \n");
    print_slow("                                                                                                       gggggg      g:::::g                                        \n");
    print_slow("                                                                                                       g:::::gg   gg:::::g                                        \n");
    print_slow("                                                                                                        g::::::ggg:::::::g                                        \n");
    print_slow("                                                                                                         gg:::::::::::::g                                         \n");
    print_slow("                                                                                                           ggg::::::ggg                                           \n");
    print_slow("                                                                                                              gggggg    \n");
}

date()
{
    time_t current_time;
    char* c_time_string;
    current_time=time(NULL);
    c_time_string=ctime(&current_time);
    print_slow(c_time_string);

}
