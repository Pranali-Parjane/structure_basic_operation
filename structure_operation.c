#include <stdio.h>
#include <string.h>

struct carinfo {
    char name[20];
    float price;
};

int main() {
    struct carinfo c[10]; 
    int i, k, d, u, ch;
    
   //input info
    for(i = 0; i < 3; i++) {
        printf("Enter the car information\n");
        printf("Enter the name of the car:\n");
        scanf("%s", c[i].name);
        printf("Enter the price:\n");
        scanf("%f", &c[i].price);
    }
    
    // Display info
    for(i = 0; i < 3; i++) {
        printf("Car information:\n");
        printf("Name of car: %s\n", c[i].name);
        printf("Price of car: %.2f\n", c[i].price);
    }
    
    do {
        printf("\n1. Insertion\n2. Deletion\n3. Updating\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Insertion of a new car\n");
                printf("Position (0-3) at which you want to insert the car: ");
                scanf("%d", &k);

                if (k < 0 || k > 3) { //  invalid 
                    printf("Invalid position! Try again.\n");
                    break;
                }

                // Shifting elements to make space for new entry
                for(i = 3; i >= k; i--) {
                    strcpy(c[i+1].name, c[i].name);
                    c[i+1].price = c[i].price;
                }

                // Taking input for the new car
                printf("Enter the name of the car:\n");
                scanf("%s", c[k].name);
                printf("Enter the price:\n");
                scanf("%f", &c[k].price);

                // Displaying updated list
                for(i = 0; i < 4; i++) {
                    printf("Car information:\n");
                    printf("Name: %s\n", c[i].name);
                    printf("Price: %.2f\n", c[i].price);
                }
                break;
            
            case 2:
                printf("Deletion of a car entry\n");
                printf("Position (0-2) at which you want to delete the car: ");
                scanf("%d", &d);

                if (d < 0 || d > 2) { 
                    printf("Invalid position! Try again.\n");
                    break;
                }

                // Shifting elements left to delete an entry
                for(i = d; i < 3; i++) {
                    strcpy(c[i].name, c[i+1].name);
                    c[i].price = c[i+1].price;
                }

                printf("The modified data is:\n");
                for(i = 0; i < 2; i++) { // Display only valid entries
                    printf("Car information:\n");
                    printf("Name: %s\n", c[i].name);
                    printf("Price: %.2f\n", c[i].price);
                }
                break;
            
            case 3:
                printf("Updating car information\n");
                printf("Position (0-2) at which you want to update the car: ");
                scanf("%d", &u);

                if (u < 0 || u > 2) { 
                    printf("Invalid position! Try again.\n");
                    break;
                }

                // Taking updated car details
                printf("Enter the updated name of the car:\n");
                scanf("%s", c[u].name);
                printf("Enter the updated price:\n");
                scanf("%f", &c[u].price);

                // Displaying updated list
                for(i = 0; i < 3; i++) {
                    printf("Car information:\n");
                    printf("Name: %s\n", c[i].name);
                    printf("Price: %.2f\n", c[i].price);
                }
                break;
            
            case 4:
                printf("Exiting program...\n");
                break;
            
            default:
                printf("Wrong choice! Try again.\n");
        }
    } while(ch != 4);
    
    return 0;
}
