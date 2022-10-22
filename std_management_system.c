#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[100];
    char sex[10];
    float quiz_1_score;
    float quiz_2_score;
    float mid_term_score;
    float final_score;
    float total_score;

} Student;

// all functions prototype for individual task
void perform_operation(Student students[], int *no_of_students, int *command_number);
void show_messages();
int get_command(int *command_number);
void add_student(Student students[], int *no_of_students, int *command_number);
void delete_student(Student students[], int *no_of_students, int *command_number);
void update_student(Student students[], int *no_of_students, int *command_number);
void calc_avg_selected_std(Student students[], int *no_of_students, int *command_number);
void find_max_score_std(Student students[], int *no_of_students, int *command_number);
void find_min_score_std(Student students[], int *no_of_students, int *command_number);
void find_by_id(Student students[], int *no_of_students, int *command_number);
void sort_by_total_score(Student students[], int *no_of_students, int *command_number);
void view_all_records(Student students[], int *no_of_students, int *command_number);
void operaion(Student students[], int *no_of_students, int *command_number);

int main()
{
    Student allStudent[10] = {0};
    int total_student = 0;
    int command_number;
    printf("\n");
    printf("Welcome to Students management system.\n");
    perform_operation(allStudent, &total_student, &command_number);

    return 0;
}

// show message funcion
void show_messages()
{
    printf("Press 1 to add student in records\n");
    printf("Press 2 to delete student from the record\n");
    printf("Press 3 to update a student's record\n");
    printf("Press 4 to view all student's record\n");
    printf("Press 5 to calculate average of selected student's scores\n");
    printf("Press 6 to view who gets the maximum total\n");
    printf("Press 7 to view who gets the minimum total\n");
    printf("Press 8 to find student by id\n");
    printf("Press 9 to sort records by total scores\n");
}

// get command number funcion
int get_command(int *command_number)
{
    scanf("%d", command_number);
}

// perform operation function
void perform_operation(Student students[], int *no_of_students, int *command_number)

{

    int sign;
    printf("Press 1 to perform any operation to students database.\n");
    printf("Press 0 to exit the program.\n");
    scanf("%d", &sign);

    if (sign == 1)
    {
        show_messages();
        get_command(command_number);
        operaion(students, no_of_students, command_number);
    }
    else
    {
        exit(1);
    }
}

// real operation
void operaion(Student students[], int *no_of_students, int *command_number)
{
    if (*command_number == 1)
    {
        add_student(students, no_of_students, command_number);
    }
    else if (*command_number == 2)
    {
        delete_student(students, no_of_students, command_number);
    }
    else if (*command_number == 3)
    {
        update_student(students, no_of_students, command_number);
    }
    else if (*command_number == 4)
    {
        view_all_records(students, no_of_students, command_number);
    }
    else if (*command_number == 5)
    {
        calc_avg_selected_std(students, no_of_students, command_number);
    }
    else if (*command_number == 6)
    {
        find_max_score_std(students, no_of_students, command_number);
    }
    else if (*command_number == 7)
    {
        find_min_score_std(students, no_of_students, command_number);
    }
    else if (*command_number == 8)
    {
        find_by_id(students, no_of_students, command_number);
    }
    else if (*command_number == 9)
    {
        sort_by_total_score(students, no_of_students, command_number);
    }
}

// add student fuction
void add_student(Student students[], int *no_of_students, int *command_number)
{
    if (*no_of_students < 10)
    {
        Student student;

        printf("Enter Student ID: ");
        scanf("%d", &student.id);

        getchar();
        printf("Enter Student Name: ");
        gets(student.name);

        printf("Enter Student Sex: ");
        gets(student.sex);

        printf("Enter quiz-1 Score: ");
        scanf("%f", &student.quiz_1_score);

        printf("Enter quiz-2 Score: ");
        scanf("%f", &student.quiz_2_score);

        printf("Enter mid-term Score: ");
        scanf("%f", &student.mid_term_score);

        printf("Enter final Score: ");
        scanf("%f", &student.final_score);

        student.total_score = student.quiz_1_score + student.quiz_2_score + student.mid_term_score + student.final_score;

        students[*no_of_students] = student;
        *no_of_students = *no_of_students + 1;

        perform_operation(students, no_of_students, command_number);
    }
    else
    {
        printf("Students list is Full!! already 10 students there\n");

        perform_operation(students, no_of_students, command_number);
    }
}

// delete student funcion
void delete_student(Student students[], int *no_of_students, int *command_number)
{
    int id, i;
    printf("Enter ID of student to delete : ");
    scanf("%d", &id);

    Student filtered_students[10];
    int new_students_index = 0;

    for (i = 0; i < *no_of_students; i++)
    {
        if (students[i].id != id)
        {
            filtered_students[new_students_index] = students[i];
            new_students_index++;
        }
        if (students[i].id == id)
        {
            *no_of_students = *no_of_students - 1;
        }
    }

    students = &filtered_students[0];
    perform_operation(students, no_of_students, command_number);
}

// update student funcion
void update_student(Student students[], int *no_of_students, int *command_number)
{
    int id, i;
    printf("Enter ID of student to update : ");
    scanf("%d", &id);

    for (i = 0; i < *no_of_students; i++)
    {

        if (students[i].id == id)
        {
            printf("Enter Student ID: ");
            scanf("%d", &students[i].id);

            getchar();
            printf("Enter Student Name: ");
            gets(students[i].name);

            printf("Enter Student Sex: ");
            gets(students[i].sex);

            printf("Enter quiz-1 Score: ");
            scanf("%f", &students[i].quiz_1_score);

            printf("Enter quiz-2 Score: ");
            scanf("%f", &students[i].quiz_2_score);

            printf("Enter mid-term Score: ");
            scanf("%f", &students[i].mid_term_score);

            printf("Enter final Score: ");
            scanf("%f", &students[i].final_score);
        }
        else
        {
            printf("ID not matched\n");
        }
    }

    perform_operation(students, no_of_students, command_number);
}

