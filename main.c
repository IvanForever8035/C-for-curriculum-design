#include "./Headers/Everything.h"

int main()
{   
    startup();

    /*为文本的初始化，读取文本数据的组数，创建相对应
    的结构体并将各个结构体的指针放到一个数组中   ~by GIT  */
    student *(*name_array)=NULL;
    int len_array=0;
    FILE *fp;
    fp=fopen("studata.txt","r");
    
    fscanf(fp,"%d",&len_array);

    name_array=(struct _Stu**)malloc( len_array*sizeof(struct _Stu*));

    for(int n=0;n<=len_array-1;n++)
    {
        name_array[n]=(struct _Stu*)malloc(sizeof(struct _Stu));
    }
    fclose(fp);
    
    printf("初始化成功！\n\n");


    /*建立好数组后开始进行对所想功能的调用*/
    int choice,feedback;

Choice:
    menu14();
    getchar();
    system("cls");
    menu1();                   //选择系统：学生or老师
    
    do{
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            goto Tree1;
            break;
        case 2:
            goto Tree2;
            break;
        default:
            printf("不是正确的选项\n");
        }
    }while(choice!=1&&choice!=2);

Tree1:                                                 //学生系统的操作
    system("cls");
    stu_account();
    menu2();
    feedback=stu_account_check();                      //检验学生账户
    if(feedback==0){
        goto Choice;                                   //不想登录则返回到选择系统界面
    }
    else if(feedback==1){
        do {                                           //登录成功后进入学生系统
                menu4();
                int choice;
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        system("cls");
                        printf("\n=====浏览所有学生信息=====\n");

                        fp=fopen("studata.txt","r");
                        fscanf(fp,"%d",&len_array);
                        fclose(fp);
                        getf(name_array,len_array);
                        
                        if(len_array==0){
                            printf("表中无数据\n");
                        }else{
                            show_all(name_array,len_array);
                        }

                        break;

                    case 2:
                        system("cls");
                        printf("\n=====查询学生信息=====\n");
                        
                        fp=fopen("studata.txt","r");
                        fscanf(fp,"%d",&len_array);
                        fclose(fp);
                        getf(name_array,len_array);
                        
                        student *wstu=NULL;
                        long long num;
                        printf("输入所查学生的学号：");
                        scanf("%lld",&num);
                        show_per(name_array,len_array,num);

                        break;

                    case 0:
                        system("cls");
                        printf("欢迎下次使用,再见!\n");

                        Sleep(500);

                        printf("\n按任意键结束。\n");
                        getch();
                        return 0;

                        default:
                        system("cls");
                        printf("\n输入错误,请重新选择操作!\n");
                        
                        break;
                    }       
                printf("\n按任意键可返回主菜单。\n");
                getch();
                system("cls");
            } while(1);
    }else{
        printf("Something went wrong.\n");           //防止feedback出现其他数值导致混乱（大概率不会出现）
        exit(0);
    }
    

Tree2:                                                //老师系统的操作
    system("cls");
    mana_account();
    menu2();
    feedback=mana_account_check();
    if(feedback==0){
        goto Choice;
    }
    else if(feedback==1){
        do {
            menu3();
            int choice;
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    system("cls");
                    printf("\n=====浏览所有学生信息=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);
                    getf(name_array,len_array);
                    
                    if(len_array==0){
                        printf("表中无数据\n");
                    }else{
                        show_all(name_array,len_array);
                    }

                    break;

                case 2:
                    system("cls");
                    printf("\n=====新建学生信息=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);

                    printf("想添加的人数：");
                    int add;
                    scanf("%d",&add);

                    for(int n=0;n<=len_array-1;n++)
                    {
                        printf("free %dinternal",n);
                        free(name_array[n]);
                    }
                    free(name_array);      //因为是新建，所以要对原本的数组空间进行重新分配
                    name_array=(struct _Stu**)malloc( (len_array+add)*sizeof(struct _Stu*));

                    for(int n=0;n<=len_array+add-1;n++)
                    {
                        name_array[n]=(struct _Stu*)malloc(sizeof(struct _Stu));
                    }
                    getf(name_array,len_array);

                    int length=addinfo(name_array,len_array,add);
                    savef(name_array,length,length);

                    break;

                case 3:
                    system("cls");
                    printf("\n=====查询学生信息=====\n");

                    getf(name_array,len_array);

                    if(len_array==0){
                        printf("表中无数据\n");
                    }else{
                        long long num;
                        printf("输入所查学生的学号：");
                        scanf("%lld",&num);
                        show_per(name_array,len_array,num);
                    }

                    break;

                case 4:
                    system("cls");
                    printf("\n=====修改学生信息=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);

                    getf(name_array,len_array);

                     if(len_array==0){
                        printf("表中无数据\n");
                    }else{
                    long long wnum;
                    printf("输入想要修改信息的学号：");
                    scanf("%lld",&wnum);

                    modifyinfo(name_array,len_array,wnum);

                    printf("修改成功！\n");
                    }

                    break;

                case 5:
                    system("cls");
                    printf("\n=====删除学生信息=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);

                    getf(name_array,len_array);

                    printf("输入所查学生的学号：");

                    if(len_array==0){
                        printf("表中无数据\n");
                    }else{
                        long long fnum;
                        scanf("%lld",&fnum);
                        deleteinfo(name_array,len_array,fnum);
                        savef(name_array,len_array,len_array-1);
                    }

                        break;

                case 0:
                    system("cls");
                    printf("欢迎下次使用,再见!\n");

                    Sleep(500);

                    printf("\n按任意键结束。\n");
                    getch();
                    return 0;

                default:
                    system("cls");
                    printf("\n输入错误,请重新选择操作!\n");
                    break;
            }

            while(1) {
                printf("\n按任意键可返回主菜单。\n");
                if(getch()) break;
            }
            system("cls");
        } while(1);
    }    
    return 0;
}