#ifndef HOTAL_H_INCLUDED
#define HOTAL_H_INCLUDED

#define HOTAL1 872.0    //���ҾƵ��Ĭ�Ϸ���
#define HOTAL2 1838.0
#define HOTAL3 789.0
#define HOTAL4 1658.0
#define DISCOUNT 0.95   //�ۿ���

//�˵���������ʾ�˵�ѡ����ղ������û�������
int Menu(void);
//������Ԥ��������
int GetNights(void);
//������ס�������ͷ��䵥����ʾ������Ҫ֧���Ľ��
void ShowPrice(int nights, double price);

#endif // HOTAL_H_INCLUDED