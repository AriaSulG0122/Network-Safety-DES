#pragma once
#include "windows.h"
typedef int INT32;

class CDesOperate
{
public:
	short m_arrOutKey[16][48];//16�ֵ�����Կ
	ULONG32 m_arrBufKey[2];
	INT32 HandleData(ULONG32 *left, short choice);//ִ��һ�������ļ��ܻ���ܲ���
	INT32 MakeData(ULONG32 *left, ULONG32 *right);//ʵ��16�ּ��ܻ���ܵ����е�ÿһ�֣���ȥ��ʼ�û������ʼ�û�
	INT32 MakeKey(char *key);//�γ�16����Կ�е�ÿһ������Կ����¼����Ӧ������
public:
	//CDesOperate();//���캯��
	//~CDesOperate();//��������
	INT32 Encry(char* pPlaintext, int nPlaintextLength, char *pCipherBuffer,
		int &nCipherBufferLength, char *pKey, int nKeyLength);//��ĳһ���ַ�����
	INT32 Decry(char* pCipher, int nCipherBufferLength, char *pPlaintextBuffer,
		int &nPlaintextBufferLength, char *pKey, int nKeyLength);//��ĳһ�����Ľ���
};
static CDesOperate op;