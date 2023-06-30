#include "./Headers/Everything.h"

int addinfo(student *(*Head),int length,int add)
{
    for(int p=0;p<add;p++){
        system("cls");
        menu9();
        scanf("%s",Head[length+p]->name);
        system("cls");
        menu10(Head[length+p]->name,Head[length+p]->num,Head[length+p]->sex,Head[length+p]->score);
       
        scanf("%lld",&(Head[length+p]->num));
        system("cls");
        menu11(Head[length+p]->name,Head[length+p]->num,Head[length+p]->sex,Head[length+p]->score);
        
        scanf("%s",(Head[length+p]->sex));
        system("cls");
        menu12(Head[length+p]->name,Head[length+p]->num,Head[length+p]->sex,Head[length+p]->score);
        
        scanf("%lf",&(Head[length+p]->score));
        system("cls");
        menu13(Head[length+p]->name,Head[length+p]->num,Head[length+p]->sex,Head[length+p]->score);
    }

    Sqrt(Head,length+add);

    return (length+add);
}

void deleteinfo(student *(*Head),int length,long long num)
{
    student *findp=NULL;
    getf(Head,length);
    findp=Ddf(Head,length,num);
    if(findp==NULL){
        printf("查无此学生\n");
    }else{
        memset(findp,0,LEN);
        printf("已成功清除\n");
    }
}

void modifyinfo(student *(*Head),int length,long long wnum)
{   
    student *findp=NULL;
    findp=Ddf(Head,length,wnum);
    system("cls");
    menu9();
    scanf("%s",findp->name);
    system("cls");
    menu10(findp->name,findp->num,findp->sex,findp->score);
       
    scanf("%lld",&(findp->num));
    system("cls");
    menu11(findp->name,findp->num,findp->sex,findp->score);
        
    scanf("%s",(findp->sex));
    system("cls");
    menu12(findp->name,findp->num,findp->sex,findp->score);
        
    scanf("%lf",&(findp->score));
    system("cls");
    menu13(findp->name,findp->num,findp->sex,findp->score);

    savef(Head,length,length);

}
