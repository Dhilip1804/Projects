import tkinter as tk
from tkinter import filedialog
import subprocess
from PIL import Image, ImageTk  # Import the necessary Pillow modules
import hashlib
import numpy as np
import os

file_path = ""
inital_paramaters=[]
finalkey_list=[]
hex_values=[]
Encrpyted_strings=[]
Decrpyted_strings=[]

s_box= [
    137, 140, 253, 68, 34, 133, 135, 175, 12, 35, 120, 119, 232, 74, 78, 233,
    41, 240, 31, 46, 69, 37, 127, 136, 79, 20, 184, 193, 207, 3, 24, 157,
    36, 221, 73, 236, 57, 167, 144, 77, 118, 215, 220, 226, 249, 108, 156,172,
    255, 45, 165, 201, 248, 49, 198, 163, 58, 80, 189, 30, 242, 94, 237, 254,
    17, 23, 114, 235, 247, 18, 152, 180, 15, 16, 44, 204, 100, 141, 224, 244,
    158, 109, 149, 208, 81, 199, 42, 166, 39, 28, 105, 32, 54, 103, 150, 21,
     0,65, 178, 25, 203, 125, 187, 251, 112, 123, 145, 174, 6, 89, 87, 90,
    138, 82, 111, 121, 241, 102, 104, 110, 47, 211, 106, 214, 86, 98, 117, 197,
    61, 107, 179, 92, 188, 128, 22, 75, 142, 146, 246, 195, 33, 93, 225, 9,
    76, 143, 162, 238, 181, 53, 116, 200, 229, 59, 52, 63, 239, 139, 177, 202,
    124, 194, 96, 132, 51, 161, 252, 155, 38, 192, 50, 29, 67, 1, 56, 97,
    147, 227, 115, 206, 148, 216, 62, 186, 40, 70, 171, 230, 2, 151, 48, 173,
    13, 223, 55, 130, 219, 72, 85, 185, 218, 183, 213, 14, 7, 83, 191, 228,
    153, 169, 4, 101, 205, 26, 126, 10, 160, 84, 182, 250, 210, 60, 5, 99,
    245, 11, 88, 209, 243, 64, 134, 190, 19, 131, 95, 234, 170, 212, 27, 66,
    159, 164, 231, 196, 43, 71, 176, 129, 217, 122, 91, 8, 222, 154, 168, 113
]

inverse_s_box = [
    173, 188, 29, 210, 222, 108, 204, 251, 143, 215, 225, 8, 192, 203, 72, 73,
    64, 69, 232, 25, 95, 134, 65, 30, 99, 213, 238, 89, 171, 59, 18, 91,
    140, 4, 9, 32, 21, 168, 88, 184, 16, 86, 244, 74, 49, 19, 120, 190,
    53, 170, 164, 154, 149, 92, 194, 174, 36, 56, 153, 221, 128, 182, 155, 229,
    97, 239, 172, 3, 20, 185, 245, 197, 34, 13, 135, 144, 39, 14, 24, 57,
    84, 113, 205, 217, 198, 124, 110, 226, 109, 111, 250, 131, 141, 61, 234, 162,
    175, 125, 223, 76, 211, 117, 93, 118, 90, 122, 129, 45, 81, 119, 114, 104,
    255, 66, 178, 150, 126, 40, 11, 10, 115, 249, 105, 160, 101, 214, 22, 133,
    247, 195, 233, 163, 5, 230, 6, 23, 0, 112, 157, 1, 77, 136, 145, 38,
    106, 137, 176, 180, 82, 94, 189, 70, 208, 253, 167, 46, 31, 80, 240, 216,
    165, 146, 55, 241, 50, 87, 37, 254, 209, 236, 186, 47, 191, 107, 7, 246,
    158, 98, 130, 71, 148, 218, 201, 26, 199, 183, 102, 132, 58, 231, 206, 169,
    27, 161, 139, 243, 127, 54, 85, 151, 51, 159, 100, 75, 212, 179, 28, 83,
    227, 220, 121, 237, 202, 123, 41, 181, 248, 200, 196, 42, 33, 252, 193, 78,
    142, 43, 177, 207, 152, 187, 242, 12, 15, 235, 67, 35, 62, 147, 156, 17,
    116, 60, 228, 79, 224, 138, 68, 52, 44, 219, 103, 166, 2, 63, 48, 96
]

