# Zlin的板子大全



## 数据结构

### 并查集(DSU)

##### 普通并查集

>路径压缩
>
>```c++
>inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
>```
>
>无路径压缩
>
>```c++
>inline int find(int x)
>{
>    if (f[x] == x)
>           return x;
>    find(f[x]);
>}
>```

##### 种类并查集

>根据不同种类开n倍的空间，每个空间存一种关系
>
>```
>
>```

### ST表

> 常用来处理RMQ问题
>
> 预处理
> 时间复杂度:nlog^n^

> ```c++
> inline void ST_prework()
>{
>   for (int i = 1; i <= n; i++)
>         f[i][0] = a[i];
>   int t = log(n) / log(2) + 1;
>      for (int j = 1; j < t; j++)
>            for (int i = 1; i <= n - (1 << j) + 1; i++)
>                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
>    }
>    ```
>    
> 查询
> 时间复杂度:O(1)
>
> ```c++
> inline int ST_query(int l, int r)
>{
>   int k = log(r - l + 1) / log(2);
>   return max(f[l][k], f[r - (1 << k) + 1][k]);
> }
>    ```

### 树状数组

>宏定义
>
>```c++
>#define lowbit(x) (x & (-x))
>```
>
>修改操作
>
>```c++
>inline void add(int i, int k)
>{
>        for (; i <= n; i += lowbit(i))
>             t[i] += k;
>        return;
>}
>```
>
>查询操作
>
>```c++
>inline int ask(int l, int r)
>{
>        int sum = 0;
>        for (; r; r -= lowbit(r))
>             sum += t[r];
>        --l;
>        for (; l; l -= lowbit(l))
>             sum -= t[l];
>        return sum;
>}
>```

### 线段树

#### 普通线段树

>build操作
>
>```c++
>inline void build(int l, int r, int u)
>{
>        T[u].l = l, T[u].r = r;
>        if (l == r)
>             return;
>        int mid = l + r >> 1;
>        build(l, mid, u << 1);
>        build(mid + 1, r, u << 1 | 1);
>}
>```
>

#### 扫描线

>扫描线记得开八倍空间
>
>pushup回传标记
>
>```c++
>inline void pushup(int u)
>{
>        int l = T[u].l, r = T[u].r;
>        if (T[u].cnt)
>             T[u].len = X[r + 1] - X[l];
>        else
>             T[u].len = T[u << 1].len + T[u << 1 | 1].len;
>}
>```
>
>修改操作
>
>```c++
>inline void add(int l, int r, int u, int tag)
>{
>        if (T[u].l > r || T[u].r < l)
>             return;
>        if (T[u].l >= l && T[u].r <= r)
>        {
>             T[u].cnt += tag;
>             pushup(u);
>             return;
>        }
>        add(l, r, u << 1, tag);
>        add(l, r, u << 1 | 1, tag);
>        pushup(u);
>}
>```

### 平衡树(Splay)

适合用来维护有序队列

