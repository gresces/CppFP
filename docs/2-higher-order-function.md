# High-order Function 高阶函数

数学上的模型即为复合函数。

FP中的高阶函数为：可以接收函数作为参数或者返回一个函数的函数。

本节的内容结构即为通过这两种定义（函数作为参数，返回函数）分别介绍编程模式：

## filter and transform 过滤和转换

过滤和转换是两种通用的编程模式，这两种模式都是接受函数作为参数的原理。结合高阶函数来说，过滤是同种类型的转换（这里的类型一般是view或者STL中的复杂数据类型），转换则将一种类型转换为另一种类型。

$$
\text{filter: }(\text{collect<Type A>}, (\text{func: Type A}\to bool))\to \text{collect<Type A>}
$$
$$
\text{transform: }(\text{collect<Type A>}, (\text{func: Type A}\to\text{Type B}))\to \text{collect<Type B>}
$$

## folding 折叠

折叠也使用函数作为参数。在C++函数`accumulate()`中，可以使用二元运算来定义折叠的方式。折叠函数的表示为：
$$
\text{folding: }(R, T) \to R
$$
其中R为每一次运算的结果，而T为运算叠加的条目。

一元折叠的对应的数学特性为左结合，写成中缀表达式即：
$$
(((r_0\bigtriangledown t_0)\bigtriangledown t_1)\bigtriangledown ...\bigtriangledown t_n)
$$



# Ref.
[1. Functional Programming in C++, Book, Ivan Čukić]
