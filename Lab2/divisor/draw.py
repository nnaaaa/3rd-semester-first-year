import numpy as np
import matplotlib.pyplot as plt
arr = np.loadtxt("gcd.txt",delimiter=" ")
arr2 = np.loadtxt("gcd2.txt",delimiter=" ")

x = np.array([x[0] for x in arr])

plt.subplot(1, 2, 1)
assignments = np.array([x[1]+x[2] for x in arr])
comparasions = np.array([x[2] for x in arr])
plt.plot(x,assignments,label="assignemnt")
plt.plot(x,comparasions,label="comaparasions")
plt.title("recursive")


plt.subplot(1, 2, 2)    
assignments = np.array([x[1]+x[2] for x in arr2])
comparasions = np.array([x[2] for x in arr2])
plt.plot(x,assignments,x,comparasions)
plt.title("for loop")
plt.show()