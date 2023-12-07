//ţ���� HJ43�Թ�����
//����һ����ά���� N*M ������ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�
//Ҫ�������ҳ������Ͻǵ����½ǵ�·�ߡ���ڵ�Ϊ[0,0],�ȵ�һ���ǿ����ߵ�·��
#include "Stack.h"



bool IsPass(int** arr, int row, int col, PT pos) {
    if (pos.row >= 0 && pos.col >= 0 && pos.row < row && pos.col < col &&
        arr[pos.row][pos.col] == 0) {
        return true;
    }
    else {
        return false;
    }

}

ST path;

bool GetMazePath(int** arr, int row, int col, PT cur) {

    StackPush(&path, cur);
    //����ߵ�����
    if (cur.row == row - 1 && cur.col == col - 1) {
        return true;
    }
    //̽��curλ�õ����������ĸ�����
    PT next;
    arr[cur.row][cur.col] = 2;

    //��
    next = cur;
    next.row -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    //��
    next = cur;
    next.row += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    //��
    next = cur;
    next.col -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    //��
    next = cur;
    next.col += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    StackPop(&path);
    return false;
}

//���ջ���������·��
void PrintPath()
{
    ST st;
    StackInit(&st);
    while (!StackEmpty(&path))
    {
        StackPush(&st, StackTop(&path));
        StackPop(&path);
    }
    while (!StackEmpty(&st))
    {
        PT top = StackTop(&st);
        printf("(%d,%d)\n", top.row, top.col);
        StackPop(&st);
    }
    StackDestory(&st);

}

int main() {
    int row, col;
    scanf("%d%d", &row, &col);
    int** arr = (int**)malloc(sizeof(int*) * row);
    if (arr == NULL)
    {
        exit(-1);
    }
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * col);
        
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }


    StackInit(&path);

    PT entry = { 0, 0 };
    if (GetMazePath(arr, row, col, entry))
    {
        PrintPath();
    }

    StackDestory(&path);
    for (int i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}


//ţ���� DD3�����Թ�
//С������һ�첻С��������һ�������Թ�, С����ϣ�����Լ���ʣ������ֵP������������Թ���Ϊ���������, 
//��������һ��n* m�ĸ����Թ�, �Թ�ÿ��λ��Ϊ0����1, 0�������λ�����ϰ���, С���ܴﵽ�������λ��; 
//1����С���ܿ��Դﵽ��λ�á�С���ܳ�ʼ��(0, 0)λ��, �����Թ��ĳ�����(0, m - 1)(��֤������λ�ö���1, 
//���ұ�֤һ������㵽�յ�ɴ��·��), С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ, 
//������һ����λ������Ҫ����3����λ������ֵ, �����ƶ�����������ֵ, ��С���ܵ�����ֵ����0��ʱ��û�е������, 
//С���ܽ��޷������Թ���������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0, m - 1)λ��)��
//����������
//�������n + 1��:
//��һ��Ϊ��������n, m(3 <= m, n <= 10), P(1 <= P <= 100)
//��������n�� :
//    ÿ��m��0����1, �Կո�ָ�
//    ���������
//    ����������Թ�, �����һ������������С��·��, �����ʽ��������ʾ; ������������Թ�, 
//    �����"Can not escape!"�� �������ݱ�֤��Ψһ

bool IsPass(int** arr, int row, int col, PT pos) {
    if (pos.row >= 0 && pos.col >= 0 && pos.row < row && pos.col < col &&
        arr[pos.row][pos.col] == 1) {
        return true;
    }
    else {
        return false;
    }

}

ST path;

bool GetMazePath(int** arr, int row, int col, PT cur, int power) {
    if (power < 0)
        return false;
    StackPush(&path, cur);

    //����ߵ�����
    if (cur.row == 0 && cur.col == col - 1) {
        return true;
    }

    //̽��curλ�õ����������ĸ�����
    PT next;
    arr[cur.row][cur.col] = 2;

    //��
    next = cur;
    next.col -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power - 1))
            return true;
    }

    //��
    next = cur;
    next.col += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power - 1))
            return true;
    }

    //��
    next = cur;
    next.row -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power - 3))
            return true;
    }

    //��
    next = cur;
    next.row += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power))
            return true;
    }

    StackPop(&path);
    return false;
}

