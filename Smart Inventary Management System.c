#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define MAX_STOCK 100

struct Stock {
    int productID;
    char name[50];
    char category[50];
    char supplier[50];
    char date[20];
    float quantity;
    float rate;
};

struct Stock inventory[MAX_STOCK];
int stock_count = 0;


int compare_by_product_id(const void *a, const void *b) {
    return (((struct Stock *)a)->productID - ((struct Stock *)b)->productID);
}

int compare_by_name(const void *a, const void *b) {
    return strcmp(((struct Stock *)a)->name, ((struct Stock *)b)->name);
}

int compare_by_category(const void *a, const void *b) {
    return strcmp(((struct Stock *)a)->category, ((struct Stock *)b)->category);
}

int compare_by_supplier(const void *a, const void *b) {
    return strcmp(((struct Stock *)a)->supplier, ((struct Stock *)b)->supplier);
}

int compare_by_date(const void *a, const void *b) {
    return strcmp(((struct Stock *)a)->date, ((struct Stock *)b)->date);
}

void delay(int milliseconds) {
    long pause;
    clock_t now, then;
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause) {
        now = clock();
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void main_loader() {
    int loader;
    system("cls");
    gotoxy(50, 15);
    printf("LOADING ");
    for (loader = 1; loader < 20; loader++) {
        delay(50);
        printf("%c", 219);
    }
}

void load_data() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    stock_count = 0;
    while (fscanf(file, "%d %s %s %s %s %f %f", 
                  &inventory[stock_count].productID, inventory[stock_count].name, 
                  inventory[stock_count].category, inventory[stock_count].supplier, 
                  inventory[stock_count].date, &inventory[stock_count].quantity, 
                  &inventory[stock_count].rate) != EOF) {
        stock_count++;
    }
    fclose(file);
}

void save_data() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%d %s %s %s %s %.2f %.2f\n", 
                inventory[i].productID, inventory[i].name, 
                inventory[i].category, inventory[i].supplier, 
                inventory[i].date, inventory[i].quantity, 
                inventory[i].rate);
    }
    fclose(file);
}

void add_stock() {
    int continue_choice;
    do {
        int num_of_stocks;
        
        system("cls");
        gotoxy(30, 10);
        printf("Add Stock\n");

        gotoxy(30, 12);
        printf("Enter the number of stock items to add (or press 0 to exit): ");
        scanf("%d", &num_of_stocks);
        getchar();  // Clear the newline character

        if (num_of_stocks == 0) {
            return;
        }

        for (int n = 0; n < num_of_stocks; n++) {
            if (stock_count >= MAX_STOCK) {
                printf("Inventory full!\n");
                return;
            }

            struct Stock new_stock;
            gotoxy(30, 14 + n*12);
            printf("Enter product ID: ");
            scanf("%d", &new_stock.productID);
            getchar();  // Clear the newline character

            gotoxy(30, 16 + n*12);
            printf("Enter name: ");
            fgets(new_stock.name, sizeof(new_stock.name), stdin);
            new_stock.name[strcspn(new_stock.name, "\n")] = 0;  // Remove newline character

            gotoxy(30, 18 + n*12);
            printf("Enter category: ");
            fgets(new_stock.category, sizeof(new_stock.category), stdin);
            new_stock.category[strcspn(new_stock.category, "\n")] = 0;

            gotoxy(30, 20 + n*12);
            printf("Enter supplier: ");
            fgets(new_stock.supplier, sizeof(new_stock.supplier), stdin);
            new_stock.supplier[strcspn(new_stock.supplier, "\n")] = 0;

            gotoxy(30, 22 + n*12);
            printf("Enter date (DD-MM-YYYY): ");
            fgets(new_stock.date, sizeof(new_stock.date), stdin);
            new_stock.date[strcspn(new_stock.date, "\n")] = 0;

            gotoxy(30, 24 + n*12);
            printf("Enter quantity: ");
            scanf("%f", &new_stock.quantity);
            getchar();

            gotoxy(30, 26 + n*12);
            printf("Enter rate: ");
            scanf("%f", &new_stock.rate);
            getchar();

            inventory[stock_count++] = new_stock;
            save_data();

            gotoxy(30, 28 + n*12);
            printf("Stock added successfully!");
        }

        gotoxy(30, 30 + num_of_stocks*12);
        printf("Press 0 to return to the main menu or any other key to add more stock: ");
        continue_choice = getch() - '0';  // Convert char to int
    } while (continue_choice != 0);
}

