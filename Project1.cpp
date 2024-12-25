#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int hasTorch;
    int hasKey;
    int hasAmulet;
} Inventory;

void startGame(Inventory *inv);
void forestPath(Inventory *inv);
void cavePath(Inventory *inv);
void riverPath(Inventory *inv);
void randomEvent(Inventory *inv);

int main() {
    Inventory inventory = {0, 0, 0}; // Initialize inventory
    srand(time(0)); // Seed random number generator

    printf("--- Welcome to the Enhanced Adventure Game! ---\n");
    printf("You are about to embark on an epic journey. Choose wisely, as your decisions will determine your fate!\n\n");

    startGame(&inventory);

    return 0;
}

void startGame(Inventory *inv) {
    int choice;

    printf("\nYou find yourself at the edge of a dark forest.\n");
    printf("1. Enter the forest\n");
    printf("2. Follow the river\n");
    printf("3. Explore a nearby cave\n");
    printf("What will you do? (Enter 1, 2, or 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            forestPath(inv);
            break;
        case 2:
            riverPath(inv);
            break;
        case 3:
            cavePath(inv);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            startGame(inv);
            break;
    }
}

void forestPath(Inventory *inv) {
    int choice;

    printf("\n--- Forest Path ---\n");
    printf("You walk deeper into the forest and hear strange noises.\n");
    printf("1. Investigate the noise\n");
    printf("2. Run back to safety\n");
    printf("3. Climb a tree to get a better view\n");
    printf("What will you do? (Enter 1, 2, or 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You find a friendly elf who gives you a magical amulet. You now possess great power!\n");
            inv->hasAmulet = 1;
            randomEvent(inv);
            break;
        case 2:
            printf("You trip over a root and a wolf chases you out of the forest. You lose!\n");
            break;
        case 3:
            printf("From the tree, you spot a hidden path leading to a secret garden. You find a torch there!\n");
            inv->hasTorch = 1;
            randomEvent(inv);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            forestPath(inv);
            break;
    }
}

void cavePath(Inventory *inv) {
    int choice;

    printf("\n--- Cave Path ---\n");
    printf("The cave is dark and cold. You hear a growl deeper inside.\n");
    printf("1. Light a torch and go further\n");
    printf("2. Leave the cave\n");
    printf("3. Look for a hidden passage\n");
    printf("What will you do? (Enter 1, 2, or 3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (inv->hasTorch) {
            printf("You light your torch and find a treasure chest filled with gold! You win!\n");
        } else {
            printf("It's too dark, and you trip and fall. You lose!\n");
        }
    } else if (choice == 2) {
        printf("As you turn to leave, the cave collapses, and you barely escape. You lose!\n");
    } else if (choice == 3) {
        printf("You discover a hidden passage that leads to a locked door.\n");
        if (inv->hasKey) {
            printf("You use the key and find a room filled with ancient artifacts! You win!\n");
        } else {
            printf("The door is locked. You need a key to open it.\n");
        }
    } else {
        printf("Invalid choice. Try again.\n");
        cavePath(inv);
    }
}

void riverPath(Inventory *inv) {
    int choice;

    printf("\n--- River Path ---\n");
    printf("You follow the river and see a boat tied to a tree.\n");
    printf("1. Take the boat\n");
    printf("2. Keep walking along the river\n");
    printf("3. Search the area for useful items\n");
    printf("What will you do? (Enter 1, 2, or 3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The boat takes you to a beautiful island where you live happily ever after. You win!\n");
    } else if (choice == 2) {
        printf("You get lost and run out of supplies. You lose!\n");
    } else if (choice == 3) {
        printf("You find a rusty key hidden in the grass. This might be useful later!\n");
        inv->hasKey = 1;
        randomEvent(inv);
    } else {
        printf("Invalid choice. Try again.\n");
        riverPath(inv);
    }
}

void randomEvent(Inventory *inv) {
    int event = rand() % 3;

    printf("\n--- Random Event ---\n");
    switch (event) {
        case 0:
            printf("A wandering merchant appears and offers you a map. You feel more confident in your journey.\n");
            break;
        case 1:
            printf("You encounter a wild animal! Fortunately, you manage to scare it away.\n");
            break;
        case 2:
            printf("You find a small pouch of gold coins. Luck is on your side!\n");
            break;
    }
}

