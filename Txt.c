#include "./Headers/Everything.h"

void startup()                            //��studata.txt�Ĳ��ң�����ᴴ��
{
    FILE *fp=NULL;
    char ch[999];
    char loading[]={"������...\n"};
    for(int i=0;i<strlen(loading);i++){
        printf("%c",loading[i]);
        Sleep(50);
    }

    if((fp=fopen("studata.txt","r"))==NULL){
        int x=0;
        char notfound[]={"�Ҳ���\"studata.txt\"�ļ�\n�����½��ļ���......\n�ѳɹ����������Դ�......\n�ѳɹ��򿪣�\n"};
        fp=fopen("studata.txt","a");
        for(int i=0;i<strlen(notfound);i++){
            printf("%c",notfound[i]);
            Sleep(50);
        }
        fprintf(fp,"%d\n",x);
        fclose(fp);
    }else{
        char getit[]={"���ҵ�\"studata.txt\"�ļ�\n���Դ���......\n�ѳɹ��򿪣�\n"};
        for(int i=0;i<strlen(getit);i++){
            printf("%c",getit[i]);
            Sleep(50);
        }

    }
}

void stu_account()                               //��stu_account.txt�Ĳ��ң�����ᴴ��
{
    FILE *fp;
    fp=fopen(".//Accounts//stu_account.txt","a");

    fclose(fp);
}

void mana_account()                              //��mana_account.txt�Ĳ��ң�����ᴴ��
{
    FILE *fp;
    fp=fopen(".//Accounts//mana_account.txt","a");

    fclose(fp);
}