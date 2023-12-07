//牛客网 HJ43迷宫问题
//定义一个二维数组 N*M ，它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，
//要求编程序找出从左上角到右下角的路线。入口点为[0,0],既第一格是可以走的路。
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
    //如果走到出口
    if (cur.row == row - 1 && cur.col == col - 1) {
        return true;
    }
    //探测cur位置的上下左右四个方向
    PT next;
    arr[cur.row][cur.col] = 2;

    //上
    next = cur;
    next.row -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    //下
    next = cur;
    next.row += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    //左
    next = cur;
    next.col -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    //右
    next = cur;
    next.col += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next))
            return true;
    }

    StackPop(&path);
    return false;
}

//输出栈里面的坐标路径
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


//牛客网 DD3地下迷宫
//小青蛙有一天不小心落入了一个地下迷宫, 小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单, 
//假设这是一个n* m的格子迷宫, 迷宫每个位置为0或者1, 0代表这个位置有障碍物, 小青蛙达到不了这个位置; 
//1代表小青蛙可以达到的位置。小青蛙初始在(0, 0)位置, 地下迷宫的出口在(0, m - 1)(保证这两个位置都是1, 
//并且保证一定有起点到终点可达的路径), 小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值, 
//向上爬一个单位距离需要消耗3个单位的体力值, 向下移动不消耗体力值, 当小青蛙的体力值等于0的时候还没有到达出口, 
//小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0, m - 1)位置)。
//输入描述：
//输入包括n + 1行:
//第一行为三个整数n, m(3 <= m, n <= 10), P(1 <= P <= 100)
//接下来的n行 :
//    每行m个0或者1, 以空格分隔
//    输出描述：
//    如果能逃离迷宫, 则输出一行体力消耗最小的路径, 输出格式见样例所示; 如果不能逃离迷宫, 
//    则输出"Can not escape!"。 测试数据保证答案唯一

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

    //如果走到出口
    if (cur.row == 0 && cur.col == col - 1) {
        return true;
    }

    //探测cur位置的上下左右四个方向
    PT next;
    arr[cur.row][cur.col] = 2;

    //左
    next = cur;
    next.col -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power - 1))
            return true;
    }

    //右
    next = cur;
    next.col += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power - 1))
            return true;
    }

    //上
    next = cur;
    next.row -= 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power - 3))
            return true;
    }

    //下
    next = cur;
    next.row += 1;
    if (IsPass(arr, row, col, next)) {

        if (GetMazePath(arr, row, col, next, power))
            return true;
    }

    StackPop(&path);
    return false;
}

//输出栈里面的坐标路径
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



//正确代码

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

    //如果走到出口 
    if (cur.row == 0 && cur.col == col - 1) {
        //如果找到了更短的路径就更新minpath
        if (power >= 0 && StackEmpty(&minpath) || StackSize(&path) < StackSize(&minpath))
        {
            StackDestory(&minpath);
            StackCopy(&path, &minpath);
        }
    }

    //探测cur位置的上下左右四个方向
    PT next;
    arr[cur.row][cur.col] = 2;

    //左
    next = cur;
    next.col -= 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power - 1);
    }

    //右
    next = cur;
    next.col += 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power - 1);
    }

    //上
    next = cur;
    next.row -= 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power - 3);
    }

    //下
    next = cur;
    next.row += 1;
    if (IsPass(arr, row, col, next)) {

        GetMazePath(arr, row, col, next, power);
    }

    //恢复一下
    arr[cur.row][cur.col] = 1;

    StackPop(&path);

}

//输出栈里面的坐标路径
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