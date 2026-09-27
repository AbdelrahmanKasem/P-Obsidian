import math
import numpy as np

# sep  -  we do this to seperate between objects when we want to print something
# end = '\n'  -  to start printing from a new line
# format(x, '0.2f')   -  to determine how many digits we want to print after the decimal point
# format(x, '>10.1f')   -  Right-align 
# format(x, '^10.1f')   -  Center-align
# format(x, '<10.1f')   -  Left-align
# print("{:<10.2f}\n{:>10.3f}".format(x, y))
# from math import sin, pi  -  here is the syntax to import a specific function


# Practical exercise: 1


=========================================
2 * 3;

k = 3 + 4;
print(k);

(k + 1) * (k - 1);

h = (k + 2) * 3 + 3 + (k + 7)
print(h)
========================================
# %reset;

x = 1;
y = 2;
z = 3;
t = 4;

print(f'"x = {x}, y = {y}, z = {z}, t = {t}"');

del(x);

print(f'"y = {y}, z = {z}, t = {t}"');
===========================================
x = (1/3) - (1/7);
y = pow(2, 4) + pow(2, -4);
z = (3 + 0.2) / (1 - 0.35);

print(x, y, z, sep='\n')

print("===============")

print(x, y, z, sep=', ')

print("===============")

print(format(x, '>8.3f'))
print(format(y, '>8.3f'))
print(format(z, '>8.3f'))

print("===============")

print(f"{x:^12.2e}");
print(f"{y:^12.2e}");
print(f"{z:^12.2e}");

===============================

x = 8.2 * 1.3 + (37.1 + 6.03);
y = 7.8 * (5 - 0.9) + 22.07;

if (x > y) :
    print("x is greater than y")
else :
    print("x is leth than y")

================================

import numpy as np
import math

print(np.e)
print(math.pi)

================================
import numpy as np
import math 

x = math.log(pow(np.e, 3) - 2);
y = math.sqrt(np.sin(1)**2 + np.cos(1)**2);

print(x,'\n',y);

===================================

import numpy as np
import math
a= float(input("Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ РІРµС‰РµСЃС‚РІРµРЅРЅРѕРіРѕ С‚РёРїР°"))
b= float(input("Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ РІРµС‰РµСЃС‚РІРµРЅРЅРѕРіРѕ С‚РёРїР°"))
c= int(input("Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ С†РµР»РѕРµ С‚РёРїР°"))
d= int(input("Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ С†РµР»РѕРµ С‚РёРїР°"))

x = (5 * math.sqrt(c) - np.sin(np.deg2rad(a + b))) / pow(((c + d) * (d - 2 * a)), 4)
print(x);

y = abs(2**a + np.e**(b-a*d))
print(y)
