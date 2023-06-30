#include "./Headers/Everything.h"

/*
    包含：
    1.Swts——数组内容交换函数
    2.Sqrt——快速排序函数
    3.Ddf——二分查找函数
    注意：
    下列函数针对的是：内容为指向结构的指针的数组（下面备注对此句话的引用标识为：1‘）
    即：array[]=p,*p=struct
    ———— by GIT 2023.4.17
*/

void Swt(struct _Stu *(*a),struct _Stu *(*b))   //此为对 1’其内容（即指针）的交换函数
{
    struct _Stu *s=NULL;                        //s为中间介质变量
    s=*b;
    *b=*a;
    *a=s;
}

void Sqrt(struct _Stu *(name_array[]),int len_array)         //此为对 1‘其内容的快速排序函数；且排序的参考对象是_Stu.num（即学号）
{
    if(len_array>1)
    {
        int slider=0;                   //slider即滑块，一个进行遍历的指针
        int standard=len_array-1;     //standard是本次比较选取的比较标准；在一次遍历后，standard必定在其正确位置
        int i_smaller=0;                                     //这个i指的是小于*(*standard)).num的个数,比较出一个小于的加一，从0开始记
        while(slider<standard)                               //这个循环是快速找到大于*(*standard)).num的第一个数                       
        {
            if(((name_array[slider])->num)>((name_array[standard])->num))          //找到了就进入if里面
            {
               int border=slider;               //border指的是大于*(*standard)).num和小于其的分界线，坐落于大于其的第一位的上面

                for(;slider<standard;slider++)               //这个for是设定好border后再往后找有没有小于的数，有的话就挪到前面
                {
                    if(((name_array[slider])->num)<((name_array[standard])->num))
                    {
                        Swt(name_array+slider,name_array+border);                  //slider（指向所找到的那个小的数）与现在的border进行数值交换
                        
                        border++;                            //加完后border挪到下一位，以符合自己的定义
                        i_smaller++;                         //因为有小于的数存在，所以i加一
                    }
                }

                Swt(name_array+standard,name_array+border);                        //最后把放在末尾（放末尾可以与其它数据隔离，避免遍历对其的影响）的standard放在正确位置
                standard=border;
                break;                                       //如果进入了if就说明while完成了它的使命，直接跳出
            }
            slider++;
            i_smaller++;                                    //因为有小于的数存在，所以i加一
        }

        Sqrt(name_array,i_smaller);                         //sqrt的精髓：递归
        Sqrt(name_array+standard+1,len_array-i_smaller-1);
    }
}

struct _Stu * Ddf(struct _Stu *(name_array[]),int len_array,long long number)   //二分查找函数
{
    if(number<((name_array[0])->num)||number>((name_array[len_array-1])->num))  //判断有没有在最大最小值之内
    {
        return NULL;
    }
    else if(((name_array[0])->num)==number)                                     //判断是否是最大最小值
    {
        return name_array[0];
    }
    else if(((name_array[len_array-1])->num)==number)
    {
        return name_array[len_array-1];
    }
    else                                                                        //取中值
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

        return NULL;                                                            //若还是没找到，返回NULL
    }
}