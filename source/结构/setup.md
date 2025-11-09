

## setup()：初始化

当Arduino程序开始运行时会调用setup()函数。通常我们setup()函数其中初始化一些变量、引脚状态及一些调用的库等。当Arduino控制器通电或复位后，setup函数会运行一次。

```c++
void setup()
{
    pinMode(13, OUTPUT);
}
```

