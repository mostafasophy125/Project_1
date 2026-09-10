#include <stdio.h>
#include "STD.h"
#include "SDB.h"

static student g_database[SDB_MAX_STUDENTS];
static uint8   g_usedSize = 0;

static int32 SDB_FindIndexById(uint32 id)
{
    uint8 i;
    for (i = 0; i < g_usedSize; i++)
    {
        if (g_database[i].Student_ID == id)
        {
            return (int32)i;
        }
    }
    return -1;
}

bool SDB_IsFull(void)
{
    return (g_usedSize >= SDB_MAX_STUDENTS) ? true : false;
}

uint8 SDB_GetUsedSize(void)
{
    return g_usedSize;
}

bool SDB_AddEntry(void)
{
    student newStudent;

    if (SDB_IsFull() == true)
    {
        printf("Database is full. Cannot add a new entry.\n");
        return false;
    }

    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);

    if (SDB_IsIdExist(newStudent.Student_ID) == true)
    {
        printf("A student with this ID already exists.\n");
        return false;
    }

    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course1 ID: ");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course2 ID: ");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course3 ID: ");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    g_database[g_usedSize] = newStudent;
    g_usedSize++;

    printf("Student added successfully.\n");
    return true;
}

void SDB_DeleteEntry(uint32 id)
{
    int32 index = SDB_FindIndexById(id);
    uint8 i;

    if (index == -1)
    {
        printf("No student found with ID %u.\n", id);
        return;
    }

    for (i = (uint8)index; i < g_usedSize - 1; i++)
    {
        g_database[i] = g_database[i + 1];
    }
    g_usedSize--;

    printf("Student with ID %u deleted.\n", id);
}

bool SDB_ReadEntry(uint32 id)
{
    int32 index = SDB_FindIndexById(id);

    if (index == -1)
    {
        printf("No student found with ID %u.\n", id);
        return false;
    }

    printf("---- Student Record ----\n");
    printf("Student ID   : %u\n", g_database[index].Student_ID);
    printf("Student Year : %u\n", g_database[index].Student_year);
    printf("Course1 ID   : %u\n", g_database[index].Course1_ID);
    printf("Course1 Grade: %u\n", g_database[index].Course1_grade);
    printf("Course2 ID   : %u\n", g_database[index].Course2_ID);
    printf("Course2 Grade: %u\n", g_database[index].Course2_grade);
    printf("Course3 ID   : %u\n", g_database[index].Course3_ID);
    printf("Course3 Grade: %u\n", g_database[index].Course3_grade);

    return true;
}

void SDB_GetList(uint8 *count, uint32 *list)
{
    uint8 i;

    *count = g_usedSize;
    for (i = 0; i < g_usedSize; i++)
    {
        list[i] = g_database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id)
{
    return (SDB_FindIndexById(id) != -1) ? true : false;
}