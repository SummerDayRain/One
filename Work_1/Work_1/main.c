//
//  main.c
//  Work_1
//
//  Created by qianfeng on 15-7-18.
//  Copyright (c) 2015年 qianfeng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    //动态开辟二维数组
    int index = 0;
    printf("请输入你要打印的行数");
    scanf("%d",&index);
    int **array,i,j;
    array=(int**)malloc(index*sizeof(int*));
    for(i=0;i<index; i++)
    {
        array[i]=(int*)malloc( index* sizeof(int));
    }
    int number = 1;
    int flag = 0;
    if(index%2 == 1) flag = 1;
    
    //进行转圈赋值
    for(int circle = 0; circle <= index/2 + flag - 1; circle ++)
    {
        //上边
        for(i = 0 + circle; i < index - circle ; i++)
        {
            
            array[0 + circle][i] = number++;
        }
        
        //右边
        for(i = 1 + circle ; i < index - circle ; i++)
        {
            
            array[i][index - 1 - circle ] = number++;
        }
        
        //下边
        for(i = index - 2 - circle  ; i >= 0 + circle ; i--)
        {
            
            array[index - 1 - circle][i ] = number++;
        }
        
        //左边
        for(i = index - 2 - circle; i > 0 + circle; i--)
        {
            array[i ][0 + circle] = number++;
        }
        
    }
    
    printf("结果为:\n");
    for(i = 0; i < index ; i++)
    {
        for(j = 0; j < index ; j ++)
        {
            printf("%4d",array[i][j]);
        }
        printf("\n");
    }
    free(array);
    return 0;
}