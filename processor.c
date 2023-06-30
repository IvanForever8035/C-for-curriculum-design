#include "./Headers/Everything.h"

void getf(student *(*Head),int length)      //从studata.txt文件中获取数据
{
    FILE *fp;
    fp=fopen("studata.txt","r");
    fgetc(fp);
    for(int n=0;n<length;n++){
        fscanf(fp,"%s%lld%s%lf",(Head[n])->name,&(Head[n])->num,(Head[n])->sex,&(Head[n])->score); 
    }

    fclose(fp);
}

void savef(student *(*Head),int length,int volume){      //向studata.txt文件导入数据
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

void show_all(student *(*Head),int length){              //输出studata.txt中所有学生的所有信息
    printf("姓名                      学号                  性别              绩点\n");
    for(int n=0;n<length;n++){
        printf("%s\t%25lld\t%10s%20.2f\n",Head[n]->name,Head[n]->num,Head[n]->sex,Head[n]->score);
    };
}

student show_per(student *(*Head),int length,long long num){  //输出特定某一个人的信息
    student *perp=NULL;

    perp=Ddf(Head,length,num);
    if(perp==NULL){
        printf("查无此人\n");
    }else{
        printf("姓名                      学号                  性别              绩点\n");
        printf("%s\t%25lld\t%10s%20.2f\n",perp->name,perp->num,perp->sex,perp->score);
    }
    
}

int stu_account_check()           //学生系统登录验证
{
    FILE *fp;
    long long account,code,kaccount,kcode;
    char ch;
    Input:
    scanf("%lld",&account);
    system("cls");
    menu5(account);
    scanf("%lld",&code);

    fp=fopen("./Accounts/stu_account.txt","r");      //大体思路：从账户文本中得到用户名和密码
    do{                                              //一一比对，直到符合或读到最后
        fscanf(fp,"%lld",&kaccount);
        fscanf(fp,"%lld",&kcode);
        if(feof(fp)!=0){
            break;
        }
        }while(kaccount!=account);
    
    if(kaccount==account){
        if(kcode==code){
        printf("正确\n");
        Sleep(500);
        system("cls");
        return 1;        
    }else{
        printf("输入错误\n");               //密码错误可重新输入
        Sleep(500);
        system("cls");
        menu2();
        goto Input;
        }
    }else{
        system("cls");
        menu15();
        do{
            if((ch=getch())==27){         //账户不存在可选择重新登录或返回至上一个界面
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



int mana_account_check()        //教师系统登录验证
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
        printf("正确\n");
        Sleep(500);
        system("cls");
        return 1;
    }else{
        printf("输入错误\n");
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