// write a program to create a student record (sno, sname, marks,grade (to be generated by you))
// and find the grade according to marks and insert into the record. 
// Make a list of n students and sort them based on marks in descending order and print the result.

#include <stdio.h>
#include <string.h>

struct student
{
    int sno;
    char sname[100];
    int marks[4];
    char grade;
};

void readStudent(struct student *s)
{
    int i;
    printf("Enter the student details:\n");
    printf("Sno: ");
    scanf("%d", &s->sno);
    printf("Sname: ");
    scanf("%s", s->sname);
    printf("Marks: ");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &s->marks[i]);
    }
}

void calculateGrade(struct student *s)
{
    int i, sum = 0;
    for (i = 0; i < 4; i++)
    {
        sum += s->marks[i];
    }
    if (sum >= 360)
    {
        s->grade = 'A';
    }
    else if (sum >= 300)
    {
        s->grade = 'B';
    }
    else if (sum >= 240)
    {
        s->grade = 'C';
    }
    else if (sum >= 180)
    {
        s->grade = 'D';
    }
    else if (sum >= 120)
    {
        s->grade = 'E';
    }
    else
    {
        s->grade = 'F';
    }
}

// arrange students in descending order of total marks
void arrangeStudents(struct student s[], int n)
{
    int i, j;
    struct student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (s[j].marks[0] + s[j].marks[1] + s[j].marks[2] + s[j].marks[3] < s[j + 1].marks[0] + s[j + 1].marks[1] + s[j + 1].marks[2] + s[j + 1].marks[3])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void printStudent(struct student s)
{
    int i;
    printf("Sno: %d\n", s.sno);
    printf("Sname: %s\n", s.sname);
    printf("Marks: ");
    for (i = 0; i < 4; i++)
    {
        printf("%d ", s.marks[i]);
    }
    printf("\n");
    printf("Grade: %c\n", s.grade);
}

int main()
{
    int n, i;
    struct student s[100];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        readStudent(&s[i]);
        calculateGrade(&s[i]);
    }
    arrangeStudents(s, n);
    printf("\nThe students in descending order of marks are:\n");
    for (i = 0; i < n; i++)
    {
        printStudent(s[i]);
    }
    return 0;
}