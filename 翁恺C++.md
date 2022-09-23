### 多态
在函数前添加 `virtual` 关键字时也需要在析构函数前添加，此时在类的内存最前面会生成一个隐藏的指针，指向此类的函数表。动态绑定是由这个指针来实现的(因此只有通过指针、引用才能向上造型、体现多态性)。
### 引用
实现：``const pointer``
- 作为成员变量时：必须使用初始化列表绑定一个变量。因为其他时候都是赋值，而引用不能赋值且必须初始化。
- 作为返回值：与指针一样，不能返回局部变量，只能返回全局变量。普通的局部变量（并非指针或引用）是可以被返回的
例：``double value = subscript(12)`` 是将 subscript 返回的引用的值赋给了 value。
- 参数是引用时，传入的参数必须是变量，不能是式子。如果是式子会产生临时变量替代这个式子

### const
```
//第一个 const 防止作为左值。最后一个 const 修饰 this 指针
const Integer operator+(const Integer& n) const{
    return Integer(i + n.i);
}
```

## 重载
```
z = x + y;  //√
z = x + 3;  //√     自动将 3 转换为临时的类再调用重载的 + 
z = x + 3.5;//x     如果没有提供double的重装就不能 +
z = 3 + y;  //x     + 自动识别为 int 类的 +
            //√     双目运算的全局相加是可以的
```
可以在构造函数之前加上 ``explicit`` 关键词变成显式的，不会隐含自动转换，这时上面的 ``z = x + 3`` 也会出错
### 重载的运算符函数作为成员函数还是非成员函数
- 单目操作符应该是成员函数
- =  ()  []  ->  ->*必须是成员函数
- 赋值操作应该是成员函数
- 所有其他的双目运算应该是非成员函数

在类外面定义重载需要使用friend
```
class Integer{
    friend const Integer operator+(
            const Integer& lhs,
            const Integer& rhs);
}
const Integer operator+(
            const Integer& lhs,
            const Integer& rhs){
    return Integer(lhs.i + rhs.i);
}
```

### 重载操作符的原型
``+ - * / % ^ & | ~``
``const T operatorX(const T& I,const T& r) const;``
``! && || < <= == >= >``
``bool operatorX(const T& I,const T& r) const;``
``[]``
``T& T::operator[](int index);``
``++ --``
``const Integer& operator++();      //prefix++``
``const Integer operator++(int);      //postfix++``
``const Integer& operator--();      //prefix--``
``const Integer operator--(int);      //postfix--``

```
const Integer& Integer::operator++(){
    *this += 1;
    return *this;
}

const Integer Integer::operator++(int){
    Integer old(*this); //拷贝构造
    ++(*this);          //调用后置的自增
    return old;         //因为不能返回本地变量的引用
}
```

同理用 ``==`` 来定义 ``!=``
    用 ``<`` 来定义 ``>``
    用 ``<=`` 来定义 ``>=``

#### 重载赋值
```
T& T::operator=(const T& rhs){
    //当this=rhs时，若需要先释放空间的，会将其直接删除
    if(this != &rhs){
        //执行赋值
    }
    return *this;
}
```

#### 重载类型转换
X的对象转换为T:
``X::operator T()``
- 操作符名称任意
- 无explicit
- 无返回值类型
- 编译器会将其转换：X->T

##### C++类型转换
char -> short -> int -> float -> double
                 int -> long

T -> T&     T& -> T     T* -> void*
T[] ->T*    T* -> Y[]   T -> const T

### 类模板可以定义默认值
```
template <calss T, int bounds = 100>
class F{
    public:
        F();
        T& operator[](int);
    private:
        T elements[bounds];
}
```