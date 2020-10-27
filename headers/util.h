map<string, char *> env;

string trim(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<string> split(const string &s, char seperator)
{
    vector<string> output;

    string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != string::npos)
    {
        string substring(s.substr(prev_pos, pos - prev_pos));

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos - prev_pos));

    return output;
}

void clear()
{
    system(env["CLEAR_COMMAND"]);
}
