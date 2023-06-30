#include "./Headers/Everything.h"

void startup()                            //对studata.txt的查找，无则会创建
{
    FILE *fp=NULL;
    char ch[999];
    char loading[]={"加载中...\n"};
    for(int i=0;i<strlen(loading);i++){
        printf("%c",loading[i]);
        Sleep(50);
    }

    if((fp=fopen("studata.txt","r"))==NULL){
        int x=0;
        char notfound[]={"找不到\"studata.txt\"文件\n尝试新建文件中......\n已成功建立并尝试打开......\n已成功打开！\n"};
        fp=fopen("studata.txt","a");
        for(int i=0;i<strlen(notfound);i++){
            printf("%c",notfound[i]);
            Sleep(50);
        }
        fprintf(fp,"%d\n",x);
        fclose(fp);
    }else{
        char getit[]={"已找到\"studata.txt\"文件\n尝试打开中......\n已成功打开！\n"};
        for(int i=0;i<strlen(getit);i++){
            printf("%c",getit[i]);
            Sleep(50);
        }

    }
}

void stu_account()                               //对stu_account.txt的查找，无则会创建
{
    FILE *fp;
    fp=fopen(".//Accounts//stu_account.txt","a");

    fclose(fp);
}

void mana_account()                              //对mana_account.txt的查找，无则会创建
{
    FILE *fp;
    fp=fopen(".//Accounts//mana_account.txt","a");

    fclose(fp);
}