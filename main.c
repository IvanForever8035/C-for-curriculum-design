#include "./Headers/Everything.h"

int main()
{   
    startup();

    /*Ϊ�ı��ĳ�ʼ������ȡ�ı����ݵ��������������Ӧ
    �Ľṹ�岢�������ṹ���ָ��ŵ�һ��������   ~by GIT  */
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
    
    printf("��ʼ���ɹ���\n\n");


    /*�����������ʼ���ж����빦�ܵĵ���*/
    int choice,feedback;

Choice:
    menu14();
    getchar();
    system("cls");
    menu1();                   //ѡ��ϵͳ��ѧ��or��ʦ
    
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
            printf("������ȷ��ѡ��\n");
        }
    }while(choice!=1&&choice!=2);

Tree1:                                                 //ѧ��ϵͳ�Ĳ���
    system("cls");
    stu_account();
    menu2();
    feedback=stu_account_check();                      //����ѧ���˻�
    if(feedback==0){
        goto Choice;                                   //�����¼�򷵻ص�ѡ��ϵͳ����
    }
    else if(feedback==1){
        do {                                           //��¼�ɹ������ѧ��ϵͳ
                menu4();
                int choice;
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        system("cls");
                        printf("\n=====�������ѧ����Ϣ=====\n");

                        fp=fopen("studata.txt","r");
                        fscanf(fp,"%d",&len_array);
                        fclose(fp);
                        getf(name_array,len_array);
                        
                        if(len_array==0){
                            printf("����������\n");
                        }else{
                            show_all(name_array,len_array);
                        }

                        break;

                    case 2:
                        system("cls");
                        printf("\n=====��ѯѧ����Ϣ=====\n");
                        
                        fp=fopen("studata.txt","r");
                        fscanf(fp,"%d",&len_array);
                        fclose(fp);
                        getf(name_array,len_array);
                        
                        student *wstu=NULL;
                        long long num;
                        printf("��������ѧ����ѧ�ţ�");
                        scanf("%lld",&num);
                        show_per(name_array,len_array,num);

                        break;

                    case 0:
                        system("cls");
                        printf("��ӭ�´�ʹ��,�ټ�!\n");

                        Sleep(500);

                        printf("\n�������������\n");
                        getch();
                        return 0;

                        default:
                        system("cls");
                        printf("\n�������,������ѡ�����!\n");
                        
                        break;
                    }       
                printf("\n��������ɷ������˵���\n");
                getch();
                system("cls");
            } while(1);
    }else{
        printf("Something went wrong.\n");           //��ֹfeedback����������ֵ���»��ң�����ʲ�����֣�
        exit(0);
    }
    

Tree2:                                                //��ʦϵͳ�Ĳ���
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
                    printf("\n=====�������ѧ����Ϣ=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);
                    getf(name_array,len_array);
                    
                    if(len_array==0){
                        printf("����������\n");
                    }else{
                        show_all(name_array,len_array);
                    }

                    break;

                case 2:
                    system("cls");
                    printf("\n=====�½�ѧ����Ϣ=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);

                    printf("����ӵ�������");
                    int add;
                    scanf("%d",&add);

                    for(int n=0;n<=len_array-1;n++)
                    {
                        printf("free %dinternal",n);
                        free(name_array[n]);
                    }
                    free(name_array);      //��Ϊ���½�������Ҫ��ԭ��������ռ�������·���
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
                    printf("\n=====��ѯѧ����Ϣ=====\n");

                    getf(name_array,len_array);

                    if(len_array==0){
                        printf("����������\n");
                    }else{
                        long long num;
                        printf("��������ѧ����ѧ�ţ�");
                        scanf("%lld",&num);
                        show_per(name_array,len_array,num);
                    }

                    break;

                case 4:
                    system("cls");
                    printf("\n=====�޸�ѧ����Ϣ=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);

                    getf(name_array,len_array);

                     if(len_array==0){
                        printf("����������\n");
                    }else{
                    long long wnum;
                    printf("������Ҫ�޸���Ϣ��ѧ�ţ�");
                    scanf("%lld",&wnum);

                    modifyinfo(name_array,len_array,wnum);

                    printf("�޸ĳɹ���\n");
                    }

                    break;

                case 5:
                    system("cls");
                    printf("\n=====ɾ��ѧ����Ϣ=====\n");

                    fp=fopen("studata.txt","r");
                    fscanf(fp,"%d",&len_array);
                    fclose(fp);

                    getf(name_array,len_array);

                    printf("��������ѧ����ѧ�ţ�");

                    if(len_array==0){
                        printf("����������\n");
                    }else{
                        long long fnum;
                        scanf("%lld",&fnum);
                        deleteinfo(name_array,len_array,fnum);
                        savef(name_array,len_array,len_array-1);
                    }

                        break;

                case 0:
                    system("cls");
                    printf("��ӭ�´�ʹ��,�ټ�!\n");

                    Sleep(500);

                    printf("\n�������������\n");
                    getch();
                    return 0;

                default:
                    system("cls");
                    printf("\n�������,������ѡ�����!\n");
                    break;
            }

            while(1) {
                printf("\n��������ɷ������˵���\n");
                if(getch()) break;
            }
            system("cls");
        } while(1);
    }    
    return 0;
}