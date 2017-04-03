import webbrowser
import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import spline

f = open("fifo1.txt")
s = f.readlines()
s1 = []
f.close()
for a in s:
    s1.append(a.split())
s2 = np.array(s1).astype(np.float)
x = np.array(s2[:,1])
y=np.arange(0,10000)
y1 = []
for i in range (0,10000):
    y1.append(i)
x1 = []
for a in s2[:,1]:
    x1.append(a)
x_smooth = np.linspace(y.min(), y.max(), 2000)
y_smooth = spline(y1, x1, x_smooth)
print y_smooth
plt.plot(x_smooth, y_smooth)
plt.show()