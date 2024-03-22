
/* 베이스로 들어가는 비교 함수 */
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

/* 사용 방법 */
qsort(배열, 원소 개수, sizeof(원소), compare);