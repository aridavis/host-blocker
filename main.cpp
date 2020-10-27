#include <bits/stdc++.h>
using namespace std;

#include "headers/util.h"
#include "env.h"
#include "headers/host.h"
#include "headers/password.h"

int main()
{
    readEnv();
    readPassword();
    int input = 0;

    string pass = "";

    do
    {
        clear();
        printf("Input Password: ");
        cin >> pass;
        getchar();

        if (password != pass)
        {
            printf("Incorrect Password!\n");
            printf("Press enter to continue...\n");
            getchar();
        }

    } while (password != pass);

    readHosts();

    while (input != 5)
    {
        clear();
        printf("Entry Host Blocker\n");
        printf("Written By: Ari Davis\n");
        printf("=====================\n\n");

        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Change Password\n");
        printf("5. Exit\n");
        printf("Choose: ");

        scanf("%d", &input);
        getchar();
        if (input == 1)
        {
            addHost();
        }
        else if (input == 2)
        {
            viewHosts();
            getchar();
        }
        else if (input == 3)
        {
            deleteHost();
        }
        else if (input == 4)
        {
            changePassword();
        }
    }
    return 0;
}