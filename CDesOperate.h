
#pragma once
#include "windows.h"
typedef int INT32;

class CDesOperate
{
public:
	short groupCount;
	short keyArray[16][48];//16�ֵ�����Կ
	short textArray[17][64];//��������
	short ciphArray[17][64];//��������
	INT32 MakeData(char *plaintext);//ʵ��16�ּ��ܻ���ܵ����е�ÿһ�֣���ȥ��ʼ�û������ʼ�û�
	INT32 MakeCiph(short *ciphtext,int k);
	INT32 MakeKey(char *key);//�γ�16����Կ�е�ÿһ������Կ����¼����Ӧ������
public:
	//CDesOperate();//���캯��
	//~CDesOperate();//��������
	int encry(int k);
	int decry(int k);
};
extern CDesOperate op;