>准备工作
>
>```c++
>struct Node
>{
>        int s[2]; // 左右儿子
>        int p;    // 父节点
>        int val;
>        int cnt;
>        int size;
>        void init(int p1, int val1)
>        {
>             p = p1, val = val1;
>             cnt = size = 1;
>        }
>} tr[N];
>int root = 0, tot = 0;
>```
>
>更新节点大小
>
>```c++
>inline void pushup(int x) // 更新点x的大小
>{
>        tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + tr[x].cnt;
>}
>```
>
>旋转操作
>
>```c++
>inline void rotate(int x) // 旋转x
>{
>        int y = tr[x].p, z = tr[y].p;
>        int k = tr[y].s[1] == x;
>        tr[z].s[tr[z].s[1] == y] = x;
>        tr[x].p = z;
>        tr[y].s[k] = tr[x].s[k ^ 1];
>        tr[tr[x].s[k ^ 1]].p = y;
>        tr[x].s[k ^ 1] = y;
>        tr[y].p = x;
>        pushup(x), pushup(y);
>}
>```
>
>旋转节点x到它的父节点为k，如果父节点为0，说明是根节点
>
>```c++
>inline void splay(int x, int k)
>{
>        while (tr[x].p != k)
>        {
>             int y = tr[x].p, z = tr[y].p;
>             if (z != k)
>                 (tr[y].s[0] == x) ^ (tr[z].s[0] == y) ? rotate(x) : rotate(y);
>             rotate(x);
>        }
>        if (k == 0)
>             root = x;
>}
>```
>
>查找操作，把查找的点转换为根
>
>```c++
>inline void find(int val) // 找到权值等于val的点并把它转为根
>{
>        int x = root;
>        while (tr[x].s[val > tr[x].val] && tr[x].val != val)
>             x = tr[x].s[val > tr[x].val];
>        splay(x, 0);
>}
>```
>
>查找前驱和后继
>
>```c++
>inline int get_pre(int val) // 求前驱
>{
>        find(val);
>        int x = root;
>        if (tr[x].val < val)
>             return x;
>        x = tr[x].s[0];
>        while (tr[x].s[1])
>             x = tr[x].s[1];
>        return x;
>}
>
>inline int get_suc(int val) // 求后继
>{
>        find(val);
>        int x = root;
>        if (tr[x].val > val)
>             return x;
>        x = tr[x].s[1];
>        while (tr[x].s[0])
>             x = tr[x].s[0];
>        return x;
>}
>```
>
>删除操作
>先把前驱转为根，后继转为前驱的儿子，这样val节点只有它自身，没有儿子节点，可以直接删除
>
>```c++
>inline void del(int val)
>{
>        int pre = get_pre(val);
>        int suc = get_suc(val);
>        splay(pre, 0);
>        splay(suc, pre);
>        int del = tr[suc].s[0];
>        if (tr[del].cnt > 1)
>             --tr[del].cnt, splay(del, 0);
>        else
>             tr[suc].s[0] = 0, splay(suc, 0);
>}
>```
>
>查询排名
>
>```c++
>// 因为预处理插入了两个无穷大和无穷小的数，所以排名不需要+1
>inline int get_rank(int val) // 查询val的排名
>{
>        find(val);
>        if (tr[root].val < val) // 如果val没有出现过，要判断根节点和val的大小关系
>             return tr[tr[root].s[0]].size + tr[root].cnt;
>        return tr[tr[root].s[0]].size;
>}
>```
>
>查询排名为k的val
>
>```c++
>// 因为插入了无穷大和无穷小，所以传入k时要+1,k为实际情况的k+1
>inline int get_val(int k) // 查询排名为k的val
>{
>        int x = root;
>        while (1)
>        {
>             int y = tr[x].s[0];
>             if (tr[x].cnt + tr[y].size < k)
>             {
>                 k -= tr[x].cnt + tr[y].size;
>                 x = tr[x].s[1];
>             }
>             else
>             {
>                 if (tr[y].size >= k)
>                     x = tr[x].s[0];
>                 else
>                     break;
>             }
>        }
>        splay(x, 0);
>        return tr[x].val;
>}
>```
>
>插入操作
>
>```c++
>inline void insert(int val)
>{
>        int x = root, p = 0;
>        while (x && tr[x].val != val)
>             p = x, x = tr[x].s[val > tr[x].val];
>        if (x)
>             ++tr[x].cnt;
>        else
>        {
>             x = ++tot;
>             tr[p].s[val > tr[p].val] = x;
>             tr[x].init(p, val);
>        }
>        splay(x, 0);
>}
>```

### 分块

>初始化操作，做好分块的左边界和右边界，大小一般为sqrt(n)
>
>```c++
>inline void init()
>{
>        int len = sqrt(n), tot = (n - 1) / len + 1;
>        for (int i = 1; i <= tot; i++)
>             l[i] = r[i - 1] + 1, r[i] = i * len;
>        r[tot] = n;
>        for (int i = 1; i <= tot; i++)
>             for (int j = l[i]; j <= r[i]; j++)
>                 belong[j] = i;
>}
>```
>
>单点修改
>
>区间修改
>利用tag数组存整个区块的修改情况

#### 时间分块

>
>
>

## 数学

### 基础

>2ab = (a+b)^2^-a^2^-b^2^ 
>2ab+2ac+2bd = (a+b+c)^2^-a^2^-b^2^-c^2^
>
>多元同理
>
>大数不能直接用sqrt，要自己用二分查找求值

### 高精度

#### 加法

