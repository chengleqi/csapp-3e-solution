/*
A：总是返回１．因为int到double不会有精度上的损失，所以ｘ，dx转float(损失精度)的结果是一样的。

B：不总是返回１．如x=INT_MIN，Y=1。

C：由于int转换为double不会有精度上的损失，且在int范围内使用double做加法得到的结果一定是精确的（这是因为double的尾数足以容纳32bit），因此满足结合律。

D：不总是返回１．原因同上。例如dx与dy互为倒数且dy*dz=+infinite。

E：不总是返回１．例如dx=1.0, dz=0.0　。
*/