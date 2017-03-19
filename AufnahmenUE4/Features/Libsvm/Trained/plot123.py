from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

file = open('features.all',"r")
f1 =[]
f2=[]
f3=[]
for zeile in file:
    aktion = zeile.split(' ')[0]
    feature1 = zeile.split(' ')[1]
    feature1 = float(feature1.split(':')[1])
    feature2 = float(zeile.split(' ')[2].split(':')[1])
    feature3 = float(zeile.split(' ')[3].split(':')[1])
    if aktion == "0":
        f1.append(feature1)
        f2.append(feature2)
        f3.append(feature3)
        ax.scatter(feature1,feature2,feature3,color="darkblue",marker=".",s =0.2)
    elif aktion == "1":
        ax.scatter(feature1,feature2,feature3,color="blue",marker=".",s =0.2)
    elif aktion == "2":
        ax.scatter(feature1,feature2,feature3,color="cyan",marker=".",s =0.2)
    elif aktion == "3":
        ax.scatter(feature1,feature2,feature3,color="yellow",marker=".",s =0.2)
    elif aktion == "4":
        ax.scatter(feature1,feature2,feature3,color="red",marker=".",s =0.2)
    elif aktion == "5":
        ax.scatter(feature1,feature2,feature3,color="brown",marker=".",s =0.2)


ax.set_xlabel('Kopfhoehe')
ax.set_ylabel('Minimale Abstand')
ax.set_zlabel('Maximale Abstand')

plt.show()
