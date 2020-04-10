# 1-sum-of-two-numbers
1. 关于两数之和的题解
2. 使用两层循环，第一层遍历所有元素，第二层遍历第一层给定元素后面的所有元素。

# 在需要取出栈或队列中的元素进行操作时，定义临时变量进行存储的好处
因为是取出节点进行操作，可以定义临时变量存储所取节点，好处在于 
1. 避免频繁调用成员函数浪费时间， 
2. 使代码逻辑更加清晰一目了然， 
3. 避免同时调用多种成员出现调用冲突。

# 画程序流程图
1. 在写程序时有利于：1）快速将一闪而过的思维灵感用自然语言描述出来，而后再将其转换为机器语言较为高效；2）有利于将运行逻辑更清晰，更直观地展现出来（逻辑可视化）。
2. 在读程序时有利于：将原作者的思维逻辑按顺序，循环，判断框图可视化，比没有明显联结关系的代码更易直观理解。

# delete 和 delete [] 的使用区别
1.delete内置类型的数组时，可以混用delete 和 delete []， 因为delete内置类型不需要调用析构函数。
2.delete自定义类型的数组时，只能用 delete[]，如果用delete只会调用第一个元素的析构函数，无法释放每个元素的内存空间。
3.delete单个元素的内存空间时，可以混用delete 和 delete []。

# 内存空间泄露
内存泄漏（Memory Leak）是指程序中己“动态分配”的“堆内存”由于某种原因程序未释放或无法释放，造成系统内存的浪费，导致程序运行速度减慢甚至系统崩溃等严重后果。


# 动态规划的解题步骤：
1.确定可以用动规，也就是最优序列可以由最优子序列表示（存在重叠overlap）
2.开动规数组表示状态
3.列出递推式（前两步都有的话，这一步水到渠成）
4.代码实现
（最难的是第一步）
//动规一定要穷举出所有的状态，不过一些已经计算过的可以不用再重复计算而已。

# 智能指针主要解决三个问题：
1. 忘记释放发生的内存泄露
2. 悬垂指针问题
3. 抛出异常时的内存泄露
