from pathlib import Path
import numpy as np
import matplotlib.pyplot as plt
import math

#Defining a function that can read the stacked data my c++ code outputs
def read_stacked_xy(path):
    x, y = [], []
    mode = None  # "x" or "y"

    # Create a function that opens the data file and outputs the data
    with Path(path).open("r", encoding="utf-8") as f:
        for raw in f:
            line = raw.strip()
            if not line:
                continue

            # Determine which axis is being read
            low = line.lower()
            if low.startswith("# vector x"):
                mode = "x"
                continue
            if low.startswith("# vector y"):
                mode = "y"
                continue

            # skip other comments
            if line.startswith("#"):
                continue

            # allow "1.23", or "1.23 4.56" or "1.23,4.56" on the same line
            parts = line.replace(",", " ").split()
            vals = [float(p) for p in parts]

            # Write the values to the correct array
            if mode == "x":
                x.extend(vals)
            elif mode == "y":
                y.extend(vals)

    # Define the np arrays
    x = np.array(x, dtype=float)
    y = np.array(y, dtype=float)

    # Throw an error if two datasets aren't equal
    if len(x) != len(y):
        raise ValueError(f"Length mismatch: len(x)={len(x)} vs len(y)={len(y)}")

    return x, y


# Define linspace for problem 1
x_prob1 = np.linspace(0, 2, 100)
y_prob1 = np.tan(x_prob1)

# Get the data needed from c++
euler_x10, euler_y10 = read_stacked_xy("euler_10_pts.txt")
euler_x50, euler_y50 = read_stacked_xy("euler_50_pts.txt")
euler_x75, euler_y75 = read_stacked_xy("euler_75_pts.txt")
euler_x100, euler_y100 = read_stacked_xy("euler_100_pts.txt")
euler_x500, euler_y500 = read_stacked_xy("euler_500_pts.txt")
euler_x1000, euler_y1000 = read_stacked_xy("euler_1000_pts.txt")
RK4_x10, RK4_y10 = read_stacked_xy("RK4_10_pts.txt")
RK4_x50, RK4_y50 = read_stacked_xy("RK4_50_pts.txt")
RK4_x75, RK4_y75 = read_stacked_xy("RK4_75_pts.txt")
RK4_x100, RK4_y100 = read_stacked_xy("RK4_100_pts.txt")
RK4_x500, RK4_y500 = read_stacked_xy("RK4_500_pts.txt")
RK4_x1000, RK4_y1000 = read_stacked_xy("RK4_1000_pts.txt")

# Plots for problem l
plt.scatter(euler_x50, euler_y50, label = "Euler Method", c="red")
plt.scatter(RK4_x50, RK4_y50, label = "RK4 data", c="blue")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(-0.2, 50)
plt.title("Different Integration Methods for 50 pts")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(euler_x50, euler_y50, label = "Euler Method", c="red")
plt.scatter(RK4_x50, RK4_y50, label = "RK4 data", c="blue")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(0, 20)
plt.xlim(1.25, 1.5)
plt.title("Different Integration Methods for 50 pts (zoomed in)")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(euler_x75, euler_y75, label = "Euler Method", c="red")
plt.scatter(RK4_x75, RK4_y75, label = "RK4 data", c="blue")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(-0.2, 50)
plt.title("Different Integration Methods for 75 pts")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(euler_x75, euler_y75, label = "Euler Method", c="red")
plt.scatter(RK4_x75, RK4_y75, label = "RK4 data", c="blue")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(0, 20)
plt.xlim(1.25, 1.5)
plt.title("Different Integration Methods for 75 pts (zoomed in)")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(euler_x100, euler_y100, label = "Euler Method", c="red")
plt.scatter(RK4_x100, RK4_y100, label = "RK4 data", c="blue")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(-0.2, 50)
plt.title("Different Integration Methods for 100 pts")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(euler_x100, euler_y100, label = "Euler Method", c="red")
plt.scatter(RK4_x100, RK4_y100, label = "RK4 data", c="blue")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(0, 20)
plt.xlim(1.25, 1.5)
plt.title("Different Integration Methods for 100 pts (zoomed in)")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(euler_x100, euler_y100, label = "100 points", c="red")
plt.scatter(euler_x75, euler_y75, label = "75 points", c="blue")
plt.scatter(euler_x50, euler_y50, label = "50 points", c="green")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(0, 20)
plt.xlim(1.25, 1.5)
plt.title("Same integration method with differing number of points (Euler)")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

