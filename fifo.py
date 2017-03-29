import webbrowser
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.colors import ListedColormap

f = open("fifo.txt")
s = f.readlines()
s1 = []
f.close()

for a in s:
    s1.append(a.split())
message = """<html>
<body>"""

part = """ """

for sp in s1:
    message += """<hr><p> The Request made is: %s""" %sp[-2]
    message += """<p> The Page Numbers allocated are: </p>"""
    if sp[-1] == "0":
        message += """<p><font size="3" color=\"red\">"""
        for x in sp[:-2]:
            if x != "-1":
                message += x + """ """
        message += """ Miss"""
    else:
        message += """<p><font size="3" color=\"blue\">"""
        for x in sp[:-2]:
            if x != "-1":
                message += x + """ """
        message += """ Hit"""
    message+= """</font></p>"""
message += """</body></head>"""
f = open('abc.html', 'w')
f.write(message)
f.close()
filename = 'abc.html'
webbrowser.open_new_tab(filename)