permutation_table = [20, 7, 36, 13, 23, 33, 3, 27, 17, 46, 9, 41, 44, 22, 12, 29, 18, 1, 32, 14,
                     26, 8, 4, 11, 38, 45, 19, 2, 30, 21, 47, 34, 5, 10, 15, 6, 25, 24, 31, 37, 0,
                     42, 43, 35, 40, 28, 16, 39]


def open_file_dialog():
    global file_path
    file_path = filedialog.askopenfilename()
    if file_path:
        result_label.config(text=f"Selected Image: {file_path}")



# inital state generator 
def image_to_sha256_bytes(image_file_path):
    try:
        # Open the image file in binary mode
        with open(image_file_path, 'rb') as file:
            # Read the image content
            image_data = file.read()
            # Create a SHA-256 hash object
            sha256_hash = hashlib.sha256()
            # Update the hash object with the image data
            sha256_hash.update(image_data)
            # Get the binary representation of the hash
            hash_bytes = sha256_hash.digest()
            return list(hash_bytes)
    except FileNotFoundError:
        return None

def normalized_value(x):
    final=0
    for i in x:
        final^=i

    return final/2**8
        


def initial_state_generator():
    initial_state_list = []

    byte_list = image_to_sha256_bytes(file_path)
    if byte_list is None:
        print("Failed to get byte list from image.")
        return

    initial_state_list = [byte_list[0:11], byte_list[11:22], byte_list[22:32]]
    for i in initial_state_list:
        inital_paramaters.append(normalized_value(i))  # Assuming normalized_value function is defined elsewhere

    print("Initial state is done....")





# key generation

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

def key_generation():
    global finalkey_list
    # System parameters for Rossler system
    a_rossler, b_rossler, c_rossler = 0.2, 0.2, 5.7

    # System parameters for Lorenz system
    sigma_lorenz, rho_lorenz, beta_lorenz = 10.0, 28.0, 8.0 / 3.0

    # System parameters for Chen's system
    a_chen, b_chen, c_chen = 35.0, 3.0, 28.0

    # System parameters for Chua's system
    a_chua, b_chua, m0_chua, m1_chua = 15.6, 28.0, -1.143, -0.714


    hex_strings=tuple(inital_paramaters)


    # Initial conditions for all systems
    x0, y0, z0 = hex_strings


    # Time span for integration
 
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
        
        inital_paramaters.clear()   # clearing for next stage
        image_to_blocks()
    
    
    print("key generation is done....")
    



# image to blocks

def image_to_blocks():

    image = Image.open(file_path)
    image = image.convert('RGB')
    # Convert the image to a NumPy array
    image_data = image.load()

    
    # Initialize an empty list to store the hexadecimal values
    hex_string = ""
    count = 0

    # Iterate through each pixel and convert it to a hexadecimal value
    for y in range(image.height):
        for x in range(image.width):
            pixel = image_data[x, y]
            hex_value = "{:02X}{:02X}{:02X}".format(pixel[0], pixel[1], pixel[2])
            hex_string += hex_value
            count += 1
            
            # If we have processed 16 pixels, add hex_string to hex_values and reset
            if count == 16:
                hex_values.append(hex_string)
                hex_string = ""
                count = 0

    # If there are fewer than 16 pixels, add zero-padding
    while count < 16:
        hex_string += "000000"
        count += 1
        # You can also break out of the loop if you want exactly 16 values,
        #even if there are fewer pixels available

    # Append the last hex_string to hex_values
    hex_values.append(hex_string)



#image encryption
 
def substitute_bits(input_8bit, s_box):
        return s_box[input_8bit]