void view_stock() {
    int exit_choice;
    do {
        system("cls");
        gotoxy(0, 2);
        printf("Inventory Details:\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-20s | %-20s | %-20s | %-15s | %-10s | %-10s |\n", 
               "ProductID", "Name", "Category", "Supplier", "Date", "Quantity", "Rate");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < stock_count; i++) {
            printf("| %-10d | %-20s | %-20s | %-20s | %-15s | %-10.2f | %-10.2f |\n", 
                   inventory[i].productID, inventory[i].name, 
                   inventory[i].category, inventory[i].supplier, 
                   inventory[i].date, inventory[i].quantity, 
                   inventory[i].rate);
        }
        printf("---------------------------------------------------------------------------------------------------------\n");
      
        printf("\nPress 0 to return to the main menu or any other key to continue viewing stock: ");
        exit_choice = getch() - '0';
    } while (exit_choice != 0);
}

void update_stock() {
    int continue_choice;
    do {
        int productID;
        system("cls");
        gotoxy(30, 10);
        printf("Update Stock\n");
        gotoxy(30, 12);
        printf("Enter product ID to update (or press 0 to exit): ");
        scanf("%d", &productID);
        getchar();

        if (productID == 0) {
            return;
        }

        for (int i = 0; i < stock_count; i++) {
            if (inventory[i].productID == productID) {
                gotoxy(30, 14);
                printf("Enter new quantity: ");
                scanf("%f", &inventory[i].quantity);
                getchar();

                gotoxy(30, 16);
                printf("Enter new rate: ");
                scanf("%f", &inventory[i].rate);
                getchar();

                save_data();
                gotoxy(30, 18);
                printf("Stock updated successfully!");
                gotoxy(30, 20);
                printf("Press 0 to return to the main menu or any other key to update another stock: ");
                continue_choice = getch() - '0';
                break;
            }
        }
        if (continue_choice != 0) {
            gotoxy(30, 22);
            printf("Product ID not found!");
            getch();
            continue_choice = 1;
        }
    } while (continue_choice != 0);
}

void remove_stock() {
    int continue_choice;
    do {
        int productID;
        float quantity_to_remove;
        system("cls");
        gotoxy(30, 10);
        printf("Remove Stock\n");
        gotoxy(30, 12);
        printf("Enter product ID to remove stock (or press 0 to exit): ");
        scanf("%d", &productID);
        getchar();

        if (productID == 0) {
            return;
        }

        for (int i = 0; i < stock_count; i++) {
            if (inventory[i].productID == productID) {
                gotoxy(30, 14);
                printf("Enter quantity to remove: ");
                scanf("%f", &quantity_to_remove);
                getchar();

                if (quantity_to_remove > inventory[i].quantity) {
                    gotoxy(30, 16);
                    printf("Not enough stock to remove that quantity!");
                    getch();
                    return;
                }

                inventory[i].quantity -= quantity_to_remove;
                save_data();

                gotoxy(30, 18);
                printf("Stock removed successfully!");
                gotoxy(30, 20);
                printf("Press 0 to return to the main menu or any other key to remove more stock: ");
                continue_choice = getch() - '0';
                break;
            }
        }
        if (continue_choice != 0) {
            gotoxy(30, 22);
            printf("Product ID not found!");
            getch();
            continue_choice = 1;
        }
    } while (continue_choice != 0);
}

