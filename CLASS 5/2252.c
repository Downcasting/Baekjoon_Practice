
// 1509번 - 줄 세우기

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct Student{
    int num;
    int checked;
    struct Student** tallerStudents;
    int tallerStudentsNum;
}Student;

/* Global Var */
/* Function */
Student* makeStudent(int num);
void tallerStudent(Student* a, Student* b);
void printStudents(Student* st);
/* Main */
int main(void){
    int N, M;
    scanf("%d %d",&N, &M);
    Student* clas[N];
    f(i,N)
        clas[i] = makeStudent(i);
    
    int a,b;
    f(i,M){
        scanf("%d %d",&a,&b);
        tallerStudent(clas[a-1], clas[b-1]);
    }
    f(i,N)
        printStudents(clas[i]);
    return 0;
}

/* Functions */
Student* makeStudent(int num){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->num = num;
    newStudent->checked = 0;
    newStudent->tallerStudents = (Student**)malloc(5*sizeof(Student*));
    newStudent->tallerStudentsNum = 0;
    return newStudent;
}
void tallerStudent(Student* a, Student* b){
    b->tallerStudents[b->tallerStudentsNum++] = a;
    if(b->tallerStudentsNum % 5 == 0)
        b->tallerStudents = (Student**) realloc(b->tallerStudents,(b->tallerStudentsNum + 5)*sizeof(Student*));
}
void printStudents(Student* st){
    if(st->checked)
        return;
    f(i,st->tallerStudentsNum)
        printStudents(st->tallerStudents[i]);
    printf("%d ",st->num+1);
    st->checked = 1;
    return;
}