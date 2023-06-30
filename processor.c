#include "./Headers/Everything.h"

void getf(student *(*Head),int length)      //��studata.txt�ļ��л�ȡ����
{
    FILE *fp;
    fp=fopen("studata.txt","r");
    fgetc(fp);
    for(int n=0;n<length;n++){
        fscanf(fp,"%s%lld%s%lf",(Head[n])->name,&(Head[n])->num,(Head[n])->sex,&(Head[n])->score); 
    }

    fclose(fp);
}

void savef(student *(*Head),int length,int volume){      //��studata.txt�ļ���������
    FILE *fp;

    Sqrt(Head,length);
    fp=fopen("studata.txt","w+");

    fprintf(fp,"%d\n",volume);
    for(int n=0;n<length;n++){
        if((Head[n]->num)==0){
            continue;
        }else{
        fprintf(fp,"%s\t%25lld\t%10s\t%10.2f\n",Head[n]->name,Head[n]->num,Head[n]->sex,Head[n]->score); 
            }
        }
        
    fclose(fp);
}

void show_all(student *(*Head),int length){              //���studata.txt������ѧ����������Ϣ
    printf("����                      ѧ��                  �Ա�              ����\n");
    for(int n=0;n<length;n++){
        printf("%s\t%25lld\t%10s%20.2f\n",Head[n]->name,Head[n]->num,Head[n]->sex,Head[n]->score);
    };
}

student show_per(student *(*Head),int length,long long num){  //����ض�ĳһ���˵���Ϣ
    student *perp=NULL;

    perp=Ddf(Head,length,num);
    if(perp==NULL){
        printf("���޴���\n");
    }else{
        printf("����                      ѧ��                  �Ա�              ����\n");
        printf("%s\t%25lld\t%10s%20.2f\n",perp->name,perp->num,perp->sex,perp->score);
    }
    
}

int stu_account_check()           //ѧ��ϵͳ��¼��֤
{
    FILE *fp;
    long long account,code,kaccount,kcode;
    char ch;
    Input:
    scanf("%lld",&account);
    system("cls");
    menu5(account);
    scanf("%lld",&code);

    fp=fopen("./Accounts/stu_account.txt","r");      //����˼·�����˻��ı��еõ��û���������
    do{                                              //һһ�ȶԣ�ֱ�����ϻ�������
        fscanf(fp,"%lld",&kaccount);
        fscanf(fp,"%lld",&kcode);
        if(feof(fp)!=0){
            break;
        }
        }while(kaccount!=account);
    
    if(kaccount==account){
        if(kcode==code){
        printf("��ȷ\n");
        Sleep(500);
        system("cls");
        return 1;        
    }else{
        printf("�������\n");               //����������������
        Sleep(500);
        system("cls");
        menu2();
        goto Input;
        }
    }else{
        system("cls");
        menu15();
        do{
            if((ch=getch())==27){         //�˻������ڿ�ѡ�����µ�¼�򷵻�����һ������
            return 0;
        }else if(ch==13){
            system("cls");
            menu2();
            goto Input;
            }
        }while(ch!=27||ch!=13);
    }
    fclose(fp);
}



int mana_account_check()        //��ʦϵͳ��¼��֤
{
    FILE *fp;
    long long account,code,kaccount,kcode;
    char ch;
    Input:
    scanf("%lld",&account);
    system("cls");
    menu5(account);
    scanf("%lld",&code);

    fp=fopen("./Accounts/mana_account.txt","r");
    do{
        fscanf(fp,"%lld",&kaccount);
        fscanf(fp,"%lld",&kcode);
        if(feof(fp)!=0){
            break;
        }
        }while(kaccount!=account);
    
    if(kaccount==account){
        if(kcode==code){
        printf("��ȷ\n");
        Sleep(500);
        system("cls");
        return 1;
    }else{
        printf("�������\n");
        Sleep(500);
        system("cls");
        menu2();
        goto Input;
        }
    }else{
        system("cls");
        menu15();
        if((ch=getch())==27){
            return 0;
        }else if(ch==13){
            system("cls");
            menu2();
            goto Input;
        }
    }
}