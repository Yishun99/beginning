/*
- 从右往左进行比较匹配（一般的字符串搜索算法如KMP都是从从左往右进行匹配）；

- 算法分为两个阶段：预处理阶段和搜索阶段；

- 预处理阶段时间和空间复杂度都是是O(m+)，是字符集大小，一般为256；

- 搜索阶段时间复杂度是O(mn)；

- 当模式串是非周期性的，在最坏的情况下算法需要进行3n次字符比较操作；

- 算法在最好的情况下达到O(n / m)，比如在文本串bn中搜索模式串am-1b ，只需要n/m次比较。
*/

const int ASIZE = 256;

//bad-character shift
void preBmBc(char *x, int m, int bmBc[]) {
   int i;
   //case bmbc2.gif
   for (i = 0; i < ASIZE; ++i)
      bmBc[i] = m;
   //case bmbc1.gif
   for (i = 0; i < m - 1; ++i)
      bmBc[x[i]] = m - i - 1; //x[i]这个字符到pattern末尾的距离
}
 
 
// pattern中以i位置字符为后缀和以最后一个字符为后缀的公共后缀串的长度
void suffixes(char *x, int m, int *suff) {
   int f, g, i;
 
   suff[m - 1] = m;
   g = m - 1;
   for (i = m - 2; i >= 0; --i) {
      if (i > g && suff[i + m - 1 - f] < i - g)
         suff[i] = suff[i + m - 1 - f];
      else {
         if (i < g)
            g = i;
         f = i;
         while (g >= 0 && x[g] == x[g + m - 1 - f])
            --g;
         suff[i] = f - g;
      }
   }
}
 
 //good-suffix shift
void preBmGs(char *x, int m, int bmGs[]) {
   int i, j, suff[XSIZE];
 
   // pattern中以i位置字符为后缀和以最后一个字符为后缀的公共后缀串的长度
   suffixes(x, m, suff);
   
   // 初始为m
   for (i = 0; i < m; ++i)
      bmGs[i] = m;
   
   // case bmgs2.gif
   j = 0;
   for (i = m - 1; i >= 0; --i)
      if (suff[i] == i + 1) //表示从头开始的字串
         for (; j < m - 1 - i; ++j)
            if (bmGs[j] == m)
               bmGs[j] = m - 1 - i; //从头匹配应该移动的距离

   // case bmgs1.gif
   for (i = 0; i <= m - 2; ++i)
      bmGs[m - 1 - suff[i]] = m - 1 - i;
}
 
 
void BM(char *x, int m, char *y, int n) {
   int i, j, bmGs[XSIZE], bmBc[ASIZE];
 
   /* Preprocessing */
   preBmGs(x, m, bmGs);
   preBmBc(x, m, bmBc);
 
   /* Searching */
   j = 0;
   while (j <= n - m) {
      for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
      if (i < 0) {
         OUTPUT(j);
         j += bmGs[0];
      }
      else
         j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
   }
}
   


