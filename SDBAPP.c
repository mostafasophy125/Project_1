#include <stdio.h>
#include "STD.h"
#include "SDB.h"
#include "SDBAPP.h"

static void SDB_PrintMenu(void)
{
    printf("\n===== Student Database Menu =====\n");
    printf("1. Add entry\n");
    printf("2. Get used size in database\n");
    printf("3. Read student data\n");
    printf("4. Get the list of all student IDs\n");
    printf("5. Check if ID exists\n");
    printf("6. Delete student data\n");
    printf("7. Check if database is full\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void SDB_APP(void)
{
    uint8 choice;
    unsigned int choiceInput;

    do
    {
        SDB_PrintMenu();
        scanf("%u", &choiceInput);
        choice = (uint8)choiceInput;
        SDB_action(choice);
    } while (choice != 0);

    printf("Exiting program. Goodbye!\n");
}

void SDB_action(uint8 choice)
{
    uint32 id;
    uint8  count;
    uint32 list[SDB_MAX_STUDENTS];
    uint8  i;

    switch (choice)
    {
        case 1:
            (void)SDB_AddEntry();
            break;

        case 2:
            printf("Used size: %u / %u\n", SDB_GetUsedSize(), SDB_MAX_STUDENTS);
            break;

        case 3:
            printf("Enter Student ID to read: ");
            scanf("%u", &id);
            (void)SDB_ReadEntry(id);
            break;

        case 4:
            SDB_GetList(&count, list);
            if (count == 0)
            {
                printf("Database is empty.\n");
            }
            else
            {
                printf("Stored Student IDs (%u):\n", count);
                for (i = 0; i < count; i++)
                {
                    printf("  - %u\n", list[i]);
                }
            }
            break;

        case 5:
            printf("Enter Student ID to check: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id) == true)
            {
                printf("ID %u exists.\n", id);
            }
            else
            {
                printf("ID %u does not exist.\n", id);
            }
            break;

        case 6:
            printf("Enter Student ID to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;

        case 7:
            if (SDB_IsFull() == true)
            {
                printf("Database is full.\n");
            }
            else
            {
                printf("Database is not full.\n");
            }
            break;

        case 0:
            break;

        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
}