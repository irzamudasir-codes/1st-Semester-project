#include <stdio.h>
#include <string.h>
void loadstdfromfile();
void addstudent();
void updatestudent();
void deletestudent();
void room();
void maketimetable();
void timetable();
void admitcard();
void createresult();
void result();
void updateresult(int x);
void showallstd();
void printmenu();

struct Student
{
    int id;
    char name[25];
    float marks[6];
    char r[20];
    float tmarks;
    float gpa;
    char grade;
} s[50];

struct timetable
{
    char date[6][15];
    char exam[6][15];
    char invig[6][15];
} tt;
int count = 0;

int main()
{
    loadstdfromfile();
    int choice;
    printf("\033[1;30;43m Examination Management System \033[0m \n");
printf("\n\033[34mAre you a :\033[0m\n\033[35m  1)Teacher\n     or \n  2)Student\n\033[0m");
       int w;
       char password[20];
       int studentchoice;
       if (scanf("%d", &w) != 1 || (w != 1 && w != 2))
        {
            printf("\n\033[31mInvalid input! Please enter either 1 or 2!\n\033[0m");
              return 0;
        }
        // for the student 
        else if(w==2){
             while (1) {
        printf("Enter password: ");
        scanf(" %s", password);
        if (strcmp(password, "1234st") == 0) {
            printf("\033[32m Access granted!\n\033[0m");
            break;  // exit loop when correct
        } else {
            printf("\033[31m Incorrect password. Try again.\n\033[0m");
        }
    }
            while(1){
            printf("\n\033[1;30;46m Dear Student, Welcome to Examination Portal !\033[0m\n\n");
            printf(" 1) \033[33mShow admit card\n\033[0m");
            printf(" 2) \033[32mShow result\n\033[0m");
            printf(" 3) \033[34mExit!\n\033[0m");
           printf("\033[35m Enter your choice :\n\033[0m");
           if (scanf("%d", &studentchoice) != 1){
            printf("\n\033[31mInvalid input! Please enter a number between 1 and 3.\n\033[0m");
            while (getchar() != '\n');
            continue;
        }
           switch (studentchoice)
           {
        case 1:
            admitcard();
            break;
        case 2:
            result();
            break;
        case 3:
              printf("\n\033[33mExiting program. Goodbye!\n\033[0m");
            return 0;
        default:
            printf("\n\033[31mInvalid operation! Please choose between 1-3.\n\033[0m");
           }
        }
    }
    // for the teacher
        else if(w==1){
             while (1) {
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp(password, "1234te") == 0) {
            printf("\033[32m Access granted!\n\033[0m");
            break;  // exit loop when correct
        } else {
            printf("\033[31m Incorrect password. Try again.\n\033[0m");
        }
    }
    while (1)
    {
       printf("\n\033[1;30;47m Dear Teacher, Welcome to Examination Portal !\033[0m\n");
        printmenu();
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 10)
        {
            printf("\n\033[31mInvalid input! Please enter a number between 1 and 10.\n\033[0m");
            while (getchar() != '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            maketimetable();
            break;
        case 3:
            timetable();
            break;
        case 4:
            admitcard();
            break;
        case 5:
            createresult();
            break;
        case 6:
            result();
            break;
        case 7:
            updatestudent();
            break;
        case 8:
            deletestudent();
            break;
        case 9:
            showallstd();
            break;
        case 10:
            printf("\n\033[33mExiting program. Goodbye!\n\033[0m");
            return 0;
        default:
            printf("\n\033[31mInvalid operation! Please choose between 1-10.\n\033[0m");
        }
}
        }

}

void loadstdfromfile()
{
    FILE *fp = fopen("student_data.txt", "r");
    if (fp == NULL)
    {
        count = 0;
        return;
    }

    int id;
    char name[25];
    count = 0;

    while (fscanf(fp, "ID: %d\nName: %[^\n]\n", &id, name) == 2)
    {
        s[count].id = id;
        strcpy(s[count].name, name);
        count++;
        fscanf(fp, "----------------\n");
    }

    fclose(fp);
}