void replenish_stock() {
    int exit_choice;
    do {
        float threshold;
        system("cls");
        gotoxy(30, 10);
        printf("Replenish Stock\n");
        gotoxy(30, 12);
        printf("Enter quantity threshold for replenishment: ");
        scanf("%f", &threshold);
        getchar();

        system("cls");
        gotoxy(0, 2);
        printf("Inventory Below Threshold:\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-20s | %-20s | %-20s | %-15s | %-10s | %-10s |\n", 
               "ProductID", "Name", "Category", "Supplier", "Date", "Quantity", "Rate");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < stock_count; i++) {
            if (inventory[i].quantity < threshold) {
                printf("| %-10d | %-20s | %-20s | %-20s | %-15s | %-10.2f | %-10.2f |\n", 
                       inventory[i].productID, inventory[i].name, 
                       inventory[i].category, inventory[i].supplier, 
                       inventory[i].date, inventory[i].quantity, 
                       inventory[i].rate);
            }
        }
        printf("---------------------------------------------------------------------------------------------------------\n");
        gotoxy(30, 28);
        printf("Press 0 to return to the main menu or any other key to continue: ");
        exit_choice = getch() - '0';
    } while (exit_choice != 0);
}

void sort_and_view_stock() {
    int exit_choice;
    do {
        int option;
        system("cls");
        gotoxy(30, 10);
        printf("Sort by:\n");
        gotoxy(30, 12);
        printf("1. Product ID\n");
        gotoxy(30, 13);
        printf("2. Name\n");
        gotoxy(30, 14);
        printf("3. Category\n");
        gotoxy(30, 15);
        printf("4. Supplier\n");
        gotoxy(30, 16);
        printf("5. Date\n");
        gotoxy(30, 18);
        //printf("Enter your choice: ");
        option = getch() - '0';

        // Create a temporary copy of the inventory
        struct Stock temp_inventory[MAX_STOCK];
        for (int i = 0; i < stock_count; i++) {
            temp_inventory[i] = inventory[i];
        }

        switch (option) {
            case 1:
                qsort(temp_inventory, stock_count, sizeof(struct Stock), compare_by_product_id);
                break;
            case 2:
                qsort(temp_inventory, stock_count, sizeof(struct Stock), compare_by_name);
                break;
            case 3:
                qsort(temp_inventory, stock_count, sizeof(struct Stock), compare_by_category);
                break;
            case 4:
                qsort(temp_inventory, stock_count, sizeof(struct Stock), compare_by_supplier);
                break;
            case 5:
                qsort(temp_inventory, stock_count, sizeof(struct Stock), compare_by_date);
                break;
            default:
                gotoxy(30, 20);
                printf("Invalid choice!");
                getch();
                return;
        }

        // Display the sorted inventory
        system("cls");
        gotoxy(0, 2);
        printf("Sorted Inventory Details:\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-20s | %-20s | %-20s | %-15s | %-10s | %-10s |\n", 
               "ProductID", "Name", "Category", "Supplier", "Date", "Quantity", "Rate");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < stock_count; i++) {
            printf("| %-10d | %-20s | %-20s | %-20s | %-15s | %-10.2f | %-10.2f |\n", 
                   temp_inventory[i].productID, temp_inventory[i].name, 
                   temp_inventory[i].category, temp_inventory[i].supplier, 
                   temp_inventory[i].date, temp_inventory[i].quantity, 
                   temp_inventory[i].rate);
        }
        printf("---------------------------------------------------------------------------------------------------------\n");

        gotoxy(30, stock_count * 2 + 24);
        printf("Press 0 to return to the main menu or any other key to sort and view again: ");
        exit_choice = getch() - '0';
    } while (exit_choice != 0);
}

