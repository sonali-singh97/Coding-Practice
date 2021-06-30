string longestCommonPrefix(vector<string> &strs)
{
    int len = strs.size();

    if (len == 0)
    {
        return "";
    }

    string common = strs[0];

    for (int i = 1; i < len; i++)
    {
        int len2 = common.length();
        for (int j = 0; j < len2; j++)
        {
            if (common[j] != strs[i][j])
            {
                common = common.substr(0, j);
            }
        }
    }
    return common;
}