void addstudent()
{
    if (count >= 50)
    { // Check once before adding
        printf("\n\033[31mMaximum number of students reached.\n\033[0m");
        return;
    }

    FILE *fp = fopen("student_data.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (; count < 50; count++)
    {
        printf("\n\033[36mEnter the ID of the student (enter -1 to stop): \033[0m");
        scanf("%d", &s[count].id);

        if (s[count].id == -1)
        {
            break;
        }

        int duplicate = 0;
        for (int i = 0; i < count; i++)
        {
            if (s[count].id == s[i].id)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
        {
            printf("\n\033[31mThis is an existing ID. Enter a unique one:\n\033[0m");
            count--;
            continue;
        }

        printf("\n\033[34mEnter the name of the student: \033[0m");
        scanf(" %[^\n]", s[count].name);

        fprintf(fp, "ID: %d\nName: %s\n----------------\n", s[count].id, s[count].name);

        printf("\n\033[32mStudent added successfully.\n\033[0m");
    }

    fclose(fp);
}

void room()
{
    for (int i = 0; i < 25; i++)
        strcpy(s[i].r, "classroom1");
    for (int i = 25; i < 50; i++)
        strcpy(s[i].r, "classroom2");
}

void admitcard()
{

    char choice;
    while (1)
    {
        int n, a = -1;
        printf("\n \033[32mTo display admit card Enter the student id:\n \033[0m");
        scanf("%d", &n);
        for (int i = 0; i < count; i++)
        {
            if (n == s[i].id)
            {
                a = i;
                break;
            }
        }
        if (a == -1)
            printf("\nStudent ID not found!\n");

        else
        {
            room();
            printf("\t\033[33m==============STUDENT ADMIT CARD==============\t\033[0m");
            printf("\n\033[36m ID = \033[0m %d\n\033[36m NAME =\033[0m %s\n\033[36m ROOM = \033[0m %s\n", s[a].id, s[a].name, s[a].r);
            timetable();

            printf("\n\033[32mDo you want to check another students's admit card? (y/n): \033[0m");
            scanf(" %c", &choice);
            if (choice == 'n' || choice == 'N')
                break;
        }
    }
}

void deletestudent()
{
    int n, a = -1;
    printf("\nEnter the ID of the student to delete: ");
    scanf("%d", &n);

    for (int i = 0; i < count; i++)
    {
        if (n == s[i].id)
        {
            a = i;
            break;
        }
    }

    if (a == -1)
    {
        printf("\nStudent not found.\n");
        return;
    }

    for (int k = a; k < count - 1; k++)
    {
        s[k] = s[k + 1];
    }
    count--;
    printf("\nStudent with ID %d deleted successfully.\n", n);

    FILE *fp = fopen("student_data.txt", "w");
    if (fp != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            fprintf(fp, "ID: %d\nName: %s\n----------------\n", s[i].id, s[i].name);
        }
        fclose(fp);
    }

    fp = fopen("result.txt", "w");
    if (fp != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            fprintf(fp, "ID: %d\n", s[i].id);
            fprintf(fp, "Total Marks: %.2f\n", s[i].tmarks);
            fprintf(fp, "GPA: %.2f\n", s[i].gpa);
            fprintf(fp, "Grade: %c\n", s[i].grade);
            fprintf(fp, "----------------------\n");
        }
        fclose(fp);
    }
}