//���ջ���������·��
void PrintPath(ST* ps) {
    ST st;
    StackInit(&st);
    while (!StackEmpty(ps)) {
        StackPush(&st, StackTop(ps));
        StackPop(ps);
    }
    while (StackSize(&st) > 1) {
        PT top = StackTop(&st);
        printf("[%d,%d],", top.row, top.col);
        StackPop(&st);
    }
    PT top = StackTop(&st);
    printf("[%d,%d]", top.row, top.col);
    StackPop(&st);
    StackDestory(&st);

}

int main() {
    int row, col, power;
    scanf("%d%d%d", &row, &col, &power);
    int** arr = (int**)malloc(sizeof(int*) * row);

    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(sizeof(int) * col);

    }
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }


    StackInit(&path);

    PT entry = { 0, 0 };
    if (GetMazePath(arr, row, col, entry, power)) {
        PrintPath(&path);
    }
    else {
        printf("Can not escape!");
    }

    StackDestory(&path);
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}



//��ȷ����

void StackCopy(ST* source, ST* dest)
{
    //StackInit(pminpath);
    /*for(int i = 0;i<ppath->top;i++)
    {
        StackPush(pminpath, ppath->_a[i]);
    }*/
    dest->_a = (STDataType*)malloc(sizeof(STDataType) * source->capacity);
    memcpy(dest->_a, source->_a, sizeof(STDataType) * source->capacity);
    dest->capacity = source->capacity;
    dest->top = source->top;
}




int StackEmpty(ST* ps) {
    assert(ps);
    return ps->top == 0;

}


bool IsPass(int** arr, int row, int col, PT pos) {
    if (pos.row >= 0 && pos.col >= 0 && pos.row < row && pos.col < col &&
        arr[pos.row][pos.col] == 1) {
        return true;
    }
    else {
        return false;
    }

}

ST path;
ST minpath;

void GetMazePath(int** arr, int row, int col, PT cur, int power) {
    StackPush(&path, cur);

    //����ߵ����� 
    if (cur.row == 0 && cur.col == col - 1) {
        //����ҵ��˸��̵�·���͸���minpath
        if (power >= 0 && StackEmpty(&minpath) || StackSize(&path) < StackSize(&minpath))
        {
            StackDestory(&minpath);
            StackCopy(&path, &minpath);
        }
    }

    //̽��curλ�õ����������ĸ�����
    PT next;
    arr[cur.row][cur.col] = 2;

    //��
    next = cur;
    next.col -= 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power - 1);
    }

    //��
    next = cur;
    next.col += 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power - 1);
    }

    //��
    next = cur;
    next.row -= 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power - 3);
    }

    //��
    next = cur;
    next.row += 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power);
    }

    //�ָ�һ��
    arr[cur.row][cur.col] = 1;

    StackPop(&path);

}

//���ջ���������·��
void PrintPath(ST* ps) {
    ST st;
    StackInit(&st);
    while (!StackEmpty(ps)) {
        StackPush(&st, StackTop(ps));
        StackPop(ps);
    }
    while (StackSize(&st) > 1) {
        PT top = StackTop(&st);
        printf("[%d,%d],", top.row, top.col);
        StackPop(&st);
    }
    PT top = StackTop(&st);
    printf("[%d,%d]", top.row, top.col);
    StackPop(&st);
    StackDestory(&st);

}

int main() {
    int row, col, power;
    scanf("%d%d%d", &row, &col, &power);
    int** arr = (int**)malloc(sizeof(int*) * row);

    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(sizeof(int) * col);

    }
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }


    StackInit(&path);
    StackInit(&minpath);
    PT entry = { 0, 0 };
    GetMazePath(arr, row, col, entry, power);

    if (!StackEmpty(&minpath))
    {
        PrintPath(&minpath);
    }
    else {
        printf("Can not escape!\n");
    }


    StackDestory(&path);
    StackDestory(&minpath);
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}