# @LeetCode 两数之和--Two Sum [C++]
# 问题描述
给定一个整数数组<kbd>nums</kbd>和一个目标值<kbd>target</kbd>，请你在该数组中找出和为目标值的那**两个**整数，并返回他们的**数组下标**

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

**示例：**
>给定 nums = [2, 7, 11, 15], target = 9
>
>因为 nums[**0**] + nums[**1**] = 2 + 7 = 9
>
>所以返回 [**0, 1**]

# 解题方法及复杂度分析
## 暴力法
遍历每个元素*x*，并查找是否存在一个值与*target - x*相等的目标元素。

**复杂度分析：**

- 时间复杂度：*O(n^2^)*，对于每个元素，试图通过遍历数组的其余部分来寻找它所对应的目标元素，这将耗费*O(n)*的时间。因此时间复杂度为*O(n^2^)*。

# 程序实现
```cpp
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
	    	unordered_map<int, int> m;
	    	vector<int> res;
	    	for (int i = 0; i < nums.size(); i++) {
	    		m[nums[i]] = i;    // Key = nums[i], T = i
	    	}
	    	for (int i = 0; i < nums.size(); i++) {
	    		int t = target - nums[i];
	    		if (m.count(t) && m[t] != i) {
	    		    res.push_back(i);
	    		    res.push_back(m[t]);
	    		    break;    //假设每种输入只会对应一个答案
	    		}
	    	}
	    	return res;
		}
	};
```

# 数据结构说明
## unordered_map
**1、代码**

```cpp
	template< class Key,			// unordered_map::key_type
		  class T,			// unordered_map::mapped_type
	  	  class Hash = hash<key>,	// unordered_map::hasher
	  	  class Pred = equal_to<key>,	// unordered_map::key_equal
	  	  class Alloc = allocator< pair<const Key, T>>	// unordered_map::allocator_type
	  	  > class unordered_map;
```
**2、定义及说明**

unordered_map是**关联式**容器，其存储由**键值**和**映射值**组合形成的元素组，并且允许基于其键值快速检索各个元素。

在unordered_map中，键值通常作为**唯一**标识元素，而映射值关联在键值上。键值和映射值的**类型可以不同**。

在unordered_map内部，元素组不按照键值或映射值以特定顺序排序，但是依据它们的哈希值组织到桶中，以方便参照它们的键值快速访问单个元素组（平均时间复杂度通常是常数）。

尽管unordered_map容器在其元素组子集进行区间迭代的效率较低，相比map容器而言，它能更快访问单个元素组。

unordered_map运用直接访问运算符(operator[])，可以使用键值作为参数直接访问映射值。

**3、参数说明**

| 序号 | 名称 | 说明 |
|:-----------:|:-------------:|:-------------|
|1|Map|键值的类型。unordered_map中每个元素由键值唯一标识。|
| 2 |T |映射值的类型。unordered_map中每个元素以其映射值形式存储数据。|
|3|Hash|一种一元函数对象类型，它将类型为key类型的对象作为参数，并根据它返回类型为size_t的唯一值。|
|4|Pred|接受类型为key的两个值，判断其是否相等并返回bool值。函数形式pred(a,b)，若a=b，函数返回true。|
5|Alloc|定义存储分配模型的分配器类型。 默认情况下，使用allocator类模板，该模板定义最简单的内存分配模型，并且与值无关。|

**4、函数说明**

- size_type count (const key_type& k) const;

	搜索unordered_map中键值为k的元素并返回计数值，否则返回0。

	使用方法: std::unordered_map::count

## vector
**1、代码**

```cpp
template <class T, class Alloc = allocator<T> > class vector; // generic template
```

**2、定义及说明**

向量是可以改变大小的数组序列容器。和数组一样，向量使用连续的存储位置作为元素，这意味着它们的元素也可以使用常量指向其元素的偏移来访问，并且和数组一样有效。但与数组不同，它们的大小可以动态变化，其存储由容器自动处理。

在内部中，向量使用动态分配的数组来存储它们的元素。插入新元素时可能需要重新分配数组来增加大小，这意味着分配新数组并将所有元素移动到该数组。对于向量而言，每次添加元素到容器时，不需要重新分配。

**3、参数说明**

| 序号 | 名称 | 说明 |
|:-----------:|:-------------:|:-------------|
|1|T|元素的类型。只有在T被移动时不移除容器时，才能达到最优的移动元素方式而不是像数组一样在重新分配时复制元素。|
|2|Alloc|定义存储分配模型的分配器类型。默认情况下，使用allocator类模板，该模板定义最简单的内存分配模型，并且与T值无关。|

**4、函数说明**

- size_type size() const;

	返回向量中元素个数。

	使用方法：std::vector::size

- void push_back (const value_type& val);
	
	添加新元素到向量尾部。val的值被复制（移动）给新元素。

	使用方法：std::vector::push_back

@ 北京·怀柔 2019.01.03
