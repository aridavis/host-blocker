vector<string> blockedUrls;

void readHosts()
{
    string line;
    ifstream file(env["HOST_PATH"]);

    while (getline(file, line))
    {
        vector<string> splitted = split(trim(line), ' ');
        blockedUrls.push_back(splitted[1]);
    }

    sort(blockedUrls.begin(), blockedUrls.end());
}

void writeHost()
{
    string line;
    for (auto &url : blockedUrls)
    {
        line += "127.0.0.1 " + url + "\n";
    }
    sort(blockedUrls.begin(), blockedUrls.end());
    ofstream file;
    file.open(env["HOST_PATH"]);
    file << line;
    file.close();
}

void viewHosts()
{
    if (blockedUrls.empty())
    {
        printf("No entry found!");

        return;
    }
    sort(blockedUrls.begin(), blockedUrls.end());
    clear();
    printf("Blocked URL List\n");
    printf("================\n\n");
    for (auto &url : blockedUrls)
    {
        cout << url << endl;
    }
}

void deleteHost()
{
    clear();

    if (blockedUrls.empty())
    {
        printf("No entry found!");
        getchar();
        return;
    }

    viewHosts();

    string s;
    printf("\nEnter URL to delete: ");
    cin >> s;
    getchar();
    bool found = false;
    int idx = 0;
    for (auto &url : blockedUrls)
    {
        if (url == s)
        {
            found = true;
            break;
        }
        idx++;
    }

    if (found)
    {
        string c = "";
        do
        {
            cout << "Are you sure to delete " << s << " [y/n]?" << endl;
            cin >> c;
            getchar();
        } while (c != "Y" && c != "y" && c != "n" && c != "N");

        if (c == "Y" || c == "y")
        {
            blockedUrls.erase(blockedUrls.begin() + idx);
            printf("Success Deleting URL!\n");
            printf("Press enter to continue...\n");
            getchar();

            writeHost();
        }
    }
}

void addHost()
{
    clear();
    string url;
    do
    {
        printf("Input URL to block: ");
        cin >> url;
        getchar();
    } while (url.length() < 1);
    bool found = false;
    for (auto &u : blockedUrls)
    {
        if (url == u)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        clear();
        cout << "Fail! URL is already added" << endl;
        getchar();
        return;
    }
    blockedUrls.push_back(url);
    writeHost();
    clear();
    printf("Succes Blocking URL\n");
    printf("Press enter to continue...\n");
    getchar();
}
