## 1.  Switches

```cpp
int k = 1;
for (int i = 1; i <= m; i++) {
    if (k > n) break;
    if (a[k][i] == 0) {
        for (int j = k + 1; j <= n; j++) if (a[j][i] != 0) {
            for (int l = 1; l <= m + 1; l++) swap(a[j][l], a[k][l]);
            break;
        }
    }
    if (a[k][i] == 0) continue;
    for (int j = k + 1; j <= n; j++) if (a[j][i] == 1) {
        for (int l = i; l <= m + 1; l++) a[j][l] ^= a[k][l];
    }
    k++;
}
```

## 2. Bad Wiring

对每个灯列出一个方程，系数代表相应开关能不能控制这个灯。

将系数矩阵化简为行阶梯。因为要求 1 最少的解，所以枚举自由元，求出对应的解向量。



### 3. Lanterns

自由元可以任意选。

### 

### 4. 翻转游戏

bitset 优化暴力。



### 5.  Gambler Bo

异或相当于模 2 下运算，这里改成模 3



### 6.