>存储数据
>lenc = max(lena,lenb)，字符串读取输入，翻转存入数组
>
>```
>int a[N], b[N], c[N];
>int lena, lenb, lenc;
>```
>
>相加操作
>
>```c++
>inline void add(int *a, int *b, int *c)
>{
>    
>        for (int i = 0; i < lenc; i++)
>        {
>             c[i] += a[i] + b[i];  // 累加
>             c[i + 1] = c[i] / 10; // 进位
>             c[i] %= 10;           // 存余
>        }
>        if (c[lenc]) // 处理最高位
>             ++lenc;
>}
>```

#### 减法

>a - b
>
>```c++
>inline void sub(int *a, int *b, int *c)
>{
>        for (int i = 0; i < lenc; i++)
>        {
>             if (a[i] < b[i])
>                 --a[i + 1], a[i] += 10; // 借位
>             c[i] = a[i] - b[i];         // 相减
>        }
>        while (lenc && !c[lenc]) // 删除前导0
>             --lenc;
>}
>```

#### 乘法

>从低位到高位，先累加乘积，然后进位，存余
>
>```c++
>inline void mul(int *a, int *b, int *c)
>{
>        for (int i = 0; i < lena; i++)
>        {
>             for (int j = 0; j < lenb; j++)
>             {
>                 c[i + j] = a[i] * b[j];
>                 c[i + j + 1] = c[i + j] / 10;
>                 c[i + j] %= 10;
>             }
>        }
>        while (lenc && !c[lenc]) // 删除多余的前导0
>             --lenc;
>}
>```

#### 除法

>***从高位到低位***
>大数a除以小数b
>
>```c++
>// lenc = lena
>inline void div(int *a, int b, int *c)
>{
>        ll r = 0; // 被除数
>        for (int i = lena - 1; i >= 0; i--)
>        {
>             r = r * 10 + a[i];
>             c[lena - 1 - i] = r / b;
>             r %= b;
>        }
>        reverse(c, c + lenc);
>        while (lenc && !c[lenc]) // 处理前导0
>             --lenc;
>}
>```



### 快速幂

>快速求a^n^的值
>
>```c++
>inline int quick_pow(int a, int n)
>{
>        int res = 1;
>        while (n)
>        {
>             if (n & 1)
>                 res *= a;
>             a = a * a;
>             n >>= 1;
>        }
>        return res;
>}
>```

### 快速GCD

> 利用更减相损术和builtin内置函数，二进制运算速度更快
>
> ```c++
> int qGCD(int a, int b)
> {
>        int az = __builtin_ctz(a), bz = __builtin_ctz(b); // 如果数据ll，用函数ctzll
>        int z = min(az, bz), dif;
>        b >>= bz;
>        while (a)
>        {
>            a >>= az;
>            dif = abs(b - a);
>            az = __builtin_ctz(dif);
>            if (a < b)
>                b = a;
>            a = dif;
>        }
>        return b << z;
> }
> ```

### 逆元

>*费马定理*
>给定两个数a,p，p为质数，a^p-2^为a模p的乘法逆元
>
>*扩展欧几里得算法*
>ax+by=gcd(a,b)

### 组合数

#### 杨辉三角

> C(n,m)= C(n,n-m)= C(n-1,m-1)+C(n-1,m)
> 适合n<5e3的情况 
>
> ```c++
> // c[n][m]表示从n个元素中取m个的方案数
> inline void prework()
> {
>  for (int i = 0; i <= 5001; i++)
>      for (int j = 0; j <= i; j++)
>          if (!j)
>              c[i][j] = 1;
>          else
>              c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % q;
> }
> ```

#### 预处理法,乘法逆元

>
><img src="组合乘法逆元.png" style="zoom:80%;" />
>**适用范围**：n，m在1e5以内，且取模的数mod为素数时
>利用快速幂求逆元
>
>```c++
>inline void init() // 预处理，fac[]表示阶乘, inf[]表示阶乘的逆元
>{
>fac[0] = inf[0] = 1;
>for (int i = 1; i <= N; i++)
>{
>   fac[i] = fac[i - 1] * i % mod;
>   inf[i] = inf[i - 1] * quick_pow(i, mod - 2) % mod;
>}
>}
>```

## 图论

### 最短路算法

#### Dijkstra

