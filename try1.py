import webbrowser
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.colors import ListedColormap

f = open('example.txt')
s = f.read()
f.close()
f = open('abc.html', 'w')

message = """<html>
<body>
<p>%s</p>
""" %s

message = message + """<p>

<font size="3" color=\"red\">This is some text!</font></p>"""

N = 50
x = np.random.rand(N)
y = np.random.rand(N)

colors = np.random.rand(N)

area = np.pi * (15 * np.random.rand(N))**2  # 0 to 15 point radii

plt.scatter(x, y, s=area, c=colors, alpha=0.5)
plt.savefig('test.jpg')

message = message + """<img src=\"test.jpg\"></body>"""
f.write(message)
f.close()
filename = 'file:///home/alconblue/projects/OS/abc.html'
webbrowser.open_new_tab(filename)