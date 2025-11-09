# loop()：无限循环（主程序）

在setup()函数对程序完成了初始化后，loop()函数将会运行。loop函数是一个循环体，在Arduino启动后，loop()函数中的程序将会不断运行。

```C++
void loop()
{
    digitalWrite(13, HIGH);
}
```