void analyze_data() {
    int exit_choice;
    do {
        system("cls");
        float total_inventory_value = 0.0;
        int supplier_count = 0;
        int category_count = 0;

        char suppliers[MAX_STOCK][50];
        char categories[MAX_STOCK][50];

        for (int i = 0; i < stock_count; i++) {
            total_inventory_value += inventory[i].quantity * inventory[i].rate;
            int supplier_exists = 0;
            int category_exists = 0;

            for (int j = 0; j < supplier_count; j++) {
                if (strcmp(suppliers[j], inventory[i].supplier) == 0) {
                    supplier_exists = 1;
                    break;
                }
            }

            for (int j = 0; j < category_count; j++) {
                if (strcmp(categories[j], inventory[i].category) == 0) {
                    category_exists = 1;
                    break;
                }
            }

            if (!supplier_exists) {
                strcpy(suppliers[supplier_count++], inventory[i].supplier);
            }

            if (!category_exists) {
                strcpy(categories[category_count++], inventory[i].category);
            }
        }


        printf("\n\n\n\n\n\n\t\tTotal inventory value: %.2f\n", total_inventory_value);
    
        printf("\t\tTotal number of suppliers: %d\n", supplier_count);
  
        printf("\t\tTotal number of categories: %d\n", category_count);

        for (int i = 0; i < category_count; i++) {
            float category_total_quantity = 0.0;
            for (int j = 0; j < stock_count; j++) {
                if (strcmp(categories[i], inventory[j].category) == 0) {
                    category_total_quantity += inventory[j].quantity;
                }
            }
             
            printf("\t\tTotal quantity for category '%s': %.2f\n", categories[i], category_total_quantity);
        }

        printf("\nPress 0 to return to the main menu or any other key to continue analyzing: ");
        exit_choice = getch() - '0';
    } while (exit_choice != 0);
}

void search_inventory() {
    char query[50];
    system("cls");
    printf("Search Inventory:\n");
    printf("Enter product name, category, or supplier to search: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0;

    printf("Search Results:\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-20s | %-20s | %-15s | %-10s | %-10s |\n", 
           "ProductID", "Name", "Category", "Supplier", "Date", "Quantity", "Rate");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        if (strstr(inventory[i].name, query) || strstr(inventory[i].category, query) || strstr(inventory[i].supplier, query)) {
            printf("| %-10d | %-20s | %-20s | %-20s | %-15s | %-10.2f | %-10.2f |\n", 
                   inventory[i].productID, inventory[i].name, 
                   inventory[i].category, inventory[i].supplier, 
                   inventory[i].date, inventory[i].quantity, 
                   inventory[i].rate);
        }
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("\nPress any key to return to the main menu...");
    getch();
}


void menu() {
    int choice;
    do {
        system("cls");
        gotoxy(20, 3);
        printf("==============================================================");
        gotoxy(20, 4);
        printf("|                 Inventory Management System                |");
        gotoxy(20, 5);
        printf("==============================================================");
        gotoxy(20, 6);
        printf("|                                                            |");
        gotoxy(20, 7);
        printf("|                    1. View Stock                           |");
        gotoxy(20, 8);
        printf("|                    2. Add Stock                            |");
        gotoxy(20, 9);
        printf("|                    3. Update Stock                         |");
        gotoxy(20, 10);
        printf("|                    4. Remove Stock                         |");
        gotoxy(20, 11);
        printf("|                    5. Replenish Stock                      |");
        gotoxy(20, 12);
        printf("|                    6. Sort Stock                           |");
        gotoxy(20, 13);
        printf("|                    7. Analyze Data                         |");
        gotoxy(20, 14);
        printf("|                    8. Search Data                          |");
        gotoxy(20, 15);
        printf("|                    0. Exit                                 |");
        gotoxy(20, 16);
        printf("|                                                            |");
        gotoxy(20, 17);
        printf("==============================================================");
        gotoxy(20, 18);
        
        choice = getch() - '0';

        switch (choice) {
            case 1:
                view_stock();
                break;
            case 2:
                add_stock();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                remove_stock();
                break;
            case 5:
                replenish_stock();
                break;
            case 6:
                sort_and_view_stock();
                break;
            case 7:
                analyze_data();
                break;
            case 8:
                search_inventory();
                break;
            case 0:
                break;
            default:
                gotoxy(20, 19);
                printf("Invalid choice! Press any key to try again.");
                getch();
        }
    } while (choice != 0);
}

void welcome_message() {
    system("cls");
    
    int row = 8; // Starting row for the welcome message
    int col = 20; // Starting column for centering the message

    gotoxy(col, row++);
    printf("*******************************************************************************");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                  Welcome to Inventory Management System                     *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*                                                                             *");
    gotoxy(col, row++);
    printf("*******************************************************************************");
    
    gotoxy(col, row++);
    printf("\nPress any key to continue...");
    getch();
}

int main() {
    main_loader();
    load_data();
    welcome_message();
    menu();
    return 0;
}