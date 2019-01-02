#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//typedef long long ll;
const int N = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxk = 3e5 + 10;

struct node1
{
    int l, r;
    int id;
};

struct node2
{
    int val;
    int pos;
};

struct node3
{
    int val;
    int l, r;
};

node1 seg[maxk];
vector<node2> pre[8 * maxk];
node3 tree[100 * maxk];
int tmp[8 * maxk], root[8 * maxk];
int n, q, k, tot, num;

void pushup(int cur)
{
    tree[cur].val = max(tree[tree[cur].l].val, tree[tree[cur].r].val);
}

int build(int l, int r)
{
    int cur, m;
    cur = num++;
    tree[cur].l = 0, tree[cur].r = 0, tree[cur].val = N;
    if (l == r)
        return cur;
    m = (l + r) / 2;
    tree[cur].l = build(l, m);
    tree[cur].r = build(m + 1, r);
    return cur;
}

int update(int rot, int tar, int val, int l, int r)
{
    int cur, m;
    cur = num++;
    tree[cur] = tree[rot];
    if (l == r)
    {
        tree[cur].val = min(tree[cur].val, val);
        return cur;
    }
    m = (l + r) / 2;
    if (tar <= m)
        tree[cur].l = update(tree[cur].l, tar, val, l, m);
    else
        tree[cur].r = update(tree[cur].r, tar, val, m + 1, r);
    pushup(cur);
    return cur;
}

int query(int rot, int pl, int pr, int l, int r)
{
    int res;
    int m;
    if (pl <= l && r <= pr)
        return tree[rot].val;
    res = -N, m = (l + r) / 2;
    if (pl <= m)
        res = max(res, query(tree[rot].l, pl, pr, l, m));
    if (pr > m)
        res = max(res, query(tree[rot].r, pl, pr, m + 1, r));
    return res;
}

int main()
{
    node2 gou;
    int ll, rr, res;
    int i, j, p, flag, a, b;
    int l, r, mid, pp;
    cin >> n >> q >> k;
    //scanf("%d%d%d",&n,&q,&k);
    for (i = 1; i <= k; i++)
    {
        cin >> seg[i].l >> seg[i].r >> seg[i].id;
        //scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].id);
        tmp[++tot] = seg[i].l, tmp[++tot] = seg[i].r;
    }
    sort(tmp + 1, tmp + tot + 1);
    tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
    /*
    printf("^^^%d^^^\n",tot);
    for(i=1;i<=tot;i++) printf("%lld ",tmp[i]);
    printf("\n");
    */
    for (i = 1; i <= k; i++)
    {
        p = lower_bound(tmp + 1, tmp + tot + 1, seg[i].l) - tmp;
        //printf("*%d ",p);
        gou.val = seg[i].r, gou.pos = seg[i].id;
        pre[p].pb(gou);
    }
    root[tot + 1] = build(1, n);
    for (i = tot; i >= 1; i--)
    {
        //printf("***%d***\n",i);
        flag = 0;
        for (j = 0; j < pre[i].size(); j++)
        {
            gou = pre[i][j];
            //printf("%d %lld   ",gou.pos,gou.val);
            if (flag == 0)
            {
                root[i] = update(root[i + 1], gou.pos, gou.val, 1, n);
                flag = 1;
            }
            else
            {
                root[i] = update(root[i], gou.pos, gou.val, 1, n);
            }
        }
        //printf("\n");
        if (flag == 0)
            root[i] = root[i + 1];
    }
    while (q--)
    {
        cin >> a >> b >> ll >> rr;
        //scanf("%d%d%d%d",&a,&b,&ll,&rr);
        if (ll > tmp[tot])
            puts("no");
        else
        {
            l = 1, r = tot, pp = 1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (tmp[mid] < ll)
                    l = mid + 1;
                else
                    r = mid - 1, pp = mid;
            }
            //printf("***%d***\n",pp);
            res = query(root[pp], a, b, 1, n);
            if (res <= rr)
                puts("yes");
            else
                puts("no");
        }
    }

    return 0;
}
