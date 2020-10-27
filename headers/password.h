string password = "";

void readPassword()
{
    string line;
    ifstream file(env["PASSWORD_PATH"]);

    while (getline(file, line))
    {
        password = trim(line);
    }
}

void changePassword()
{
    string pass = "";
    do
    {
        clear();
        printf("Input new password [min 6 chars]: ");
        cin >> pass;
        getchar();
    } while (pass.length() < 6);

    string conpass = "";
    printf("Input confirmation password: ");
    cin >> conpass;
    getchar();

    if (conpass != pass)
    {
        printf("Password must be the same with confirmation password!");
        getchar();
    }
    else
    {
        ofstream file;
        file.open(env["PASSWORD_PATH"]);
        file << pass;
        file.close();
    }
}