def image_encryption():
    key_string = finalkey_list
    result_hex=""

    for data_string in hex_values:
        if len(data_string) != 96:
            print(data_string, len(data_string))

        original_384_bit = [int(data_string[i:i+2], 16) for i in range(0, len(data_string), 2)]

        for i in range(len(key_string)):
            key_str = key_string[i]

            key_bytes = [int(key_str[j:j+2], 16) for j in range(0, len(key_str), 2)]
        
            actual_value = sum(key_bytes) % 2
            
            if actual_value % 2 == 1:
                shifted_data_string = data_string[2:] + data_string[:2]
            else:
                shifted_data_string = data_string[-2:] + data_string[:-2]
                
            original_384_bit = [int(shifted_data_string[j:j+2], 16) for j in range(0, len(shifted_data_string), 2)]

            try:
                permuted_384_bit = [original_384_bit[index] for index in permutation_table]
            except IndexError:
                print(len(original_384_bit))
                print(original_384_bit)
                continue

            substituted_384_bit = [substitute_bits(value, s_box) for value in permuted_384_bit]

            byte = ''.join(format(x, '08b') for x in key_bytes)
            s_384_bit = ''.join(format(x, '08b') for x in substituted_384_bit)

            result = ""
            
            for k in range(len(byte)):
                if (byte[k] == "0" and s_384_bit[k] == "0") or (byte[k] == "1" and s_384_bit[k] == "1"):
                    result += "0"
                else:
                    result += "1"

            result_hex = ''.join([hex(int(result[m:m+4], 2))[2:].upper() for m in range(0, len(result), 4)])
            data_string = result_hex
            
        Encrpyted_strings.append(result_hex)


    # Replace this with the path to your original image
    original_image_path = file_path

    # Open the original color image
    original_image = Image.open(original_image_path)

    # Define the width and height of the original image
    original_width, original_height = original_image.size

    # Initialize an empty list to store the hexadecimal values

    hex_string = ""
    # Create a new image using the dimensions of the original image
    reconstructed_image = Image.new('RGB', (original_width, original_height))

    # Iterate through the hexadecimal values and reconstruct the image
    pixel_data = []
    pixel_count = 0

    for hex_string in Encrpyted_strings:
        for i in range(0, len(hex_string), 6):  # Read six characters at a time
            if pixel_count < original_width * original_height:
                hex_color = hex_string[i:i+6]
                r = int(hex_color[0:2], 16)
                g = int(hex_color[2:4], 16)
                b = int(hex_color[4:6], 16)
                pixel_data.append((r, g, b))
                pixel_count += 1

    # Put the pixel data into the reconstructed image
    reconstructed_image.putdata(pixel_data)

    # Display the reconstructed image
    reconstructed_image.show()

    reconstructed_image.save(r"Encrpyted.jpg")

    hex_values.clear()
    print("image encryption is done....")
    

# image decryption

def inverse_substitute_bits(output_8bit, inverse_s_box):
    return inverse_s_box[output_8bit-1]
