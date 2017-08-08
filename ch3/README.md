# ch3 The Semantics of Data
## Data 语意学
***
0x00000000
```c++
class X {};
class Y:public virtual X {};  
class Z:public virtual X {};
class A:public Y, public Z {};
```
> `sizeof` X 的结果 1  
> `sizeof` Y 的结果 8  
> `sizeof` Z 的结果 8  
> `sizeof` A 的结果 16  

ps:64位操作系统 g++ 4.8.4
空的class有一个编译器安插进去的char，使得一个class的两个object得以在内存中配置独一无二的地址    

Y和Z的大小受到三个因素影响：
- 语言本身所造成的额外负担  虚指针 vptr
- 编译器对特殊情况所提供的优化处理  继承关系
- Alignment的限制  对齐

****Empty virtual base class****  
在这个策略下，一个empty virtual base class 被视为derived class object 最开头的一部分，这就节省了上述第二点中的1 byte。
***
## 3.1 Data Member的绑定(The Binding of a Data Member)  
0x00000001
```c++
// 某个foo.h头文件，从某处含入
extern float x;
// 程序员的 Point3d.h文件
class Point3d
{
public:
    Point3d(float,float,float);
    // 问题：被传回和被设定的 x 是哪一个 x 呢？
    float X() const {return x;}
    void X(float new_x) const { x = new_x; }
    //..
private:
    float x,y,z;
};
```
问：Point3d::X()传回哪一个X? 是class内部那个x，还是外部(extern)那个x?  
