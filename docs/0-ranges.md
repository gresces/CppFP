# C++20 \<ranges\>

C++20引入新的ranges库，其中的算法是惰性的，只有在需要的时候才进行求值。

例子：
```
// no ranges
for (int count = 0, i = 1; count < 10; i++) {
  if (isMod3(i)) {
    count++;
    std::cout << i << std::endl;
  }
}
// use ranges
for (auto x : std::ranges::iota_view(1)
              | std::ranges::views::filter(isMod3)
              | std::ranges::views::take(10)) {
  std::cout << x << std::endl;
}
```

范围是一种concept（这是一个在C++20中新增的语言功能，可以在编译时约束模板参数，从而防止模板实例化不正确）。范围是一种统一的序列表示形式，可以是一个数组、容器、字符串和文件流等一切能够返回一系列元素的数据源。

视图是一个轻量级的范围，也可以视为范围的一种拓展。它允许我们在一个范围上链式地应用多个算法，从而实现流畅且功能强大的数据处理操作。

范围算法：C++20使用了一系列的范围算法，这些算法的接口是范围接口而不是传统的迭代器，这些算法可以直接作用在范围上，而不需要指定范围的开始和结束。

ranges库中提供了范围访问、范围概念、范围转换器、视图、范围工厂和范围适配器及一些辅助函数。



### range访问

均在ranges命名空间，所以都使用ranges::作为开头。具体的访问器内容有起始、结束、数据个数、连续范围指针等。

### range concept

TODO

### range conversions

在C++23标准中出现，

<!-- TODO -->

### range factory

用于产生view，比如上面例子中使用的iota_view就可以产生序列，除此之外还有empty_view、single_view等。只是一个generator而不是一个真正的序列。需要的时候可以产生元素，惰性求值。

### range adaptors

将一个range作为输入，将view作为输出，命名空间为std::views，可能常用的有reverse take drop filter transform。

可以使用管道操作符将adaptors串联起来，而不用进行函数的嵌套。

### Alias

std::views <> std::ramges::views

std::transform std::ranges::transform 是不同的，请在使用时指定相应的命名空间。

# Ref.
[1. 在C++里面用管道？C++20 Ranges简介 - C++ Weekly EP5](https://www.bilibili.com/video/BV1aV411q752/)
[2. Ranges library (C++20)](https://en.cppreference.com/w/cpp/ranges)
[3. C++20 Ranges简述](https://www.cnblogs.com/linxmouse/p/17579183.html)
[4. Microsoft Docs ranges](https://learn.microsoft.com/zh-cn/cpp/standard-library/ranges?view=msvc-170)