def image_decryption():

    inverse_permutation_table = [0] * len(permutation_table)

    for index, value in enumerate(permutation_table):
        inverse_permutation_table[value] = index

    # Convert the encrypted result_hex back to a list of bytes


    Decrpyted_strings=[]
    decrypted_data_string =""
    for data_string in Encrpyted_strings:
    
        for i in range(len(finalkey_list)-1,-1,-1):
            
        
            try:
                encrypted_bytes = bytes.fromhex(data_string)
            except ValueError:
                pass

            # Step 1: Undo the XOR operation with the key
            decrypted_substituted_384_bit = []

            key_bytes = bytes.fromhex(finalkey_list[i])
            actual_value = sum(key_bytes) % 2
            for i, byte in enumerate(key_bytes):
                xor_value = byte ^ encrypted_bytes[i]
                decrypted_substituted_384_bit.append(xor_value)

                
            # Step 2: Undo the inverse S-box substitution
            decrypted_original_384_bit = [
                inverse_substitute_bits(value, inverse_s_box) for value in decrypted_substituted_384_bit]

            decrypted_original_384_bit = [decrypted_original_384_bit[index] for index in inverse_permutation_table]
            
            # Step 3: Undo the shifting
            if actual_value % 2 == 1:
                decrypted_original_384_bit = decrypted_original_384_bit[-1:] + decrypted_original_384_bit[:-1]
            else:
                decrypted_original_384_bit = decrypted_original_384_bit[1:] + decrypted_original_384_bit[:1]

        
            # Convert the decrypted values back to a hexadecimal string
            decrypted_data_string = ''.join(format(byte, '02X') for byte in decrypted_original_384_bit)
            data_string=decrypted_data_string
            
    
        Decrpyted_strings.append(decrypted_data_string)



    # Replace this with the path to your original image
    original_image_path = file_path

    # Open the original color image
    original_image = Image.open(original_image_path)

    # Define the width and height of the original image
    original_width, original_height = original_image.size

    # Initialize an empty list to store the hexadecimal values

    hex_string = ""
    # Create a new image using the dimensions of the original image
    reconstructed_image = Image.new('RGB', (original_width, original_height))

    # Iterate through the hexadecimal values and reconstruct the image
    pixel_data = []
    pixel_count = 0

    for hex_string in Decrpyted_strings:
        for i in range(0, len(hex_string), 6):  # Read six characters at a time
            if pixel_count < original_width * original_height:
                hex_color = hex_string[i:i+6]
                r = int(hex_color[0:2], 16)
                g = int(hex_color[2:4], 16)
                b = int(hex_color[4:6], 16)
                pixel_data.append((r, g, b))
                pixel_count += 1

    # Put the pixel data into the reconstructed image
    reconstructed_image.putdata(pixel_data)

    # Display the reconstructed image
    reconstructed_image.show()

    reconstructed_image.save(r"Decrpyted.jpg")

    Encrpyted_strings.clear()
    Decrpyted_strings.clear()
    finalkey_list.clear()
    print("image decryption is done....")
    








# Create the main application window
app = tk.Tk()
app.title("Choas Encryption System")

# Set the window size
app.geometry("600x550")  # Set your desired width and height

# Disable window resizing
app.resizable(False, False)

# Load the background image and resize it to fit the window while preserving aspect ratio
bg_image = Image.open("background.png")
bg_image = bg_image.resize((600, 550), Image.ANTIALIAS)  # Set the window size as the new size
bg_photo = ImageTk.PhotoImage(bg_image)

# Create a label to display the background image
bg_label = tk.Label(app, image=bg_photo)
bg_label.place(relwidth=1, relheight=1)

# Create a label to display the selected image path
result_label = tk.Label(app, text="")
result_label.pack()

# Create buttons for different actions with larger font and increased button size
button_font = ('Helvetica', 16)
button_width = 20
button_height = 2

# Define button colors
button_bg_color = "white"

open_button = tk.Button(app, text="Select Image", command=open_file_dialog, font=button_font, width=button_width, height=button_height, bg=button_bg_color)
initial_state_button = tk.Button(app, text="Initial State", command=initial_state_generator, font=button_font, width=button_width, height=button_height, bg=button_bg_color)
key_generation_button = tk.Button(app, text="Key Generation", command=key_generation, font=button_font, width=button_width, height=button_height, bg=button_bg_color)
image_encryption_button = tk.Button(app, text="Image Encryption", command=image_encryption, font=button_font, width=button_width, height=button_height, bg=button_bg_color)
image_decryption_button = tk.Button(app, text="Image Decryption", command=image_decryption, font=button_font, width=button_width, height=button_height, bg=button_bg_color)


# Pack buttons to the GUI
open_button.pack(pady=10)
initial_state_button.pack(pady=10)
key_generation_button.pack(pady=10)
image_encryption_button.pack(pady=10)
image_decryption_button.pack(pady=10)

# Start the main event loop
app.mainloop()
