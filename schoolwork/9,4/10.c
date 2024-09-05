struct ss
{
    int fa;
    int l, r;
} t[200010];

void cal(int *ans, int i)
{
    if (!t[i].l && !t[i].r)
        ++(*ans);
    if (t[i].l)
        cal(&ans, t[i].l);
    if (t[i].r)
        cal(&ans, t[i].r);
}