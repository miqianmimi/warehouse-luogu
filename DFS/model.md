# 递归；回溯；DFS;BFS 四大类算法的模板

## 递归
递归优点：用到了栈结构简单. 缺点：效率低，可能栈溢出

```c
void f(){
    if(符合边界条件)
    {
        return;
    }
    ///某种形式的调用
    f();
}
```

## 回溯

回溯：递归的一种，通过递归代码实现回溯目的，理解为有剪枝的DFS过程

```c
void dfs(int 当前状态){
    if (当前状态为边界条件)
        {
            记录或输出
            return
        }
    for(i=0;i<n;i++){
        //扩展出一个子状态
        修改了全局变量
        if(子状态满足约束条件){
            dfs(子状态)
        }
        恢复全局变量//回溯部分
    }
}
```
## 常用搜索方法：
BFS DFS 枚举
0.枚举 
1.BFS 用于计算图的连通性，单源最短路径，计算最小操作
2.DFS 火力中心布局

## BFS
模板
```c
queue<type> q;
q.push(初始状态)
while (!q.empty())
{
    type t = q.front();
    q.pop();
    遍历 T 的各个状态 next
    {
        if(next is legal)
            q.push(next)
            计数或者维护
    }
}
```

## DFS
模板
```c
DFS(顶点)
{
    处理当前顶点，记录为已访问，
    遍历与当前顶点相邻的未方位顶点
    {
        标记更改；
        DFS(下一个子状态)；
        恢复更改
    }
}
```

```c
Trace（当前状态） 
{
    if 当前状态是结束状态
    {
         if 是最佳解： 记录。
         退出
    }
    遍历当前状态的各个邻接状态
    {
        if 当前状态满足约束条件 且 满足最优性要求 ： Trace（子状态） 
    } 
}
```