plt.scatter(RK4_x100, RK4_y100, label = "100 points", c="red")
plt.scatter(RK4_x75, RK4_y75, label = "75 points", c="blue")
plt.scatter(RK4_x50, RK4_y50, label = "50 points", c="green")
plt.plot(x_prob1, y_prob1, label = "Analytic Solution")

plt.ylim(0, 20)
plt.xlim(1.25, 1.5)
plt.title("Same integration method with differing number of points (RK4)")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()


n_mat = [10, 50, 75, 100, 500]
y10 = euler_y10[np.where(euler_x10 == 0.8)[0]]
y50 = euler_y50[np.where(euler_x50 == 0.8)[0]]
y75 = euler_y75[np.where(euler_x75 == 0.8)[0]]
y100 = euler_y100[np.where(euler_x100 == 0.8)[0]]
y500 = euler_y500[np.where(euler_x500 == 0.8)[0]]
y1000 = euler_y1000[np.where(euler_x1000 == 0.8)[0]]
error_matrix_e = [abs(y10 - y1000)/y1000, abs(y50 - y1000)/y1000, abs(y75 - y1000)/y1000, abs(y100 - y1000)/y1000, abs(y500 - y1000)/y1000]



y10_1 = RK4_y10[np.where(RK4_x10 == 0.8)[0]]
y50_1 = RK4_y50[np.where(RK4_x50 == 0.8)[0]]
y75_1 = RK4_y75[np.where(RK4_x75 == 0.8)[0]]
y100_1 = RK4_y100[np.where(RK4_x100 == 0.8)[0]]
y500_1 = RK4_y500[np.where(RK4_x500 == 0.8)[0]]
y1000_1 = RK4_y1000[np.where(RK4_x1000 == 0.8)[0]]
error_matrix_R = [abs(y10_1 - y1000_1)/y1000_1, abs(y50_1 - y1000_1)/y1000_1, abs(y75_1 - y1000_1)/y1000_1, abs(y100_1 - y1000_1)/y1000_1, abs(y500_1 - y1000_1)/y1000_1]
print(error_matrix_R)
print(error_matrix_e)
plt.plot(n_mat, error_matrix_R, label = "RK4", color = "red")
#plt.plot(n_mat, error_matrix_e, label = 'Euler', color ='blue')
plt.xscale('log')
plt.yscale('log')
plt.title("Convergence")
plt.xlabel("n")
plt.ylabel("Fractional difference at x=0.8")
plt.legend()
plt.grid(True)
plt.show()

