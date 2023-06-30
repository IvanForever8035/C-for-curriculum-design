#include "./Headers/Everything.h"

/*
    ������
    1.Swts�����������ݽ�������
    2.Sqrt��������������
    3.Ddf�������ֲ��Һ���
    ע�⣺
    ���к�����Ե��ǣ�����Ϊָ��ṹ��ָ������飨���汸ע�Դ˾仰�����ñ�ʶΪ��1����
    ����array[]=p,*p=struct
    �������� by GIT 2023.4.17
*/

void Swt(struct _Stu *(*a),struct _Stu *(*b))   //��Ϊ�� 1�������ݣ���ָ�룩�Ľ�������
{
    struct _Stu *s=NULL;                        //sΪ�м���ʱ���
    s=*b;
    *b=*a;
    *a=s;
}

void Sqrt(struct _Stu *(name_array[]),int len_array)         //��Ϊ�� 1�������ݵĿ�����������������Ĳο�������_Stu.num����ѧ�ţ�
{
    if(len_array>1)
    {
        int slider=0;                   //slider�����飬һ�����б�����ָ��
        int standard=len_array-1;     //standard�Ǳ��αȽ�ѡȡ�ıȽϱ�׼����һ�α�����standard�ض�������ȷλ��
        int i_smaller=0;                                     //���iָ����С��*(*standard)).num�ĸ���,�Ƚϳ�һ��С�ڵļ�һ����0��ʼ��
        while(slider<standard)                               //���ѭ���ǿ����ҵ�����*(*standard)).num�ĵ�һ����                       
        {
            if(((name_array[slider])->num)>((name_array[standard])->num))          //�ҵ��˾ͽ���if����
            {
               int border=slider;               //borderָ���Ǵ���*(*standard)).num��С����ķֽ��ߣ������ڴ�����ĵ�һλ������

                for(;slider<standard;slider++)               //���for���趨��border������������û��С�ڵ������еĻ���Ų��ǰ��
                {
                    if(((name_array[slider])->num)<((name_array[standard])->num))
                    {
                        Swt(name_array+slider,name_array+border);                  //slider��ָ�����ҵ����Ǹ�С�����������ڵ�border������ֵ����
                        
                        border++;                            //�����borderŲ����һλ���Է����Լ��Ķ���
                        i_smaller++;                         //��Ϊ��С�ڵ������ڣ�����i��һ
                    }
                }

                Swt(name_array+standard,name_array+border);                        //���ѷ���ĩβ����ĩβ�������������ݸ��룬������������Ӱ�죩��standard������ȷλ��
                standard=border;
                break;                                       //���������if��˵��while���������ʹ����ֱ������
            }
            slider++;
            i_smaller++;                                    //��Ϊ��С�ڵ������ڣ�����i��һ
        }

        Sqrt(name_array,i_smaller);                         //sqrt�ľ��裺�ݹ�
        Sqrt(name_array+standard+1,len_array-i_smaller-1);
    }
}

struct _Stu * Ddf(struct _Stu *(name_array[]),int len_array,long long number)   //���ֲ��Һ���
{
    if(number<((name_array[0])->num)||number>((name_array[len_array-1])->num))  //�ж���û���������Сֵ֮��
    {
        return NULL;
    }
    else if(((name_array[0])->num)==number)                                     //�ж��Ƿ��������Сֵ
    {
        return name_array[0];
    }
    else if(((name_array[len_array-1])->num)==number)
    {
        return name_array[len_array-1];
    }
    else                                                                        //ȡ��ֵ
    {
        int left=0;
        int right=len_array-1;

        do
        {
            int mid=(left+right)/2;

            if(((name_array[mid])->num)==number)
            {
                return name_array[mid];
                break;
            }
            else if(((name_array[mid])->num)>number)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }while(left<=right);

        return NULL;                                                            //������û�ҵ�������NULL
    }
}