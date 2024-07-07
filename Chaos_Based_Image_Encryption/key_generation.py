import numpy as np
from scipy.integrate import solve_ivp
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes
from PIL import Image
import os
import hashlib
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Rossler system
def rossler(t, state, a, b, c):
    x, y, z = state
    dxdt = -y - z
    dydt = x + a * y
    dzdt = b + z * (x - c)
    return [dxdt, dydt, dzdt]

# Lorenz system
def lorenz(t, state, sigma, rho, beta):
    x, y, z = state
    dxdt = sigma * (y - x)
    dydt = x * (rho - z) - y
    dzdt = x * y - beta * z
    return [dxdt, dydt, dzdt]

# Chen's system
def chen(t, state, a, b, c):
    x, y, z = state
    dxdt = a * (y - x)
    dydt = (c - a) * x - x * z + c * y
    dzdt = x * y - b * z
    return [dxdt, dydt, dzdt]

def chua(t, state, alpha, beta, m0, m1):
    x, y, z = state
    dxdt = alpha * (y - x) - m0 * x - ((m1-m0)* abs(x+1) - abs(x-1))/2
    dydt = x - y + z
    dzdt = -beta * y
    return [dxdt, dydt, dzdt]

def runge_kutta(f, t_span, y0, args=(), h=0.01):
    t_values = np.arange(t_span[0], t_span[1] + h, h)
    y = np.zeros((len(y0), len(t_values)))
    y[:, 0] = y0
    
    for i in range(len(t_values) - 1):
        k1 = h * np.array(f(t_values[i], y[:, i], *args))
        k2 = h * np.array(f(t_values[i] + h / 2, y[:, i] + k1 / 2, *args))
        k3 = h * np.array(f(t_values[i] + h / 2, y[:, i] + k2 / 2, *args))
        k4 = h * np.array(f(t_values[i] + h, y[:, i] + k3, *args))
        y[:, i + 1] = y[:, i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6
    
    return t_values, y


def keyfinal(t_values,sol):
    x,y,z=sol
    step_counter=0
    for i in range(len(t_values)):
        if i % 100 == 0:
            t = t_values[i]
            x_val = x[i]
            y_val = y[i]
            z_val = z[i]
            step_counter += 1
    key=[x_val,y_val,z_val]
    return key

# System parameters for Rossler system
a_rossler, b_rossler, c_rossler = 0.2, 0.2, 5.7

# System parameters for Lorenz system
sigma_lorenz, rho_lorenz, beta_lorenz = 10.0, 28.0, 8.0 / 3.0

# System parameters for Chen's system
a_chen, b_chen, c_chen = 35.0, 3.0, 28.0

# System parameters for Chua's system
a_chua, b_chua, m0_chua, m1_chua = 15.6, 28.0, -1.143, -0.714


input_file_path = 'inital_paramaters.txt'

# Read the hex strings from the text file into an array
hex_strings = []
with open(input_file_path, 'r') as file:
    for line in file:
        hex_strings.append(line.strip())

hex_strings=tuple(hex_strings)


# Initial conditions for all systems
x0, y0, z0 = hex_strings

print(x0,y0,z0)

# Time span for integration
finalkey_list=[]

for i in range(1,5):
    t_span = (0, i*100)

    # Numerically solve the differential equations using the Runge-Kutta method (runge_kutta)
    t_values_r, sol_r = runge_kutta(rossler, t_span, [x0, y0, z0], args=(a_rossler, b_rossler, c_rossler))
    t_values_l, sol_l = runge_kutta(lorenz, t_span, [x0, y0, z0], args=(sigma_lorenz, rho_lorenz, beta_lorenz))
    t_values_c, sol_c = runge_kutta(chen, t_span, [x0, y0, z0], args=(a_chen, b_chen, c_chen))
    t_values_ch, sol_ch = runge_kutta(chua, t_span, [x0, y0, z0], args=(a_chua, b_chua, m0_chua, m1_chua))

    key1=keyfinal(t_values_r, sol_r )
    key2=keyfinal(t_values_l, sol_l)
    key3=keyfinal(t_values_c, sol_c)
    key4=keyfinal(t_values_ch, sol_ch)

    

    sol=np.array([[np.float32(key1[0]),np.float32(key2[0]),np.float32(key3[0]),np.float32(key4[0])],[np.float32(key1[1]),np.float32(key2[1]),np.float32(key3[1]),np.float32(key4[1])],[np.float32(key1[2]),np.float32(key2[2]),np.float32(key3[2]),np.float32(key4[2])]])
    finalkey=sol.tobytes().hex()
    finalkey_list.append(finalkey)
    
output_file_path = 'key_strings.txt'

# Write the hex strings to a text file
with open(output_file_path, 'w') as file:
    for hex_string in finalkey_list:
        file.write(hex_string + '\n')

print(f"key_strings saved to '{output_file_path}'")





