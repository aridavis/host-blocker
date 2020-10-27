void readEnv()
{
    string line;
    ifstream file("config/.env");

    if (file == NULL)
    {
        printf("Env file not found");
        exit(0);
    }

    while (getline(file, line))
    {
        vector<string> splitted = split(trim(line), '=');
        std::string str = splitted[1];
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        env[splitted[0]] = cstr;
    }
}