#ifndef HOTAL_H_INCLUDED
#define HOTAL_H_INCLUDED

#define HOTAL1 872.0    //各家酒店的默认房费
#define HOTAL2 1838.0
#define HOTAL3 789.0
#define HOTAL4 1658.0
#define DISCOUNT 0.95   //折扣率

//菜单函数：显示菜单选项，接收并返回用户的输入
int Menu(void);
//返回用预定的天数
int GetNights(void);
//根据入住的天数和房间单价显示最终需要支付的金额
void ShowPrice(int nights, double price);

#endif // HOTAL_H_INCLUDED