"""
# Plot the function for problem 2
m = 1.67e-27
T = 10000
k = 1.3806e-23
pi = 3.1415926535
factor = m/(2*k*T)
x_axis = np.linspace(0, 4.5e4, 300)
y_axis = (factor/pi)**(3/2)*4*pi*x_axis**2*np.exp(-factor*x_axis**2)

plt.plot(x_axis, y_axis)

plt.xlabel("v (m/s)")
plt.ylabel("f(v)")
plt.legend()
plt.grid(True)
plt.show()


euler_prob2_100_1_x, euler_prob2_100_1_y = read_stacked_xy("euler_100_pts_prob2_1.txt")
euler_prob2_100_2_x, euler_prob2_100_2_y = read_stacked_xy("euler_100_pts_prob2_2.txt")
euler_prob2_100_3_x, euler_prob2_100_3_y = read_stacked_xy("euler_100_pts_prob2_3.txt")
euler_prob2_150_1_x, euler_prob2_150_1_y = read_stacked_xy("euler_150_pts_prob2_1.txt")
euler_prob2_200_1_x, euler_prob2_200_1_y = read_stacked_xy("euler_200_pts_prob2_1.txt")

RK4_prob2_100_1_x, RK4_prob2_100_1_y = read_stacked_xy("RK4_100_pts_prob2_1.txt")
RK4_prob2_100_2_x, RK4_prob2_100_2_y = read_stacked_xy("RK4_100_pts_prob2_2.txt")
RK4_prob2_100_3_x, RK4_prob2_100_3_y = read_stacked_xy("RK4_100_pts_prob2_3.txt")
RK4_prob2_150_1_x, RK4_prob2_150_1_y = read_stacked_xy("RK4_150_pts_prob2_1.txt")
RK4_prob2_200_1_x, RK4_prob2_200_1_y = read_stacked_xy("RK4_200_pts_prob2_1.txt")


plt.plot(euler_prob2_200_1_x, euler_prob2_200_1_y, label = "Euler Method", color = "blue")
plt.plot(RK4_prob2_200_1_x, RK4_prob2_200_1_y, label = "RK4 Method", color = "red")

plt.title("Euler vs. RK4 for highest resolution case")
plt.ylabel("$\int f(v)$")
plt.xlabel("$v_m$ (m/s)")
plt.legend()
plt.grid(True)
plt.show()

plt.plot(euler_prob2_200_1_x, euler_prob2_200_1_y, label = "200 pts", color = "blue")
plt.plot(euler_prob2_150_1_x, euler_prob2_150_1_y, label = "150 pts", color = "red")
plt.plot(euler_prob2_100_1_x, euler_prob2_100_1_y, label = "100", color = "green")

plt.title("Different number of points (Euler)")
plt.ylabel("$\int f(v)$")
plt.xlabel("$v_m$ (m/s)")
plt.legend()
plt.grid(True)
plt.show()

plt.plot(RK4_prob2_200_1_x, RK4_prob2_200_1_y, label = "200 pts", color = "blue")
plt.plot(RK4_prob2_150_1_x, RK4_prob2_150_1_y, label = "150 pts", color = "red")
plt.plot(RK4_prob2_100_1_x, RK4_prob2_100_1_y, label = "100", color = "green")

plt.title("Different number of points (RK4)")
plt.ylabel("$\int f(v)$")
plt.xlabel("$v_m$ (m/s)")
plt.legend()
plt.grid(True)
plt.show()

plt.plot(euler_prob2_100_1_x, euler_prob2_100_1_y, label = "$v_m$ = 4.5e4", color = "blue")
plt.plot(euler_prob2_100_2_x, euler_prob2_100_2_y, label = "$v_m$ = 6e4", color = "red")
plt.plot(euler_prob2_100_3_x, euler_prob2_100_3_y, label = "$v_m$ = 7.5e4", color = "green")

plt.title("Different max value for same number of points (Euler)")
plt.ylabel("$\int f(v)$")
plt.xlabel("$v_m$ (m/s)")
plt.legend()
plt.grid(True)
plt.show()

plt.plot(RK4_prob2_100_1_x, RK4_prob2_100_1_y, label = "$v_m$ = 4.5e4", color = "blue")
plt.plot(RK4_prob2_100_2_x, RK4_prob2_100_2_y, label = "$v_m$ = 6e4", color = "red")
plt.plot(RK4_prob2_100_3_x, RK4_prob2_100_3_y, label = "$v_m$ = 7.5e4", color = "green")

plt.title("Different max value for same number of points (RK4)")
plt.ylabel("$\int f(v)$")
plt.xlabel("$v_m$ (m/s)")
plt.legend()
plt.grid(True)
plt.show()"""