void maketimetable()
{
    int s, choice;
    FILE *fp;

    printf("\033[31mENTER STARTING DATE OF EXAMS\n(NOTE! STARTING DATE MUST BE IN 6TH MONTH)\n\033[0m");
    scanf(" %d", &s);

    fp = fopen("timetable.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("\033[34mFollowing subjects are there:\n\033[0m");
        printf("\033[35m1)English\n2)Programming\n3)Physics\n4)Calculus\n5)DSA\n6)PST\n\033[0m");
        printf("\033[31mEnter %dth exam\n\033[0m", i + 1);
        printf("Enter the choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            strcpy(tt.exam[i], "English");
            break;
        case 2:
            strcpy(tt.exam[i], "Programming");
            break;
        case 3:
            strcpy(tt.exam[i], "Physics");
            break;
        case 4:
            strcpy(tt.exam[i], "Calculus");
            break;
        case 5:
            strcpy(tt.exam[i], "DSA");
            break;
        case 6:
            strcpy(tt.exam[i], "PST");
            break;
        default:
            strcpy(tt.exam[i], "Unknown Subject");
            break;
        }

        printf("\n\033[32mYou have stored \"%s\" as exam %d.\n\n\033[0m", tt.exam[i], i + 1);
        fprintf(fp, "Exam %d: %s\n", i + 1, tt.exam[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("\n\033[34mFollowing are the invigilators available:\n\033[0m");
        printf("\033[35m1)Ms Maira\n2)Ms Hira\n3)Sir Samad\n4)Sir Asad\n5)Sir Naseem\n6)Ms Aisha\n\033[0m");
        printf("\033[31mEnter invigilator for exam #%d\n\033[0m", i + 1);
        printf("Enter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            strcpy(tt.invig[i], "Ms Maira");
            break;
        case 2:
            strcpy(tt.invig[i], "Ms Hira");
            break;
        case 3:
            strcpy(tt.invig[i], "Sir Samad");
            break;
        case 4:
            strcpy(tt.invig[i], "Sir Asad");
            break;
        case 5:
            strcpy(tt.invig[i], "Sir Naseem");
            break;
        case 6:
            strcpy(tt.invig[i], "Ms Aisha");
            break;
        default:
            strcpy(tt.invig[i], "Unknown");
            break;
        }

        printf("\n\033[33mYou have stored \"%s\" as invigilator %d.\n\n\033[0m", tt.invig[i], i + 1);
        fprintf(fp, "Invigilator %d: %s\n", i + 1, tt.invig[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        sprintf(tt.date[i], "%02d-06-25", s);
        s += 2;
        fprintf(fp, "Date of Exam %d: %s\n", i + 1, tt.date[i]);
    }

    fclose(fp);
    printf("\n\033[32mTimetable successfully saved to timetable.txt\n\033[0m");
}

void timetable()
{
    FILE *fp;
    int i = 0;

    fp = fopen("timetable.txt", "r");
    if (fp == NULL)
    {
        printf("No timetable found! Please create one first.\n");
        return;
    }

    for (i = 0; i < 6; i++)
    {
        fscanf(fp, "Exam %*d: %[^\n]\n", tt.exam[i]);
    }

    for (i = 0; i < 6; i++)
    {
        fscanf(fp, "Invigilator %*d: %[^\n]\n", tt.invig[i]);
    }

    for (i = 0; i < 6; i++)
    {
        fscanf(fp, "Date of Exam %*d: %[^\n]\n", tt.date[i]);
    }

    fclose(fp);
    printf("\033[33m =====================TIMETABLE=====================\033[0m");
    printf("\n------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-15s |\n", "Date", "Subject", "Invigilator");
    printf("\033[36m------------------------------------------------------------\n\033[0m");

    for (i = 0; i < 6; i++)
    {
        printf("\033[34m| %-15s | %-20s | %-15s |\n\033[0m", tt.date[i], tt.exam[i], tt.invig[i]);
    }

    printf("\033[36m------------------------------------------------------------\n\033[0m");
}

void createresult()
{
    int n, a = -1;
    float total = 0, avg;
    FILE *fp;

    printf("\nEnter student ID: ");
    scanf("%d", &n);

    for (int i = 0; i < count; i++)
    {
        if (n == s[i].id)
        {
            a = i;
            break;
        }
    }

    if (a == -1)
    {
        printf("Student ID not found.\n");
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("\n\033[36mEnter marks for %s out of 100: \033[0m", tt.exam[i]);
        scanf("%f", &s[a].marks[i]);
        total += s[a].marks[i];
    }

    s[a].tmarks = total;
    avg = total / 6.0;
    s[a].gpa = (avg / 100.0) * 4.0;

    if (avg >= 85)
        s[a].grade = 'A';
    else if (avg >= 75)
        s[a].grade = 'B';
    else if (avg >= 65)
        s[a].grade = 'C';
    else if (avg >= 50)
        s[a].grade = 'D';
    else
        s[a].grade = 'F';

    fp = fopen("result.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening result file!\n");
        return;
    }

    fprintf(fp, "ID: %d\n", s[a].id);
    fprintf(fp, "Total Marks: %.2f\n", s[a].tmarks);
    fprintf(fp, "GPA: %.2f\n", s[a].gpa);
    fprintf(fp, "Grade: %c\n", s[a].grade);
    fprintf(fp, "----------------------\n");

    fclose(fp);

    printf("\n\033[32mResult successfully stored in result.txt\n\033[0m");
}

void result()
{
    while (1)
    {
        int n, a = -1;
        char choice;
        printf("\n \033[34mTo display result card Enter the student id:\n \033[0m");
        scanf("%d", &n);

        for (int i = 0; i < count; i++)
        {
            if (n == s[i].id)
            {
                a = i;
                break;
            }
        }

        if (a == -1)
        {
            printf("\n\033[31mStudent ID not found!\n\033[0m");
            continue;
        }

        else
        {
            printf("\t\033[33m======================RESULT=====================\t\033[0m");
            printf("\n\033[32mID =\033[0m %d\n\033[32mNAME =\033[0m %s\n", s[a].id, s[a].name);
            printf("\033[33m------------------------------------------------------------\n\033[0m");
            printf("\033[36m| %-15s| %-20s| %-15s |\n\033[0m", "SUBJECT", "MARKS OBTAINED", "TOTAL MARKS");
            printf("\033[33m------------------------------------------------------------\n\033[0m");
            for (int i = 0; i < 6; i++)
            {
                printf("| %-15s | %-20.2f | %-15d |\n", tt.exam[i], s[a].marks[i], 100);
            }
            printf("\033[33m------------------------------------------------------------\n\033[0m");
            printf("\n\033[31mTOTAL MARKS OBTAINED = %f / 600\n\033[0m", s[a].tmarks);
            printf("\n\033[31mGPA = %f\n\033[0m", s[a].gpa);
            printf("\n\033[31mGRADE = %c\n\033[0m", s[a].grade);

            if (s[a].gpa >= 3.6)
                printf("\n\033[33mREMARKS = EXCELLENT PERFORMANCE!\n\033[0m");
            else if (s[a].gpa >= 3.0)
                printf("\n\033[33mREMARKS = ABOVE AVERAGE! VERY GOOD!\n\033[0m");
            else if (s[a].gpa >= 2.5)
                printf("\n\033[33mREMARKS = AVERAGE! SATISFACTORY!\n\033[0m");
            else if (s[a].gpa >= 2.0)
                printf("\n\033[31mREMARKS = BELOW AVERAGE! NEEDS IMPROVEMENT!\n\033[0m");
            else
                printf("\n\033[31mREMARKS = POOR PERFORMANCE! FAIL!\n");
        }
        printf("\n\033[34mDo you want to check another result? (y/n):\n \033[0m");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n')
            break;
    }
}

void updatestudent()
{
    int n, a = -1;
    int ch1, ch2;
    char choice;
    float m;

    printf("\033[35m===========UPDATING A STUDENT===========\n\033[0m");

    while (1)
    {
        printf("\nEnter ID of that student: \n");
        scanf(" %d", &n);

        a = -1;
        for (int i = 0; i < count; i++)
        {
            if (n == s[i].id)
            {
                a = i;
                break;
            }
        }

        if (a == -1)
        {
            printf("\nStudent not found.\n");
            continue;
        }

        printf("\n\033[34mEnter what do you want to update:\n\033[0m");
        printf("1) Name\n2) Marks\n3) Exit\n");
        scanf(" %d", &ch1);

        if (ch1 == 1)
        {
            printf("\nEnter new name: ");
            scanf(" %[^\n]", s[a].name);

            FILE *fp = fopen("student_data.txt", "w");

            if (fp == NULL)
            {
                printf("\nError opening student_data.txt!\n");
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    fprintf(fp, "ID: %d\nName: %s\n----------------\n", s[i].id, s[i].name);
                }
                fclose(fp);
            }

            printf("\n\033[32mName updated successfully and saved to file!\n\033[0m");
        }
        else if (ch1 == 2)
        {
            printf("\n\033[36m Enter subject in which marks are to be updated:\n \033[0m");
            printf("\033[33m1)%s\n2)%s\n3)%s\n4)%s\n5)%s\n6)%s\n \033[0m",
                   tt.exam[0], tt.exam[1], tt.exam[2],
                   tt.exam[3], tt.exam[4], tt.exam[5]);
            scanf(" %d", &ch2);

            if (ch2 >= 1 && ch2 <= 6)
            {
                printf("\n\033[34mEnter updated marks of %s: \033[0m", tt.exam[ch2 - 1]);
                scanf("%f", &m);
                s[a].marks[ch2 - 1] = m;
                printf("\n\033[32mMarks updated successfully!\n\033[0m");
                s[a].tmarks = 0;
                for (int i = 0; i < 6; i++)
                {
                    s[a].tmarks += s[a].marks[i];
                }

                float avg = s[a].tmarks / 6.0;
                s[a].gpa = (avg / 100.0) * 4.0;

                if (avg >= 85)
                    s[a].grade = 'A';
                else if (avg >= 75)
                    s[a].grade = 'B';
                else if (avg >= 65)
                    s[a].grade = 'C';
                else if (avg >= 50)
                    s[a].grade = 'D';
                else
                    s[a].grade = 'F';

                printf("\n\033[32mMarks updated successfully!\n\033[0m");
                updateresult(a);

                FILE *fp = fopen("result.txt", "w"); // overwrites the entire file
                if (fp == NULL)
                {
                    printf("\nError opening file!");
                    return;
                }

                for (int j = 0; j < count; j++)
                {
                    fprintf(fp, "ID: %d\n", s[j].id);
                    fprintf(fp, "Total Marks: %.2f\n", s[j].tmarks);
                    fprintf(fp, "GPA: %.2f\n", s[j].gpa);
                    fprintf(fp, "Grade: %c\n", s[j].grade);
                    fprintf(fp, "----------------------\n");
                }

                fclose(fp);
                printf("\n\033[32mFile updated successfully!\n\033[0m");
            }

            else
                printf("\nInvalid subject choice!\n");
        }
        else if (ch1 == 3)
        {
            printf("\n\033[31mExiting this function.\n\033[0m");
            break;
        }
        else
            printf("\n\033[31mInvalid choice.\n\033[0m");

        printf("\n\033[32mDo you want to update more students? (y/n): \033[0m");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
            break;
    }
}

void updateresult(int x)
{

    printf("\t\033[34m======================UPDATED RESULT======================\t\033[0m");
    printf("\n\033[32mID = \033[0m%d\n \033[32m NAME =\033[0m %s\n", s[x].id, s[x].name);
     printf("\033[33m------------------------------------------------------------\n\033[0m");
    printf("\033[36m| %-15s| %-20s | %-15s |\n\033[0m", "SUBJECT", "MARKS OBTAINED", "TOTAL MARKS");
    printf("\033[33m------------------------------------------------------------\n\033[0m");
    for (int i = 0; i < 6; i++)
    {
        printf("\033[34m| %-15s | %-20.2f | %-15d |\n\033[0m", tt.exam[i], s[x].marks[i], 100);
    }
    printf("\033[33m------------------------------------------------------------\n\033[0m");
    printf("\n\033[31mTOTAL MARKS OBTAINED = %f / 600\n\033[0m", s[x].tmarks);
    printf("\033[31mGPA = %f\n\033[0m", s[x].gpa);
    printf("\033[31mGRADE = %c\n\033[0m", s[x].grade);

    if (s[x].gpa >= 3.6)
        printf("\n\033[31mREMARKS = EXCELLENT PERFORMANCE!\033[0m");
    else if (s[x].gpa >= 3.0)
        printf("\n\033[31mREMARKS = ABOVE AVERAGE! VERY GOOD!\033[0m");
    else if (s[x].gpa >= 2.5)
        printf("\n\033[31mREMARKS = AVERAGE! SATISFACTORY!\033[0m");
    else if (s[x].gpa >= 2.0)
        printf("\n\033[31mREMARKS = BELOW AVERAGE! NEEDS IMPROVEMENT!\033[0m");
    else
        printf("\n\033[31mREMARKS = POOR PERFORMANCE! FAIL!\033[0m");
}

void showallstd()
{
    FILE *fp;
    struct Student temp;

    printf("\n\033[33m=========== VIEW STUDENTS ===========\n\033[0m");
    printf("\033[35mID\t\tNAME\n\033[0m");

    fp = fopen("student_data.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo student data found! Please add students first.\n");
        return;
    }

    while (fscanf(fp, "ID: %d\nName: %[^\n]\n----------------\n", &temp.id, temp.name) == 2)
    {
        printf("\n\033[36m%d\033[0m\t\t%s\n", temp.id, temp.name);
    }

    fclose(fp);
}

void printmenu(void)
{
    printf("\033[33m\n============EXAMINATION SYSTEM=========\n\033[0m");
    printf("\033[31m1) Add students\n\033[0m");
    printf("\033[34m2) Make timetable\n\033[0m");
    printf("\033[32m3) Display timetable\n\033[0m");
    printf("\033[35m4) Show admit card\n\033[0m");
    printf("\033[36m5) Create result\n\033[0m");
    printf("\033[31m6) Show result\n\033[0m");
    printf("\033[34m7) Update student\n\033[0m");
    printf("\033[32m8) Delete student\n\033[0m");
    printf("\033[35m9) Showall student\n\033[0m");
    printf("\033[36m10) Exit\n\033[0m");
    printf("\033[33m=====================================\n\033[0m");
    printf("\n\033[32mEnter the choice:\033[0m");
}