>主体，优先队列为小根堆
>时间复杂度:nlog^m^ 
>
>```c++
>inline void dijkstra()
>{
>        dis[s] = 0;
>        q.push({0, s});
>        while (!q.empty())
>        {
>             node u = q.top();
>             q.pop();
>             int x = u.pos;
>             if (vis[x])
>                 continue;
>             vis[x] = 1;
>             for (int i = head[x]; i; i = a[i].next)
>             {
>                 int y = a[i].to;
>                 if (dis[y] > dis[x] + a[i].w)
>                 {
>                     dis[y] = dis[x] + a[i].w;
>                     if (!vis[y])
>                         q.push({dis[y], y});
>                 }
>             }
>        }
>}
>```

#### Bellman-Ford

>堆优化版——SPFA
>时间复杂度:最好O(m)，最坏O(nm)，菊花图的情况
>
>```c++
>inline void spfa()
>{
>   dis[s] = 0;
>   vis[s] = 1;
>   queue<int> q;
>   q.push(s);
>   int x;
>   while (!q.empty())
>   {
>        x = q.front();
>        q.pop();
>        vis[x] = 0;
>        for (int i = head[x]; i; i = e[i].next)
>        {
>            int y = e[i].to, d = e[i].dis;
>            if (dis[y] > dis[x] + d)
>            {
>                dis[y] = dis[x] + d;
>                if (!vis[y])
>                    vis[y] = 1, q.push(y);
>            }
>        }
>   }
>}
>```

#### Johnson

>Johnson优化，能有处理负权值和有负环的情况
>时间复杂度:n^2^log^m^
>
>预处理:先给每条边新添加一条0边
>
>```c++
>for (int i = 1; i <= n; i++)
>        add_edge(0, i, 0);
>```
>
>然后利用SPFA来判断负环，同时创建h数组（等同于势能，处理负权值）
>
>```c++
>inline bool spfa(int s)
>{
>        for (int i = 1; i <= n; i++)
>             h[i] = 63, vis[i] = 0;
>        h[s] = 0;
>        vis[s] = 1;
>        queue<int> q;
>        q.push(s);
>        int x;
>        while (!q.empty())
>        {
>             x = q.front();
>             q.pop();
>             vis[x] = 0;
>             for (int i = head[x]; i; i = e[i].next)
>             {
>                 int y = e[i].to, d = e[i].w;
>                 if (h[y] > h[x] + d)
>                 {
>                     h[y] = h[x] + d;
>                     if (!vis[y])
>                     {
>                         ++num[y]; // 说明经过当前点，次数加1
>                         if (num[y] > n) // n为自己设定的上限，如果循环次数超过n，说明存在负环，直接返回
>                             return false;
>                         vis[y] = 1, q.push(y);
>                     }
>                 }
>             }
>        }
>        return true;
>}
>```
>
>SPFA预处理完成后利用h数组更新权重
>
>```c++
> for (int j = 1; j <= n; j++)
>        for (int i = head[j]; i; i = e[i].next)
>            e[i].w = e[i].w + h[j] - h[e[i].to];
>```
>
>更新完成后可以保证权值全为正数，随后根据题意运行Dijkstra，最终输出答案要注意减去h数组差值

### LCA/最近公共祖先

> 数组类型
>
> ```c++
> int dep[N], fa[N][22];
> ```
>
> DFS预处理
>
> ```C++
> inline void dfs(int u, int f)
> {
>  dep[u] = dep[f] + 1;
>  fa[u][0] = f;
>  for (int i = 1; i <= 19; i++)
>      fa[u][i] = fa[fa[u][i - 1]][i - 1];
>  for (int v : e[u])
>      if (v != f)
>          dfs(v, u);
> }
> ```
>
> LCA本体
>
> ```c++
> inline int lca(int u, int v)
> {
>  if (dep[u] < dep[v])
>      swap(u, v);
>  for (int i = 19; i >= 0; i--)
>      if (dep[fa[u][i]] >= dep[v])
>          u = fa[u][i]; // 让u，v处于同一层
>  if (u == v)
>      return u;
>  for (int i = 19; i >= 0; i--)
>      if (fa[u][i] != fa[v][i])
>          u = fa[u][i], v = fa[v][i]; // 返回祖先的下一层
>  return fa[u][0];
> }
> ```

### Tarjan算法

