#pragma once
#include "WinDef.h"
typedef int INT32;
class CDesOperate
{
private:
	ULONG32 m_arrOutKey[16][2];//16�ֵ�����Կ
	ULONG32 m_arrBufKey[2];
	INT32 HandleData(ULONG32 *left, short choice);//ִ��һ�������ļ��ܻ���ܲ���
	INT32 MakeData(ULONG32 *left, ULONG32 *right, ULONG32 number);//ʵ��16�ּ��ܻ���ܵ����е�ÿһ�֣���ȥ��ʼ�û������ʼ�û�
	INT32 MakeKey(ULONG32 *keyleft, ULONG32 *keyright, ULONG32 number);//�γ�16����Կ�е�ÿһ������Կ
	INT32 MakeFirstKey(ULONG32 *keyP);//�����û�����ĳ�ʼ��Կ�����γ�16�������õ�������Կ
public:
	CDesOperate();//���캯��
	~CDesOperate();//��������
	INT32 Encry(char* pPlaintext, int nPlaintextLength, char *pCipherBuffer,
		int &nCipherBufferLength, char *pKey, int nKeyLength);//��ĳһ���ַ�����
	INT32 Decry(char* pCipher, int nCipherBufferLength, char *pPlaintextBuffer,
		int &nPlaintextBufferLength, char *pKey, int nKeyLength);//��ĳһ�����Ľ���
};
