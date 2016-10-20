#ifndef __CARRAY_H__
#define __CARRAY_H__

//��̬����ʵ��
#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DEFAULT_A_SIZE 10


	typedef struct _DArray
	{
		int size;
		int count;
		void **data;

	}DArray;


	typedef void(*VisitFunc)(void *ctx, void *data);

	DArray *darray_create();		//������̬����
	static BOOL darray_expand(DArray *darray, int needone);	//����ָ�����������
	BOOL darray_shrink(DArray *darray);	//����ָ�����������
	BOOL darray_preapppend(DArray *darray, void * data);//��ӣ�ͷ��Ԫ��
	BOOL darray_append(DArray *darray, void * data);	//��ӣ�β��Ԫ��
	BOOL darray_insert(DArray *darray, int index, void * data);	//����Ԫ��
	BOOL darray_delete(DArray *darray, int index);	//ɾ��Ԫ��
	int darray_len(DArray * darray);			//���鳤��
	int darray_find(DArray * darray, void * data);			//���ҳ�Ա��һ�γ��ֵ�����
	BOOL darray_isempty(DArray * darray);		//�����Ƿ�Ϊ��
	void darray_empty(DArray * darray);		//�������
	void *darray_getat(DArray * darray, int index);		//ȡָ���±�����
	BOOL darray_set_by_index(DArray *darray, int index, void *data);//�滻����ָ��λ�õ�ֵ
	BOOL darray_foreach(DArray *darray, VisitFunc visitfunc, void *ctx);//��������
	BOOL darray_destroy(DArray *darray);//�ͷ�ָ�������ڴ�

#ifdef __cplusplus
	}
#endif

#endif //__CARRAY_H__