>时间戳 dfn[x] 节点x第一次被访问的顺序
>
>追溯值 low[x] 从x节点出发，能到的最早的时间戳
>
>```c++
>vector<int> e[N];
>int dfn[N], low[N], tot;
>int stk[N], instk[N], top;
>int scc[N], siz[N], cnt;
>inline void tarjan(int x)
>{
>    // 入X点，盖时间戳，入栈
>    dfn[x] = low[x] = ++tot;
>    stk[++top] = x, instk[x] = 1;
>    for (int y : e[x])
>    {
>        // 未访问
>        if (!dfn[y])
>        {
>            tarjan(y);
>            low[x] = min(low[x], low[y]);
>        }
>        else if (instk[y])
>            low[x] = min(low[x], dfn[y]);
>    }
>    // X为强连通图的根,输出分量图
>    if (dfn[x] == low[x])
>    {
>        int y;
>        ++cnt;
>        do
>        {
>            y = stk[top--];
>            instk[y] = 0;
>            scc[y] = cnt;
>            siz[cnt]++;
>        } while (y != x);
>    }
>}
>```
>
>

### 点双连通分量

>基础性质：
>**1、** 除了一种比较特殊的点双，其他的点双都满足：任意两点间都存在至少两条点不重复路径。
>**2、** 图中任意一个割点都在至少两个点双中。
>**3、** 任意一个不是割点的点都只存在于一个点双中。
>
>注意点：要在tarjan基础上加特判起点没有祖先的情况
>
>```c++
>bool cut[N];
>inline void tarjan(int x)
>{
>    int ss = 0;
>    dfn[x] = low[x] = ++tot;
>    stk[++top] = x, instk[x] = 1;
>    for (int y : e[x])
>    {
>        if (!dfn[y])
>        {
>            ++ss;
>            tarjan(y);
>            low[x] = min(low[x], low[y]);
>            if (low[y] >= dfn[x])
>                cut[x] = 1;
>        }
>        else if (instk[y])
>            low[x] = min(low[x], dfn[y]);
>    }
>    if (ss == 1 && x == 1) // ss表示是否在环内，x表示是否为起点
>        cut[x] = 0;
>}
>```

### 边双连通分量

>基础性质:
>**1、** 割边不属于任意边双，而其它非割边的边都属于且仅属于一个边双。
>**2、** 对于一个边双中的任意两个点，它们之间都有至少两条**边不重复**的路径。
>
>```
>
>```
>
>

### 拓扑排序

有向无环图（DAG），可以判断有向图中是否有环

#### DFS算法

>通过c数组来存放颜色，表示不同的状态
>
>```c++
>vector<int> e[N], tp; // e[N]类似邻接表，存放有向边，tp存拓扑排序
>int c[N];             // 存放颜色，0表示为经过，1表示已经被经过，-1表示正在被经过
>bool dfs(int u)
>{
>    c[u] = -1;
>    for (auto v : e[u])
>    {
>        if (~c[v]) // 说明有环存在
>            return 0;
>        if (!c[v] && !dfs(v)) // 递归，说明v下面有环
>            return 0;
>    }
>    c[u] = 1;
>    tp.push_back(u);
>    return 1;
>}
>bool toposort()
>{
>    memset(c, 0, sizeof c);
>    for (int i = 1; i <= n; i++) // 遍历每个点，如果颜色没被标记，进行搜索
>        if (!c[i] && !dfs(i))
>            return 0;
>    reverse(tp.begin(), tp.end());
>    return 1;
>}
>```
>
>
>

#### 卡恩算法（Kahn）

>通过队列来维护入度为0的集合
>
>```c++
>vector<int> e[N], tp; // e[N]类似邻接表，存放有向边，tp存拓扑排序
>int din[N];           // 存放每个点的入度
>bool toposort()
>{
>    queue<int> q;
>    for (int i = 1; i <= n; i++)
>        if (!din[i])
>            q.push(i);
>    while (!q.empty())
>    {
>        int u = q.front();
>        q.pop();
>        tp.push_back(u);
>        for (auto v : e[u])
>            if (--din[v] == 0)
>                q.push(v);
>    }
>    return tp.size() == n;
>}
>```

### 欧拉回路

>
>
>

### 最小生成树



>
>
>```
>
>```

### 二分图

>
>
>

## 字符串

### 一点没学
