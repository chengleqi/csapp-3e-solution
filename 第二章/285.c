/*
A:
bias = 2^(k-1) - 1 =
v = 2^E + M

7.0 = 111.000 = 1.11000x2^2

E = 2 = e - bias ==>  e = E + bias = 2 + bias = 1 + 2^(k-1) ==> 0 1000...001 1100...


B:
E = n+bias, M = 0b1.11*, f = 0b11*, V = 2^(n+1)-1

bit representation: 0, n+bias, 11*


C:
要想得到最小的规格数，M必须是1.00...的样式 E = 1 - bias
V = 2^(1-bias) 取倒数 ==> V = 2^(bias-1) ==> E = bias - 1
e = bias + E ==> e = 2bias -1 = 2(2^(k-1) - 1) - 1 = 2^k -3
==> 0 1111...101 000000
*/