// calculate average of selected students
void calc_avg_selected_std(Student students[], int *no_of_students, int *command_number)
{
    int selected_num, i, j;
    float total_mark = 0;

    printf("How many number's of students , you want to average? \n");
    scanf("%d", &selected_num);
    int selected_id[selected_num];

    printf("Enter all id separete with space\n");

    for (i = 0; i < selected_num; i++)
    {
        scanf("%d", &selected_id[i]);
    }

    for (i = 0; i < selected_num; i++)
    {
        for (j = 0; j < *no_of_students; j++)
        {
            if (students[j].id == selected_id[i])
            {
                total_mark = total_mark + students[j].total_score;
            }
        }
    }

    printf("Average of selected students = %f\n\n", total_mark / selected_num);

    perform_operation(students, no_of_students, command_number);
}

// find students by id
void find_by_id(Student students[], int *no_of_students, int *command_number)
{
    int id, i;
    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (i = 0; i < *no_of_students; i++)
    {
        if (students[i].id == id)
        {

            printf("Id of Student  : %d\n", students[i].id);
            printf("Name of Student  : ");
            puts(students[i].name);

            printf("Sex of Student : ");
            puts(students[i].sex);

            printf("Quiz-1 Score of Student : %f\n", students[i].quiz_1_score);
            printf("Quiz-2 Score of Student : %f\n", students[i].quiz_2_score);
            printf("Mid-term Score of Student  : %f\n", students[i].mid_term_score);
            printf("Final Score of Student : %f\n", students[i].final_score);

            printf("Total Score of Student : %f\n", students[i].total_score);

            printf("\n");
        }
        else
        {
            printf("Enter valid ID \n");
        }
    }

    perform_operation(students, no_of_students, command_number);
}

// find maximum scored student
void find_max_score_std(Student students[], int *no_of_students, int *command_number)
{
    int i = 0;
    Student student;

    student.id = students[0].id;
    student.total_score = students[0].id;

    for (i = 0; i < *no_of_students; i++)
    {
        if (students[i].total_score > student.total_score)
        {
            student.id = students[i].id;
            student.total_score = students[i].id;
        }
    }

    for (i = 0; i < *no_of_students; i++)
    {
        if (students[i].id == student.id)
        {

            printf("Id of Student  : %d\n", students[i].id);
            printf("Name of Student  : ");
            puts(students[i].name);

            printf("Sex of Student : ");
            puts(students[i].sex);

            printf("Quiz-1 Score of Student : %f\n", students[i].quiz_1_score);
            printf("Quiz-2 Score of Student : %f\n", students[i].quiz_2_score);
            printf("Mid-term Score of Student  : %f\n", students[i].mid_term_score);
            printf("Final Score of Student : %f\n", students[i].final_score);

            printf("Total Score of Student : %f\n", students[i].total_score);

            printf("\n");
        }
    }

    perform_operation(students, no_of_students, command_number);
}

// find minimum scored student
void find_min_score_std(Student students[], int *no_of_students, int *command_number)
{
    int i = 0;
    Student student;

    student.id = students[0].id;
    student.total_score = students[0].id;

    for (i = 0; i < *no_of_students; i++)
    {
        if (students[i].total_score < student.total_score)
        {
            student.id = students[i].id;
            student.total_score = students[i].id;
        }
    }

    for (i = 0; i < *no_of_students; i++)
    {
        if (students[i].id == student.id)
        {

            printf("Id of Student  : %d\n", students[i].id);
            printf("Name of Student  : ");
            puts(students[i].name);

            printf("Sex of Student : ");
            puts(students[i].sex);

            printf("Quiz-1 Score of Student : %f\n", students[i].quiz_1_score);
            printf("Quiz-2 Score of Student : %f\n", students[i].quiz_2_score);
            printf("Mid-term Score of Student  : %f\n", students[i].mid_term_score);
            printf("Final Score of Student : %f\n", students[i].final_score);

            printf("Total Score of Student : %f\n", students[i].total_score);

            printf("\n");
        }
    }

    perform_operation(students, no_of_students, command_number);
}

// sort students based on total score function
void sort_by_total_score(Student students[], int *no_of_students, int *command_number)
{
    int i, j;
    Student temp_std;
    for (i = 0; i < *no_of_students; i++)
    {
        for (j = 0; j < *no_of_students - 1 - i; j++)
        {
            if (students[j + 1].total_score > students[j].total_score)
            {
                temp_std = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp_std;
            }
        }
    }

    view_all_records(students, no_of_students, command_number);

    perform_operation(students, no_of_students, command_number);
}

// view all students record funciton
void view_all_records(Student students[], int *no_of_students, int *command_number)
{
    int i;

    for (i = 0; i < *no_of_students; i++)
    {
        printf("Id of Student %d : %d\n", i + 1, students[i].id);
        printf("Name of Student %d : ", i + 1);
        puts(students[i].name);

        printf("Sex of Student %d : ", i + 1);
        puts(students[i].sex);

        printf("Quiz-1 Score of Student %d : %f\n", i + 1, students[i].quiz_1_score);
        printf("Quiz-2 Score of Student %d : %f\n", i + 1, students[i].quiz_2_score);
        printf("Mid-term Score of Student %d : %f\n", i + 1, students[i].mid_term_score);
        printf("Final Score of Student %d : %f\n", i + 1, students[i].final_score);

        printf("Total Score of Student %d : %f\n", i + 1, students[i].total_score);

        printf("\n");
    }

    perform_operation(students, no_of_students, command_number);
}