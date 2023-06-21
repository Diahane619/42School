int max(int* tab, unsigned int len) 
{
    if (len == 0)
        return 0;
    int max_num = tab[0];
    unsigned int i = 1;
    while (i < len) 
    {
        if (tab[i] > max_num)
            max_num = tab[i];
        i++;
    }
    return max_num;
}